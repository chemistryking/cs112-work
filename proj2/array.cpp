/* array.cpp defines "C style" array operations
 * Name: Matthew Nykamp
 * Date: 9/26/16
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */

#include "array.h"
#include <fstream>
using namespace std;

void initialize(double *a, int size) {
	int val = 0;
	for (int i = 0; i < size; i++) {
		val = i + 1;
		a[i] = val;
	}
}

void print(double *a, int size) {
	for (int i = 0; i < size; i++) {
		cout << *a << '\t';
		a++;
	}
}

/* This method returns the average of all the values in an array a.
 *
 */

double average(double *a, int size) {
	double average = 0;
	int index = 0;
	for (index; index < size; index++) {
		average += *a;
		a++;
	}
	return average / index;
}

/*Takes in the reference to a double array and returns a double
 * that is the sum of the values in the array.
 */

double sum(double *a, int size) {
	double amount = 0;
	for (size; size > 0; size--) {
		amount += *a;
		a++;
	}
	return amount;
}

/* This method reads in size values from an istream and stores them in a double array a.
 *
 */

void read(istream& in, double *a, int size) {
//	for (size; size > 0; size--) {
//		in >> *a;
//		a++;
//	}


	for (int i = 0; i < size; i++) {
		in >> a[i];
	}
}

/*	This method fills an array from a text file. It takes in numValues, an integer argument, amount of values
 * from fileName and adds them to an array, which is modified and not returned.
 *
 */

void fill(const string& fileName, double *&a, int &numValues) {
	ifstream fin(fileName.c_str());
	assert(fin.is_open());
	fin >> numValues;
	delete[] a;
	a = new double[numValues];
	read(fin, a, numValues);
	fin.close();
}

/*	This method resizes an array from the second argument, an integer, into the third argument,
 * another integer. If an array is shrunk, the extra values will be trimmed from the modified array
 * that is passed in.
 *
 */

void resize(double *&a, int oldSize, int newSize) {
	if (newSize != oldSize) {
		double * temp = new double[newSize];
		if (newSize < oldSize) {
			for (int i = 0; i < newSize; i++) {
				temp[i] = a[i];
			}
		} else if (newSize > oldSize) {
			for (int i = 0; i < oldSize; i++) {
				temp[i] = a[i];
			}
		}
		delete[] a;
		a = temp;
	}
}

/*	This method takes in three arrays and three integers. It modifies the third array
 * to become a concatenation of the first two arrays, with the values from the first
 * array appearing first, and the values of the second appearing second. the third integer
 * becomes the size of the modified array.
 */

void concat(double *a1, int size1, double *a2, int size2, double *&a3,
		int &size3) {
	size3 = size1 + size2;
	if (a3[0] != NULL) {
		delete[] a3;
	}
	a3 = new double[size3];
	for (int i = 0; i < size1; i++) {
		a3[i] = a1[i];
	}
	for (int i = 0; i < size2; i++) {
		a3[i + size1] = a2[i];
	}
}
