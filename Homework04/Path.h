/*
 * Path.h
 * The header class for Path
 * Created on: Feb 26, 2018
 * Author: Royce Lloyd(ril2) for CS 232 at Calvin College
 */

#ifndef PATH_H_
#define PATH_H_

#include <string.h>
#include <vector>
#include <iostream>
#include <sstream>
#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
using namespace std;



class Path {
public:
	Path();
	int find(const string& program) const;
	string getDirectory(int) const;

private:
	vector<string> fileNames;
};

#endif /* PATH_H_ */
