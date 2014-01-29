#pragma once

#include "../Vector2D.h"
#include "basecomponent.h"
class PositionComponent :
	public BaseComponent
{
public:
	PositionComponent(float x, float y);
	Vector2D* getPosition();
	void setPosition(float x, float y);
	void setPosition(Vector2D* vec);

	Vector2D* mPosition;
};

