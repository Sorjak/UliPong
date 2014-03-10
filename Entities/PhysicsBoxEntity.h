#pragma once
#include "baseentity.h"

#include "Box2D/Box2D.h"

#include "../Components/PhysicsBoxComponent.h"
#include "../Components/RenderComponent.h"

class PhysicsBoxEntity :
	public BaseEntity
{
public:
	PhysicsBoxEntity(long id, b2World* world);
};

