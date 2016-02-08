#include <iostream>

using namespace std;

class Song{
	private:
		const static int MAX_CHAR = 100;
		char title[MAX_CHAR];
		char artist[MAX_CHAR];
		char duration[MAX_CHAR];
		char album[MAX_CHAR];
	public:
		Song();
		void add(char newTitle[MAX_CHAR], char newArtist[MAX_CHAR], char newDuration[MAX_CHAR], char newAlbum[MAX_CHAR]);
		bool compare(int select, char compared[MAX_CHAR]) const;
		void output(char outTitle[MAX_CHAR], char outArtist[MAX_CHAR], char outDuration[MAX_CHAR], char outAlbum[MAX_CHAR]) const;
		void print() const;
};
