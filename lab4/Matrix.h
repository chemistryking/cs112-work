/* Matrix.h provides a class for manipulating 2-dimensional vectors.
 * Student Name: Matthew Nykamp
 * Date: 10-04-16
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */

#ifndef MATRIX_H_
#define MATRIX_H_

#include "Vec.h"

typedef double Item;

class Matrix {
public:
	Matrix();
	Matrix(unsigned rows, unsigned cols);
	unsigned getRows() const {return myRows;};
	unsigned getColumns() const {return myColumns;};
	Vec<Item>& operator[](unsigned);
	const Vec<Item>& operator[](unsigned) const;
	bool operator==(const Matrix&) const;
private:
	unsigned myRows;
	unsigned myColumns;
	Vec<Vec<Item> > myVec;
	friend class MatrixTester;
};

#endif
