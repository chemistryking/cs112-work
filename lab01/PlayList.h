/* PlayList.h declares class PlayList.
 * Student Name: Matthew Nykamp
 * Date: 09-13-16
 * Begun by: Joel Adams, for CS 112 at Calvin College.
 */

#ifndef PLAYLIST_H_
#define PLAYLIST_H_

#include <string>
#include "Song.h"
#include <vector>
using namespace std;

class PlayList {
public:
	PlayList(const string& fileName);
	unsigned getNumSongs() const;
	vector<Song> searchByArtist(const string&) const;
	vector<Song> searchByYear(const unsigned&) const;
private:
	vector<Song> mySongs;
};

#endif /*PLAYLIST_H_*/
