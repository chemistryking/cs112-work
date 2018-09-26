/* tester.cpp drives the testing of the Queue classes.
 * Joel Adams, for CS 112 at Calvin College.
 */

 #include "ArrayQueueTester.h"
 #include "LinkedQueueTester.h"
#include "PalDetectorTester.h"
#include "PalDetector.h"
 
 int main() {
 	ArrayQueueTester aqt;
 	aqt.runTests();
 	LinkedQueueTester lqt;
 	lqt.runTests();
 	PalDetectorTester pdt;
 	pdt.testDetection();
// 	PalDetector pd("testFile.txt", "testOutFile.txt"); //these two lines were run to verify, check the text files included
// 	pd.detectPalindromes();
 }
 
 
