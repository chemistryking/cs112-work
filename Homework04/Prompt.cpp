/*
 * Prompt.cpp
 *
 *  Created on: Feb 28, 2018
 *      Author: ril2
 */

#include "Prompt.h"

Prompt::Prompt() {
	char temp[100];
	string cwd = getcwd(temp, 100);

	if (getcwd == NULL)
	{
		string errorMsg;
		perror(errorMsg.c_str());
		cerr << "Prompt(): Error making prompt. " << errorMsg << endl;
	} else {
		valuePrompt = cwd;
	}
}
