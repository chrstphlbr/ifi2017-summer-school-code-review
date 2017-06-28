#include "agent.h"

#include <cassert>

#include "battery.h"
#include "perception.h"
#include "tests.h"

const int x_size = 10;
const int y_size = 20;

TEST(Agent_IsAlive) {
  Battery battery(50);
  int time = 100;
  Agent agent(&battery, &time, x_size, y_size);
  assert(agent.IsAlive());

  for (int i = 0; i < 50; ++i) {
    battery.Use();
  }
  assert(!agent.IsAlive());
}

// This test check only that nothing crashes.
TEST(Agent_NextDirection) {
  Battery battery(50);
  int time = 100;
  Agent agent(&battery, &time, x_size, y_size);
  Perception p;
  agent.NextDirection(p);
}


