#include "RenderComponent.h"

RenderComponent::RenderComponent(string filename, float x, float y, int w, int h){
	sf::Texture tex;
	tex.loadFromFile(filename);

	mDrawObject = new sf::Sprite(tex);
	mDrawObject->setPosition(x, y);
	mDrawObject->setScale(.1f, .1f);
}

sf::Sprite* RenderComponent::getDrawObject() {
	return mDrawObject;
}
