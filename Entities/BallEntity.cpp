#include "BallEntity.h"


BallEntity::BallEntity(long id){
	mID = id;

	systemFlags.push_back("renders");
	//systemFlags.push_back("collides");

	componentMap["position"] = new PositionComponent(100.f, 100.f);

	sf::CircleShape* shape = new sf::CircleShape(20.f);
    shape->setFillColor(sf::Color::Green);
	shape->setPosition(100.f, 100.f);
	componentMap["render"] = new RenderComponent(shape);
}