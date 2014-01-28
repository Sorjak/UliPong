#include "Engine.h"

Engine::Engine() {
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

}

void Engine::startGame() {
	running = true;
	
	while (running) {
		// Now let's iterate through the systems map and update everyone
		for(map<string,BaseSystem*>::iterator it = systemList.begin(); it != systemList.end(); ++it) {
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
	BaseSystem *render = new RenderSystem(SCREEN_WIDTH, SCREEN_HEIGHT, "UliPong");
	render->init(this);
	systemList["renders"] = render;
}

void Engine::initEntities() {

}

void Engine::addEntitiesToSystems() {
	for(size_t i = 0; i < toadd.size(); i++) {
		vector<string> entitySystems = toadd[i]->systemFlags;
		for (size_t j = 0; j < entitySystems.size(); j++) {
			systemList[entitySystems[j]]->registerEntity(toadd[i]);
		}
	}
	toadd.clear();
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

		for(map<string,BaseSystem*>::iterator itx = systemList.begin(); itx != systemList.end(); ++itx) {
			itx->second->removeEntity(e);
		}
		delete e;
	}

}

long Engine::getNextId() {
	return lastID++;
}

float Engine::getFPS() {
	RenderSystem* rs = (RenderSystem*)systemList["render"];
	return rs->getCurrentFPS();
}