/*
 * List.cpp
 *
 *  Created on: Oct 11, 2016
 *      Author: mrn6
 */

#include "List.h"
#include <iostream>
using namespace std;

List::List() {
	myFirst = NULL;
	myLast = NULL;
	mySize = 0;
}

List::Node::Node() {
	myItem = Item();
	myNext = NULL;
}

List::Node::Node(Item item, Node* nextNode) {
	myItem = item;
	myNext = nextNode;
}

unsigned List::getSize() const {
	return mySize;
}

Item List::getFirst() const {
	if (mySize != 0 && myFirst != NULL) {
		return myFirst->myItem;
	}
	throw underflow_error("Can't getFirst() for an empty List.");
}

Item List::getLast() const {
	if (mySize != 0 && myLast != NULL) {
		return myLast->myItem;
	}
	throw underflow_error("Can't getLast() for an empty List.");
}

void List::append(const Item add) {
	Node * nodePtr = new List::Node(add, NULL);
	if (mySize == 0) {
		myFirst = nodePtr;
	} else {
		myLast->myNext = nodePtr;
	}
	mySize += 1;
	myLast = nodePtr;
}

List::~List() {
	delete myFirst;
	myFirst = myLast = NULL;
	mySize = 0;
}

List::Node::~Node() {
//	cout << "~Node() is deallocating the node containing item "
//	             << myItem << endl;
	delete myNext;
}

List::List(const List& original) {
	myFirst = myLast = NULL;          //  set pointers
	mySize = 0;                       //   and size to 'empty' values
	if (original.getSize() > 0) {     //  if there are nodes to copy:
		Node* oPtr = original.myFirst; //  start at the first node
		while (oPtr != NULL) {         //  while there are more nodes:
			append(oPtr->myItem);       //   append the item in that node
			oPtr = oPtr->myNext;        //   advance to next node
		}
	}
}

List& List::operator=(const List& original) {
	if (&myFirst != &original.myFirst) {
		delete myFirst;
		myFirst = myLast = NULL;
		mySize = 0;
		if (original.getSize() > 0) {
			Node* oPtr = original.myFirst;
			while (oPtr != NULL) {         //  while there are more nodes:
				append(oPtr->myItem);       //   append the item in that node
				oPtr = oPtr->myNext;        //   advance to next node
			}
		}
	}
	return *this;
}
