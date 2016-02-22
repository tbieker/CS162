#include "song.h"
#include <iostream>
#include <cstring>
#include <iomanip>


Song::Song(){
	title = new char[strlen("No title") + 1];
	strcpy(title, "No title");
	artist = new char[strlen("No artist") + 1];
	strcpy(artist, "No artist");
	duration = new char[strlen("No duration") + 1];
	strcpy(duration, "No duration");
	album = new char[strlen("No album") + 1];
	strcpy(album, "No album");
}

Song::Song(const char title[MAX_CHAR], const char artist[MAX_CHAR], const char duration[MAX_CHAR], const char album[MAX_CHAR]){
	this->title = new char[strlen(title) + 1];
	strcpy(this->title, title);	
	this->artist = new char[strlen(artist) + 1];
	strcpy(this->artist, artist);	
	this->duration = new char[strlen(duration) + 1];
	strcpy(this->duration, duration);
	this->album = new char[strlen(album) + 1];
	strcpy(this->album, album);
}

Song::~Song(){
	if(title != NULL){
		delete [] title;
	}
	if(artist != NULL){	
		delete [] artist;
	}
	if(duration != NULL){
		delete [] duration;
	}
	if(album != NULL){
		delete [] album;
	}
}

void Song::add(const char title[MAX_CHAR], const char artist[MAX_CHAR], const char duration[MAX_CHAR], const char album[MAX_CHAR]){
	if(this->title != NULL){
		delete [] this->title;
	}
	this->title = new char[strlen(title) + 1];
	strcpy(this->title, title);
	
	if(this->artist != NULL){
		delete [] this->artist;
	}
	this->artist = new char[strlen(artist) + 1];
	strcpy(this->artist, artist);	
	
	if(this->duration != NULL){
		delete [] this->duration;
	}
	this->duration = new char[strlen(duration) + 1];
	strcpy(this->duration, duration);
	
	if(this->album != NULL){
		delete [] this->album;
	}
	this->album = new char[strlen(album) + 1];
	strcpy(this->album, album);
}

bool Song::compare(int select, char compared[MAX_CHAR]) const{	//compare artist or album to provided string. Return true if strings are equal.
	
	//select options: 0 = artist, 1 = album
	
	switch(select){
		case 0:		//compare artist
			if(strcmp(artist, compared) == 0){	//if strings are the same, return true
				return true;
			}
		case 1:		//compare album
			if(strcmp(album, compared) == 0){	//if strings are the same, return true
				return true;
			}
	}
	return false;
}

void Song::output(char title[MAX_CHAR], char artist[MAX_CHAR], char duration[MAX_CHAR], char album[MAX_CHAR]) const{
	//return title, artist, duration and album for output to savefile
	
	strcpy(title, this->title);
	strcpy(artist, this->artist);
	strcpy(duration, this->duration);
	strcpy(album, this->album);
}

void Song::print() const{
	cout << left
		<< setw(20) << title
		<< setw(20) << artist
		<< setw(10) << duration
		<< setw(20) << album
		<< endl;
}
