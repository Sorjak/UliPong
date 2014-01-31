#pragma once

#include "Box2D/Box2D.h"
#include "basecomponent.h"
class PositionComponent :
	public BaseComponent
{
public:
	PositionComponent(float x, float y);
	b2Vec2* getPosition();
	void setPosition(float x, float y);
	void setPosition(b2Vec2* vec);

	b2Vec2* mPosition;
};

