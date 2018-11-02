/* Nicole Chu
 * 2290152
 * nichu@chapman.edu
 * 350-01
 * Assignment #4
 */

/*
 * This is the header file for my Student class. It contains a list of functions that will be defined in the class.
 */

#include <iostream>

using namespace std;

class Student
{
public:
  void meanWaitTime(Queue<int> qWaitTimes);
  void medianWaitTime(Queue<int> qWaitTimes);
  void longestWaitTime(Queue<int> qWaitTimes);
  void numWaitTen(Queue<int> qWaitTimes);


};
