/*
 * List.h
 *
 *  Created on: Oct 11, 2016
 *      Authors: Matthew Nykamp and Liam Lichti
 *
 *		Liam Lichti is responsible for Testers and Methods for operator==, readFrom (stream), writeTo (stream), prepend, and insert written by Liam Lichti
 *		Matthew Nykamp is responsible for Testers and Methods for operator!=, readFrom (string), writeTo (string), getIndexOf, and remove
 */

#ifndef LIST_H_
#define LIST_H_

#include <iostream>
#include <cassert>
#include <fstream>
using namespace std;

template<class Item>
class List {
private:
	struct Node {
		Item myItem;
		Node* myNext;
		Node();
		Node(Item, Node*);
		virtual ~Node();
	};
	unsigned mySize;
	Node* myFirst;
	Node* myLast;
public:
	List();
	List(const List&);
	virtual ~List();
	friend class ListTester;
	unsigned getSize() const;
	Item getFirst() const;
	Item getLast() const;
	void append(const Item);
	List& operator=(const List&);
	void readFrom(string);
	void writeTo(string) const;
	bool operator==(const List& original); //equality operator
	bool operator!=(const List& original); //inequality operator
	void readFrom(istream& in); //readfrom method
	void writeTo(ostream& out); //writeTo method
	void prepend(const Item& it);
	unsigned getIndex(const Item it) const;
	void insert(const Item it, unsigned index);
	Item remove(unsigned index);
};

template<class Item>
List<Item>::List() {
	myFirst = NULL;
	myLast = NULL;
	mySize = 0;
}

template<class Item>
List<Item>::Node::Node() {
	myItem = Item();
	myNext = NULL;
}

template<class Item>
List<Item>::Node::Node(Item item, Node* nextNode) {
	myItem = item;
	myNext = nextNode;
}

template<class Item>
unsigned List<Item>::getSize() const {
	return mySize;
}

template<class Item>
Item List<Item>::getFirst() const {
	if (mySize != 0) {
		return myFirst->myItem;
	}
	throw underflow_error("Can't getFirst() for an empty List.");
}

template<class Item>
Item List<Item>::getLast() const {
	if (mySize != 0) {
		return myLast->myItem;
	}
	throw underflow_error("Can't getFirst() for an empty List.");
}

template<class Item>
void List<Item>::append(const Item add) {
	Node * nodePtr = new List<Item>::Node(add, NULL);
	if (mySize == 0) {
		myFirst = nodePtr;
	} else {
		myLast->myNext = nodePtr;
	}
	mySize += 1;
	myLast = nodePtr;
}

template<class Item>
List<Item>::~List() {
	delete myFirst;
	myFirst = myLast = NULL;
	mySize = 0;
}

template<class Item>
List<Item>::Node::~Node() {
//	cout << "~Node() is deallocating the node containing item "
//	             << myItem << endl;
	delete myNext;
}

