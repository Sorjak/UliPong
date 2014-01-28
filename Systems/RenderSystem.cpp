#include "RenderSystem.h"

RenderSystem::RenderSystem(int width, int height, const char* title)
{
	mWidth  = width;
	mHeight = height;
	mWindow.create(sf::VideoMode(width, height), title);

	mClock = new sf::Clock();
	mFont.loadFromFile("media/SourceSansPro-Regular.ttf");

	fpsTimer = mClock.getElapsedTime().asMilliseconds();
	framesElapsed = 0;
	currentFPS = 60;
}


RenderSystem::~RenderSystem() {}

void RenderSystem::update() {
	frameStartTime = mClock.getElapsedTime().asMilliseconds();
    sf::CircleShape shape(100.f);
    shape.setFillColor(sf::Color::Green);
	shape.setPosition(100, 100);
    mWindow.clear();
    mWindow.draw(shape);
    

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


