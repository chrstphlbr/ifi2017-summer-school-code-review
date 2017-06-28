// Copyright 2017 Stefano Pellegrini
//
// Tool to run simulations of vacuum cleaners.

#include <iostream>

#include "map.h"
#include "simulation.h"

using std::cout;
using std::endl;

int main() {
  const int x_size = 10;
  const int y_size = 20;
  Map map = Map::TwoRoomsMap(x_size, y_size);
  Simulation simulation(map);
  simulation.Run();
  cout << "Score: " << simulation.GetAgentScore() << endl;
  return 0;
}

// TODO(peste)
// - add display N-steps, follow wall, find charging station, maps with doors
