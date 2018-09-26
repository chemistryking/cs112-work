/* ListTester.cpp defines the test methods for class List.
 * Joel Adams, for CS 112 at Calvin College.
 * Edited By: mrn6
 */

#include "ListTester.h" // ListTester
#include "List.h"       // List
#include <iostream>     // cin, cout
#include <fstream>
#include <cassert>      // assert()
#include <cstdlib>      // exit()
#include <stdexcept>    // underflow_error
using namespace std;

void ListTester::runTests() {
	cout << "Running List tests..." << endl;
	testDefaultConstructor();
	testNodeDefaultConstructor();
	testNodeExplicitConstructor();
	testAppend();
	testDestructor();
	testCopyConstructor();
	testAssignment();
	testEquality();
	testInequality();
	testReadFromStream();
	testWriteToStream();
	testPrepend();
	testSearching();
	testInsertion();
	testDelete();
	testReadFromFile();
	testWriteToFile();
	testInsertAfter();
	testInsertBefore();
	testOutput();
	cout << "All tests passed!" << endl;
}

void ListTester::testDefaultConstructor() {
	cout << "Testing List default constructor... " << flush;
	List<double> aList;
	assert(aList.mySize == 0);
	assert(aList.myFirst == NULL);
	assert(aList.myLast == NULL);
	cout << "Passed!" << endl;
}

void ListTester::testNodeDefaultConstructor() {
	cout << "Testing Node default constructor... " << flush;
	List<double>::Node aNode;
	assert(aNode.myItem == 0);
	assert(aNode.myNext == NULL);
	cout << "Passed!" << endl;
}

void ListTester::testNodeExplicitConstructor() {
	cout << "Testing Node explicit constructor... " << flush;
	List<double>::Node n1(11, NULL);
	assert(n1.myItem == 11);
	assert(n1.myNext == NULL);
	cout << " 1 " << flush;

	List<double>::Node *n3 = new List<double>::Node(33, NULL);
	List<double>::Node n2(22, n3);
	assert(n2.myItem == 22);
	assert(n2.myNext == n3);
	cout << " 2 " << flush;
	cout << "Passed!" << endl;
}

void ListTester::testAppend() {
	cout << "Testing append()... " << flush;
	// empty List
	List<double> aList;
	assert(aList.getSize() == 0);
	assert(aList.myFirst == NULL);
	assert(aList.myLast == NULL);
	try {
		aList.getFirst();
		cerr << "getFirst() worked on empty list" << endl;
		exit(1);
	} catch (underflow_error&) {
		cout << " 0a " << flush;
	}
	try {
		aList.getLast();
		cerr << "getLast() worked on empty list" << endl;
		exit(1);
	} catch (underflow_error&) {
		cout << " 0b " << flush;
	}
	// append to empty list
	aList.append(11);
	assert(aList.getSize() == 1);
	assert(aList.myFirst != NULL);
	assert(aList.myLast == aList.myFirst);
	assert(aList.getFirst() == 11);
	assert(aList.getLast() == 11);
	assert(aList.myFirst->myNext == NULL);
	cout << " 1 " << flush;
	// append to a list containing 1 Item
	aList.append(22);
	assert(aList.getSize() == 2);
	assert(aList.myFirst != NULL);
	assert(aList.myLast != NULL);
	assert(aList.myFirst != aList.myLast);
	assert(aList.getFirst() == 11);
	assert(aList.getLast() == 22);
	assert(aList.myFirst->myNext != NULL);
	assert(aList.myLast->myNext == NULL);
	cout << " 2 " << flush;
	// append to a list containing 2 Items
	aList.append(33);
	assert(aList.getSize() == 3);
	assert(aList.myFirst != NULL);
	assert(aList.myLast != NULL);
	assert(aList.getFirst() == 11);
	assert(aList.getLast() == 33);
	assert(aList.myFirst->myNext->myItem == 22);
	assert(aList.myLast->myNext == NULL);
	cout << " 3 " << flush;
	cout << "Passed!" << endl;
}

void ListTester::testDestructor() {
	cout << "Testing destructor... " << flush;
	List<double> aList;
	aList.~List();
	assert(aList.getSize() == 0);
	assert(aList.myFirst == NULL);
	assert(aList.myLast == NULL);
	cout << " 1 " << flush;

	aList.append(11);
	aList.append(22);
	aList.append(33);
	aList.~List();
	assert(aList.getSize() == 0);
	assert(aList.myFirst == NULL);
	assert(aList.myLast == NULL);
	cout << " 2 " << flush;
	cout << "Passed!  But double-check for memory leaks!" << endl;
}

