/* main.cpp tests the classes in our project (lab01).
 * Student Name: Matthew Nykamp
 * Date: 09-13-16
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */

#include "SongTester.h"
#include "PlayListTester.h"
#include "Application.h"

int main() {
	SongTester sTester;
	//sTester.runTests();
	PlayListTester plTester;
	//plTester.runTests();
	Application app("testSongs.txt");
	app.start();
}

