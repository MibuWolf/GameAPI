#include "StdAfx.h"
#include <CrySchematyc/ResourceTypes.h>
#include <CrySchematyc\Reflection\TypeDesc.h>
#include "WeaponComponent.h"

static void RegisterWeaponComponent(Schematyc::IEnvRegistrar& registrar)
{
	Schematyc::CEnvRegistrationScope scope = registrar.Scope(IEntity::GetEntityScopeGUID());
	{
		Schematyc::CEnvRegistrationScope componentScope = scope.Register(SCHEMATYC_MAKE_ENV_COMPONENT(WeaponComponent));
		// Functions
		{
		}
	}
}

CRY_STATIC_AUTO_REGISTER_FUNCTION(&RegisterWeaponComponent)


void WeaponComponent::InitializeClass()
{

}


void WeaponComponent::ProcessEventClass(SEntityEvent& event)
{

}

void WeaponComponent::ReflectType(Schematyc::CTypeDesc<WeaponComponent>& desc)
{
	desc.SetGUID("{77886B1A-B260-40CE-A697-BD256EAE1B88}"_cry_guid);
	desc.AddBase<ItemComponent>();
	desc.SetEditorCategory("Items");
	desc.SetLabel("Weapon Component");
	desc.SetDescription("Base Weapon Component");
	desc.AddMember(&WeaponComponent::sItemPro, 0, "weaponPro", "WeaponProperty", "Set Weapon Property", SItemProperties());
}
