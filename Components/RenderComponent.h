#pragma once

#include "SFML/Graphics.hpp"
#include "basecomponent.h"


class RenderComponent :
	public BaseComponent
{
public:
	RenderComponent(string filename, float x, float y, int w, int h);
	sf::Sprite* getDrawObject();

	sf::Sprite* mDrawObject;
};

