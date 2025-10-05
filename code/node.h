/*
Name:	Matthew Wilson
Course:	CSCE 2110.002
Date:	10/29/21

This program declares the member functions of the node object.
*/

#include<iostream>
#include<string>
using namespace std;

#ifndef NODE_H
#define NODE_H

class node//holds data in hash table
{
	public:
		node();//constructor
		
		//setters
		void SetName(string);
		void SetNext(node*);
		void SetTomb(int);
		
		//getters
		string GetName();
		node* GetNext();
		int GetTomb();
	
	private:
		string name;//name
		node* next;//points to next node in bucket
		int tomb;//tells if bucket held node before deletion.
};

#endif