void ListTester::testCopyConstructor() {
	cout << "Testing copy constructor... " << flush;
	// copy empty list
	List<double> list1;
	List<double> list2(list1);
	assert(list2.getSize() == 0);
	assert(list2.myFirst == NULL);
	assert(list2.myLast == NULL);
	cout << " 1 " << flush;

	// copy nonempty list
	List<double> list3;
	list3.append(11);
	list3.append(22);
	list3.append(33);
	List<double> list4(list3);
	assert(list4.getSize() == 3);
	assert(list4.getFirst() == 11);
	assert(list4.getLast() == 33);
	assert(list4.myFirst->myNext->myItem == 22);
	assert(list4.myFirst != list3.myFirst);
	assert(list4.myLast != list3.myLast);
	cout << " 2 " << flush;
	cout << "Passed!" << endl;
}

void ListTester::testAssignment() {
	cout << "Testing assignment... " << flush;
	// empty to empty assignment
	List<double> list1;
	List<double> list2;
	list2 = list1;
	assert(list2.getSize() == 0);
	assert(list2.myFirst == NULL);
	assert(list2.myLast == NULL);
	cout << " 1 " << flush;

	// non-empty to empty assignment
	List<double> list3;
	list3.append(11);
	list3.append(22);
	list3.append(33);
	List<double> list4;
	list4 = list3;
	assert(list4.getSize() == 3);
	assert(list4.getFirst() == 11);
	assert(list4.getLast() == 33);
	assert(list4.myFirst->myNext->myItem == 22);
	// check that nodes are distinct
	assert(list4.myFirst != list3.myFirst);
	assert(list4.myFirst->myNext != list3.myFirst->myNext);
	assert(list4.myLast != list3.myLast);
	cout << " 2 " << flush;

	// equal-sized non-empty to non-empty assignment
	List<double> list5;
	list5.append(44);
	list5.append(55);
	list5.append(66);
	list5 = list3;
	assert(list5.getSize() == 3);
	assert(list5.getFirst() == 11);
	assert(list5.getLast() == 33);
	assert(list5.myFirst->myNext->myItem == 22);
	// check that nodes are distinct
	assert(list5.myFirst != list3.myFirst);
	assert(list5.myFirst->myNext != list3.myFirst->myNext);
	assert(list5.myLast != list3.myLast);
	cout << " 3 " << flush;

	// empty to non-empty assignment
	List<double> list6;
	list6.append(44);
	list6.append(55);
	list6.append(66);
	List<double> list7;
	list6 = list7;
	assert(list6.getSize() == 0);
	assert(list6.myFirst == NULL);
	assert(list6.myLast == NULL);
	cout << " 4 " << flush;

	// unequal-sized non-empty to non-empty assignment
	List<double> list8;
	list8.append(44);
	list8.append(55);
	list8.append(66);
	list8.append(77);
	list8 = list3;
	assert(list8.getSize() == 3);
	assert(list8.getFirst() == 11);
	assert(list8.getLast() == 33);
	assert(list8.myFirst->myNext->myItem == 22);
	// check that nodes are distinct
	assert(list8.myFirst != list3.myFirst);
	assert(list8.myFirst->myNext != list3.myFirst->myNext);
	assert(list8.myLast != list3.myLast);
	cout << " 5 " << flush;

	// assignment chaining
	List<double> list9;
	list9.append(44);
	list9.append(55);
	list9.append(66);
	list9.append(77);
	List<double> list10;
	list10 = list9 = list8;
	assert(list10.getSize() == 3);
	assert(list10.getFirst() == 11);
	assert(list10.getLast() == 33);
	assert(list10.myFirst->myNext->myItem == 22);
	cout << " 6 " << flush;

	// self-assignment (stupid, but possible)
	List<double> list11;
	list11.append(11);
	list11.append(22);
	list11.append(33);
	list11 = list11;
	assert(list11.getSize() == 3);
	assert(list11.getFirst() == 11);
	assert(list11.getLast() == 33);
	assert(list11.myFirst->myNext->myItem == 22);
	cout << " 7 " << flush;

	cout << "Passed!  But double-check for memory leaks!" << endl;
}

