#include "BallEntity.h"


BallEntity::BallEntity(long id){
	mID = id;

	systemFlags.push_back("renders");
	systemFlags.push_back("collides");

}