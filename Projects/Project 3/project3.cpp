//Author: Tyler Bieker
//Class: Computer Science 162
//Assignment: Project 3
//Date: 02/03/2016
//Sources:

#include <iostream>
#include "songlist.h"

using namespace std;

int main(){
	char menuSelect;	//variable to hold user's selection from menus
	SongList collection;
	
	//choose option to create new database file or load database
	cout << "Tyler's music library" << endl;
	cout << "Please select option: " << endl;
	cout << "0: New database" << endl;
	cout << "1: Load database" << endl;
	cout << ": ";
	
	cin >> menuSelect;
	cin.ignore(100, '\n');
	
	switch(menuSelect){
		case '0':	//new database
			break;
		case '1':	//load database
			collection.load();
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
		cin.ignore(100, '\n');
		
		switch(menuSelect){
			case '1':	//add
				collection.add();
				break;
			case '2':	//display
				collection.display();
				break;
			case '3':	//remove
				collection.remove();
				break;
			case '4':	//search artist
				collection.searchArtist();
				break;
			case '5':	//search album
				collection.searchAlbum();
				break;
			case '6':	//quit
				collection.save();
				return 0;
			default:	//default if user input wrong selection                           
				cout << "Invalid selection." << endl;
		}
	}
}



