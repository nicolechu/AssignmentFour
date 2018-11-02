/* Nicole Chu
 * 2290152
 * nichu@chapman.edu
 * 350-01
 * Assignment #4
 */

/*
 * This is the header file for my Simulation class. It contains a list of functions that will be defined in the class.
 */

#ifndef SIMULATION_H
#define SIMULATION_H
#include <iostream>
#include "Queue.h"

using namespace std;

class Simulation
{
public:
  void readFile(string filePath, Queue<int> &qStudents, int &numWindows, Queue<int> &qIdleTimes, Queue<int> &qWaitTimes);
  void officeLine(Queue<int> &qStudents, Queue<int> &qWindows, int numWindows);
};

#endif
