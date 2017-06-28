// Copyright 2017 Stefano Pellegrini

#include "agent.h"

#include "utils.h"
#include <list>
#include <random>

Agent::Agent(const Battery* battery, const int* time) :
  battery_(battery), time_(time) {}

Direction Agent::SmartDirection(const Perception& p) {
    std::vector<Direction> directions = {};
    if (p.HasObstacle(Direction::UP))
        directions.push_back(Direction::UP);
    if (p.HasObstacle(Direction::LEFT))
        directions.push_back(Direction::LEFT);
    if (p.HasObstacle(Direction::RIGHT))
        directions.push_back(Direction::RIGHT);
    if (p.HasObstacle(Direction::DOWN))
        directions.push_back(Direction::RIGHT);

    std::random_device random_device;
    std::mt19937 engine{random_device()};
    std::uniform_int_distribution<int > dist(0, directions.size() - 1);

    int random_element = (int)directions[dist(engine)];
    return directions[random_element];
}


Direction Agent::NextDirection(const Perception& p) {
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

bool Agent::IsAlive() const {
  return battery_->Level() > 0;
}
