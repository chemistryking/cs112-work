/* tester.cpp drives the testing of our Vec class.
 * Student: Matthew Nykamp
 * Date: 9-27-16
 * Begun by: Joel C. Adams, for CS 112 at Calvin College.
 */

#include "VecTester.h"
#include "Application.h"

int main() {
	VecTester vt;
	vt.runTests();
	Application a;
	a.run();
}
