#include "RenderComponent.h"

RenderComponent::RenderComponent(string filename, float x, float y, int w, int h){
	sf::Texture tex;
	tex.loadFromFile(filename);

	mDrawObject = new sf::Sprite(tex);
	mDrawObject->setPosition(x, y);
	mDrawObject->setTextureRect(sf::IntRect(x, y, w, h));
}

sf::Sprite* RenderComponent::getDrawObject() {
	return mDrawObject;
}
