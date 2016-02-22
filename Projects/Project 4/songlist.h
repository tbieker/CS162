#ifndef SONG_H
#define SONG_H

#include "song.h"
#include <iostream>

using namespace std;

class SongList{
	private:
		const static int MAX_CHAR = 100;
		const static int SONG_LIST_SIZE = 10;
		int size; 			//size of song list
		char* name;			//name of file saved or to be saved
		Song* songs;
		int counter;			//counter for number of songs in array
		void heading();		//heading for displaying songs
		void expand();			//expand list size
	public:
		SongList();
		void add();			//add song to list
		void remove();			//remove song from list
		void display();		//display list of songs
		void searchArtist();	//search and display by artist
		void searchAlbum();		//search and display by album
		void load();			//load list from file
		void save();			//save list to file

		~SongList();			//destructor
};

#endif

