#include "PositionComponent.h"


PositionComponent::PositionComponent(float x, float y){
	mPosition = new Vector2D(x, y);
}

Vector2D* PositionComponent::getPosition() {
	return mPosition;
}

void PositionComponent::setPosition(float x, float y) {
	mPosition = new Vector2D(x, y);
}

void PositionComponent::setPosition(Vector2D* vec) {
	mPosition = vec;
}

