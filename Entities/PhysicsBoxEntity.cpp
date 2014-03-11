#include "PhysicsBoxEntity.h"


PhysicsBoxEntity::PhysicsBoxEntity(long id, b2World* world, b2Vec2 startpos, b2Vec2 dimensions) {
	mID = id;

	systemFlags.push_back("renders");
	systemFlags.push_back("physics");

	componentMap["physics"] = new PhysicsBoxComponent(world, startpos, dimensions, b2_dynamicBody);

	componentMap["render"] = new RenderComponent("media/circle.jpg", startpos.x, startpos.y, dimensions.x, dimensions.y);
}

