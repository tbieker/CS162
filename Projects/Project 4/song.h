#include <iostream>

using namespace std;

class Song{
	private:
		char* title;
		char* artist;
		char* duration;
		char* album;
		
		const static int MAX_CHAR = 100;
	public:
		Song();
		Song(const char title[MAX_CHAR], const char artist[MAX_CHAR], const char duration[MAX_CHAR], const char album[MAX_CHAR]);
		~Song();	//Destructor	
		void add(const char title[MAX_CHAR], const char artist[MAX_CHAR], const char duration[MAX_CHAR], const char album[MAX_CHAR]);
		bool compare(int select, char compared[MAX_CHAR]) const;
		void output(char outTitle[MAX_CHAR], char outArtist[MAX_CHAR], char outDuration[MAX_CHAR], char outAlbum[MAX_CHAR]) const;
		void print() const;
};
