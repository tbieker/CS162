#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstring>
#include "songlist.h"

using namespace std;

SongList::SongList(){
	counter = 0;
}

void SongList::add(){
	char title[MAX_CHAR], artist[MAX_CHAR], duration[MAX_CHAR], album[MAX_CHAR];
	
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
	
	for(int x = index; x < counter; x++){	//shift all entries in array to left and overwrite intended song to be removed
		songs[x] = songs[x + 1];
	}
	counter--;	//decrement counter by 1
	
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
	
	cout << "Enter file name: ";
	cin.get(name, MAX_CHAR, '\n');
	cin.ignore(100, '\n');
	cout << endl;
	
	ifstream inFile;
	//name = strcat(name, ".txt");	//append .txt to end of file to find saved text file
	inFile.open(name);
	
	while(!inFile){	//return error if no file found
		cout << "File not found" << endl;
		cout << "Re-Enter file name: ";
		cin.get(name, MAX_CHAR, '\n');
		cin.ignore(100, '\n');
		inFile.open(name);
	}
	
	char input = inFile.peek();	//check for End Of Function
	
	char title[MAX_CHAR];
	char artist[MAX_CHAR];
	char duration[MAX_CHAR];
	char album[MAX_CHAR];	
	
	while(input != EOF){
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
	if(name[0] == '\0'){		//enter new save file name if no file was loaded
		cout << "Save file as: ";
		cin.get(name, 100, '\n');
		cin.ignore(100, '\n');
		while(!cin){
			cin.clear();
			cin.ignore(100, '\n');
			cout << endl;
			cout << "No name entered" << endl 
				<< "Enter valid name: ";
			cin.get(name, 100, '\n');
			cin.ignore(100, '\n');
		}
		//name = strcat(name, ".txt");	//append .txt to end of name to create text file
	}
	
	ofstream outFile;
	outFile.open(name);
	
	char title[MAX_CHAR];
	char artist[MAX_CHAR];
	char duration[MAX_CHAR];
	char album[MAX_CHAR];	
	
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

