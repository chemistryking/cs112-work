/* ArrayQueue.h declares a Queue class using a dynamic array.
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 * Student name: Matthew Nykamp
 * Date: 11-15-16
 * 
 * Class Invariant: 
 *    mySize == 0 ||
 *    mySize > 0 && myArray[myFirst] == getFirst()
 *               && myArray[myLast-1] == getLast().
 * 
 *  (When I am not empty:
 *     myFirst is the index of my oldest value;
 *     myLast is the index of the spot where the next
 *       item to be appended will be placed.)      
 */

#ifndef ARRAY_QUEUE_H_
#define ARRAY_QUEUE_H_

#include "QueueException.h"
#include <cstring>
using namespace std;

template<class Item>
class ArrayQueue {
public:

	ArrayQueue(const ArrayQueue& original);
	virtual ~ArrayQueue();
	ArrayQueue& operator=(const ArrayQueue& original);
	unsigned getSize() const;
	unsigned getCapacity() const;
	bool isEmpty() const;
	bool isFull() const;
	ArrayQueue(unsigned);
	Item getFirst() const;
	Item getLast() const;
	void append(Item);
	Item remove();
	void setCapacity(unsigned);
protected:
	virtual void makeCopyOf(const ArrayQueue& original);
private:
	unsigned mySize;       // number of items I contain
	unsigned myCapacity;   // how many items I can store
	unsigned myFirst;      // index of oldest item (if any)
	unsigned myLast;       // index of next available spot for append (if any)
	Item* myArray;      // dynamic array of items

	friend class ArrayQueueTester;
};

template<class Item>
ArrayQueue<Item>::ArrayQueue(const ArrayQueue<Item>& original) {
	makeCopyOf(original);
}

template<class Item>
void ArrayQueue<Item>::setCapacity(unsigned newCapacity) {
	if (newCapacity <= 0 || newCapacity < getSize()) {
		throw QueueException("setCapacity()",
				"Cannot set capacity to be zero or smaller than current capacity");
	} else {

		Item * tempArray = new Item[newCapacity];

		for(unsigned i = 0; i < mySize; i++) {
			tempArray[i] = myArray[(i+myFirst) % myCapacity];
		}

		myFirst = 0;
		myLast = mySize;

		delete[] myArray;
		myArray = tempArray;
		myCapacity = newCapacity;
	}
}

//Initializes the ArrayQueue to a certain capacity,
//Allocating an array of Items to that size
//Throws an exception if the capacity is 0 or less
template<class Item>
ArrayQueue<Item>::ArrayQueue(unsigned capacity) {
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
template<class Item>
Item ArrayQueue<Item>::getFirst() const {
	if (isEmpty()) {
		throw EmptyQueueException("getFirst()");
	} else {
		return myArray[myFirst];
	}
}

//Returns the last item in the queue
//throwing an EmptyQueueException if it is empty
template<class Item>
Item ArrayQueue<Item>::getLast() const {
	if (isEmpty()) {
		throw EmptyQueueException("getLast()");
	} else {
		return myArray[(myCapacity + myLast - 1) % myCapacity];
	}
}

//If the queue is not full, appends an item to the end
//incrementing the size,
//otherwise throws a FullQueueException
template<class Item>
void ArrayQueue<Item>::append(Item add) {
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
template<class Item>
Item ArrayQueue<Item>::remove() {
	if (isEmpty()) {
		throw EmptyQueueException("remove()");
	} else {
		Item temp = myArray[myFirst];
		myFirst = (myFirst + 1) % myCapacity;
		mySize--;
		return temp;
	}
}

template<class Item>
void ArrayQueue<Item>::makeCopyOf(const ArrayQueue<Item>& original) {
	mySize = original.mySize;
	myCapacity = original.myCapacity;
	myFirst = original.myFirst;
	myLast = original.myLast;
	myArray = new Item[myCapacity];
	memcpy(myArray, original.myArray, myCapacity * sizeof(Item));
}

template<class Item>
ArrayQueue<Item>::~ArrayQueue() {
	delete[] myArray;
	myArray = NULL;
	mySize = myFirst = myLast = 0;
}

template<class Item>
ArrayQueue<Item>& ArrayQueue<Item>::operator=(const ArrayQueue<Item>& aQueue) {
	if (this != &aQueue) {
		delete[] myArray;
		makeCopyOf(aQueue);
	}
	return *this;
}

template<class Item>
bool ArrayQueue<Item>::isEmpty() const {
	return mySize == 0;
}

template<class Item>
bool ArrayQueue<Item>::isFull() const {
	return getSize() == myCapacity;
}

template<class Item>
unsigned ArrayQueue<Item>::getCapacity() const {
	return myCapacity;
}

template<class Item>
unsigned ArrayQueue<Item>::getSize() const {
	return mySize;
}

#endif /*ARRAY_QUEUE_H_*/
