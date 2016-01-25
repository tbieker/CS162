#include "list.h"
#include <iostream>
using namespace std;

bool insert(int val, int intList[], int& size)
{
	//insert your code here and modify the following line
	if(size == 0){			//if list contains zero numbers, add to list
		intList[size] = val;
		size++;
		return true;
	}
	for(int x = 0; x < size; x++){
		if(val == intList[x]){
			break;		//return false if value is already in list
		}else if(val > intList[x]){
			if(x == (size - 1)){	//if x has reached end of list, append val to end of list
				intList[x + 1] = val;
				size++;
				return true;
			}
			continue;
		}else if(val < intList[x]){			
			for(int y = size; y > x; y--){	//shift all items in array up one from x
				intList[y] = intList[y - 1];
			}
			intList[x] = val;
			size++;
			return true;
		}
	}
	return false;
}

bool remove(int val, int intList[], int& size)
{
	//insert your code here and modify the following line
	for(int x = 0; x < size; x++){
		if(val == intList[x]){
			for(int y = x; y < size; y++){
				intList[y] = intList[y + 1];
			}
			size--;
			return true;
		}
	}
	return false;
}

void print(const int intList[], int size)
{
	cout << endl << "[ ";
	for(int i=0; i<size; i++)
	{
		cout << intList[i] << " ";
	}
	cout << "]" << endl;
}



