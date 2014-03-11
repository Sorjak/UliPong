#pragma once

#include "baseentity.h"

#include "Box2d/Box2d.h"

#include "../Components/PhysicsBoxComponent.h"
#include "../Components/RenderComponent.h"

class PhysicsWallEntity :
	public BaseEntity
{
public:
	PhysicsWallEntity(long id, b2World* world, b2Vec2 startpos, b2Vec2 dimensions);
};

