/*
 * HeightChecker.cpp
 *
 *  Created on: Nov 22, 2016
 *      Author: mrn6
 */

#include "HeightChecker.h"

void HeightChecker::runHeightChecker() {
	cout
			<< "Welcome to the height checker, please enter a file number from 1 to 10"
			<< endl;
	string temp;
	cin >> temp;
	string temp2;
	if (temp == "10") {
		temp2 = "/home/cs/112/proj/09/randomInts" + temp + ".txt";
	} else {
		temp2 = "/home/cs/112/proj/09/randomInts0" + temp + ".txt";
	}
	ifstream fin(temp2.c_str());
	assert(fin.is_open());

	BST<int> bst;

	unsigned duplicates = 0;
	for (unsigned i = 0; i < pow(2.0, 20.0); i++) {
		long temp;
		fin >> temp;
		try {
			bst.insert(temp);
		} catch (Exception& se) {
			duplicates++;
		}
	}

	cout << "The height of this array is: " << bst.getHeight()
			<< " and the number of duplicates is: " << duplicates << "."
			<< endl;

}
