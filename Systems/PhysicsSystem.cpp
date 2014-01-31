#include "PhysicsSystem.h"


PhysicsSystem::PhysicsSystem(b2World* world) {
	mWorld = world;

}

PhysicsSystem::~PhysicsSystem() {
	delete mWorld;
}

void PhysicsSystem::update() {
	mWorld->Step(1/60.f, 8, 3);
	printf("Bodies: %d\n", mWorld->GetBodyCount());
}