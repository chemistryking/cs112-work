/*
 * Song.cpp
 *
 *  Created on: Sep 13, 2016
 *      Author: mrn6
 */

#include <string>
#include "Song.h"
#include <fstream>
#include <cstdlib>

Song::Song() {
	myTitle = myArtist = "";
	myYear = 0;
}

Song::Song(string title, string artist, unsigned year) {
	myTitle = title;
	myArtist = artist;
	myYear = year;
}

string Song::getTitle() const {
	return myTitle;
}

string Song::getArtist() const {
	return myArtist;
}

unsigned Song::getYear() const {
	return myYear;
}

/* Song input method...
 * @param: in, an istream
 * Precondition: in contains the title, artist, and year data for a Song.
 * Postcondition: the title, artist, and year data have been read from in &&
 *                 myTitle == title &&
 *                 myArtist == artist &&
 *                 myYear == year.
 */
void Song::readFrom(istream& in) {
	getline(in, myTitle);
	getline(in, myArtist);
	string yearString;
	getline(in, yearString);
	myYear = atoi(yearString.c_str());
}

void Song::writeTo(ostream& out) const {
	out << myTitle << '\n'
	<< myArtist << '\n'
	<< myYear << '\n';
}
/* Song equals operator...
 * @param: song2, a Song
 * Precondition: Song contains an artist, title, and year.
 * Postcondition: the title, artist, and year have been compared and true will return if
 * 				  they are the same as the song we are comparing against.
 */
bool Song::operator==(const Song& song2) {
	return song2.getArtist()==getArtist() && song2.getTitle()==getTitle() && song2.getYear()==getYear();
}

