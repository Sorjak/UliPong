#pragma once
#include "baseentity.h"

#include "../Components/PositionComponent.h"
#include "../Components/RenderComponent.h"
#include "../Components/VelocityComponent.h"


class BallEntity :
	public BaseEntity
{
public:
	BallEntity(long id);
};

