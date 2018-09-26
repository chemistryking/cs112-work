/* LinkedQueue.cpp defines the methods for class LinkedQueue.
 * Joel Adams, for CS 112 at Calvin College.
 * Student name: Matthew Nykamp
 * Date: 11-15-16
 */

#include "LinkedQueue.h"

LinkedQueue::LinkedQueue() {
	mySize = 0;
	myFirst = NULL;
	myLast = NULL;
}


//If the queue is not empty, removes the first item (the oldest) from the queue,
//Decrementing the size,
//otherwise throws an EmptyQueueException
Item LinkedQueue::remove() {
	if(isEmpty()) {
		throw EmptyQueueException("remove()");
	} else {
		Item temp = myFirst->myItem;
		Node * tempPtr = myFirst;
		myFirst = myFirst->myNext;
		tempPtr->myNext = NULL;
		delete tempPtr;
		mySize--;
		return temp;
	}
}

//Returns the first item in the queue
Item LinkedQueue::getFirst() const {
	if (isEmpty()) {
		throw EmptyQueueException("getFirst()");
	} else {
		return myFirst->myItem;
	}
}

//Returns the last item in the queue
Item LinkedQueue::getLast() const {
	if (isEmpty()) {
		throw EmptyQueueException("getLast()");
	} else {
		return myLast->myItem;
	}
}

//Appends a new item to the end of the queue,
//incrementing the size
void LinkedQueue::append(Item add) {
	if (isEmpty()) {
		myFirst = myLast = new Node(add, NULL);
		mySize++;
	} else {
		myLast->myNext = new Node(add, NULL);
		myLast = myLast->myNext;
		mySize++;
	}
}

LinkedQueue::LinkedQueue(const LinkedQueue& original) {
	makeCopyOf(original);
}

void LinkedQueue::makeCopyOf(const LinkedQueue& original) {
	mySize = original.mySize;
	if ( mySize == 0 ) {
		myFirst = myLast = NULL;
	} else {
		myFirst = new Node(original.getFirst(), NULL);
		Node * temp0 = original.myFirst->myNext;
		Node * temp1 = myFirst;
		while (temp0 != NULL) {
			temp1->myNext = new Node(temp0->myItem, NULL);
			temp1 = temp1->myNext;
			temp0 = temp0->myNext;
		}
		myLast = temp1;
	}
}

LinkedQueue::~LinkedQueue() {
	delete myFirst;
	myFirst = myLast = NULL;
	mySize = 0;
}

LinkedQueue& LinkedQueue::operator=(const LinkedQueue& aQueue) {
	if (this != &aQueue) {
		delete myFirst;    // invokes recursive ~Node()
		makeCopyOf(aQueue);
	}
	return *this;
}

