#include "PhysicsBallComponent.h"


PhysicsBallComponent::PhysicsBallComponent(b2World* world, b2Vec2 startpos, b2BodyType type) {
	b2BodyDef mBodyDef;
	mBodyDef.position = startpos;
	mBodyDef.type = type;
	mBody = world->CreateBody(&mBodyDef);

	b2CircleShape mShape;
	mShape.m_p.Set(0, 0);
	mShape.m_radius = 3;

	b2FixtureDef mFixtureDef;
	mFixtureDef.shape = &mShape; 
	mBody->CreateFixture(&mFixtureDef);
}
