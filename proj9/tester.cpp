
#include "BST_Tester.h"
#include "HeightChecker.h"
#include <iostream>
using namespace std;

int main() {
	BST_Tester bstt;
	bstt.runTests();	
	cout << endl << "Tests finished, running application..." << endl << endl;
	HeightChecker hc;
	hc.runHeightChecker();
}
