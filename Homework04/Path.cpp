/*
 * Path.cpp
 *
 *  Created on: Feb 26, 2018
 *      Author: ril2
 */

#include "Path.h"

Path::Path() {
	char* path;
	path = getenv("PATH");
	if (path == NULL) {
		string errorMsg;
		perror(errorMsg.c_str());
		cerr << "Path cannot be established: " << errorMsg << endl;
	}

	istringstream iss(path);

	while (!iss.eof()) {
		string fileName;
		getline(iss, fileName, ':');

		fileNames.push_back(fileName);
	}
}

int Path::find(const string& program) const {

	for (unsigned i = 0; i < fileNames.size(); i++) {
		DIR *directory = NULL;
		directory = opendir(fileNames[i].c_str());

		if (directory == NULL) {
			string errorMsg;
			perror(errorMsg.c_str());
			cerr << "Cannot open a PATH directory to " << fileNames[i] << ": "
					<< errorMsg << endl;
			return -1;
		} else {
			dirent *info = readdir(directory);
			if (strcmp(info->d_name, program.c_str())) {
				return i;
			}
			if (closedir(directory) == -1) {
				string errorMsg;
				perror(errorMsg.c_str());
				cerr << "Cannot close directory: " << errorMsg << endl;
			}
		}
	}

	return -1;
}

string Path::getDirectory(int i) const {
	if (i >= fileNames.size() || i < 0) {
		cerr << "getDirectory(): index out of bounds error" << endl;
		return NULL;
	}
	return fileNames[i];
}
