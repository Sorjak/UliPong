#include "Engine.h"

Engine::Engine() {
	b2Vec2 Gravity(0.f, 9.8f);
	mWorld = new b2World(Gravity);
	mWorld->SetContinuousPhysics(true);

	mWindow.create(sf::VideoMode(SCREEN_WIDTH, SCREEN_HEIGHT), "UliPong");
	mWindow.setFramerateLimit(60);

	initGame();
	initSystems();
	initEntities();
}

Engine::~Engine() {
	//for (map<string, BaseSystem*>::iterator it = systemList.begin(); it != systemList.end(); ++it) {
	//	delete it->second;
	//}

	//for (size_t i = 0; i < entityList.size(); i++) {
	//	delete entityList[i];
	//}
	delete mWorld;
}

void Engine::startGame() {
	running = true;
	
	while (running) {
		// Now let's iterate through the systems map and update everyone
		for(vector<pair<string,BaseSystem*>>::iterator it = systemList.begin(); it != systemList.end(); ++it) {
			it->second->update();
		}

		// Add any newly created entities to their proper systems
		addEntitiesToSystems();
	}
	endGame();
}

void Engine::setRunning(bool set) {
	running = set;
}

void Engine::endGame() {
}

void Engine::initGame() {
	lastID = 0;
}

void Engine::initSystems() {
	BaseSystem* input = new RenderSystem(&mWindow);
	input->init(this);
	systemList.push_back(make_pair("input", input));

	BaseSystem* physics = new PhysicsSystem(mWorld);
	physics->init(this);
	systemList.push_back(make_pair("physics", physics));

	BaseSystem* render = new RenderSystem(&mWindow);
	render->init(this);
	systemList.push_back(make_pair("renders", render));
}

void Engine::initEntities() {
	for (int i = 0; i < SCREEN_WIDTH / 200; i++) {
		b2Vec2 box_start(200*i, 10);
		b2Vec2 box_dims(50, 50);

		BaseEntity* physics_box = new PhysicsBoxEntity(getNextId(), mWorld, box_start, box_dims);
		addEntity(physics_box);
	}

	b2Vec2 wall_start(0, SCREEN_HEIGHT - 20);
	b2Vec2 wall_dims(SCREEN_WIDTH, 20);

	BaseEntity* physics_wall = new PhysicsWallEntity(getNextId(), mWorld, wall_start, wall_dims);
	addEntity(physics_wall);


}

void Engine::addEntitiesToSystems() {
	for(size_t i = 0; i < toadd.size(); i++) {
		vector<string> entitySystems = toadd[i]->systemFlags; // All of the system flags for the entity we want to add
		for (size_t j = 0; j < entitySystems.size(); j++) {
			string systemString = entitySystems[j]; // The current system flag we are trying to match
			for (size_t k = 0; k < systemList.size(); k++) {
				if (systemList[k].first == systemString) { // We've found a system that matches the system flag. 
					systemList[k].second->registerEntity(toadd[i]); // Add entity (toadd[i]) to the system.
				}
			}
		}
	}
	toadd.clear(); // Added all entities, clear the queue.
}

void Engine::addEntity(BaseEntity* e) {
	toadd.push_back(e); // 0 means not yet added to proper systems
	entityList.push_back(e);
}

void Engine::removeEntity(BaseEntity* e) {
	int pos = -1;
	for (size_t i = 0; i < entityList.size(); i++) {
		if (entityList[i] == e)
			pos = i;
	}

	if (pos >= 0) {
		vector<BaseEntity*>::iterator it = entityList.begin()+pos;
		entityList.erase(it);

		for(vector<pair<string,BaseSystem*>>::iterator itx = systemList.begin(); itx != systemList.end(); ++itx) {
			itx->second->removeEntity(e);
		}
		delete e;
	}

}

long Engine::getNextId() {
	return lastID++;
}

float Engine::getFPS() {
	//RenderSystem rs = (RenderSystem)systemList["render"];
	//return rs.getCurrentFPS();
	return 60;
}
