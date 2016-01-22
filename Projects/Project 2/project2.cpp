//Author: Tyler Bieker
//Class: Computer Science 162
//Assignment: Project 2
//Date: 01/16/2015
//Sources: www.cplusplus.com

#include <iostream>
#include <iomanip>
#include <fstream>
#include <cstring>

using namespace std;

const int MAX_CHAR = 100;	//Maximum size for character strings
const int MAX_ARRAY = 1000;	//Maximum array size

struct Song{
	char songTitle[MAX_CHAR];
	char songArtist[MAX_CHAR];
	char songDuration[MAX_CHAR];			//song duration in minutes
	char albumTitle[MAX_CHAR];
};

void addSong(Song library[MAX_ARRAY], int& count);		//add song to database
void displayDatabase(Song library[MAX_ARRAY], int count);	//display all song data in database
void removeSong(Song library[MAX_ARRAY], int& count);		//remove song from database
void searchArtist(Song library[MAX_ARRAY], int count);		//search for songs by artist
void searchAlbum(Song library[MAX_ARRAY], int count);		//search for songs by album
void loadDatabase(char dbName[MAX_CHAR], Song library[MAX_ARRAY], int& count); 	//load database from file
void saveDatabase(char dbName[MAX_CHAR], Song library[MAX_ARRAY], int count);	//output database to file

int main(){
	char dbName[MAX_CHAR] = {'\0'};	//working database filename initialized to empty
	Song songLibrary[MAX_ARRAY];	//array to hold song information
	int count = 0;		//counter for number of files in array
	char menuSelect;	//variable to hold user's selection from menus
	
	//choose option to create new database file or load database
	cout << "Tyler's music library" << endl;
	cout << "Please select option: " << endl;
	cout << "0: New database" << endl;
	cout << "1: Load database" << endl;
	cout << ": ";
	
	cin >> menuSelect;
	
	switch(menuSelect){
		case '0':	//new database
			//cout << "Enter name of new database: ";
			//cin >> dbName;
			break;
		case '1':	//load database
			loadDatabase(dbName, songLibrary, count);
			break;
		default:
			break;
	}
	
	//Primary menu. Continues until users exits by 'Save and Quit' option
	while(true){
		cout << "Select option: " << endl;
		cout << "1: Add song" << endl;
		cout << "2: Display all songs" << endl;
		cout << "3: Remove song" << endl;
		cout << "4: Search by artist" << endl;
		cout << "5: Search by album" << endl;
		cout << "6: Save and quit" << endl;
		cout << ": ";
		
		cin >> menuSelect;
		
		switch(menuSelect){
			case '1':	//add
				addSong(songLibrary, count);
				break;
			case '2':	//display
				displayDatabase(songLibrary, count);
				break;
			case '3':	//remove
				removeSong(songLibrary, count);
				break;
			case '4':	//search artist
				searchArtist(songLibrary, count);
				break;
			case '5':	//search album
				searchAlbum(songLibrary, count);
				break;
			case '6':	//quit
				saveDatabase(dbName, songLibrary, count);
				return 0;
			default:	//default if user input wrong selection                           
				cout << "Invalid selection." << endl;
		}
	}
}

void addSong(Song library[MAX_ARRAY], int& count){
	cout << endl;
	
	cin.clear();			//clear previous input stream
	cin.ignore(100, '\n');
	
	cout << "Enter title: ";
	cin.get(library[count].songTitle, MAX_CHAR, '\n');
	cin.ignore(100, '\n');
	cout << "Enter artist: ";
	cin.get(library[count].songArtist, MAX_CHAR, '\n');
	cin.ignore(100, '\n');
	cout << "Enter duration(minutes.seconds): ";
	cin.get(library[count].songDuration, MAX_CHAR, '\n');
	cin.ignore(100, '\n');
	cout << "Enter album title: ";
	cin.get(library[count].albumTitle, MAX_CHAR, '\n');
	cin.ignore(100, '\n');
	cout << endl;
	count++;
}	

void displayDatabase(Song library[MAX_ARRAY], int count){
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
	
	for(int x = 0; x < count; x++){
		cout << setw(10) << (x + 1)	//Increment the index so that the index is displayed to the user as starting at 1
			<< setw(20) << library[x].songTitle
			<< setw(20) << library[x].songArtist
			<< setw(10) << library[x].songDuration
			<< setw(20) << library[x].albumTitle
			<< endl;
	}
	cout << endl;
}

