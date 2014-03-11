#include "PhysicsWallEntity.h"


PhysicsWallEntity::PhysicsWallEntity(long id, b2World* world, b2Vec2 startpos, b2Vec2 dimensions) {
	mID = id;

	systemFlags.push_back("physics");
	systemFlags.push_back("renders");


	componentMap["physics"] = new PhysicsBoxComponent(world, startpos, dimensions, b2_staticBody);


	componentMap["render"] = new RenderComponent("media/wall.png", startpos.x, startpos.y, dimensions.x, dimensions.y);
}

