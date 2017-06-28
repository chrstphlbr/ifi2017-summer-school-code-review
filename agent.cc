// Copyright 2017 Stefano Pellegrini

#include "agent.h"
#include "utils.h"

#include <cstdlib>
#include <ctime>

#include <iostream>
using namespace std;

Agent::Agent(const Battery* battery, const int* time) :
				  battery_(battery), time_(time) {}

Direction avail_directions[] = {Direction::RIGHT,Direction::UP,Direction::DOWN,Direction::LEFT};

Direction Agent::NextDirection(const Perception& p) {

	//generate a random int between 0 and 2
	int userBeg = 0;
	int userEnd = 2;
	int rand_int =  rand()%((userEnd - userBeg) + 1) + userBeg;

	//FIRST STATEGY (very stupid): Look at the obstacle's direction, then choose randomly one of
	//the other directions

	// message for the reviewer: sorry for the duplicate code, I need to
	// refresh my c++ basics... out of scope now :)
	if(p.HasObstacle(Direction::LEFT)){
		//pick randomly one of the other directions
		Direction directions [] = {Direction::RIGHT,Direction::UP,Direction::DOWN};
		return directions[rand_int];
	}

	if(p.HasObstacle(Direction::RIGHT)){
		//pick randomly one of the other directions
		Direction directions [] = {Direction::LEFT,Direction::UP,Direction::DOWN};
		return directions[rand_int];
	}

	if(p.HasObstacle(Direction::UP)){
		//pick randomly one of the other directions
		Direction directions [] = {Direction::RIGHT,Direction::LEFT,Direction::DOWN};
		return directions[rand_int];
	}

	if(p.HasObstacle(Direction::DOWN)){
		//pick randomly one of the other directions
		Direction directions [] = {Direction::RIGHT,Direction::UP,Direction::LEFT};
		return directions[rand_int];
	}

	// SECOND STRATEGY (previous one): completely random
	const float random = Random();
	if (random < 0.2) {
		return Direction::NONE;
	}
	if (random < 0.4) {
		return Direction::LEFT;
	}
	if (random < 0.6) {
		return Direction::UP;
	}
	if (random < 0.8) {
		return Direction::DOWN;
	}
	return Direction::RIGHT;

}

/*
Direction Agent::GetRightDirection(Direction direction){
	// generate random number between 0 and 2
	int userBeg = 0;
	int userEnd = 2;
	int rand_int =  rand()%((userEnd - userBeg) + 1) + userBeg;

	Direction directions [2];

	for(int i = 0; i < 3; i++){
		if(avail_directions[i] == direction)

	}

}*/

bool Agent::IsAlive() const {
	return battery_->Level() > 0;
}
