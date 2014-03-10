#include "PhysicsBoxComponent.h"


PhysicsBoxComponent::PhysicsBoxComponent(b2World* world, b2Vec2 startpos) {
	b2BodyDef mBodyDef;
	mBodyDef.position = b2Vec2(startpos.x/30.f, startpos.y/30.f);
	mBodyDef.type = b2_dynamicBody;
	mBody = world->CreateBody(&mBodyDef);

	b2PolygonShape mShape;
	mShape.SetAsBox((32.f/2)/30.f, (32.f/2)/30.f);

	b2FixtureDef mFixtureDef;
	mFixtureDef.shape = &mShape; 
	mBody->CreateFixture(&mFixtureDef);
}