/* Nicole Chu
 * 2290152
 * nichu@chapman.edu
 * 350-01
 * Assignment #4
 */

/*
 * This is the main file which calls the Simulation, Student, and Window class functions.
   Here, I built 4 Queues that store integer values representing the times that students need
   at each window and also student wait times and window idle times. At the end of the file,
   I call the manual queue destructor for each of the queues I built.
 */

#include <iostream>
#include "Queue.h"
#include "Simulation.cpp"
#include "Window.cpp"
#include "Student.cpp"
#include "DoublyLinkedList.h"

using namespace std;

int main(int argc, char* argv[])
{
  string filePath;

  /*
   * Takes the user input file path from the command line and assigns it to a string variable.
     If no file path is provided on the command line, the user is prompted to enter one.
     If the user inputs more than one argument in the command line, then an error message displays.
   */
  switch(argc)
  {
    case 1:
      cout << "Please enter your file path: ";
      cin >> filePath;
      break;
    case 2:
      filePath = argv[1];
      break;
    default:
      cout << "ERROR: Please enter one file path." << endl;
      exit;
  }

  /*
   * Here, I declare variables that will be passed to the Simulation class in order to read the
     user's file.
   */
  int numWindows = -1;
  Queue<int> qStudents;
  Queue<int> qWindows;
  Queue<int> qWaitTimes;
  Queue<int> qIdleTimes;

  /*
   * After declaring a Simulation object, I call the readFile function to iterate through the
     user's input file. After building the appropriate queues of integers, I call the officeLine
     function to simulate the students moving out of line into the queue of windows.
   */
  Simulation sim;
  sim.readFile(filePath, qStudents, numWindows, qIdleTimes, qWaitTimes);
  sim.officeLine(qStudents, qWindows, numWindows);

  /*
   * I create a Student object to call the functions that will output the desired calculations
     on student wait times.
   */
  Student s;
  s.meanWaitTime(qWaitTimes);
  s.medianWaitTime(qWaitTimes);
  s.longestWaitTime(qWaitTimes);
  s.numWaitTen(qWaitTimes);

  /*
   * I create a Window object to call the functions that will output the desired calculations
     on window idle times.
   */
  Window w;
  w.meanIdleTime(qIdleTimes);
  w.longestIdleTime(qIdleTimes);
  w.numIdleFive(qIdleTimes);

  /*
   * I created manual destructors for my queues so I call them at the end of my program.
   */
  qStudents.destructQ();
  qWindows.destructQ();
  qIdleTimes.destructQ();
  qWaitTimes.destructQ();
}
