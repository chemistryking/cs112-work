/*
 * PalDetector.h
 *
 *  Created on: Nov 21, 2016
 *      Author: mrn6
 */

#ifndef PALDETECTOR_H_
#define PALDETECTOR_H_

#include "Stack.h"
#include "ArrayQueue.h"
#include <fstream>
#include <cassert>
#include <cstdlib>
using namespace std;

class PalDetector {
public:
	PalDetector(const string&, const string&);
	void detectPalindromes();
	bool isPalindrome(const string&);
private:
	string inputFile;
	string outputFile;
};

#endif /* PALDETECTOR_H_ */
