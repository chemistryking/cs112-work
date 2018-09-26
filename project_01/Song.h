/* Song.h declares a class for storing song information.
 * Student Name: Matthew Nykamp
 * Date: 09-13-16
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */

#ifndef SONG_H_
#define SONG_H_

#include <string>

using namespace std;

class Song {
public:
	Song();
	Song(string, string, unsigned);
	string getTitle() const;
	string getArtist() const;
	unsigned getYear() const;
	void readFrom(istream&);
	void writeTo(ostream&) const;
	bool operator==(const Song& song2);
private:
	string myTitle;
	string myArtist;
	unsigned myYear;
};

#endif /* SONG_H_ */
