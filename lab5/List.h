/*
 * List.h
 *
 *  Created on: Oct 11, 2016
 *      Author: mrn6
 */

#ifndef LIST_H_
#define LIST_H_

typedef double Item;

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
};

#endif /* LIST_H_ */
