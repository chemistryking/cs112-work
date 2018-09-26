/* Matrix.h provides a class for manipulating 2-dimensional vectors.
 * Student Name: Matthew Nykamp and Peter Betten
 * Date: 10-04-16
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 *
 * Methods by Matthew: operator!=, readFrom(istream), writeTo(string), operator+()
 * Methods by Peter: writeTo(), readFrom(string), operator-(), getTranspose()
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include "Vec.h"
#include "Matrix.h"
#include <fstream>
#include <iostream>
#include <cassert>
using namespace std;


template<class Item>
class Matrix {
public:
	Matrix();
	Matrix(unsigned rows, unsigned cols);
	unsigned getRows() const {return myRows;};
	unsigned getColumns() const {return myColumns;};
	Vec<Item>& operator[](unsigned);
	const Vec<Item>& operator[](unsigned) const;
	bool operator==(const Matrix<Item>&) const;
	bool operator!=(const Matrix<Item>&) const;
	void readFrom(istream&);
	void writeTo(string) const;
	void readFrom(string);
	void writeTo(ostream&) const;
	Matrix<Item> operator+(Matrix<Item>&);
	Matrix<Item> operator-(Matrix<Item>&);
	Matrix<Item> getTranspose();
private:
	unsigned myRows;
	unsigned myColumns;
	Vec<Vec<Item> > myVec;
	friend class MatrixTester;
};

//Default constructor
template<class Item>
Matrix<Item>::Matrix() {
	myRows = myColumns = 0;
}

//Explicit constructor
template<class Item>
Matrix<Item>::Matrix(unsigned rows, unsigned cols) {
	myRows = rows;
	myColumns = cols;
	myVec.setSize(rows);
	for (unsigned i = 0; i < rows; i++) {
		myVec[i].setSize(cols);
	}
}

//Write version of subscript operator
template<class Item>
Vec<Item>& Matrix<Item>::operator[](unsigned index) {
	if (index >= myRows) {
		throw range_error("invalid index ");
	}
	return myVec[index];
}

//Read version of subscript operator
template<class Item>
const Vec<Item>& Matrix<Item>::operator[](unsigned index) const {
	if (index >= myRows) {
		throw range_error("invalid index ");
	}
	return myVec[index];
}

//Returns true if two matrices are equal
template<class Item>
bool Matrix<Item>::operator==(const Matrix<Item>& m2) const {
	if (myRows != m2.getRows() || myColumns != m2.getColumns()) {
		return false;
	} else {
		return myVec == m2.myVec;
	}
}

//Returns true if two matrices are not equal
template<class Item>
bool Matrix<Item>::operator!=(const Matrix<Item>& m2) const {
	if (myRows == m2.getRows() && myColumns == m2.getColumns()) {
		return myVec != m2.myVec;
	}
	return true;
}

//For the current rows and columns of the matrix,
//assigns values from istream in
template<class Item>
void Matrix<Item>::readFrom(istream& in) {
	for (unsigned i = 0; i < myRows; i++) {
		for (unsigned j = 0; j < myColumns; j++) {
			in >> myVec[i][j];
		}
	}
}

//First writes the number of rows and columns to a file and then
//writes all the values in the matrix
template<class Item>
void Matrix<Item>::writeTo(string fileName) const {
	ofstream fout(fileName.c_str());
	assert(fout.is_open());
	fout << myRows << " " << myColumns << endl;

	for (unsigned i = 0; i < myRows; i++) {
		for (unsigned j = 0; j < myColumns; j++) {
			fout << myVec[i][j] << "\t";
		}
		fout << endl;
	}
}

//Reads in the size of the matrix from a file and then
//all the values from the file
template<class Item>
void Matrix<Item>::readFrom(string fileName) {
	ifstream fin(fileName.c_str());
	assert(fin.is_open());
	fin >> myRows;
	fin >> myColumns;
	myVec.setSize(myRows);
	for (unsigned i = 0; i < myRows; i++) {
		myVec[i].setSize(myColumns);
		for (unsigned j = 0; j < myColumns; j++) {
			fin >> myVec[i][j];
		}
	}
}

//Sends each value in the matrix to ostream out
template<class Item>
void Matrix<Item>::writeTo(ostream& out) const {
	for (unsigned i = 0; i < myRows; i++) {
		for (unsigned j = 0; j < myColumns; j++) {
			out << myVec[i][j] << "\t";
		}
		out << endl;
	}
}

//Adds two matrices together and returns the sum
template<class Item>
Matrix<Item> Matrix<Item>::operator+(Matrix<Item>& m2) {
	Matrix<Item> temp(myRows, myColumns);
	if (myRows == m2.myRows && myColumns == m2.myColumns) {
		for (unsigned i = 0; i < myRows; i++) {
			temp.myVec[i] = myVec[i] + m2.myVec[i];
		}
		return temp;
	}
	throw invalid_argument("Rows or columns are different sizes.");
}

//Subtracts m2 from this matrix and returns the difference
template<class Item>
Matrix<Item> Matrix<Item>::operator-(Matrix& m2) {
	Matrix<Item> temp(myRows, myColumns);
	if (myRows == m2.myRows && myColumns == m2.myColumns) {
		for (unsigned i = 0; i < myRows; i++) {
			temp.myVec[i] = myVec[i] - m2.myVec[i];
		}
		return temp;
	}
	throw invalid_argument("Rows or columns are different sizes.");
}

//Returns a matrix which is this matrix with columns and rows switched
template<class Item>
Matrix<Item> Matrix<Item>::getTranspose() {
	Matrix temp(myColumns, myRows);
	for (unsigned r = 0 ; r <  myColumns ; r++) {
		for ( unsigned c = 0; c < myRows; c++){
			temp[r][c] = myVec[c][r];

		}

	}
	return temp;

}


#endif