void ListTester::testReadFromFile() {
	cout << "Testing read from file... " << flush;
	// testing with an empty list
	List<double> list1;
	list1.readFrom("ListStream.txt");
	assert(list1.getSize() == 4);
	assert(list1.getFirst() == 11);
	assert(list1.myFirst->myNext->myItem == 22);
	assert(list1.myFirst->myNext->myNext->myItem == 33);
	assert(list1.getLast() == 44);
	cout << " 1 " << flush;

	//testing adding to an existing list
	list1.readFrom("ListStream2.txt");
	assert(list1.getSize() == 7);
	assert(list1.getFirst() == 11);
	assert(list1.myFirst->myNext->myItem == 22);
	assert(list1.myFirst->myNext->myNext->myItem == 33);
	assert(list1.myFirst->myNext->myNext->myNext->myItem == 44);
	assert(list1.myFirst->myNext->myNext->myNext->myNext->myItem == 22);
	assert(list1.myFirst->myNext->myNext->myNext->myNext->myNext->myItem == 44);
	assert(list1.getLast() == 66);
	cout << " 2 " << flush;

	cout << "Passed!" << endl;
}

void ListTester::testWriteToFile() {
	cout << "Testing write to file... " << flush;
	// testing with a copy
	List<double> list1;
	list1.readFrom("ListStream.txt");
	list1.writeTo("ListStreamCopy.txt");
	List<double> list2;
	list2.readFrom("ListStreamCopy.txt");
	assert(list2.getSize() == 4);
	assert(list2.getFirst() == 11);
	assert(list2.myFirst->myNext->myItem == 22);
	assert(list2.myFirst->myNext->myNext->myItem == 33);
	assert(list2.getLast() == 44);

	cout << "Passed!" << endl;
}

//testEquality
void ListTester::testEquality() {
	cout << "Testing Equality... " << flush;
	List<double> list1;
	list1.append(11);
	list1.append(22);
	list1.append(33);
	List<double> list2;
	list2.append(11);
	list2.append(22);
	list2.append(33);
	List<double> list3;
	List<double> list4;
	list4.append(11);
	list4.append(44);
	list4.append(22);

	// asserting list1 and list 2 are equal
	assert(list1 == list2);
	cout << " 0 " << flush;

	// non-empty to empty equality
	assert(!(list1 == list3));
	cout << " 1 " << flush;

	// testing two lists with same size but different values
	assert(list1.getSize() == list4.getSize());
	assert(!(list1.myFirst->myNext == list4.myFirst->myNext));
	assert(!(list1.myLast == list4.myLast));
	cout << " 2 " << flush;

	cout << "Passed!" << endl;
}

//testInequality
void ListTester::testInequality() {
	cout << "Testing inequality... " << flush;

	// Two Empty List
	List<double> list1;
	List<double> list2;
	assert(!(list1 != list2));
	cout << " 0 " << flush;

	// Nonempty to empty
	List<double> list3;
	list3.append(44);
	list3.append(55);
	list3.append(66);
	list3.append(77);
	assert(list3 != list1);
	cout << " 1 " << flush;

	// Two List of unequal Size with values
	List<double> list4;
	list4.append(11);
	list4.append(22);
	list4.append(66);
	list4.append(77);

	List<double> list5;
	list5.append(11);
	list5.append(22);
	list5.append(66);

	assert(list4.getSize() != list5.getSize());
	cout << " 2 " << flush;

	//Two List of Equal Size but different Last Value
	List<double> list6;
	list6.append(11);
	list6.append(22);
	list6.append(66);
	list6.append(77);

	List<double> list7;
	list7.append(11);
	list7.append(22);
	list7.append(66);
	list7.append(99);

	assert(list6.getSize() == list7.getSize());
	assert(list6.getLast() != list7.getLast());
	cout << " 3 " << flush;

	//Two List of Equal Size but different first Value
	List<double> list8;
	list8.append(11);
	list8.append(22);
	list8.append(66);
	list8.append(77);

	List<double> list9;
	list9.append(88);
	list9.append(22);
	list9.append(66);
	list9.append(77);

	assert(list8.getSize() == list9.getSize());
	assert(list8.getFirst() != list9.getFirst());
	cout << " 4 " << flush;

	//Equal Size different values but same first value
	List<double> list10;
	list10.append(11);
	list10.append(22);
	list10.append(33);
	list10.append(44);

	List<double> list11;
	list11.append(11);
	list11.append(55);
	list11.append(66);
	list11.append(77);

	assert(list10.getSize() == list11.getSize());
	assert(list10.getFirst() == list11.getFirst());
	assert(list10.myFirst->myNext != list11.myFirst->myNext);
	assert(list10.myFirst->myNext->myNext != list11.myFirst->myNext->myNext);
	assert(list10.getLast() != list11.getLast());
	cout << " 5 " << flush;

	cout << " Passed! " << endl;
}

