/*
 * Application.cpp
 *
 *  Created on: Oct 10, 2016
 *      Author: Matthew Nykamp and Peter Betten
 */

#include "Application.h"
#include <iostream>
#include <cassert>
#include <fstream>
#include "Matrix.h"
using namespace std;

Application::Application() {
}

//Allows the user to run three operations on matrices defined in
//user-entered files and displays the resultant matrix
void Application::run() {
	cout << "\nWelcome to the Matrix program!\nPlease choose an operation:\n"
			<< "1. :Addition\n2. :Subtraction:\n3. :Transpose:" << endl;
	unsigned choice;
	cin >> choice;
	string fileName1, fileName2;
	cout << "Please enter the name of the file containing the first matrix: "
			<< endl;
	cin >> fileName1;
	Matrix<double> m1, m3;
	m1.readFrom(fileName1);
	if (choice == 1) {
		cout
				<< "Please enter the name of the file containing the second matrix: "
				<< endl;
		cin >> fileName2;
		Matrix<double> m2;
		m2.readFrom(fileName2);
		m3 = m1 + m2;
	} else if (choice == 2) {
		cout
				<< "Please enter the name of the file containing the second matrix: "
				<< endl;
		cin >> fileName2;
		Matrix<double> m2;
		m2.readFrom(fileName2);
		m3 = m1 - m2;
	} else if (choice == 3) {

		m3 = m1.getTranspose();
	}
	cout << "The resultant matrix is:\n[";
	for(unsigned i = 0; i < m3.getRows(); i ++) {
		for(unsigned j = 0; j < m3.getColumns(); j ++) {
			if(j != m3.getColumns()-1){
				cout << m3[i][j] << ", ";
			}
			else{
				cout << m3[i][j];
			}
		}
		if(i != m3.getRows()-1) {
			cout << endl;
		}
	}
	cout << "]" << endl;
}
