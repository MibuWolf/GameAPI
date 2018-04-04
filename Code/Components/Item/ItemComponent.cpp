#include "StdAfx.h"
#include "ItemComponent.h"
#include <CrySchematyc/ResourceTypes.h>
#include <CrySchematyc\Reflection\TypeDesc.h>


static void RegisterItemComponent(Schematyc::IEnvRegistrar& registrar)
{
	Schematyc::CEnvRegistrationScope scope = registrar.Scope(IEntity::GetEntityScopeGUID());
	{
		Schematyc::CEnvRegistrationScope componentScope = scope.Register(SCHEMATYC_MAKE_ENV_COMPONENT(ItemComponent));
		// Functions
		{
		}
	}
}

CRY_STATIC_AUTO_REGISTER_FUNCTION(&RegisterItemComponent)


void ItemComponent::Initialize()
{
	LoadGeometry();
	Physicalize();
	InitializeClass();
}

void ItemComponent::InitializeClass()
{
}

uint64 ItemComponent::GetEventMask() const
{
	return BIT64(ENTITY_EVENT_COMPONENT_PROPERTY_CHANGED);
}

void ItemComponent::ProcessEvent(SEntityEvent & event)
{
	switch (event.event)
	{
	case ENTITY_EVENT_COMPONENT_PROPERTY_CHANGED:
	{
		if (sItemPro != sPreItemPro)
		{
			sPreItemPro = sItemPro;
			LoadGeometry();
			Physicalize();
		}
	}break;
	default:
		break;
	}

	ProcessEventClass(event);
}

void ItemComponent::ProcessEventClass(SEntityEvent & event)
{
}

void ItemComponent::LoadGeometry()
{
	string sPath = this->GetProperties()->sRenderProperties.sGeomPath.value.c_str();

	if (sPath.empty())
		return;

	m_pEntity->LoadGeometry(GEOMETRY_SLOT, sPath);

	
}

void ItemComponent::Physicalize()
{
	SEntityPhysicalizeParams params;
	params.mass = this->GetProperties()->sPhysicsProperties.fMass;
	params.type = PE_RIGID;

	m_pEntity->Physicalize(params);
}

void ItemComponent::PickUp(ActorComponent *pNewOwner)
{
	if (!pNewOwner)
		return;

	pOwner = pNewOwner;
	pOwner->GetEntity()->AttachChild(m_pEntity);
}

bool ItemComponent::IsPickable()
{
	return !pOwner;
}

void ItemComponent::ReflectType(Schematyc::CTypeDesc<ItemComponent>& desc)
{
	desc.SetGUID("{D2982E9A-ED40-4077-AAE7-5D3B11076123}"_cry_guid);
}
