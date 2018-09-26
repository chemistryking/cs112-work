/*
 * PalDetector.cpp
 *
 *  Created on: Nov 21, 2016
 *      Author: mrn6
 */

#include "PalDetector.h"

//simple constructor which merely initializes the file names to be the arguments
PalDetector::PalDetector(const string& input, const string& output) {
	inputFile = input;
	outputFile = output;
}

//A method which opens an input stream to one file, an output stream to another,
//and reads in all the lines from the input file one at a time. For each line,
//isPalindrome is called, testing whether the line is a palindrome, if it is,
//this method prints out the same line to the output file with an appended "***"
void PalDetector::detectPalindromes() {
	ifstream inFile(inputFile.c_str());
	assert(inFile.is_open());
	ofstream outFile(outputFile.c_str());
	assert(outFile.is_open());

	while (!inFile.eof()) {
		string tempIn;
		getline(inFile, tempIn);
		outFile << tempIn << " ";
		if (isPalindrome(tempIn)) {
			outFile << "***" << endl;
		} else {
			outFile << "\n";
		}
	}

	inFile.close();
	outFile.close();
}

//This method takes a string and stores each character into both a stack
//and a queue. After doing so, each element in both is popped/removed
//and if they are not the same character, false is returned, representing that
//the string is not a palindrome. If the end is reached, the string is a palindrome
//and true is returned.
bool PalDetector::isPalindrome(const string& palindrome) {
	if (palindrome.length() == 0) {
		return false;
	}
	Stack<char> s1(1);
	ArrayQueue<char> q1(1);

	for (unsigned i = 0; i < palindrome.length(); i++) {
		if (isalpha(palindrome[i])) {
			try {
				q1.append(tolower(palindrome[i]));
			} catch (FullQueueException& se) {
				q1.setCapacity(q1.getCapacity() * 2);
				q1.append(tolower(palindrome[i]));
			}
			try {
				s1.push(tolower(palindrome[i]));
			} catch (StackException& se) {
				s1.setCapacity(s1.getCapacity() * 2);
				s1.push(tolower(palindrome[i]));
			}
		}
	}

	char ch1;
	char ch2;
	unsigned length = q1.getSize();

	for (unsigned i = 0; i < length; i++) {
		ch1 = s1.pop();
		ch2 = q1.remove();
		if (ch1 != ch2) {
			return false;
		}
	}
	return true;
}

