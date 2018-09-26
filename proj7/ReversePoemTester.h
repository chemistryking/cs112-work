/*
 * ReversePoemTester.h
 *
 *  Created on: Nov 7, 2016
 *      Author: mrn6
 */

#ifndef REVERSEPOEMTESTER_H_
#define REVERSEPOEMTESTER_H_

#include <cassert>
#include <iostream>
#include <fstream>
#include "ReversePoem.h"
using namespace std;

class ReversePoemTester {
public:
	void runTests();
	void testConstructor();
	void testGetTitle();
	void testGetAuthor();
	void testGetBody();
	void testGetBodyReversed();
};

#endif /* REVERSEPOEMTESTER_H_ */
