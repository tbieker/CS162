#include <iostream>
#include <iomanip>
using namespace std;

int main()
{

	int ** table;

	int rows = 10;

	//write code here to allocate memory for the table
	
	table = new int* [rows];			//initialize rows
	for(int i = 0; i < rows; i++){
		table[i] = new int[i + 1];		//initialize columns
		}

	//write code here to populate it with required integers
	
	for(int row = 0; row < rows; row++){
		for(int col = 0; col < row; col++){
			table[row][col] = col;
			}
		}

	//write code here to print the table

	for(int row = 0; row < rows; row++){
		for(int col = 0; col < row; col++){
			cout << left << setw(2);
			cout << table[row][col];
			}
			cout << endl;
		}

	//write code here to deallocate memory for the table
	for(int x = 0; x < rows; x++){
		delete [] table[x];
	}
	delete [] table;
	
	return 0;
}

