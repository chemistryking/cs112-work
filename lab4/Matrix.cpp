/* Matrix.cpp defines Matrix class methods.
 * Student Name: Matthew Nykamp
 * Date: 10-04-16
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */

#include "Matrix.h"

Matrix::Matrix() {
	myRows = myColumns = 0;
}

Matrix::Matrix(unsigned rows, unsigned cols) {
	myRows = rows;
	myColumns = cols;
	myVec.setSize(rows);
	for (unsigned i = 0; i < rows; i++) {
		myVec[i].setSize(cols);
	}
}

Vec<Item>& Matrix::operator[](unsigned index) {
	if (index >= myRows) {
		throw range_error("invalid index ");
	}
	return myVec[index];
}

const Vec<Item>& Matrix::operator[](unsigned index) const {
	if (index >= myRows) {
		throw range_error("invalid index ");
	}
	return myVec[index];
}

bool Matrix::operator==(const Matrix& m2) const {
	if (myRows != m2.getRows() || myColumns != m2.getColumns()) {
		return false;
	} else {
		return myVec == m2.myVec;
	}
}
