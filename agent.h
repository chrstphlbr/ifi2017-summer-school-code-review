#ifndef AGENT_H_
#define AGENT_H_

#include "battery.h"
#include "geometry.h"
#include "map.h"
#include "perception.h"
#include <vector>

// Models a vacuum cleaner.
class Agent {
 public:
  // Constructs an agent with a |battery| and a |time| that are read
  // only. Both arguments should outlive the agent.
  Agent(const Battery* battery, const int* time, const int x_size, const int y_size);

  // Get the next direction of the agent based on the current perception |p|.
  Direction NextDirection(const Perception& p);

  // Whether the agent has still some battery left.
  bool IsAlive() const;

  int x_size;
  int y_size;

 private:
  // Not owned by the agent.
  const Battery* battery_;
  // Not owned by the agent.
  const int* time_;

  // way to charger
  std::vector<Direction> way;

  // need to go home?
  bool needToGoHome = false;

  // methods
  bool NeedToGoHome();
  Direction GoHomeDirection();

};

#endif  // AGENT_H_
