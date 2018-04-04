#pragma once

#include <array>
#include <numeric>

#include <ICryMannequin.h>
#include <CryMath/Cry_Camera.h>
#include <CrySchematyc\Reflection\TypeDesc.h>
#include <CryEntitySystem/IEntityComponent.h>
#include <DefaultComponents/Input/InputComponent.h>
#include <DefaultComponents/Cameras/CameraComponent.h>
#include <DefaultComponents/Physics/CharacterControllerComponent.h>
#include <DefaultComponents/Geometry/AdvancedAnimationComponent.h>



////////////////////////////////////////////////////////
// Represents a player participating in gameplay
////////////////////////////////////////////////////////

#define PICKUP_RANGE 3.0

class ActorComponent : public IEntityComponent
{
	enum class EInputFlagType
	{
		Hold = 0,
		Toggle
	};

	typedef uint8 TInputFlags;

	enum class EInputFlag
		: TInputFlags
	{
		MoveLeft = 1 << 0,
		MoveRight = 1 << 1,
		MoveForward = 1 << 2,
		MoveBack = 1 << 3
	};

	template<typename T, size_t SAMPLES_COUNT>
	class MovingAverage
	{
		static_assert(SAMPLES_COUNT > 0, "SAMPLES_COUNT shall be larger than zero!");

	public:

		MovingAverage()
			: m_values()
			, m_cursor(SAMPLES_COUNT)
			, m_accumulator()
		{
		}

		MovingAverage& Push(const T& value)
		{
			if (m_cursor == SAMPLES_COUNT)
			{
				m_values.fill(value);
				m_cursor = 0;
				m_accumulator = std::accumulate(m_values.begin(), m_values.end(), T(0));
			}
			else
			{
				m_accumulator -= m_values[m_cursor];
				m_values[m_cursor] = value;
				m_accumulator += m_values[m_cursor];
				m_cursor = (m_cursor + 1) % SAMPLES_COUNT;
			}

			return *this;
		}

		T Get() const
		{
			return m_accumulator / T(SAMPLES_COUNT);
		}

		void Reset()
		{
			m_cursor = SAMPLES_COUNT;
		}

	private:

		std::array<T, SAMPLES_COUNT> m_values;
		size_t m_cursor;

		T m_accumulator;
	};

public:

	ActorComponent();
	virtual ~ActorComponent();

	virtual void Initialize() override;

	virtual uint64 GetEventMask() const override;
	virtual void ProcessEvent(SEntityEvent& event) override;

	// Reflect type to set a unique identifier for this component
	static void ReflectType(Schematyc::CTypeDesc<ActorComponent>& desc)
	{
		desc.SetGUID("{DA8EB37A-7B68-47AD-A331-0485AD362C45}"_cry_guid);

		//desc.SetEditorCategory("Actor");
		//desc.SetLabel("Actor Component");
		//desc.SetDescription("Base Actor Component");
		//desc.AddMember(&ActorComponent::animationADBPath, 0, "adbPath", "animationADB", "Set ADB File Path", "");
		//desc.AddMember(&ActorComponent::characterPath, 1, "characterPath", "characterPath", "Set Character Path", "");
		//desc.AddMember(&ActorComponent::controlDefPath, 2, "controlDefPath", "controlDefPath", "Set controlDefPath", "");

	}

public:

	// 加载Character的逻辑接口
	void LoadCharacter(string modelName);

	// 设置部件模型
	void SetPartModel(string partName, string modelName);

	void Revive();

protected:
	void UpdateMovementRequest(float frameTime);
	void UpdateLookDirectionRequest(float frameTime);
	void UpdateAnimation(float frameTime);
	void UpdateCamera(float frameTime);
	void Update(float frameTime);
	void ShowPickupMessage(string itemName);

	void SpawnAtSpawnPoint();

	void CreateWeapon(const char *name);

	void HandleInputFlagChange(TInputFlags flags, int activationMode, EInputFlagType type = EInputFlagType::Hold);

protected:
	Cry::DefaultComponents::CCameraComponent* m_pCameraComponent = nullptr;
	Cry::DefaultComponents::CCharacterControllerComponent* m_pCharacterController = nullptr;
	Cry::DefaultComponents::CAdvancedAnimationComponent* m_pAnimationComponent = nullptr;
	Cry::DefaultComponents::CInputComponent* m_pInputComponent = nullptr;

	FragmentID m_idleFragmentId;
	FragmentID m_walkFragmentId;
	TagID m_rotateTagId;

	TInputFlags m_inputFlags;
	Vec2 m_mouseDeltaRotation;
	MovingAverage<Vec2, 10> m_mouseDeltaSmoothingFilter;

	FragmentID m_activeFragmentId;

	Quat m_lookOrientation; //!< Should translate to head orientation in the future
	float m_horizontalAngularVelocity;
	MovingAverage<float, 10> m_averagedHorizontalAngularVelocity;

	// 根据逻辑需求填充资源路径（）
	Schematyc::MannequinAnimationDatabasePath		animationADBPath;
	Schematyc::CharacterFileName					characterPath;
	Schematyc::MannequinControllerDefinitionPath	controlDefPath;
};
