/* Nicole Chu
 * 2290152
 * nichu@chapman.edu
 * 350-01
 * Assignment #4
 */

/*
 * This is the Window class that contains functions that calculate and output the required values for the assignment.
 */

#include <iostream>
#include "Window.h"

using namespace std;

/*
 * meanIdleTime function
 * This function takes the queue of window idle times as a parameter and calculates the mean.
 */
void Window::meanIdleTime(Queue<int> qIdleTimes)
{
  Queue<int> queue = qIdleTimes;

  int sum = 0;
  int size = queue.size();

  while(!queue.isEmpty())
  {
    sum += queue.remove();
  }

  double mean = (double)sum/size;

  cout << "Mean window idle time: " << mean << endl;
}

/*
 * longestIdleTime funtion
 * This iterates through the queue of idle times to find the longest one.
 */
void Window::longestIdleTime(Queue<int> qIdleTimes)
{
  Queue<int> queue = qIdleTimes;

  int longest = -1;
  int temp;

  while(!queue.isEmpty())
  {
    temp = queue.remove();
    if(temp > longest)
      longest = temp;
  }

  cout << "Longest window idle time: " << longest << endl;
}

/*
 * numIdleFive funtion
 * This iterates through the queue of idle times to find the count of times that are more than 5 minutes.
 */
void Window::numIdleFive(Queue<int> qIdleTimes)
{
  Queue<int> queue = qIdleTimes;

  int temp;
  int count = 0;

  while(!queue.isEmpty())
  {
    temp = queue.remove();

    if(temp > 5)
      ++count;
  }

  cout << "# of windows idle for over 5 minutes: " << count << endl;
}
