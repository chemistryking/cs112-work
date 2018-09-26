/* tester.cpp drives the testing of our Vec template and Matrix class.
 * Student: Matthew Nykamp
 * Date: 10-04-16
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
 */

#include "MatrixTester.h"
#include "Application.h"

int main() {
//	VecTester vt;
//	vt.runTests();
	MatrixTester mt;
	mt.runTests();
	Application a;
	a.run();
}