//writeToStream test
void ListTester::testWriteToStream() {
	cout << "Testing writeTo(ostream)... " << flush;

	//creating list
	List<double> list1;
	list1.append(10);
	list1.append(11);
	list1.append(12);

	// write to an ofstream instead of cout, to automate the test
	ofstream fout("listStreamOut.txt");
	assert(fout.is_open());
	list1.writeTo(fout);
	fout.close();

	// now read in what we just wrote...
	ifstream fin("listStreamOut.txt");
	assert(fin.is_open());;
	double value;
	for (unsigned i = 0; i < 3; i++) {
		fin >> value;
		assert(value == i + 10);
	}
	cout << "Passed! See 'listStreamOut.txt' for values..." << endl;
}

//Read from stream
void ListTester::testReadFromStream() const {
	cout << "Testing readFrom(istream)... " << flush;
	// an ifstream is-an istream, so use one to automate the test
	ifstream fin("listStreamOut.txt");
	assert(fin.is_open());
	// get the size and build the List
	List<double> list;
	// test readFrom()
	list.readFrom(fin);
	assert(list.myFirst->myItem == 10);
	assert(list.myFirst->myNext->myItem == 11);
	assert(list.myFirst->myNext->myNext->myItem == 12);
	fin.close();
	cout << "Passed!" << endl;
}

/*testing the prepend method
 */
void ListTester::testPrepend() {
	cout << "Testing prepend... " << flush;

	//creating lists
	List<double> list1;
	list1.append(11);
	list1.append(22);
	list1.append(33);
	List<double> list2;

	//adding to the beginning of a non-empty list
	list1.prepend(-1);
	assert(list1.getSize() == 4);
	assert(list1.myFirst->myItem == -1);
	assert(list1.myFirst->myNext->myItem == 11);
	assert(list1.myFirst->myNext->myNext->myItem == 22);
	assert(list1.myLast->myItem == 33);
	cout << " 0 " << flush;

	//adding to the beginning of an empty list
	list2.prepend(27);
	assert(list2.myFirst->myItem == 27);
	assert(list2.myLast->myItem == 27);
	cout << " 1 " << flush;

	cout << "Passed!" << endl;

}

//Searching
void ListTester::testSearching() {
	cout << "Testing search..." << flush;

	//Create List
	List<double> list1;
	list1.append(10);
	list1.append(11);
	list1.append(12);

	int index;

	//Check the Index is pointing to the correct integer
	index = list1.getIndex(10);
	assert(index == 0);
	index = list1.getIndex(11);
	assert(index == 1);
	index = list1.getIndex(12);
	assert(index == 2);
	cout << " 0 " << flush;

	int NotHere;

	//Return -1 if NULL
	List<double> list2;
	list1.append(11);
	list1.append(22);
	list1.append(33);
	index = list1.getSize();
	NotHere = list1.getIndex(55);
	assert(NotHere == -1);
	NotHere = list1.getIndex(25);
	assert(NotHere == -1);

	cout << " 1 " << flush;

	cout << "Passed!" << endl;
}

