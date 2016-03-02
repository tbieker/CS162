//put your implementation of LinkedList class here

#include <iostream>
#include "list.h"

using namespace std;

LinkedList::LinkedList(){
	head = NULL;
	tail = NULL;
}

bool LinkedList::add(int val){
	Node * curr;
	Node * newNode = new Node();
	newNode->data = val;
	
	//if entry is first of list
	if(head == NULL){
		newNode->next = NULL;
		newNode->prev = NULL;
		head = newNode;
		tail = newNode;
		
		return true;
	}
	
	//if data is less than head data, enter before head and move head
	if(newNode->data < head->data){
		newNode->next = head;
		newNode->prev = NULL;
		head->prev = newNode;
		head = newNode;
		
		return true;
	}
	
	curr = head;
	
	//search through list and enter data
	while(curr != NULL){
		//if data already exists in list, return false
		if(newNode->data == curr->data){
			return false;
		}
		
		//search and enter data in ascending order
		if(newNode->data < curr->data){
			newNode->next = curr;
			newNode->prev = curr->prev;
			curr->prev->next = newNode;
			curr->prev = newNode;
			
			return true;
		}
		
		curr = curr->next;
	}
	
	//if reached end of list, put node at tail
	newNode->next = NULL;
	newNode->prev = tail;
	newNode->prev->next = newNode;
	tail = newNode;
		
	return true;
}

bool LinkedList::remove(int val){
	Node * curr;
	
	//remove head value
	if(head->data == val){
		curr = head->next;
		curr->prev = NULL;
		delete head;
		head = curr;
		
		return true;
	}
	
	//remove tail value
	if(tail->data == val){
		curr = tail->prev;
		curr->next = NULL;
		delete tail;
		tail = curr;
		
		return true;
	}
	
	//search list and remove value
	curr = head;
	
	while(curr != NULL){
		if(curr->data == val){
			curr->next->prev = curr->prev;
			curr->prev->next = curr->next;
			
			delete curr;
			return true;
		}
		curr = curr->next;
	}
	
	//value not found
	return false;
}


void LinkedList::printAscending() const{	
	Node * curr;
	curr = head;
	
	while(curr != NULL){
		cout << curr->data << endl;
		curr = curr->next;
	}
	cout << endl;
}


void LinkedList::printDescending() const{
	Node * curr;
	curr = tail;
	
	while(curr != NULL){
		cout << curr->data << endl;
		curr = curr->prev;
	}
	cout << endl;
}





