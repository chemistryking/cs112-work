/*
 * ReversePoem.h
 *
 *  Created on: Nov 1, 2016
 *      Author: mrn6
 */

#ifndef REVERSEPOEM_H_
#define REVERSEPOEM_H_

#include <iostream>
#include <fstream>
#include <cassert>
#include "Stack.h"
using namespace std;

class ReversePoem {
public:
	ReversePoem(string fileName);
	string getTitle() const {return title;}
	string getAuthor() const {return author;}
	string getBody() const {return body;}
	string getBodyReversed() const {return bodyReversed;}
private:
	string title;
	string author;
	string body;
	string bodyReversed;
};

#endif /* REVERSEPOEM_H_ */
