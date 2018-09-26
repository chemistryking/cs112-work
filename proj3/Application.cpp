/*
 * Application.cpp
 *
 *  Created on: Oct 3, 2016
 *      Author: Matthew Nykamp and Royce Lloyd
 *
 *      Matthew Nykamp is responsible for the following methods:
 *      -operator[]() write version
 *      -writeTo()
 *      -operator+()
 *      -operator*()
 *      Royce Lloyd is responsible for the following methods:
 *      -operator[]() read version
 *      -operator!=()
 *      -readFrom()
 *      -operator-()
 */

#include "Application.h"
#include "Vec.h"
#include <iostream>

Application::Application() {
}

// This method asks the user to input dim, the dimensions in the system.
// It then asks for the starting location for the user to input, and it
// takes a user-defined number of vectors and adds them to the starting
// point, returning the resultant vector.

void Application::run() {
	cout << "Welcome to the vector program!" << endl;
	cout << "Please enter the number of dimensions: " << flush;
	unsigned dim, numVectors;
	cin >> dim;
	cout << "Please enter the " << dim
			<< " coordinates of the starting location: " << flush;
	Vec start(dim);
	for (unsigned i = 0; i < dim; i++) {
		cin >> start[i];
	}
	cout << "How many vectors will be added? " << flush;
	cin >> numVectors;
	for (unsigned i = 0; i < numVectors; i++) {
		Vec add(dim);
		cout << "Please enter the " << dim << " coordinates of the vector: "
				<< flush;
		for (unsigned i = 0; i < dim; i++) {
			cin >> add[i];
		}
		start = start + add;
	}
	cout << "The coordinates of this vector are: {" << flush;
	for (unsigned i = 0; i < dim; i++) {
		if (dim != 1 && i != dim - 1) {
			cout << start[i] << ", ";
		} else {
			cout << start[i];
		}
	}
	cout << "}" << endl;
}
