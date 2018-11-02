/* Nicole Chu
 * 2290152
 * nichu@chapman.edu
 * 350-01
 * Assignment #4
 */

/*
 * Simulation.cpp contains function definitions for the readFile and officeLine
   functions defined in the Simulation.h file.
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include "Simulation.h"
#include "Queue.h"

using namespace std;

/*
 * readFile function
 * This function iterates through the user's file path and builds the queues of students, windows, idle times, and wait times.
 */
void Simulation::readFile(string filePath, Queue<int> &qStudents, int &numWindows, Queue<int> &qIdleTimes, Queue<int> &qWaitTimes)
{
  ifstream inputFile;
  string line;
  int lineCount = 0;

  string windows;
  int clockTick = 0;
  string time;
  int numStudents = -1;
  int studentCount = 0;
  string students;
  string tempS;
  int tempI;

  int longestIdle = -1;
  int shortestWait = 100;
  int numIdle = 0;
  int numWait = 0;

  inputFile.open(filePath);

  /*
   * After opening the user's given file, a while loop is used to iterate through the file.
     lineCount keeps track of which line of the file the loop is on so that the correct variables are
     initialized.
   */
  while(getline(inputFile, line))
  {
    lineCount++;

    /*
     * If we're on the first line of the file, we want to initialize numWindows to the provided number
       of windows available.
     */
    if(lineCount == 1)
    {
      windows = line;
      stringstream w(windows);
      w >> numWindows;
    }
    else
    {
      /*
       * If we're not on the first line of the file, we go through the rest of the file and assign the
         appropriate variables.
       * If clockTick has not been initialized yet, we initialize it to the current line's value.
       */
      if(clockTick == 0)
      {
        time = line;
        stringstream t(time);
        t >> clockTick;
      }
      /*
       * If clockTick has been initialized but numStudents has not, we initialize numStudents to the
         number of students that arrive at the clock tick.
       */
      else if(numStudents == -1 && clockTick != 0)
      {
        students = line;
        stringstream s(students);
        s >> numStudents;
      }
      /*
       * If numStudents is greater than zero, we add student's required window times to the student queue.
         We subtract one from numStudents so that we can get the correct number of students into the queue
         as we continue to iterate through the file.
       * We also keep track of the longest and shortest student window times to be able to keep track of
         student wait times and window idle times.
       */
      else if(numStudents > 0)
      {
        tempS = line;
        stringstream x(tempS);
        x >> tempI;

        qStudents.insert(tempI);

        if(tempI > longestIdle)
          longestIdle = tempI;
        if(tempI < shortestWait)
          shortestWait = tempI;

        studentCount++;
        numStudents--;
      }
      else
      {
        /*
         * If we've reached the end of the clock tick and we have no more student times to insert into our queue,
           we use the longest & shortest student window times to build our queues for student wait times and
           window idle times.
         */
        if(numWindows > studentCount)
        {
          numIdle = numWindows - studentCount;
          for(int i = 0; i < numIdle; i++)
          {
            qIdleTimes.insert(longestIdle);
          }
        }
        if(numWindows < studentCount)
        {
          numWait = studentCount - numWindows;
          for(int i = 0; i < numWait; i++)
          {
            qWaitTimes.insert(shortestWait);
          }
        }

        /*
         * We then reset variable values for the next clock tick.
         */
        numStudents = -1;
        studentCount = 0;
        longestIdle = -1;

        time = line;
        stringstream t(time);
        t >> clockTick;
      }
    }
  }

  /*
   * In case there's another set of idle windows/waiting students that aren't picked up in our iteration of the file
     because the file ends and never reaches our else statement, a copy of our above if statement is placed outside of the loop.
   */
  if(numWindows > studentCount)
  {
    numIdle = numWindows - studentCount;
    for(int i = 0; i < numIdle; i++)
    {
      qIdleTimes.insert(longestIdle);
    }
  }
  if(numWindows < studentCount)
  {
    numWait = studentCount - numWindows;
    for(int i = 0; i < numWait; i++)
    {
      qWaitTimes.insert(shortestWait);
    }
  }
}

/*
 * officeLine function
 * This simulates the office line by moving students from their queue into the queue of windows.
 */
void Simulation::officeLine(Queue<int> &qStudents, Queue<int> &qWindows, int numWindows)
{
  bool cont = true;

  while(cont)
  {
    int temp = qStudents.remove();

    qWindows.insert(temp);

    if(qStudents.isEmpty() || qWindows.size() == numWindows)
    {
      cont = false;
    }
  }
}
