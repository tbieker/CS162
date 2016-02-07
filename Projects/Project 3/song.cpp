#include "song.h"
#include <iostream>
#include <cstring>
#include <iomanip>

Song::Song(){	//initialize char arrays to null
	for(int x = 0; x < MAX_CHAR; x++){
		title[x] = {'\0'};
		artist[x] = {'\0'};
		duration[x] = {'\0'};
		album[x] = {'\0'};
	}
}

void Song::add(char newTitle[MAX_CHAR], char newArtist[MAX_CHAR], char newDuration[MAX_CHAR], char newAlbum[MAX_CHAR]){
	strcpy(title, newTitle);
	strcpy(artist, newArtist);
	strcpy(duration, newDuration);
	strcpy(album, newAlbum);
}

bool Song::compare(int select, char info[MAX_CHAR]) const{
	
	//select options: 0 = artist, 1 = album
	
	if(select == 0){
		if(strcmp(artist, info) == 0){	//if strings are the same, return true
			return true;
		}else{
			return false;
		}
	}
	if(select == 1){
		if(strcmp(album, info) == 0){	//if strings are the same, return true
			return true;
		}else{
			return false;
		}
	}
}

void Song::print() const{
	cout << left
		<< setw(20) << title
		<< setw(20) << artist
		<< setw(10) << duration
		<< setw(20) << album
		<< endl;
}

void Song::output(char outTitle[MAX_CHAR], char outArtist[MAX_CHAR], char outDuration[MAX_CHAR], char outAlbum[MAX_CHAR]){
	strcpy(outTitle, title);
	strcpy(outArtist, artist);
	strcpy(outDuration, duration);
	strcpy(outAlbum, album);
}
