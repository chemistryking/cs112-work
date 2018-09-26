/* A class designed to accomodate a loop through which the user enters input in order to manage playlist.
 * application.cpp
 *
 *  Created on: Sep 17, 2016
 *      Author: Matthew Nykamp
 */

#include "Application.h"
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

/* Application constructor
 * Postcondition: bool IsRunning is false, uses file fileName to get the playlist.
 */
Application::Application(const string& fileName) {
	isRunning = false;
	file = fileName;
}
/* This method takes no arguments and instead makes a loop, only ended by entering 0.
 * It has options to search a playlist by either artist, year, or by phrase,
 * to add or remove a song, or to save the playlist to a file.
 *
 */

void Application::start() {
	PlayList pList(file.c_str());

	isRunning = true;
	cout << "Welcome to the Playlist Manager!" << endl;
	cout << "Please enter your selection: " << endl << endl;
	int choice;

	while (isRunning) {
		cout << endl << "1:  Search playlist for songs by artist " << endl;
		cout << "2:  Search playlist for songs by year " << endl;
		cout
				<< "3:  Search playlist for songs with a given phrase in their title "
				<< endl;
		cout << "4:  Add a song to the playlist " << endl;
		cout << "5:  Remove a song from the playlist " << endl;
		cout << "6:  Save the playlist" << endl;
		cout << "0:  Quit " << endl << endl;

		cin >> choice;
		cin.ignore(100,'\n');
		while (!(choice == 0 || choice == 1 || choice == 2 || choice == 3
				|| choice == 4 || choice == 5 || choice == 6)) {
			cout << "Please enter a number between 0 and 6." << endl;
			cin >> choice;
			cin.ignore(100,'\n');
		}
		if (choice == 0) {
			isRunning = 0;
		} else if (choice == 1) {
			cout << "Please enter one word in the name of the artist: " << endl;
			string artist;
			cin >> artist;
			cin.ignore(100,'\n');
			vector<Song> artistSearch = pList.searchByArtist(artist);
			for (unsigned i = 0; i < artistSearch.size(); i++) {
				cout << artistSearch[i].getTitle() << " by "
						<< artistSearch[i].getArtist() << " released in "
						<< artistSearch[i].getYear() << endl;
			}
		} else if (choice == 2) {
			cout << "Please enter the year a song was released: " << endl;
			unsigned year;
			cin >> year;
			cin.ignore(100,'\n');
			vector<Song> yearSearch = pList.searchByYear(year);
			for (unsigned i = 0; i < yearSearch.size(); i++) {
				cout << yearSearch[i].getTitle() << " by "
						<< yearSearch[i].getArtist() << " released in "
						<< yearSearch[i].getYear() << endl;
			}
		} else if (choice == 3) {
			cout << "Please enter a keyword to search by title: " << endl;
			string keyword;
			cin >> keyword;
			cin.ignore(100,'\n');
			vector<Song> keywordSearch = pList.searchByTitlePhrase(keyword);
			for (unsigned i = 0; i < keywordSearch.size(); i++) {
				cout << keywordSearch[i].getTitle() << " by "
						<< keywordSearch[i].getArtist() << " released in "
						<< keywordSearch[i].getYear() << endl;
			}
		} else if (choice == 4) {
			string songName, artistName;
			cout << "Please enter the name of the song to be added: " << endl;
			getline(cin, songName);
			unsigned date;
			cout << "Please enter the date the song was released: " << endl;
			cin >> date;
			cin.ignore(100,'\n');
			cout << "Please enter the artist of the song to be added: " << endl;
			getline(cin, artistName);
			Song newSong(songName, artistName, date);
			pList.addSong(newSong);
		} else if (choice == 5) {
			string songName, artistName;
			cout << "Please enter the name of the song to be removed: " << endl;
			getline(cin, songName);
			cout << "Please enter the artist of the song to be removed: "
					<< endl;
			getline(cin, artistName);
			unsigned date;
			cout << "Please enter the date the song was released: " << endl;
			cin >> date;
			cin.ignore(100,'\n');
			Song newSong(songName, artistName, date);
			pList.removeSong(newSong);
		} else if (choice == 6) {
			cout << "Enter the name of the file you would like to save it in: "
					<< endl;
			string saveName;
			cin >> saveName;
			cin.ignore(100,'\n');
			pList.save(saveName);
			cout << "File was saved." << endl;
		}
	}

}

