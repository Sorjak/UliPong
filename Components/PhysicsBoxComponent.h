#pragma once
#include "basecomponent.h"

#include "Box2D/Box2D.h"

class PhysicsBoxComponent :
	public BaseComponent
{
public:
	PhysicsBoxComponent(b2World* world, b2Vec2 startpos);

	b2Body* mBody;
};

