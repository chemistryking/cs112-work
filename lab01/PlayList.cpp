/* PlayList.cpp defines the PlayList methods.
 *
 * Student Name: Matthew Nykamp
 * Date: 09-13-16
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */

#include "PlayList.h"
#include <fstream>
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
		if (mySongs[i].getYear()==year) {
			v.push_back(mySongs[i]);
		}
	}

	return v;
}
