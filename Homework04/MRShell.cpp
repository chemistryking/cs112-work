/*
 * MRShell.cpp
 *
 *  Created on: Mar 5, 2018
 *      Author: mrn6
 */

#include "MRShell.h"

MRShell::MRShell() {
}

void MRShell::run() {
	bool shouldExit = false;
	extern char** environ;

	// Create the path and the prompt for the current directory
	Path *path = new Path();
	Prompt *prompt = new Prompt();

	string input = "";

	while (!shouldExit) {
		cout << "MRShell: ~" << prompt->get() << "$ " << flush;
		getline(cin, input);
		istringstream inputstream(input);

		CommandLine *cm = new CommandLine(inputstream);

		bool shouldWait = cm->noAmpersand();
		string command = cm->getCommand();

		if (command == "cd") {
			char* arg = cm->getArgVector(1);
			if (arg != NULL) {
				int ret = chdir(arg);
				if (ret == 0) {
					prompt = new Prompt();
				} else {
					cout << "Invalid path for command cd." << endl;
				}
			} else {
				// Return to default directory
				int ret = chdir("/");
				if (ret == 0) {
					prompt = new Prompt();
				} else {
					cout << "Invalid path for command cd." << endl;
				}
			}
		} else if (command == "pwd") {
			cout << prompt->get() << endl;
		} else if (command == "exit") {
			shouldExit = true;
		} else {
			int whichPath = path->find(command);

			if (whichPath != -1) {
				pid_t pid = fork();

				if (pid == 0) {
					string fullPath = path->getDirectory(whichPath) + "/"
							+ cm->getCommand();
					cout << fullPath.c_str() << endl;
					execve(fullPath.c_str(), cm->getArgVector(), environ);
				} else if (pid > 0) {
					if (shouldWait) {
						int *status = NULL;
						waitpid(pid, status, 0);
						sched_yield();
					}
				} else {
					cout << "Cannot fork a new process." << endl;
				}
			} else {
				cout
						<< "Cannot find a system program or built in function with name: "
						<< command << ". Please enter a new input." << endl;
			}
		}
	}

}
