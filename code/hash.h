/*
Name:	Matthew Wilson
Course:	CSCE 2110.002
Date:	10/29/21

This header file declares the member functions of the hash object.
*/

#include"node.h"

#ifndef HASH_H
#define HASH_H

class Hash
{
	public:
		Hash();//constructor
		
		int hash(string);//converts name into index
		
		void Collision(string);//handles collisions by chaining
		
		void Insert(string);//inserts into hash table
		
		void Search(string);//searches for name in hash table
		
		void Delete(string);//deletes name from hash table
		
		void Print();//prints all data in hash table
	
	private:
		static const int size = 10;//size of table
		node* HashTable[size];//hash table
		int collisions = 0;// collision counter
};

#endif