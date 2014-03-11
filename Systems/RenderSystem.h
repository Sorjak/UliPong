#pragma once
#include <string>

#include "SFML/Graphics.hpp"

#include "BaseSystem.h"

#include "../Components/RenderComponent.h"
#include "../Components/PhysicsBoxComponent.h"

class RenderSystem : public BaseSystem
{
public:
	RenderSystem(sf::RenderWindow* window);
	~RenderSystem();

	sf::RenderWindow* mWindow;
	sf::Clock mClock;

	sf::Font mFont;

	void update();
	int getCurrentFPS();
	

private:
	int currentFPS;
	int frameStartTime;
	int frameEndTime;
	int fpsTimer;
	int framesElapsed;
	int mWidth;
	int mHeight;
};

