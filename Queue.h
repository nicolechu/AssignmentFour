/* Nicole Chu
 * 2290152
 * nichu@chapman.edu
 * 350-01
 * Assignment #4
 */

/*
 * This is my Doubly-Linked List based Queue template class. It contains functions to insert & remove elements,
   peek at the element at the front of the queue, return if the queue is empty, print the size of the queue, and
   print the queue. I also created a destructor that has to be called manually.
 */

#ifndef QUEUE_H
#define QUEUE_H

#include <iostream>
#include "DoublyLinkedList.h"

using namespace std;

template <class T>
class Queue
{
public:
  Queue();
  Queue(int maxSize);

  void insert(T data);
  T remove();
  T peek();
  bool isEmpty();
  int size();
  void print();

  void destructQ();

private:
  unsigned int numElements;
  DoublyLinkedList<T> myQueue;
};

/*
 * The default constructor sets the number of elements in the queue to zero.
 */
template <class T>
Queue<T>::Queue()
{
  numElements = 0;
}

/*
 * destructQ function
 * The manual destructor function calls the manual destruct function from the DoublyLinkedList class.
 */
template <class T>
void Queue<T>::destructQ()
{
  myQueue.destruct();
}

/*
 * insert function
 * This function calls the DoublyLinkedList function insertBack to insert an element at the end of the queue.
 * numElements is then set to the size of the doubly linked list.
 */
template <class T>
void Queue<T>::insert(T data)
{
  myQueue.insertBack(data);
  numElements = myQueue.getSize();
}

/*
 * remove function
 * This function calls the DoublyLinkedList function removeFront to remove and return the element at the front of the queue.
 * numElements is then set to the size of the doubly linked list.
 */
template <class T>
T Queue<T>::remove()
{
  T temp = myQueue.removeFront();
  numElements = myQueue.getSize();
  return temp;
}

/*
 * peek function
 * This function returns the element at the front of the queue by calling the getFront function from the DoublyLinkedList class.
 */
template <class T>
T Queue<T>::peek()
{
  return myQueue.getFront();
}

/*
 * isEmpty function
 * This function returns true if there are no elements in the queue.
 */
template <class T>
bool Queue<T>::isEmpty()
{
  return (numElements == 0);
}

/*
 * size function
 * The size function returns the number of elements in the queue.
 */
template <class T>
int Queue<T>::size()
{
  return numElements;
}

/*
 * print function
 * The print function calls the printList function from the DoublyLinkedList class to output the entire queue.
 */
template <class T>
void Queue<T>::print()
{
  myQueue.printList();
}

#endif
