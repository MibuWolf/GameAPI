#pragma once
#include <CrySchematyc/ResourceTypes.h>
#include <CrySchematyc\Reflection\TypeDesc.h>


enum GeometrySlot
{
	GEOMETRY_SLOT = 0
};

struct SRenderProperties
{
	inline bool	operator == (const SRenderProperties& rhs) const { return 0 == memcmp((void*)this, &rhs, sizeof(rhs)); };
	inline bool	operator != (const SRenderProperties& rhs) const { return 0 != memcmp((void*)this, &rhs, sizeof(rhs)); };

	Schematyc::GeomFileName sGeomPath;
	Schematyc::MaterialFileName sMaterialPath;
};

static void ReflectType(Schematyc::CTypeDesc<SRenderProperties>& desc)
{
	desc.SetGUID("{74D0EC18-6E98-474A-A002-C5B261D73C18}"_cry_guid);
	desc.SetLabel("Render Properties");
	desc.SetDescription("Render Properties");
	desc.AddMember(&SRenderProperties::sGeomPath, 0,"geometry", "GeometryPath", "Select Geometry Path.", "");
	desc.AddMember(&SRenderProperties::sMaterialPath, 1, "material", "MaterialPath", "Select Material Path.", "");
}



struct SPhysicsProperties
{
	inline bool	operator == (const SPhysicsProperties& rhs) const { return 0 == memcmp((void*)this, &rhs, sizeof(rhs)); };
	inline bool	operator != (const SPhysicsProperties& rhs) const { return 0 != memcmp((void*)this, &rhs, sizeof(rhs)); };

	float fMass;
};

static void ReflectType(Schematyc::CTypeDesc<SPhysicsProperties>& desc)
{
	desc.SetGUID("{DFA57015-6796-4B2C-9999-6B3A4A703B6F}"_cry_guid);
	desc.SetLabel("Physics Properties");
	desc.SetDescription("Physics Properties");
	desc.AddMember(&SPhysicsProperties::fMass, 0, "mass", "mass", "Set Physics Mass.", 1);
}



struct SItemProperties
{
	inline bool	operator == (const SItemProperties& rhs) const { return 0 == memcmp((void*)this, &rhs, sizeof(rhs)); };
	inline bool	operator != (const SItemProperties& rhs) const { return 0 != memcmp((void*)this, &rhs, sizeof(rhs)); };

	SRenderProperties	sRenderProperties;
	SRenderProperties	sPreRenderProperties;
	SPhysicsProperties 	sPhysicsProperties;
};


static void ReflectType(Schematyc::CTypeDesc<SItemProperties>& desc)
{
	desc.SetGUID("{45782A7C-0226-4125-8C9F-C75D903965BA}"_cry_guid);
	desc.SetLabel("Item Properties");
	desc.SetDescription("Item Properties");
	desc.AddMember(&SItemProperties::sRenderProperties, 0, "renderPro", "RenderProperties", "Render Setting for this Item.", SRenderProperties());
	desc.AddMember(&SItemProperties::sPhysicsProperties, 1, "physicsPro", "PhysicsProperties", "Physics Setting for this Item.", SPhysicsProperties());
}