template<class Item>
List<Item>::List(const List& original) {
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

template<class Item>
List<Item>& List<Item>::operator=(const List<Item>& original) {
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

//Reads in all values from a file until end-of-file is reached
template<class Item>
void List<Item>::readFrom(string fileName) {
	ifstream fin(fileName.c_str());
	assert(fin.is_open());
	Item item;
	fin >> item;
	while(!fin.eof()){
		append(item);
		fin >> item;
	}
}

//Writes all values from the list to a file, with a tab in between each item
template<class Item>
void List<Item>::writeTo(string fileName) const{
	ofstream fout(fileName.c_str());
	assert(fout.is_open());
	Node* myPtr = myFirst;
	while (myPtr != NULL) {
		fout << myPtr->myItem << '\t';
		myPtr = myPtr->myNext;
	}
}

// Compares two lists and returns true if they are the same or
// have the same memory location.
template<class Item>
bool List<Item>::operator==(const List<Item>& original) {
	if (mySize == original.mySize) {
		if (mySize == 0) {
			return true;
		}

		Node *myPtr = original.myFirst;
		Node *myPtr2 = myFirst;

		while (myPtr != NULL) {
			if (myPtr2 -> myItem != myPtr -> myItem) {
				return false;
			}
			else {
				return true;
			}
			myPtr = myPtr -> myNext;
			myPtr2 = myPtr2 -> myNext;
		}
	}

	if (mySize != original.mySize) {
		return false;
	}

	return true;
}

// Returns false if the the two lists being compared are not equal
template<class Item>
bool List<Item>::operator!=(const List<Item>& original) {
	if (mySize == original.mySize) {
		if (mySize == 0) {
			return false;
		}
		Node *nPtr = original.myFirst;
		Node *nPtr2 = myFirst;
		while (nPtr != NULL) {
			if (nPtr2 -> myItem == nPtr -> myItem) {
				return false;
			}
			else {
				return true;
			}
			nPtr = nPtr -> myNext;
			nPtr2 = nPtr2 -> myNext;
		}
	}
	if (mySize != original.mySize) {
		return true;
	}
	else {
		return false;
	}
}

// Reads in values from a stream until the stream is NULL
// storing them in this list.
template<class Item>
void List<Item>::readFrom(istream& in) {
	Item it;
	while (in != NULL) {
		in >> it;
		append(it);
	}
}

// Writes values from the list into a stream, with a tab in between.
template<class Item>
void List<Item>::writeTo(ostream& out) {
	Node *nPtr = myFirst;
	for (unsigned i = 0; i < mySize; i++) {
		out << nPtr->myItem << '\t';
		nPtr = nPtr->myNext;
	}
}



// Adds an Item to the beginning of the list
template<class Item>
void List<Item>::prepend(const Item& it) {
	if (mySize == 0) {
		Node *myPtr;
		myPtr = new Node(it, NULL);
		myFirst = myLast = myPtr;
	} else {
		Node *myPtr;
		myPtr = new Node(it, myFirst);
		myFirst = myPtr;
	}

	mySize++;
}

// Searches the list for an item, returning the index of the item,
// or returns -1 if the item is not found.
template<class Item>
unsigned List<Item>::getIndex(const Item it) const {
	Node *tempPtr = new Node(it, myFirst);
	int index = 0;
	while (tempPtr -> myNext !=NULL) {
		if (it == tempPtr -> myNext -> myItem) {
			return index;
		}
		index++;
		tempPtr = tempPtr -> myNext;
	}
	index = -1;
	return index;
}

// Inserts an item into the list at index
template<class Item>
void List<Item>::insert(const Item it, unsigned index ) {
	Node *nodePtr = new Node(it, NULL);
	Node *nodePtr2 = myFirst;
	if (mySize == 0) {
		myFirst = nodePtr;
		myLast = nodePtr;
	} else if (index == 0) {
		prepend(it);
		mySize--;
	}
	else {
		for (unsigned i = 0; i < index - 1; i++) {
			nodePtr2 = nodePtr2->myNext;
		}
		nodePtr->myNext = nodePtr2->myNext;
		nodePtr2->myNext = nodePtr;
		if (index >= mySize) {
			myLast = nodePtr;
		}
	}
	mySize++;

}

// Deletes the item at index in this list
template<class Item>
Item List<Item>::remove(unsigned index) {
	Node *nodePtr = myFirst;
	Node *nodePtr2 = myFirst->myNext;
	Node *nodePtr3 = myFirst;

	if (index <= 0) {
		myFirst = myFirst -> myNext;
		nodePtr -> myNext = NULL;
	}
	if (index >= mySize -1) {
		for (unsigned i = 0; i < mySize-2; i++) {
			nodePtr = nodePtr->myNext;
		}
		nodePtr -> myNext = NULL;
		myLast = nodePtr;
	}

	if (index > 0 && index < mySize - 2) {
		for (unsigned i = 0; i < index -1; i++) {
			nodePtr = nodePtr2;
		}
		for (unsigned i = 0; i < index; i++) {
			nodePtr3 = nodePtr2;
		}
		nodePtr->myNext = nodePtr3->myNext;
		nodePtr3->myNext = NULL;
	}
	index = -1;
	return index;
	mySize --;


}

#endif /* LIST_H_ */
