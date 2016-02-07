#include "song.h"
#include <iostream>

using namespace std;

class SongList{
	private:
		const static int MAX_CHAR = 100;
		const static int MAX_ARRAY = 1000;		//max number of songs to store in array
		char name[MAX_CHAR] = {'\0'};
		int counter;	//counter for number of songs in array
		Song songs[MAX_ARRAY];
		void heading();	//heading for displaying songs
	public:
		SongList();
		void add();			//add song to list
		void remove();			//remove song from list
		void display();		//display list of songs
		void searchArtist();	//search and display by artist
		void searchAlbum();		//search and display by album
		void load();			//load list from file
		void save();			//save list to file
};
