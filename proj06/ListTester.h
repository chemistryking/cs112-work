/* ListTester.h declares the test-class for class List.
 * Joel Adams, for CS 112 at Calvin College.
 */

#ifndef LISTTESTER_H_
#define LISTTESTER_H_

class ListTester {
public:
	void runTests();
	void testDefaultConstructor();
	void testNodeDefaultConstructor();
	void testNodeExplicitConstructor();
	void testAppend();
	void testDestructor();
	void testCopyConstructor();
	void testAssignment();
	void testEquality();
	void testInequality();
	void testReadFromStream() const;
	void testWriteToStream();
	void testPrepend();
	void testSearching();
	void testInsertion();
	void testDelete();
	void testReadFromFile();
	void testWriteToFile();
	void testInsertAfter();
	void testInsertBefore();
	void testOutput();
};

#endif /*LISTTESTER_H_*/
