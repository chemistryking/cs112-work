/* Vec.cpp defines the methods for Vec, a simple vector class.
 * Student Name: Matthew Nykamp
 * Date: 9-27-16
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
 */

#include "Vec.h"
#include <stdexcept>
#include <fstream>
#include <cassert>
#include <string>

/* Default constructor, initializes mySize to be 0
 * and myArray to be NULL
 */
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

/*	Copy constructor, creates a deep copy of the Vec passed in.
 *
 */
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

/* Sets the Vec to have all the same values as
 * another Vec, original, zeroes will be added if
 * original is larger than this Vec.
 */
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

/* Returns the variable mySize, the number of
 * elements in this Vec.
 */
unsigned Vec::getSize() {
	return mySize;
}

/* Sets the Item at index to be it, an Item argument.
 *
 */
void Vec::setItem(unsigned index, const Item& it) {
	if (index > mySize || index < 0 || mySize == 0 || index >= mySize) {
		throw std::range_error("index out of range");
	} else {
		myArray[index] = it;
	}
}

/* Returns the Item at an unsigned argument index.
 *
 */
Item Vec::getItem(unsigned index) const {
	if (index > mySize || index < 0 || mySize == 0 || index >= mySize) {
		throw std::range_error("index out of range");
	} else {
		return myArray[index];
	}
}

/* Sets the size of this Vec to be newSize, an unsigned argument.
 * If we are expanding the Vec, zeroes are added for all created elements.
 */
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

/* Returns true if this Vec and v2 have the same values and size.
 *
 */
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

/* For every element, this method sends an Item
 * to an istream which is passed in.
 */
void Vec::readFrom(istream& in) {
	for (int i = 0; i < mySize; i++) {
		in >> myArray[i];
	}
}

/* Reads in the first Item from fileName into mySize,
 * then fills myArray with Items from fileName.
 */
void Vec::readFrom(string filename) {
	ifstream fin(filename.c_str());
	assert(fin.is_open());
	delete[] myArray;
	fin >> mySize;
	myArray = new Item[mySize];
	readFrom(fin);
	fin.close();
}

/* Replaces every element with an Item read in from out, an ostream.
 *
 */
void Vec::writeTo(ostream& out) const {
	for (int i = 0; i < mySize; i++) {
		out << myArray[i] << endl;
	}
}

/* First writes mySize into fileName, then
 * writes all the values of myArray into fileName.
 */
void Vec::writeTo(string fileName) const {
	ofstream fout(fileName.c_str());
	assert(fout.is_open());
	fout << mySize << endl;
	for (int i = 0; i < mySize; i++) {
		fout << myArray[i] << endl;
	}
	fout.close();
}

/* Adds the elements of two vectors together, returning the result.
 * Throws an invalid argument exception if the vectors are not the same size.
 */
Vec Vec::operator+(const Vec& addend) {
	if (mySize != addend.mySize) {
		throw std::invalid_argument("vectors are not the same size");
	}
	Vec temp = *this;
	for (int i = 0; i < mySize; i++) {
		temp.setItem(i, myArray[i] + addend.getItem(i));
	}
	return temp;
}

/* Subtracts the elements of two vectors together, returning the result.
 * Throws an invalid argument exception if the vectors are not the same size.
 */
Vec Vec::operator-(const Vec& addend) {
	if (mySize != addend.mySize) {
		throw std::invalid_argument("vectors are not the same size");
	}
	Vec temp = *this;
	for (int i = 0; i < mySize; i++) {
		temp.setItem(i, myArray[i] - addend.getItem(i));
	}
	return temp;
}

/* Returns false if the compared against Vec
 * has a different size or if no element is the same as
 * this Vec
 */
bool Vec::operator!=(const Vec& v2) {
	int a = 0;
	if (mySize == v2.mySize) {
		for (int i = 0; i < mySize; i++) {
			if (myArray[i] == v2.myArray[i]) {
				a += 1;
			}
		}
		if (a == mySize) {
			return false;
		}
	}
	return true;
}

/* Multiplies each of the elements of two Vecs together, returning the resultant Vec.
 * Throws an invalid argument exception if the Vecs are not the same size.
 */
double Vec::operator*(const Vec& factor) {
	if (mySize != factor.mySize) {
		throw std::invalid_argument("vectors are not the same size");
	}
	Vec sums(mySize);
	for (int i = 0; i < mySize; i++) {
		sums.setItem(i, myArray[i] * factor.myArray[i]);
	}
	double sum = 0;
	for (int i = 0; i < mySize; i++) {
		sum += sums.getItem(i);
	}
	return sum;
}

/* Write version of the subscript operator; returns
 * the actual Item stored in myArray so it can be modified.
 */
Item& Vec::operator[](unsigned index) {
	if (index >= mySize) {
		throw range_error("index out of bounds");
	}
	return myArray[index];
}

/* Read version of the subscript operator; returns the
 * value of myArray at index so it cannot be modified.
 *
 */
const Item& Vec::operator[](unsigned index) const {
	if (index >= mySize) {
		throw range_error("index out of bounds");
	}
	return myArray[index];
}

/* Deallocates the memory used by this Vec,
 * sets mySize to be zero, and sets myArray
 * to be NULL.
 */
Vec::~Vec() {
	delete[] myArray;
	myArray = NULL;
	mySize = 0;
}
