#include "list.h"

int main()
{
	LinkedList aList;

	aList.add(3);
	aList.add(10);
	aList.add(1);
	aList.add(7);
	aList.add(9);
	aList.add(12);
	aList.printAscending();
	aList.printDescending();
	aList.remove(3);
	aList.remove(1);
	aList.remove(7);
	aList.remove(12);
	aList.printAscending();
	aList.printDescending();

	return 0;
}

