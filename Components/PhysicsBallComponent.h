#pragma once

#include "Box2D/Box2D.h"
#include "basecomponent.h"


class PhysicsBallComponent :
	public BaseComponent
{
public:
	PhysicsBallComponent(b2World* world, b2Vec2 startpos);

	b2Body* mBody;
};

