#include <iostream>
#include <cstring>							//added <cstring> header for strcpy used 
using namespace std;

const int MAX_CHAR = 100;
const int MIN_A = 90;
const int MIN_B = 80;
const int MIN_C = 70;

double getAvg();
char determineGrade(double finalAvg);			//added finalAvg after double
void printMsg(char grade);

int main()
{
	double score;							//fixed tabbed spacing
	char	grade;

	score = getAvg();
	grade = determineGrade(score);			//fixed spelling of determineGrade
	printMsg(grade);

	return 0;
}

double getAvg()
{
	double finalAvg;

	cout << "Please enter your final average: ";
	cin >> finalAvg;
	while(!cin)
	{
		cin.clear();
		cin.ignore(MAX_CHAR, '\n');
		cout << "input has to be numerical!" << endl;
		cin >> finalAvg;
	}
	cin.ignore(MAX_CHAR, '\n');
	return finalAvg;
}
char determineGrade(double finalAvg)	//fixed spelling of determineGrade
{
	char grade = 'F';	
	if(finalAvg >= MIN_A)
	{
		grade = 'A';	
	}
	else if(finalAvg >= MIN_B)
	{
		grade = 'B';
	}
	else if(finalAvg >= MIN_C);
	{
		grade = 'C';
	}

	return grade;
}
void printMsg(char grade)
{
	char	msg[MAX_CHAR];
	switch(grade)
	{
		case 'A':
			strcpy(msg, "Excellent!");
			break;
		case 'B':
			strcpy(msg, "Good job!");
			break;
		case 'C':
			strcpy(msg, "You've passed!");
			break;
		default:
			strcpy(msg, "Need to put down that video game!");
			break;
	}
	cout << msg << endl;
}
