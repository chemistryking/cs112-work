/* ArrayQueue.cpp defines the methods for class ArrayQueue.
 * Joel Adams, for CS 112 at Calvin College.
 * Student name: Matthew Nykamp
 * Date: 11-15-16
 */

#include "ArrayQueue.h"
#include <cstring>      // memcpy()
using namespace std;

ArrayQueue::ArrayQueue(const ArrayQueue& original) {
	makeCopyOf(original);
}

//Initializes the ArrayQueue to a certain capacity,
//Allocating an array of Items to that size
//Throws an exception if the capacity is 0 or less
ArrayQueue::ArrayQueue(unsigned capacity) {
	if (capacity <= 0) {
		throw QueueException("ArrayQueue()", "Size cannot be zero");
	} else {
		myCapacity = capacity;
		myFirst = 0;
		myLast = 0;
		myArray = new Item[capacity];
		mySize = 0;
	}
}

//Returns the first item in the queue
//throwing an EmptyQueueException if it is empty
Item ArrayQueue::getFirst() const {
	if (isEmpty()) {
		throw EmptyQueueException("getFirst()");
	} else {
		return myArray[myFirst];
	}
}

//Returns the last item in the queue
//throwing an EmptyQueueException if it is empty
Item ArrayQueue::getLast() const {
	if (isEmpty()) {
		throw EmptyQueueException("getLast()");
	} else {
		return myArray[(myLast - 1 + myCapacity) % myCapacity];
	}
}

//If the queue is not full, appends an item to the end
//incrementing the size,
//otherwise throws a FullQueueException
void ArrayQueue::append(Item add) {
	if (isFull()) {
		throw FullQueueException("append()");
	} else {
		myArray[myLast] = add;
		myLast = (myLast + 1) % myCapacity;
		mySize++;
	}

}

//Removes the first item from the queue
//unless it is empty, when it throws an EmptyQueueException
Item ArrayQueue::remove() {
	if (isEmpty()) {
		throw EmptyQueueException("remove()");
	} else {
		Item temp = myArray[myFirst];
		myFirst = (myFirst + 1) % myCapacity;
		mySize--;
		return temp;
	}
}

void ArrayQueue::makeCopyOf(const ArrayQueue& original) {
	mySize = original.mySize;
	myCapacity = original.myCapacity;
	myFirst = original.myFirst;
	myLast = original.myLast;
	myArray = new Item[myCapacity];
	memcpy(myArray, original.myArray, myCapacity * sizeof(Item));
}

ArrayQueue::~ArrayQueue() {
	delete[] myArray;
	myArray = NULL;
	mySize = myFirst = myLast = 0;
}

ArrayQueue& ArrayQueue::operator=(const ArrayQueue& aQueue) {
	if (this != &aQueue) {
		delete[] myArray;
		makeCopyOf(aQueue);
	}
	return *this;
}

bool ArrayQueue::isEmpty() const {
	return mySize == 0;
}

bool ArrayQueue::isFull() const {
	return getSize() == myCapacity;
}

unsigned ArrayQueue::getCapacity() const {
	return myCapacity;
}

unsigned ArrayQueue::getSize() const {
	return mySize;
}

