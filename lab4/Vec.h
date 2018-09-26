/* Vec.h provides a simple vector class named Vec.
 * Student Name: Matthew Nykamp
 * Date: 9-27-16
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
 */

#ifndef VEC_H_
#define VEC_H_

#include <iostream>
using namespace std;
#include <stdexcept>
#include <fstream>
#include <cassert>

template<class Item>
class Vec {
public:
	Vec();
	Vec(unsigned);
	Vec(const Vec<Item>&);
	virtual ~Vec();
	Vec<Item>& operator=(const Vec<Item>&);
	unsigned getSize();
	void setItem(unsigned, const Item&);
	Item getItem(unsigned) const;
	void setSize(unsigned);
	bool operator==(const Vec<Item>&) const;
	void writeTo(ostream&) const;
	void readFrom(istream&);
	Item& operator[](unsigned);
	const Item& operator[](unsigned) const;
	Vec<Item> operator+(const Vec<Item>&);
	Vec<Item> operator-(const Vec<Item>&);
	double operator*(const Vec<Item>&);
	bool operator!=(const Vec<Item>& v2);
	void writeTo(string) const;
	void readFrom(string);
private:
	unsigned mySize;
	Item * myArray;
	friend class VecTester;
};

/* Default constructor, initializes mySize to be 0
 * and myArray to be NULL
 */
template<class Item>
Vec<Item>::Vec() {
	mySize = 0;
	myArray = NULL;
}

/*Explicit constructor for the class, sets the size to be the
 * unsigned passed in.
 */
template<class Item>
Vec<Item>::Vec(unsigned size) {
	mySize = size;
	myArray = new Item[size];
	for (int i = 0; i < size; i++) {
		myArray[i] = 0;
	}
}

/*	Copy constructor, creates a deep copy of the Vec passed in.
 *
 */
template<class Item>
Vec<Item>::Vec(const Vec<Item>& original) {
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
template<class Item>
Vec<Item>& Vec<Item>::operator=(const Vec<Item>& original) {
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
template<class Item>
unsigned Vec<Item>::getSize() {
	return mySize;
}

/* Sets the Item at index to be it, an Item argument.
 *
 */
template<class Item>
void Vec<Item>::setItem(unsigned index, const Item& it) {
	if (index > mySize || index < 0 || mySize == 0 || index >= mySize) {
		throw std::range_error("index out of range");
	} else {
		myArray[index] = it;
	}
}

/* Returns the Item at an unsigned argument index.
 *
 */
template<class Item>
Item Vec<Item>::getItem(unsigned index) const {
	if (index > mySize || index < 0 || mySize == 0 || index >= mySize) {
		throw std::range_error("index out of range");
	} else {
		return myArray[index];
	}
}

/* Sets the size of this Vec to be newSize, an unsigned argument.
 * If we are expanding the Vec, zeroes are added for all created elements.
 */
template<class Item>
void Vec<Item>::setSize(unsigned newSize) {
	Vec<Item> temp = *this;
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
template<class Item>
bool Vec<Item>::operator==(const Vec<Item>& v2) const {
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
template<class Item>
void Vec<Item>::readFrom(istream& in) {
	for (int i = 0; i < mySize; i++) {
		in >> myArray[i];
	}
}

/* Reads in the first Item from fileName into mySize,
 * then fills myArray with Items from fileName.
 */
template<class Item>
void Vec<Item>::readFrom(string filename) {
	ifstream fin(filename.c_str());
	assert(fin.is_open());
	delete[] myArray;
	fin >> mySize;
	myArray = new Item[mySize];
	for (int i = 0; i < mySize; i++) {
		fin >> myArray[i];
	}
	fin.close();
}

/* Replaces every element with an Item read in from out, an ostream.
 *
 */
template<class Item>
void Vec<Item>::writeTo(ostream& out) const {
	for (int i = 0; i < mySize; i++) {
		out << myArray[i] << endl;
	}
}

/* First writes mySize into fileName, then
 * writes all the values of myArray into fileName.
 */
template<class Item>
void Vec<Item>::writeTo(string fileName) const {
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
template<class Item>
Vec<Item> Vec<Item>::operator+(const Vec<Item>& addend) {
	if (mySize != addend.mySize) {
		throw std::invalid_argument("vectors are not the same size");
	}
	Vec<Item> temp = *this;
	for (int i = 0; i < mySize; i++) {
		temp.setItem(i, myArray[i] + addend.getItem(i));
	}
	return temp;
}

/* Subtracts the elements of two vectors together, returning the result.
 * Throws an invalid argument exception if the vectors are not the same size.
 */
template<class Item>
Vec<Item> Vec<Item>::operator-(const Vec<Item>& addend) {
	if (mySize != addend.mySize) {
		throw std::invalid_argument("vectors are not the same size");
	}
	Vec<Item> temp = *this;
	for (int i = 0; i < mySize; i++) {
		temp.setItem(i, myArray[i] - addend.getItem(i));
	}
	return temp;
}

/* Returns false if the compared against Vec
 * has a different size or if no element is the same as
 * this Vec
 */
template<class Item>
bool Vec<Item>::operator!=(const Vec<Item>& v2) {
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
template<class Item>
double Vec<Item>::operator*(const Vec<Item>& factor) {
	if (mySize != factor.mySize) {
		throw std::invalid_argument("vectors are not the same size");
	}
	Vec<Item> sums(mySize);
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
template<class Item>
Item& Vec<Item>::operator[](unsigned index) {
	if (index >= mySize) {
		throw range_error("index out of bounds");
	}
	return myArray[index];
}

/* Read version of the subscript operator; returns the
 * value of myArray at index so it cannot be modified.
 *
 */
template<class Item>
const Item& Vec<Item>::operator[](unsigned index) const {
	if (index >= mySize) {
		throw range_error("index out of bounds");
	}
	return myArray[index];
}

/* Deallocates the memory used by this Vec,
 * sets mySize to be zero, and sets myArray
 * to be NULL.
 */
template<class Item>
Vec<Item>::~Vec() {
	delete[] myArray;
	myArray = NULL;
	mySize = 0;
}

#endif /*VEC_H_*/
