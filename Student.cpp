#include <iostream>
#include <bits/stdc++.h>
#include "Student.h"

using namespace std;

/*
 * meanWaitTime funtion
 * This function takes the queue of student wait times as a parameter and calculates the mean.
 */
void Student::meanWaitTime(Queue<int> qWaitTimes)
{
  Queue<int> queue = qWaitTimes;

  int sum = 0;
  int size = queue.size();

  while(!queue.isEmpty())
  {
    sum += queue.remove();
  }

  double mean = (double)sum/size;

  cout << "Mean student wait time: " << mean << endl;
}

/*
 * medianWaitTime funtion
 * This puts my queue of wait times into an array to be sorted using the built in sort function.
   After the array is sorted, I find the median by returning the element in the middle of the array.
 * https://stackoverflow.com/questions/28023571/sorting-a-queue-c-c 
 */
void Student::medianWaitTime(Queue<int> qWaitTimes)
{
  Queue<int> queue = qWaitTimes;
  int size = queue.size();
  int arr[size];
  int x = 0;

  while(!queue.isEmpty())
  {
    arr[x] = queue.remove();
    x++;
  }

  sort(arr, arr + size);

  int mid = size/2;

  cout << "Median student wait time: " << arr[mid] << endl;
}

/*
 * longestWaitTime funtion
 * This iterates through the queue of wait times to find the longest one.
 */
void Student::longestWaitTime(Queue<int> qWaitTimes)
{
  Queue<int> queue = qWaitTimes;

  int longest = -1;
  int temp;

  while(!queue.isEmpty())
  {
    temp = queue.remove();
    if(temp > longest)
      longest = temp;
  }

  cout << "Longest student wait time: " << longest << endl;
}

/*
 * numWaitTen funtion
 * This iterates through the queue of wait times to find the count of times that are more than 10 minutes.
 */
void Student::numWaitTen(Queue<int> qWaitTimes)
{
  Queue<int> queue = qWaitTimes;

  int temp;
  int count = 0;

  while(!queue.isEmpty())
  {
    temp = queue.remove();

    if(temp > 10)
      count++;
  }

  cout << "# of students waiting for over 10 minutes: " << count << endl;
}
