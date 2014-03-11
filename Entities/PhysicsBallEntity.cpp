#include "PhysicsBallEntity.h"


PhysicsBallEntity::PhysicsBallEntity(long id, b2World* world){
	mID = id;

	systemFlags.push_back("renders");
	systemFlags.push_back("physics");

	//componentMap["physics"] = new PhysicsBallComponent(world, startpos);

	//componentMap["render"] = new RenderComponent("media/circle.jpg", startpos.x, startpos.y, 50, 50);
}

