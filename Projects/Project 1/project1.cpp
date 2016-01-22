//Author: Tyler Bieker
//Class: Computer Science 162
//Assignment: Project 1
//Date: 01/08/2016
//Sources: www.stackoverflow.com

#include <iostream>
#include <iomanip>

using namespace std;

const int MAX_CHAR = 101;
const int MAX_ARRAY_STORAGE = 1000;

void initializeArray(double array[], int &counter);		//initiallize array to empty
void enterProduct(char productName[][MAX_CHAR], double productCost[], int &counter);	//enter product name and cost
void checkout(char productName[][MAX_CHAR], double productPrice[], int counter);		//display grand total of entries

int main(){
	double productCost[MAX_ARRAY_STORAGE];	//array to store the cost of each product
	char productName[MAX_ARRAY_STORAGE][MAX_CHAR]; //array to store the product name
	int counter = 0; //number of products entered
	bool menu = true;
	char selection;
	
	initializeArray(productCost, counter);	//zero the array
	
	cout << "Shopping cart calculator" << endl;
	cout << "Please select option" << endl;
	
	while(menu = true){
		cout << "1: Enter product" << endl;
		cout << "2: Check out" << endl;		//display total for all entries
		cout << "3: Start over" << endl;	//erase all entries and restart
		cout << "4: Quit" << endl;	//quit the program
		cout << ":";
		cin >> selection;
	
		switch(selection){
			case '1':	//enter product
				enterProduct(productName, productCost, counter);
				break;
			case '2':	//check out
				checkout(productName, productCost, counter);
				return 0;
			case '3':	//start over, erase all previous entries, and set counter to zero
				initializeArray(productCost, counter);
				break;
			case '4':	//quit program
				return 0;
			default:
				cout << "Invalid selection" << endl << "Please select again" << endl;
				break;
		}
	}
}

void initializeArray(double array[], int &counter){ //initiallize array to zero
	for(int x = 0; x < 1000; x++){
		array[x] = 0;
	}
	counter = 0; //reset counter to zero
}

void enterProduct(char productName[][MAX_CHAR], double productCost[], int &counter){
	//char productName[MAX_CHAR];
	
	cout << "Enter name of product: ";
	cin.ignore(100, '\n');	//ignore newline character from result of previous inputs
	cin.get(productName[counter], MAX_CHAR, '\n');
	cin.ignore(100, '\n');
	cout << endl;
	cout << "Enter cost: ";
	cin >> productCost[counter];
	
	if(!cin){	//if user does not enter integer value, clear failed input and prompt for reentry
		cin.clear();
		cin.ignore(100, '\n');
		cout << "That is not a valid number. Reenter price: ";
		cin >> productCost[counter];
	}
	
	cout << endl;
	cout << "You entered " << productName[counter] << " at a cost of $" << productCost[counter] << endl << endl;
	counter = counter + 1;	//increment counter for next input in array
}

void checkout(char productName[][MAX_CHAR], double productPrice[], int counter){	//add all numbers in the array and display the grand total
	double total = 0;
	
	for(int x = 0; x < counter; x++){	//add the items in the array
		total = total + productPrice[x];
	}
	
	cout.setf(ios::fixed, ios::floatfield);
	cout.setf(ios::showpoint);
	cout.precision(2);
	
	//heading to receipt format of display
	cout << endl;
	cout << left << setw(30) << "Name" << right << setw(10) << "Price" << endl;
	cout << left << setw(40) << setfill('=') << '=' << endl;
	
	//display all products in array in formatted line
	for(int i = 0; i < counter; i++){	
		cout << left << setfill('.') << setw(30) << productName[i] << right << setw(10) << productPrice[i] << endl;
	}
	
	cout << right << setfill(' ') << setw(30) << "The grand total is: $" << setw(10) << total << endl;
	cout << "Enter q to quit:";
	
	//Stop checkout display from flashing
	char reply;
	cin >> reply;
}

