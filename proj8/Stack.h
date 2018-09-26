/* Stack.h provides a (dynamic-array-based) Stack class.
 * Joel Adams, for CS 112 at Calvin College.
 * Student Name: Matthew Nykamp
 * Date: 11-01-16
 * 
 * Invariant: myTop == 0 && isEmpty() && !isFull()
 *         || myTop == myCapacity && !isEmpty() && isFull()
 *         || myTop > 0 && myTop < myCapacity && !isEmpty() && !isFull().
 * Notes: 
 * 1. Member myTop always contains the index of the next empty space in myArray
 *        (the index of the array element into which the next pushed item will be placed).
 * 2. Sending push() to a full Stack throws the exception Stack::Overflow.
 * 3. Sending pop() or getTop() to an empty Stack throws the exception Stack::Underflow.
 */

#ifndef STACK_H_
#define STACK_H_

#include "StackException.h"
#include <string>
#include <iostream>
using namespace std;

template<class Item>
class Stack {
public:
	Stack(unsigned size);
	Stack(const Stack& original);
	~Stack();
	Stack& operator=(const Stack& original);
	bool isEmpty() const;
	bool isFull() const;
	void push( Item add);
	Item getTop() const;
	Item pop();
	unsigned getSize() const;
	unsigned getCapacity() const;
	void setCapacity(unsigned newCapacity);
protected:
	void makeCopyOf(const Stack& original);
	
private:
	unsigned myCapacity;
	unsigned myTop;
	Item*    myArray;
	friend class StackTester;
};

/* explicit-value constructor
 * Parameter: size, an unsigned value.
 * Precondition: size > 0.
 * Postcondition: myTop == 0 && myCapacity == size
 *              && myArray contains the address of a dynamic array of 'size' entries.
 */
template<class Item>
Stack<Item>::Stack(unsigned size) {
	if (size <= 0) {
		throw StackException("Stack()", "Stack(size): size must be positive!");
	} else {
		myTop = 0;
		myCapacity = size;
		myArray = new Item[size];
	}
}

/* copy constructor
 * Parameter: original, a Stack (const reference).
 * Postcondition: I am a copy of original.
 */
template<class Item>
Stack<Item>::Stack(const Stack<Item>& original) {
	makeCopyOf(original);
}

/* utility method containing code refactored from
 *  the copy constructor and operator=.
 * Parameter: original, a Stack (const reference).
 * Postcondition: I am a copy of original.
 */
template<class Item>
void Stack<Item>::makeCopyOf(const Stack<Item>& original) {
	myCapacity = original.myCapacity;
	myArray = new Item[myCapacity];

	for (unsigned i = 0; i < myCapacity; i++) {
		myArray[i] = original.myArray[i];
	}
	myTop = original.myTop;
}

/* destructor
 * Postcondition: myCapacity == 0 && myTop == 0
 *             && myArray has been deallocated.
 */
template<class Item>
Stack<Item>::~Stack() {
	delete[] myArray;
	myArray = NULL;
	myCapacity = 0;
	myTop = 0;
}

/* assignment operator
 * Parameter: original, a Stack (const reference).
 * Postcondition: I am a copy of original
 *              && I have been returned.
 */
template<class Item>
Stack<Item>& Stack<Item>::operator=(const Stack<Item>& original) {
	if (this != &original) {
		delete[] myArray;
		makeCopyOf(original);
	}
	return *this;
}

// Returns true if myTop is equal to 0, or in other words:
// if the stack is empty
template<class Item>
bool Stack<Item>::isEmpty() const {
	return (myTop == 0);
}

// Returns true if myCapacity is equal to myTop, or in other words:
// if the stack is full and cannot store any more items
template<class Item>
bool Stack<Item>::isFull() const {
	return (myCapacity == myTop);
}

// Adds a new Item to the top of the stack, throwing
// and exception if the stack is full
template<class Item>
void Stack<Item>::push(Item add) {
	if(myTop==myCapacity){
		throw StackException("push()", "stack is full");
	}
	myArray[myTop] = add;
	myTop++;
}

// Returns the top Item from the stack without modifying the stack,
// throwing an exception if the stack is empty
template<class Item>
Item Stack<Item>::getTop() const {
	if (myTop > 0) {
		return myArray[myTop - 1];
	} else {
		throw StackException("getTop()", "stack is empty");
	}
}

// Returns and removes the top Item from the stack
// throwing an exception if the stack is empty
template<class Item>
Item Stack<Item>::pop() {
	if(myTop==0){
		throw StackException("pop()", "stack is empty!");
	}
	return myArray[--myTop];
}

// Returns the size of the Stack
template<class Item>
unsigned Stack<Item>::getSize() const {
	return myTop;
}

// Returns the capacity of the Stack
template<class Item>
unsigned Stack<Item>::getCapacity() const {
	return myCapacity;
}

// Sets the capacity to be newCapacity, unless
// the size is greater than newCapacity
template<class Item>
void Stack<Item>::setCapacity(unsigned newCapacity) {
	if(newCapacity < myTop) {
		throw StackException("setCapacity()", "cannot set capacity to be smaller than size!");
	} else {
		if (myCapacity!=newCapacity) {
			Item * temp = new Item[newCapacity];
			for(unsigned i = 0; i < myTop; i ++) {
				temp[i] = myArray[i];
			}
			delete[] myArray;
			myArray = temp;
			myCapacity = newCapacity;
		}
	}
}


#endif

