/*
 * PalDetectorTester.cpp
 *
 *  Created on: Nov 21, 2016
 *      Author: mrn6
 */

#include "PalDetectorTester.h"

void PalDetectorTester::testDetection() {
	cout << "Testing the PalDetector class:" << endl;
	testIsPalindrome();
	testDoesDetect();
	cout << "All tests passed! " << endl;
}

void PalDetectorTester::testIsPalindrome() {
	cout << "Testing IsPalindrome() ... " << flush;

	PalDetector pd1("madam.txt", "madamout.txt"); //create the PalDetector with a random 1 line palindrome
	//begin tests with testing an empty string
	assert(pd1.isPalindrome("") == false);
	cout << " 0 " << flush;

	//test with a one-line palindrome
	assert(pd1.isPalindrome(" Madam, I'm Adam.") == true);
	cout << " 1 " << flush;

	//test with a one-line not palindrome
	assert(pd1.isPalindrome(" Shamelessly not a palindrome") == false);
	cout << " 2 " << flush;

	//test with a single character palindrome
	assert(pd1.isPalindrome("a") == true);
	cout << " 3 " << flush;

	cout << "Passed! " << endl;
}

void PalDetectorTester::testDoesDetect() {
	cout << "Testing detectPalindromes() ... " << flush;

	//test with a simple one line palindrome
	PalDetector pd1("madam.txt", "madamout.txt");
	pd1.detectPalindromes();
	ifstream fin1("madamout.txt");
	assert(fin1.is_open());
	string tempstring;
	getline(fin1, tempstring);
	assert(tempstring == "   Madam, I'm Adam. ***");
	cout << " 1 " << flush;

	//test with a multiline palindrome
	PalDetector pd2("multiline.txt", "multilineout.txt");
	pd2.detectPalindromes();
	ifstream fin2("multilineout.txt");
	assert(fin2.is_open());
	string tempstring2;
	getline(fin2, tempstring2);
	assert(tempstring2 == "Madam, I'm Adam. ***");
	getline(fin2, tempstring2);
	assert(tempstring2 == "   A man, a plan, a canal, Panama! ***");
	cout << " 2 " << flush;

	cout << "Passed! " << endl;

	fin1.close();
	fin2.close();
}
