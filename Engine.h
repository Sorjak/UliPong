#pragma once

#define SCREEN_WIDTH 1280
#define SCREEN_HEIGHT 720

#include <vector>
#include <map>

#include "SFML/System.hpp"
#include "Box2D/Box2D.h"

#include "Components/BaseComponent.h"
#include "Entities/BaseEntity.h"
#include "Systems/BaseSystem.h"

#include "Systems/RenderSystem.h"
#include "Systems/PhysicsSystem.h"

#include "Entities/PhysicsBallEntity.h"


using namespace std;

class Engine
{
public:
	Engine();
	~Engine();

	void startGame();
	void setRunning(bool);
	void endGame();
	void addEntity(BaseEntity*);
	void removeEntity(BaseEntity*);
	long getNextId();
	float getFPS();

private:
	void initGame();
	void initSystems();
	void initEntities();
	void addEntitiesToSystems();

	int running;
	int lastID;
	b2World* mWorld;
	map<string, BaseSystem*> systemList;
	vector<BaseEntity*> entityList;
	vector<BaseEntity*> toadd;
};

