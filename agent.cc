// Copyright 2017 Stefano Pellegrini

#include "agent.h"

#include "utils.h"

Agent::Agent(const Battery* battery, const int* time, const int x_size, const int y_size) :
  battery_(battery), time_(time) {
    this->x_size = x_size;
    this->y_size = y_size;
  }

Direction Agent::NextDirection(const Perception& p) {
  if (this->NeedToGoHome()) {
    return this->GoHomeDirection();
  } else {
    const float random = Random();
    Direction toGo;
    if (random < 0.2) {
      toGo = Direction::NONE;
    }
    if (random < 0.4) {
      toGo = Direction::LEFT;
    }
    if (random < 0.6) {
      toGo = Direction::UP;
    }
    if (random < 0.8) {
      toGo = Direction::DOWN;
    } else {
      toGo = Direction::RIGHT;
    }
    this->way.push_back(toGo);
    return toGo;
  }
}

Direction Agent::GoHomeDirection() {
  Direction d = this->way.back();
  this->way.pop_back();
  return d;
}

bool Agent::NeedToGoHome() {
  println()
  this->needToGoHome = this->way.size() >= *this->time_;
  return this->needToGoHome;
}

bool Agent::IsAlive() const {
  return battery_->Level() > 0;
}
