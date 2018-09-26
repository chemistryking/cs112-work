/* BST.h declares a "classic" binary search tree of linked nodes.
 * Joel Adams, for CS 112 at Calvin College.
 * Student Name: Matthew Nykamp
 * Date: 11-22-16
 * 
 * Class Invariant:
 *   myNumItems == 0 && myRoot == NULL ||
 *   myNumItems > 0 && 
 *     myRoot stores the address of a Node containing an item &&
 *       all items in myRoot->myLeft are less than myRoot->myItem &&
 *       all items in myRoot->myRight are greater than myRoot->myItem.
 */

#ifndef BST_H_
#define BST_H_

#include "Exception.h"
#include <iostream>
#include <cmath>
using namespace std;

template<class Item>
class BST {
public:
	BST();
	virtual ~BST();
	bool isEmpty() const;
	unsigned getNumItems() const;
	void insert(const Item&);
	void traverseInorder();
	void traversePreorder();
	void traversePostorder();
	bool contains(const Item&) const;
	unsigned getHeight() const;
private:
	struct Node {
	    Node(const Item& it);
            virtual ~Node();
            unsigned getHeight() const;
            void traverseInorder();
            void traversePreorder();
            void traversePostorder();
            virtual void processItem();
            void insert(const Item&);
            bool contains(const Item& it) const;
            Item myItem;
            Node* myLeft;
            Node* myRight;
	};
	
	Node* myRoot;
	unsigned myNumItems;
	friend class BST_Tester;
};

template<class Item>
BST<Item>::BST() {
	myNumItems = 0;
	myRoot = NULL;
}

//Initiates the recursive solution for getHeight()
//returns 0 if the BST is empty
template<class Item>
unsigned BST<Item>::getHeight() const {
	if(myNumItems!=0) {
		return myRoot->getHeight();
	} else {return 0;}
}

//Returns 1 + the maximum height of the left or right
//nodes if they exist
template<class Item>
unsigned BST<Item>::Node::getHeight() const {
	if(myLeft!=NULL && myRight!=NULL) {
		return 1+max(myLeft->getHeight(),myRight->getHeight());
	} else if(myLeft==NULL && myRight!=NULL) {
		return 1 + myRight->getHeight();
	} else if(myLeft!=NULL && myRight==NULL) {
		return 1 + myLeft->getHeight();
	} else {
		return 1;
	}
}

//Traverses the binary search tree by processing the items before
//the left and right items are processed
template<class Item>
void BST<Item>::traversePostorder() {
	if(myNumItems!=0) {
		myRoot->traversePostorder();
	}
}

//Traverses the binary search tree by processing the items
//after the left items but before the right items
template<class Item>
void BST<Item>::traverseInorder() {
	if(myNumItems!=0) {
		myRoot->traverseInorder();
	}
}

//Node method providing a recursive implementation of traverseInorder()
template<class Item>
void BST<Item>::Node::traverseInorder() {
	if (myLeft != NULL) {
		myLeft->traverseInorder();
	}
	processItem();
	if (myRight != NULL) {
		myRight->traverseInorder();
	}
}

//If size is not zero, sees if the root contains item, starting a recursion
template<class Item>
bool BST<Item>::contains(const Item& it) const {
	if (myNumItems == 0) {
		return false;
	} else {
		return myRoot->contains(it);
	}
}

//If the node has the value of item, then return true, otherwise return
//the values of contains() on the left and right nodes if they exist
template<class Item>
bool BST<Item>::Node::contains(const Item& it) const {
	if (myItem == it) {
		return true;
	} else {
		bool temp1, temp2 = false;
		if (myLeft != NULL) {
			temp1 = myLeft->contains(it);
		}
		if (myRight != NULL) {
			temp2 = myRight->contains(it);
		}

		if (myLeft == NULL && myRight == NULL) {
			return false;
		} else {
			return temp1 || temp2;
		}
	}
}

//Insert an item into the appropriate spot in the binary search tree
template<class Item>
void BST<Item>::insert(const Item& it) {
	if (myNumItems == 0) {
		myRoot = new Node(it);
	} else {
		try {
			myRoot->insert(it);
		} catch (Exception& se) {
			throw Exception("insert()", "bad insert");
		}
	}
	myNumItems++;
}

//Node implementation of the recursive insert(), calling insert()
//to the left if it is smaller, calling insert() to the right if
//it is bigger, and throwing an exception if the item exists already
template<class Item>
void BST<Item>::Node::insert(const Item& it) {
	if (it==(myItem)) {
//		cout << it;
		throw Exception("insert()", "Cannot have duplicates");
	} else {
		if (it < myItem) {
			if (myLeft == NULL) {
				myLeft = new Node(it);
			} else {
				myLeft->insert(it);
			}
		} else if (it > myItem) {
			if (myRight == NULL) {
				myRight = new Node(it);
			} else {
				myRight->insert(it);
			}
		}
	}
}

template<class Item>
BST<Item>::~BST() {
	delete myRoot;
	myRoot = NULL;
	myNumItems = 0;
}

template<class Item>
BST<Item>::Node::Node(const Item& it) {
	myItem = it;
	myLeft = NULL;
	myRight = NULL;
}

template<class Item>
BST<Item>::Node::~Node() {
	delete myLeft;
	delete myRight;
}

template<class Item>
bool BST<Item>::isEmpty() const {
	return myNumItems == 0;
}

template<class Item>
unsigned BST<Item>::getNumItems() const {
	return myNumItems;
}

template<class Item>
void BST<Item>::traversePreorder() {
	if (!isEmpty()) {
		myRoot->traversePreorder();
	}
}

template<class Item>
void BST<Item>::Node::traversePreorder() {
	processItem();
	if (myLeft != NULL) {
		myLeft->traversePreorder();
	}
	if (myRight != NULL) {
		myRight->traversePreorder();
	}
}

template<class Item>
void BST<Item>::Node::processItem() {
	cout << ' ' << myItem;
}

template<class Item>
void BST<Item>::Node::traversePostorder() {
	if (myLeft != NULL) {
		myLeft->traversePostorder();
	}
	if (myRight != NULL) {
		myRight->traversePostorder();
	}
	processItem();
}


#endif /*BST_H_*/