void removeSong(Song library[MAX_ARRAY], int& count){
	int index;	//index number of song to be removed
	
	cout << "Enter index number of song to be removed: ";
	cin >> index;
	index = index - 1;	//user sees the index as starting at 1. Subtract 1 to start at correct array location
	
	while(!cin){
		cout << "Invalid number." << endl
			<< "ReEnter number: ";
		cin >> index;
	}
	
	for(int x = index; x < count; x++){	//shift all entries in array to left and overwrite intended song to be removed
		library[x] = library[x + 1];
	}
	count--;	//decrement counter by 1
	
	cout << endl;
}
		
void searchArtist(Song library[MAX_ARRAY], int count){
	char artist[MAX_CHAR];
	
	cin.clear();
	cin.ignore(100, '\n');
	
	cout << "Enter artist: ";
	cin.get(artist, MAX_CHAR, '\n');
	cin.ignore(100, '\n');
	
	cout << left;
	cout << setw(5) << "Index" 
		<< setw(20) << "Title" 
		<< setw(20) << "Artist" 
		<< setw(10) << "Duration" 
		<< setw(20) << "Album" 
		<< endl;
	cout << setw(75) << setfill('-') << '-' << endl;
	cout << setfill(' ');
	
	for(int x = 0; x < count; x++){
		if(strcmp(artist, library[x].songArtist) == 0){
			cout << setw(5) << x
				<< setw(20) << library[x].songTitle
				<< setw(20) << library[x].songArtist
				<< setw(10) << library[x].songDuration
				<< setw(20) << library[x].albumTitle
				<< endl;
		}
	}
}
	
void searchAlbum(Song library[MAX_ARRAY], int count){
	char album[MAX_CHAR];
	
	cin.clear();
	cin.ignore(100, '\n');
	
	cout << "Enter album: ";
	cin.get(album, MAX_CHAR, '\n');
	cin.ignore(100, '\n');
	
	cout << left;
	cout << setw(5) << "Index" 
		<< setw(20) << "Title" 
		<< setw(20) << "Artist" 
		<< setw(10) << "Duration" 
		<< setw(20) << "Album" 
		<< endl;
	cout << setw(75) << setfill('-') << '-' << endl;
	cout << setfill(' ');
	
	for(int x = 0; x < count; x++){
		if(strcmp(album, library[x].albumTitle) == 0){
			cout << setw(5) << x
				<< setw(20) << library[x].songTitle
				<< setw(20) << library[x].songArtist
				<< setw(10) << library[x].songDuration
				<< setw(20) << library[x].albumTitle
				<< endl;
		}
	}
}
		
void loadDatabase(char dbName[MAX_CHAR], Song library[MAX_ARRAY], int& count){	//load data into array from file input by user
	cout << "Enter file name: ";
	cin >> dbName;
	cout << endl;
	
	ifstream inFile;
	dbName = strcat(dbName, ".txt");	//append .txt to end of file to find saved text file
	inFile.open(dbName);
	
	while(!inFile){	//return error if no file found
		cout << "File not found" << endl;
		cout << "Re-Enter file name: ";
		cin >> dbName;
		inFile.open(dbName);
	}
	
	char input = inFile.peek();	//check for End Of Function
	
	while(input != EOF){
		inFile.get(library[count].songTitle, MAX_CHAR, ';');
		inFile.ignore(100, ';');
		inFile.get(library[count].songArtist, MAX_CHAR, ';');
		inFile.ignore(100, ';');
		inFile.get(library[count].songDuration, MAX_CHAR, ';');
		inFile.ignore(100, ';');
		inFile.get(library[count].albumTitle, MAX_CHAR, '\n');
		inFile.ignore(100, '\n');
		input = inFile.peek();	//recheck for EOF. Continue if no EOF
		count++;		
	}
	
	inFile.close();
	
	cout << count << " files loaded" << endl;	//print number of files loaded
	cout << endl;
}	

void saveDatabase(char dbName[MAX_CHAR], Song library[MAX_ARRAY], int count){	//export array to file
	if(dbName[0] == '\0'){		//enter new save file name if no file was loaded
		cout << "Save file as: ";
		cin.clear();
		cin.ignore(100, '\n');
		cin.get(dbName, 100, '\n');
		while(!cin){
			cin.clear();
			cin.ignore(100, '\n');
			cout << endl;
			cout << "No name entered" << endl 
				<< "Enter valid name: ";
			cin.get(dbName, 100, '\n');
		}
		dbName = strcat(dbName, ".txt");	//append .txt to end of name to create text file
	}
	
	ofstream outFile;
	outFile.open(dbName);
	
	for(int x = 0; x < count; x++){	//output Song array to file in title;artist;duration;album format
		outFile << library[x].songTitle << ";" << library[x].songArtist << ";" 
			<< library[x].songDuration << ";" << library[x].albumTitle << endl;
	}
	
	outFile.close();
}





