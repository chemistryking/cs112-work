/* array.cpp defines "C style" array operations
 * Name:
 * Date:
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */
 
#include "array.h"

void initialize(double *a, int size) {
	int val = 0;
	for (int i = 0; i < size; i++) {
		val = i+1;
		a[i] = val;
	}
}
 
void print(double *a, int size) {
	for (int i = 0; i < size; i++) {
		cout << *a << '\t';
		a++;
	}
}		

double average(double *a, int size) {
	double average = 0;
	int index = 0;
	for (index; index < size; index++) {
			average += *a;
			a++;
		}
	return average/index;
}
