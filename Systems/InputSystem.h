#pragma once


#include "BaseSystem.h"
#include "SFML/System.hpp"
#include "SFML/Graphics.hpp"


class InputSystem :
	public BaseSystem
{
public:
	InputSystem(sf::RenderWindow* window);

	void update();

	sf::RenderWindow* mWindow;

};

