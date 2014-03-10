#include "PhysicsBoxEntity.h"


PhysicsBoxEntity::PhysicsBoxEntity(long id, b2World* world) {
	mID = id;

	systemFlags.push_back("renders");
	systemFlags.push_back("physics");

	b2Vec2 startpos(10, 10);
	componentMap["physics"] = new PhysicsBoxComponent(world, startpos);

	componentMap["render"] = new RenderComponent("media/circle.jpg", startpos.x, startpos.y, 50, 50);
}
