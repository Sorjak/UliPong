#pragma once
#include "baseentity.h"
#include "Box2D/Box2D.h"

#include "../Components/PhysicsBallComponent.h"
#include "../Components/RenderComponent.h"

class PhysicsBallEntity :
	public BaseEntity
{
public:
	PhysicsBallEntity(long id, b2World* world);


};

