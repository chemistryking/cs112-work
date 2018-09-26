/* Stack.cpp defines the dynamically allocated (array-based ) Stack operations.
 * Joel Adams, for CS 112 at Calvin College.
 * Student Name: Matthew Nykamp
 * Date: 11-01-16
 */

#include "Stack.h"

/* explicit-value constructor
 * Parameter: size, an unsigned value.
 * Precondition: size > 0.
 * Postcondition: myTop == 0 && myCapacity == size
 *              && myArray contains the address of a dynamic array of 'size' entries.
 */
Stack::Stack(unsigned size) {
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
Stack::Stack(const Stack& original) {
	makeCopyOf(original);
}

/* utility method containing code refactored from
 *  the copy constructor and operator=.
 * Parameter: original, a Stack (const reference).
 * Postcondition: I am a copy of original.
 */
void Stack::makeCopyOf(const Stack& original) {
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
Stack::~Stack() {
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
Stack& Stack::operator=(const Stack& original) {
	if (this != &original) {
		delete[] myArray;
		makeCopyOf(original);
	}
	return *this;
}

// Returns true if myTop is equal to 0, or in other words:
// if the stack is empty
bool Stack::isEmpty() const {
	return (myTop == 0);
}

// Returns true if myCapacity is equal to myTop, or in other words:
// if the stack is full and cannot store any more items
bool Stack::isFull() const {
	return (myCapacity == myTop);
}

// Adds a new Item to the top of the stack, throwing
// and exception if the stack is full
void Stack::push(Item add) {
	if(myTop==myCapacity){
		throw StackException("push()", "stack is full");
	}
	myArray[myTop] = add;
	myTop++;
}

// Returns the top Item from the stack without modifying the stack,
// throwing an exception if the stack is empty
Item Stack::getTop() const {
	if (myTop > 0) {
		return myArray[myTop - 1];
	} else {
		throw StackException("getTop()", "stack is empty");
	}
}

// Returns and removes the top Item from the stack
// throwing an exception if the stack is empty
Item Stack::pop() {
	if(myTop==0){
		throw StackException("pop()", "stack is empty!");
	}
	return myArray[--myTop];
}
