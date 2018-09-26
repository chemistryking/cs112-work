/*
 * ReversePoemTester.cpp
 *
 *  Created on: Nov 7, 2016
 *      Author: mrn6
 */

#include "ReversePoemTester.h"

void ReversePoemTester::runTests() {
	cout << "Testing ReversePoem..." << endl;
	testConstructor();
	testGetTitle();
	testGetAuthor();
	testGetBody();
	testGetBodyReversed();
	cout << "All tests passed! " << endl;
}

void ReversePoemTester::testConstructor() {
	cout << "Testing Constructor..." << flush;
	ReversePoem rp1("cats.txt");
	assert(rp1.getTitle()=="Cats");
	assert(rp1.getAuthor()=="Leo J. Smada");
	assert(rp1.getBody() == "I love it when cats rub against me.\n"
				"I could never say\nI hate those purring felines.\n\n");
	assert(rp1.getBodyReversed() == "\nI hate those purring felines.\n"
				"I could never say\n"
				"I love it when cats rub against me.\n");
	cout << " 1 " << flush;
	ReversePoem rp2("worstdayever.txt");
	assert(rp2.getTitle() == "Worst Day Ever?");
	assert(rp2.getAuthor() == "Chanie Gorkin");
	assert(rp2.getBody() == "Today was the absolute worst day ever"
				"\nAnd don't try to convince me that"
				"\nThere's something good in every day"
				"\nBecause, when you take a closer look"
				"\nThis world is a pretty evil place"
				"\nEven if"
				"\nSome goodness does shine through once in a while"
				"\nSatisfaction and happiness don't last"
				"\nAnd it's not true that"
				"\nIt's all in the mind and heart"
				"\nBecause"
				"\nTrue happiness can be obtained"
				"\nOnly if one's surroundings are good"
				"\nIt's not true that good exists"
				"\nI'm sure you can agree that"
				"\nThe reality"
				"\nCreates"
				"\nMy attitude"
				"\nIt's all beyond my control"
				"\nAnd you'll never in a million years hear me say that"
				"\nToday was a good day\n\n");
	assert(rp2.getBodyReversed() == "\nToday was a good day"
				"\nAnd you'll never in a million years hear me say that"
				"\nIt's all beyond my control"
				"\nMy attitude"
				"\nCreates"
				"\nThe reality"
				"\nI'm sure you can agree that"
				"\nIt's not true that good exists"
				"\nOnly if one's surroundings are good"
				"\nTrue happiness can be obtained"
				"\nBecause"
				"\nIt's all in the mind and heart"
				"\nAnd it's not true that"
				"\nSatisfaction and happiness don't last"
				"\nSome goodness does shine through once in a while"
				"\nEven if"
				"\nThis world is a pretty evil place"
				"\nBecause, when you take a closer look"
				"\nThere's something good in every day"
				"\nAnd don't try to convince me that"
				"\nToday was the absolute worst day ever\n");
	cout << " 2 " << flush;
	cout << " Passed!" << endl;
}

void ReversePoemTester::testGetTitle() {
	cout << "Testing getTitle()..." << flush;
	//testing with cats first...
	ifstream fin1("cats.txt");
	ReversePoem rp1("cats.txt");
	string temp;
	getline(fin1, temp);
	assert(rp1.getTitle() == temp);
	assert(rp1.getTitle() == "Cats");
	cout << " 1 " << flush;
	//testing with our second poem, Worst Day Ever
	ifstream fin2("worstdayever.txt");
	ReversePoem rp2("worstdayever.txt");
	getline(fin2, temp);
	assert(rp2.getTitle() == temp);
	assert(rp2.getTitle() == "Worst Day Ever?");
	cout << " 2 " << flush;
	cout << " Passed!" << endl;
}

void ReversePoemTester::testGetAuthor() {
	cout << "Testing getAuthor()..." << flush;
	//testing with cats first...
	ifstream fin1("cats.txt");
	ReversePoem rp1("cats.txt");
	string temp;
	getline(fin1, temp);
	getline(fin1, temp);
	assert(rp1.getAuthor() == temp);
	assert(rp1.getAuthor() == "Leo J. Smada");
	cout << " 1 " << flush;
	//testing with our second poem, Worst Day Ever
	ifstream fin2("worstdayever.txt");
	ReversePoem rp2("worstdayever.txt");
	getline(fin2, temp);
	getline(fin2, temp);
	assert(rp2.getAuthor() == temp);
	assert(rp2.getAuthor() == "Chanie Gorkin");
	cout << " 2 " << flush;
	cout << " Passed!" << endl;
}

void ReversePoemTester::testGetBody() {
	cout << "Testing getBody()..." << flush;
	//testing with cats first...
	ReversePoem rp1("cats.txt");
	string temp;
	assert(rp1.getBody() == "I love it when cats rub against me.\n"
			"I could never say\nI hate those purring felines.\n\n");
	cout << " 1 " << flush;
	//testing with our second poem, Worst Day Ever
	ReversePoem rp2("worstdayever.txt");
	assert(rp2.getBody() == "Today was the absolute worst day ever"
			"\nAnd don't try to convince me that"
			"\nThere's something good in every day"
			"\nBecause, when you take a closer look"
			"\nThis world is a pretty evil place"
			"\nEven if"
			"\nSome goodness does shine through once in a while"
			"\nSatisfaction and happiness don't last"
			"\nAnd it's not true that"
			"\nIt's all in the mind and heart"
			"\nBecause"
			"\nTrue happiness can be obtained"
			"\nOnly if one's surroundings are good"
			"\nIt's not true that good exists"
			"\nI'm sure you can agree that"
			"\nThe reality"
			"\nCreates"
			"\nMy attitude"
			"\nIt's all beyond my control"
			"\nAnd you'll never in a million years hear me say that"
			"\nToday was a good day\n\n");
	cout << " 2 " << flush;
	cout << " Passed!" << endl;
}

void ReversePoemTester::testGetBodyReversed() {
	cout << "Testing getBodyReversed()..." << flush;
	//testing with cats first...
	ReversePoem rp1("cats.txt");
	string temp;
	assert(rp1.getBodyReversed() == "\nI hate those purring felines.\n"
			"I could never say\n"
			"I love it when cats rub against me.\n");
	cout << " 1 " << flush;
	//testing with our second poem, Worst Day Ever
	ReversePoem rp2("worstdayever.txt");
	assert(rp2.getBodyReversed() == "\nToday was a good day"
			"\nAnd you'll never in a million years hear me say that"
			"\nIt's all beyond my control"
			"\nMy attitude"
			"\nCreates"
			"\nThe reality"
			"\nI'm sure you can agree that"
			"\nIt's not true that good exists"
			"\nOnly if one's surroundings are good"
			"\nTrue happiness can be obtained"
			"\nBecause"
			"\nIt's all in the mind and heart"
			"\nAnd it's not true that"
			"\nSatisfaction and happiness don't last"
			"\nSome goodness does shine through once in a while"
			"\nEven if"
			"\nThis world is a pretty evil place"
			"\nBecause, when you take a closer look"
			"\nThere's something good in every day"
			"\nAnd don't try to convince me that"
			"\nToday was the absolute worst day ever\n");
	cout << " 2 " << flush;
	cout << " Passed!" << endl;
}

