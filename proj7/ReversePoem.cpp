/*
 * ReversePoem.cpp
 *
 *  Created on: Nov 1, 2016
 *      Author: mrn6
 */

#include "ReversePoem.h"

/* Creates an fstream to a file with a reverse-poem stored in it. We assume that the title
 * is the first line, the author is the second line, and starting at the fourth line is the
 * actual body of the poem. We read in all the lines, one at a time, storing them both into
 * the string body, an instance variable, and into a stack. Then, we finally pop all the elements
 * of the stack into the string bodyreversed, an instance variable.
 */

ReversePoem::ReversePoem(string fileName) {
	ifstream fin(fileName.c_str());
	assert(fin.is_open());
	//assuming the first line is not empty, is the title
	getline(fin, title);
	//assuming the second line is not empty, is the author
	getline(fin, author);
	Stack<string> poem(1);
	string temp;
	getline(fin,temp); // getting rid of the empty line between author and the body
	while (!fin.eof()) {
		getline(fin, temp);
		body += temp;
		body += '\n';
		try {
			poem.push(temp);
		} catch (StackException& se) {
			poem.setCapacity(poem.getCapacity() * 2);
			poem.push(temp);
		}
	}
	int tempSize = poem.getSize();
	for (int i = 0; i < tempSize; i++) {
		bodyReversed += poem.pop();
		bodyReversed += '\n';
	}
}

