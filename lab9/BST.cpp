/* BST.cpp defines binary search tree methods.
 * Joel Adams, for CS 112 at Calvin College.
 * Student Name: Matthew Nykamp
 * Date: 11-22-16
 */

#include "BST.h"

BST::BST() {
	myNumItems = 0;
	myRoot = NULL;
}

//Traverses the binary search tree by processing the items before
//the left and right items are processed
void BST::traversePostorder() {
	if(myNumItems!=0) {
		myRoot->traversePostorder();
	}
}

//Traverses the binary search tree by processing the items
//after the left items but before the right items
void BST::traverseInorder() {
	if(myNumItems!=0) {
		myRoot->traverseInorder();
	}
}

//Node method providing a recursive implementation of traverseInorder()
void BST::Node::traverseInorder() {
	if (myLeft != NULL) {
		myLeft->traverseInorder();
	}
	processItem();
	if (myRight != NULL) {
		myRight->traverseInorder();
	}
}

//If size is not zero, sees if the root contains item, starting a recursion
bool BST::contains(const Item& it) const {
	if (myNumItems == 0) {
		return false;
	} else {
		return myRoot->contains(it);
	}
}

//If the node has the value of item, then return true, otherwise return
//the values of contains() on the left and right nodes if they exist
bool BST::Node::contains(const Item& it) const {
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
void BST::insert(const Item& it) {
	if (myNumItems == 0) {
		myRoot = new Node(it);
	} else {
		try {
			myRoot->insert(it);
		} catch (Exception& se) {
			throw se;
		}
	}
	myNumItems++;
}

//Node implementation of the recursive insert(), calling insert()
//to the left if it is smaller, calling insert() to the right if
//it is bigger, and throwing an exception if the item exists already
void BST::Node::insert(const Item& it) {
	if (myItem == it) {
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

BST::~BST() {
	delete myRoot;
	myRoot = NULL;
	myNumItems = 0;
}

BST::Node::Node(const Item& it) {
	myItem = it;
	myLeft = NULL;
	myRight = NULL;
}

BST::Node::~Node() {
	delete myLeft;
	delete myRight;
}

bool BST::isEmpty() const {
	return myNumItems == 0;
}

unsigned BST::getNumItems() const {
	return myNumItems;
}

void BST::traversePreorder() {
	if (!isEmpty()) {
		myRoot->traversePreorder();
	}
}


void BST::Node::traversePreorder() {
	processItem();
	if (myLeft != NULL) {
		myLeft->traversePreorder();
	}
	if (myRight != NULL) {
		myRight->traversePreorder();
	}
}

void BST::Node::processItem() {
	cout << ' ' << myItem;
}

void BST::Node::traversePostorder() {
	if (myLeft != NULL) {
		myLeft->traversePostorder();
	}
	if (myRight != NULL) {
		myRight->traversePostorder();
	}
	processItem();
}

