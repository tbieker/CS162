#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "songlist.h"

using namespace std;

SongList::SongList(){
	size = SONG_LIST_SIZE;	//default size of songlist
	songs = new Song[size];
	name = NULL;
	counter = 0; //number of songs in array
}

SongList::~SongList(){
	if(songs != NULL){
		delete [] songs;
	}
	if(name != NULL){
		delete [] name;
	}
}

void SongList::add(){
	if(counter == size){
		expand();
	}
	
	//temporary char arrays to store user input
	char title[MAX_CHAR],
		 artist[MAX_CHAR],
		 duration[MAX_CHAR],
		 album[MAX_CHAR];
	
	//store user entries in temporary variables
	cout << endl;
	cout << "Enter title: ";
	cin.get(title, MAX_CHAR, '\n');
	cin.ignore(100, '\n');
	cout << "Enter artist: ";
	cin.get(artist, MAX_CHAR, '\n');
	cin.ignore(100, '\n');
	cout << "Enter duration(minutes.seconds): ";
	cin.get(duration, MAX_CHAR, '\n');
	cin.ignore(100, '\n');
	cout << "Enter album title: ";
	cin.get(album, MAX_CHAR, '\n');
	cin.ignore(100, '\n');
	cout << endl;
	
	songs[counter].add(title, artist, duration, album);
	counter++;
}

void SongList::remove(){
	int index;	//index number of song to be removed
	
	cout << "Enter index number of song to be removed: ";
	cin >> index;
	index = index - 1;	//user sees the index as starting at 1. Subtract 1 to start at correct array location
	
	while(!cin){
		cout << "Invalid number." << endl
			<< "ReEnter number: ";
		cin >> index;
	}
	
	songs[index] = songs[index + 1];
	
	for(int i = (index + 1); i < counter; i++){
		songs[i] = songs[i + 1];
	}
	
	counter--;
	cout << endl;
}

void SongList::display(){
	heading();
	
	for(int x = 0; x < counter; x++){
		cout << left << setw(10)
			<< (x + 1);			//show index of song
		songs[x].print();
	}
	cout << endl;
}

void SongList::searchArtist(){
	char artist[MAX_CHAR];
	cout << "Enter artist: ";
	cin.get(artist, MAX_CHAR, '\n');
	cin.ignore(100, '\n');
	
	heading();
	
	for(int x = 0; x < counter; x++){
		if(songs[x].compare(0, artist) == true){
			cout << left << setw(10) << (x + 1);
			songs[x].print();
		}
	}
	cout << endl;
}

void SongList::searchAlbum(){
	char album[MAX_CHAR];
	cout << "Enter album: ";
	cin.get(album, MAX_CHAR, '\n');
	cin.ignore(100, '\n');
	
	heading();
	
	for(int x = 0; x < counter; x++){
		if(songs[x].compare(1, album) == true){
			cout << setw(10) << (x + 1);
			songs[x].print();
		}
	}
}

void SongList::load(){
	counter = 0;
	char tempName[MAX_CHAR];
	cout << "Enter file name: ";
	cin.get(tempName, MAX_CHAR, '\n');
	cin.ignore(100, '\n');
	cout << endl;
	
	ifstream inFile;
	//name = strcat(name, ".txt");	//append .txt to end of file to find saved text file
	inFile.open(tempName);
	
	while(!inFile){	//return error if no file found
		cout << "File not found" << endl;
		cout << "Re-Enter file name: ";
		cin.get(tempName, MAX_CHAR, '\n');
		cin.ignore(100, '\n');
		inFile.open(tempName);
	}
	
	this->name = new char[strlen(tempName) + 1];
	strcpy(this->name, tempName);

	char input = inFile.peek();	//check for End Of Function
	
	char title[MAX_CHAR],
		artist[MAX_CHAR],
		duration[MAX_CHAR],
		album[MAX_CHAR];
	
	while(input != EOF){
		if(counter == size){
			expand();
		}
		inFile.get(title, MAX_CHAR, ';');
		inFile.ignore(100, ';');
		inFile.get(artist, MAX_CHAR, ';');
		inFile.ignore(100, ';');
		inFile.get(duration, MAX_CHAR, ';');
		inFile.ignore(100, ';');
		inFile.get(album, MAX_CHAR, '\n');
		inFile.ignore(100, '\n');
		songs[counter].add(title, artist, duration, album);
		input = inFile.peek();	//recheck for EOF. Continue if no EOF
		counter++;
	}
	
	inFile.close();
	
	cout << counter << " files loaded" << endl;	//print number of files loaded
	cout << endl;
}

void SongList::save(){
	char newName[MAX_CHAR];
	if(this->name == NULL){		//enter new save file name if no file was loaded
		cout << "Enter saved file path: ";
		cin.get(newName, 100, '\n');
		cin.ignore(100, '\n');
		while(!cin){
			cin.clear();
			cin.ignore(100, '\n');
			cout << endl;
			cout << "No path entered" << endl 
				<< "Enter valid path: ";
			cin.get(newName, 100, '\n');
			cin.ignore(100, '\n');
		}
		this->name = new char[strlen(newName) + 1];
		strcpy(this->name, newName);
		
		//name = strcat(name, ".txt");	//append .txt to end of name to create text file
	}
	
	ofstream outFile;
	outFile.open(this->name);	
	
	char title[MAX_CHAR],
		artist[MAX_CHAR],
		duration[MAX_CHAR],
		album[MAX_CHAR];
	
	for(int x = 0; x < counter; x++){	//output Song array to file in title;artist;duration;album format
		songs[x].output(title, artist, duration, album);
		outFile << title << ";" << artist << ";" 
			<< duration << ";" << album << endl;
	}
	
	outFile.close();
}

void SongList::heading(){
	cout << endl;
	cout << left;
	cout << setw(10) << "Index" 
		<< setw(20) << "Title" 
		<< setw(20) << "Artist" 
		<< setw(10) << "Duration" 
		<< setw(20) << "Album" 
		<< endl;
	cout << setw(75) << setfill('-') << '-' << endl;
	cout << setfill(' ');
}

void SongList::expand(){
	Song * temp; //temporary pointer to store previous list
	size = size * 2; //double size of list
	temp = new Song[size];
		
	char title[MAX_CHAR],
		artist[MAX_CHAR],
		duration[MAX_CHAR],
		album[MAX_CHAR];
	
	cout << "Created temp array" << endl;
	
	//copy data from old list to temp
	for(int i = 0; i < counter; i++){	
		songs[i].output(title, artist, duration, album);
		temp[i].add(title, artist, duration, album);
	}
	
	delete [] songs;
	songs = temp;
	temp = NULL;
}

