#include "PhysicsBoxComponent.h"


PhysicsBoxComponent::PhysicsBoxComponent(b2World* world, b2Vec2 startpos, b2Vec2 dimensions, b2BodyType type) {
	b2BodyDef mBodyDef;
	mBodyDef.position = b2Vec2(startpos.x/30.f, startpos.y/30.f);
	mBodyDef.type = type;
	mBody = world->CreateBody(&mBodyDef);

	b2PolygonShape mShape;
	mShape.SetAsBox((dimensions.x/2)/30.f, (dimensions.y/2)/30.f);

	b2FixtureDef mFixtureDef;
	mFixtureDef.shape = &mShape; 
	mFixtureDef.friction = .5;
	mBody->CreateFixture(&mFixtureDef);
}