/*
 * MRShell.h
 *
 *  Created on: Mar 5, 2018
 *      Author: mrn6
 */

#ifndef MRSHELL_H_
#define MRSHELL_H_
#include "Path.h"
#include "Prompt.h"
#include "CommandLine.h"
#include <unistd.h>
#include <iostream>
#include <sstream>
#include <sys/wait.h>
using namespace std;


class MRShell {
public:
	MRShell();
	void run();
};

#endif /* MRSHELL_H_ */
