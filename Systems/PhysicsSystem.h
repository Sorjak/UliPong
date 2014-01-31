#pragma once
#include "basesystem.h"
#include "Box2D/Box2D.h"

class PhysicsSystem :
	public BaseSystem
{
public:
	PhysicsSystem(b2World* world);
	~PhysicsSystem();


	b2World* mWorld;
	void update();
};