//testing the insert method
void ListTester::testInsertion() {
	cout << "Testing insert..." << flush;

	//creating lists
	List<double> list1;
	list1.append(-1);
	list1.append(11);
	list1.append(22);
	list1.append(33);
	List<double> list2;
	List<double> list3;
	list3 = list1;

	//testing with empty list
	list2.insert(0, 0);
	assert(list2.getIndex(0) == 0);
	assert(list2.myFirst->myItem == 0);
	assert(list2.myLast->myItem == 0);

	cout << " 0 " << flush;

	//testing in the middle of a non-empty list
	list1.insert(0, 0);
	assert(list1.myFirst->myNext->myItem == -1);
	assert(list1.getIndex(0) == 0);
	assert(list1.myFirst->myItem == 0);
	assert(list1.myFirst->myNext->myNext->myItem == 11);
	assert(list1.myFirst->myNext->myNext->myNext->myItem == 22);
	assert(list1.myLast->myItem == 33);

	cout << " 1 " << flush;

	//testing in the middle of a non-empty list
	list3.insert(0, 1);
	assert(list3.myFirst->myNext->myItem == 0);
	assert(list3.getIndex(0) == 1);
	assert(list3.myFirst->myItem == -1);
	assert(list3.myFirst->myNext->myNext->myItem == 11);
	assert(list3.myFirst->myNext->myNext->myNext->myItem == 22);
	assert(list3.myLast->myItem == 33);

	cout << " 2 " << flush;

	//inserting at the end of non-empty list
	list1.insert(1, 5);
	assert(list1.myLast->myItem == 1);
	assert(list1.getIndex(1) == 5);

	cout << " 3 " << flush;

	cout << "Passed!" << endl;
}

//Deletion Test
void ListTester::testDelete() {
	cout << "Testing delete()..." << flush;

	unsigned index;

	//Remove First node and make second node myFirst
	List<double> list0;
	list0.append(11);
	list0.append(22);
	list0.append(33);

	index = list0.getIndex(11);
	assert(index == 0);
	assert(list0.remove(0));
	assert(list0.myFirst->myItem == 22);

	cout << " 0 " << flush;

	//Remove Second node and make second node myLast
	List<double> list1;
	list1.append(44);
	list1.append(55);
	list1.append(66);
	list1.append(77);

	assert(list1.getSize() == 4);
	index = list1.getIndex(77);
	assert(index == 3);
	assert(list1.remove(3));
	assert(list1.myLast->myItem == 66);
	assert(list1.myLast->myItem != 77);
	cout << " 1 " << flush;

	cout << " Passed! " << endl;

}

void ListTester::testInsertAfter() {
	cout << "testing insertAfter()..." << flush;
	//list with two items, add at end
	List<string> l1;
	l1.append("First");
	l1.append("Second");
	l1.insertAfter("Second", "Third");
	assert(l1.myFirst->myItem == "First");
	assert(l1.myFirst->myNext->myItem == "Second");
	assert(l1.myFirst->myNext->myNext->myItem == "Third");
	cout << " 0 " << flush;
	//list with two items, add at the beginning
	List<string> l2;
	l2.append("First");
	l2.append("Second");
	l2.insertAfter("First", "Middle");
	assert(l2.myFirst->myItem == "First");
	assert(l2.myFirst->myNext->myItem == "Middle");
	assert(l2.myFirst->myNext->myNext->myItem == "Second");
	cout << " 1 " << flush;

	cout << "Passed!" << endl;
}

void ListTester::testInsertBefore() {
	cout << "testing insertBefore()..." << flush;
	//list with two items, add before last item
	List<string> l1;
	l1.append("First");
	l1.append("Second");
	l1.insertBefore("Second", "Middle");
	assert(l1.myFirst->myItem == "First");
	assert(l1.myFirst->myNext->myItem == "Middle");
	assert(l1.myFirst->myNext->myNext->myItem == "Second");
	cout << " 0 " << flush;
	//list with two items, add before the first element
	List<string> l2;
	l2.append("First");
	l2.append("Second");
	l2.insertBefore("First", "Before");
	assert(l2.myFirst->myItem == "Before");
	assert(l2.myFirst->myNext->myItem == "First");
	assert(l2.myFirst->myNext->myNext->myItem == "Second");
	cout << " 1 " << flush;

	cout << "Passed!" << endl;
}

void ListTester::testOutput() {
	ofstream fout("output.txt");
	assert(fout.is_open());
	cout << "testing output()..." << flush;
	//output an empty list
	List<string> l1;
	fout << l1 << endl;
	string temp;
	ifstream fin("output.txt");
	assert(fin.is_open());
	fin >> temp;
	assert(temp == "");
	cout << " 0 " << flush;

	//output a non-empty list
	List<string> l2;
	l2.append("First");
	l2.append("Second");
	l2.append("Third");
	fout << l2 << endl;
	cout << " 1 " << flush;

	fin.close();
	fout.close();

	cout << "Passed!" << endl;
}
