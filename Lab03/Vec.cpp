/* Vec.cpp defines the methods for Vec, a simple vector class.
 * Student Name: Matthew Nykamp
 * Date: 9-27-16
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
 */

#include "Vec.h"
#include <stdexcept>

Vec::Vec() {
	mySize = 0;
	myArray = NULL;
}

/*Explicit constructor for the class, sets the size to be the
 * unsigned passed in.
 */
Vec::Vec(unsigned size) {
	mySize = size;
	myArray = new Item[size];
	for (int i = 0; i < size; i++) {
		myArray[i] = 0;
	}
}

Vec::Vec(const Vec& original) {
	mySize = original.mySize;
	if (mySize == 0) {
		myArray = NULL;
	} else if (mySize > 0) {
		myArray = new Item[mySize];
		for (int i = 0; i < mySize; i++) {
			myArray[i] = original.myArray[i];
		}
	}

}

Vec& Vec::operator=(const Vec& original) {
	if (myArray == original.myArray) {
		return *this;
	}
	if (myArray != NULL) {
		delete[] myArray;
	}
	if (original.mySize == 0) {
		myArray = NULL;
		mySize = 0;
	} else if (original.mySize > 0) {
		myArray = new Item[original.mySize];
		for (int i = 0; i < original.mySize; i++) {
			myArray[i] = original.myArray[i];
		}
		mySize = original.mySize;
	}
	return *this;
}

unsigned Vec::getSize() {
	return mySize;
}

void Vec::setItem(unsigned index, const Item& it) {
	if (index > mySize || index < 0 || mySize == 0 || index >= mySize) {
		throw std::range_error("index out of range");
	} else {
		myArray[index] = it;
	}
}

Item Vec::getItem(unsigned index) const {
	if (index > mySize || index < 0 || mySize == 0 || index >= mySize) {
		throw std::range_error("index out of range");
	} else {
		return myArray[index];
	}
}

void Vec::setSize(unsigned newSize) {
	Vec temp = *this;
	if (newSize != mySize) {
		if (newSize == 0) {
			mySize = 0;
			delete[] myArray;
			myArray = NULL;
		} else if (newSize > mySize) {
			delete[] myArray;
			myArray = new Item[newSize];
			for (int i = 0; i < mySize; i++) {
				myArray[i] = temp.getItem(i);
			}
			for (int i = mySize; i < newSize; i++) {
				myArray[i] = 0;
			}
		} else if (newSize < mySize) {
			delete[] myArray;
			myArray = new Item[newSize];
			for (int i = 0; i < newSize; i++) {
				myArray[i] = temp.getItem(i);
			}
		}
	}
	mySize = newSize;
}

bool Vec::operator==(const Vec& v2) {
	if (mySize == v2.mySize) {
		for (int i = 0; i < mySize; i++) {
			if (myArray[i] != v2.getItem(i)) {
				return false;
			}
		}
		return true;
	}
	return false;
}

void Vec::readFrom(istream& in) {
	for (int i = 0; i < mySize; i ++) {
		in >> myArray[i];
	}
}

void Vec::writeTo(ostream& out) const {
	for (int i = 0; i < mySize; i++) {
		out << myArray[i] << endl;
	}
}

Vec::~Vec() {
	delete[] myArray;
	myArray = NULL;
	mySize = 0;
}
