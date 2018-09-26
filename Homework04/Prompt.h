/*
 * Prompt.h
 *
 *  Created on: Feb 28, 2018
 *      Author: ril2
 */

#ifndef PROMPT_H_
#define PROMPT_H_

#include <string>
#include <iostream>
#include <fstream>
#include <stdio.h>
#include <unistd.h>
using namespace std;

class Prompt {
public:
	Prompt();
	string get() const {return valuePrompt;};
private:
	string valuePrompt;
};

#endif /* PROMPT_H_ */
