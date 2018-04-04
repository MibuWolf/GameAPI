/*************************************************************************
-------------------------------------------------------------------------
Description:  Weapon Base Component
-------------------------------------------------------------------------
Author: Sam
*************************************************************************/
#pragma once
#include "ItemComponent.h"
#include "../Properties/Properties.h"
#include <CryEntitySystem/IEntityComponent.h>


class WeaponComponent : public ItemComponent
{
public:

	WeaponComponent() = default;
	virtual ~WeaponComponent() {}

	virtual void	InitializeClass() override;
	virtual void	ProcessEventClass(SEntityEvent& event) override;

	static void ReflectType(Schematyc::CTypeDesc<WeaponComponent>& desc);

};