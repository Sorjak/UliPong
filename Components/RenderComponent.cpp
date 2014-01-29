#include "RenderComponent.h"

RenderComponent::RenderComponent(sf::Drawable* drawObject){
	mDrawObject = drawObject;
}

sf::Drawable* RenderComponent::getDrawObject() {
	return mDrawObject;
}

void RenderComponent::setDrawObject(sf::Drawable* drawObject) {
	mDrawObject = drawObject;
}
