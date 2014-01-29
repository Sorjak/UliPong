#pragma once

#include "SFML/Graphics.hpp"
#include "basecomponent.h"


class RenderComponent :
	public BaseComponent
{
public:
	RenderComponent(sf::Drawable* drawObject);
	sf::Drawable* getDrawObject();
	void setDrawObject(sf::Drawable* drawObject);


	sf::Drawable* mDrawObject;
};

