/* Nicole Chu
 * 2290152
 * nichu@chapman.edu
 * 350-01
 * Assignment #4
 */

/*
 * This is the header file for my Window class. It contains a list of functions that will be defined in the class.
 */

#include <iostream>

using namespace std;

class Window
{
public:

  void meanIdleTime(Queue<int> qIdleTimes);
  void longestIdleTime(Queue<int> qIdleTimes);
  void numIdleFive(Queue<int> qIdleTimes);
};
