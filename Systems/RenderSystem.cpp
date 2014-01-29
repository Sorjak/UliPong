#include "RenderSystem.h"

RenderSystem::RenderSystem(int width, int height, const char* title)
{
	mWidth  = width;
	mHeight = height;
	mWindow.create(sf::VideoMode(width, height), title);

	mFont.loadFromFile("media/SourceSansPro-Regular.ttf");

	fpsTimer = mClock.getElapsedTime().asMilliseconds();
	framesElapsed = 0;
	currentFPS = 60;
}

RenderSystem::~RenderSystem() {}

void RenderSystem::update() {
	frameStartTime = mClock.getElapsedTime().asMilliseconds();
	mWindow.clear();

	for (size_t i = 0; i < entityList.size(); i++) {
		BaseEntity* current = entityList[i];
		PositionComponent* pos = (PositionComponent*) current->getComponent("position");
		RenderComponent* ren = (RenderComponent*) current->getComponent("render");

		sf::Drawable* todraw = ren->getDrawObject();
		
		mWindow.draw(*todraw);
	}

    
    
	if (frameStartTime - fpsTimer >= 1000) {
		currentFPS = framesElapsed;
		framesElapsed = 0;
		fpsTimer = mClock.getElapsedTime().asMilliseconds();
	} else {
		framesElapsed++;
	}

	string fpsString = "FPS: ";
	fpsString += to_string(getCurrentFPS());
	sf::Text fpstext (fpsString, mFont);
	mWindow.draw(fpstext);

	mWindow.display();

	frameEndTime = mClock.getElapsedTime().asMilliseconds();
}

int RenderSystem::getCurrentFPS() {
	return currentFPS;
}


