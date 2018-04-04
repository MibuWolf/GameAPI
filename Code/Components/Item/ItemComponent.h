/*************************************************************************
-------------------------------------------------------------------------
Description:  Base Item Component
-------------------------------------------------------------------------
Author: Sam
*************************************************************************/
#pragma once
#include "../Properties/Properties.h"
#include <CryEntitySystem/IEntityComponent.h>

class ActorComponent;

class ItemComponent  : public IEntityComponent
{
public:

	ItemComponent() = default;
	virtual ~ItemComponent() {}


public:

	virtual void	Initialize() override;
	virtual void	InitializeClass();
	virtual	uint64	GetEventMask() const override;
	virtual	void	ProcessEvent(SEntityEvent& event) override;
	virtual void	ProcessEventClass(SEntityEvent& event);

	virtual void	LoadGeometry();
	virtual void	Physicalize();

	virtual void	PickUp(ActorComponent *pNewOwner);
	virtual bool	IsPickable();

	// Reflect type to set a unique identifier for this component
	// and provide additional information to expose it in the sandbox
	static void ReflectType(Schematyc::CTypeDesc<ItemComponent>& desc);

	virtual SItemProperties*	GetProperties() { return &sItemPro; }

protected:

	SItemProperties sItemPro, sPreItemPro;

	ActorComponent* pOwner;
};