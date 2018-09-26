/* PlayList.cpp defines the PlayList methods.
 *
 * Student Name: Matthew Nykamp
 * Date: 09-13-16
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */

#include "PlayList.h"
#include <fstream>
#include <iostream>
#include <cassert>
using namespace std;

/* PlayList constructor
 * @param: fileName, a string
 * Precondition: fileName contains the name of a playlist file.
 */
PlayList::PlayList(const string& fileName) {
	// open a stream to the playlist file
	ifstream fin(fileName.c_str());
	assert(fin.is_open());

	// read each song and append it to mySongs
	Song s;
	while (true) {
		s.readFrom(fin);
		if (!fin) {
			break;
		}
		string separator;
		getline(fin, separator);
		mySongs.push_back(s);
	}

	// close the stream
	fin.close();
}

/* Retrieve length of the playlist
 * Return: the number of songs in the playlist.
 */
unsigned PlayList::getNumSongs() const {
	return mySongs.size();
}

vector<Song> PlayList::searchByArtist(const string& artist) const {
	vector<Song> v;

	for (unsigned i = 0; i < mySongs.size(); i++) {
		if (mySongs[i].getArtist().find(artist) != string::npos) {
			v.push_back(mySongs[i]);
		}
	}

	return v;
}

/*Returns all songs that were made in  the integer year, the year that was passed in.
 *
 */
vector<Song> PlayList::searchByYear(const unsigned& year) const {
	vector<Song> v;

	for (unsigned i = 0; i < mySongs.size(); i++) {
		if (mySongs[i].getYear() == year) {
			v.push_back(mySongs[i]);
		}
	}

	return v;
}

/*Returns all songs in the playlist that have phrase, an argument, anywhere in their title.
 *
 */
vector<Song> PlayList::searchByTitlePhrase(const string& phrase) const {
	vector<Song> v;

	for (unsigned i = 0; i < mySongs.size(); i++) {
		if (mySongs[i].getTitle().find(phrase) != string::npos) {
			v.push_back(mySongs[i]);
		}
	}

	return v;
}

/* Adds a song, which is passed in, to the playlist.
 *
 */
void PlayList::addSong(const Song& newSong) {
	mySongs.push_back(newSong);
}

/*  Precondition: There is a song in the playlist with the title, artist, and year as the song passed in.
 *  Postcondition: The first instance of the matching song is removed from the playlist.
 */
void PlayList::removeSong(const Song& aSong) {
	for (unsigned i = 0; i < mySongs.size(); i++) {
		if (mySongs[i] == aSong) {
			mySongs.erase(mySongs.begin() + i);
		}
	}
}

//Saves the playlist to a target file named "name", each song with three lines: first the title, then the artist, then the year.

void PlayList::save(const string& name) {
	ofstream fout(name.c_str());
	assert(fout.is_open());

	for (unsigned i = 0; i < mySongs.size(); i++) {
		fout << mySongs[i].getTitle() << endl;
		fout << mySongs[i].getArtist() << endl;
		fout << mySongs[i].getYear() << endl;
		fout << endl;
	}
}

//Gets the song at index i from the playlist
Song PlayList::getSong(const unsigned& index) {
	return mySongs[index];
}
