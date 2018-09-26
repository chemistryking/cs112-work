/*
 * CommandLine.cpp
 *
 *  Created on: Feb 23, 2018
 *  Course: CS 232 at Calvin College
 *  Author: Matthew Nykamp (mrn6)
 *
 *  CommandLine is a class which facilitates reading in arguments
 *  from the command line, designed for the shell MRShell
 */

#include "CommandLine.h"


/*
 * CommandLine initializes the command line
 * setting the argc to be the number of commands given
 * and storing each argument in a c style string inside argv
 */
CommandLine::CommandLine(istream& in) {
	string readIn;
	argc = 0;
	// Loop through just to find the argc

	while (!in.eof())
	{
		string argument;
		getline(in, argument, ' ');
		argc++;
	}

	// Return to beginning of stream
	in.seekg(0, in.beg);
	// Allocate argv now that we know what the size will be

	argv = (char**) calloc(argc + 1, sizeof(char*));
	//Declare a temp variable we will use as loop index

	int index = 0;
	// For each argument

	while (!in.eof()) {
		// Read in the next section of text until a space is found
		getline(in, readIn, ' ');

		// Allocate the necessary memory, the length of the string
		argv[index] = (char*) calloc(readIn.length() + 1, sizeof(char));

		// Copy over the string one character at a time
		for (unsigned i = 0; i < readIn.length(); i++) {
			argv[index][i] = readIn[i];
		}

		// Make argv[index] null terminating
		argv[index][readIn.length()] = '\0';

		// Increment index
		index++;
	}
	//Make argv null terminating
	argv[argc] = '\0';
}

/*
 * getCommand returns the name of the first argument given
 * or the name of the command
 */
char* CommandLine::getCommand() const {
	if (argv != NULL)		//Ensure that we have something to return
	{
		return argv[0];
	} else {
		return NULL;
	}
}

/*
 * getArgVector returns the ith argument passed into the command line
 */
char* CommandLine::getArgVector(int i) const {
	if (argv != NULL)		//Ensure that we have something to return
	{
		if (i > argc - 1) {
			return NULL;
		} else {
			return argv[i];
		}
	} else {
		return NULL;
	}
}
/*
 *
 * noAmpersand returns true if the constructed command line contains no ampersand
 * otherwise, returns false;
 */
bool CommandLine::noAmpersand() const {
	// Loop through all arguments after the command
	for (int i = 1; i < argc; i++) {
		if (*argv[i] == '&') {
			return false;
		}
	}
	return true;
}

/*
 * ~CommandLine deallocates the allocated memory in argv
 */
CommandLine::~CommandLine() {
	int index = 0;
	while (argv[index] != '\0')
	{
		free(argv[index]);
	}
	free(argv);
}

