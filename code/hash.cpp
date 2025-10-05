/*
Name:	Matthew Wilson
Course:	CSCE 2110.002
Date:	10/29/21

This program defines the member functions of the hash object.
*/

#include"hash.h"

Hash::Hash()
{
	for(int i = 0; i < size; i++)//populates hash table
	{
		HashTable[i] = new node;
	}
	
	collisions = 0;
}

int Hash::hash(string key)//returns index for key
{
	int hash = 0;
	int index;
	int M = 3;
	
	for(int i = 0; i < key.length(); i++)
	{
		hash = (hash * M) + (int)key[i];//multiplicative hashing
	}
	
	//cout << hash << endl;
	
	index = hash % size;
	
	return index;
}

void Hash::Collision(string n)//handles collisions
{
	int index = hash(n);
	
	node* ptr = HashTable[index];
		
	node* temp = new node;
	
	temp->SetName(n);
	temp->SetNext(NULL);
	
	while(ptr->GetNext() != NULL)
	{
		ptr = ptr->GetNext();
	}
	
	ptr->SetNext(temp);
	
	collisions++;
	
	//cout << collisions << endl;
}

void Hash::Insert(string n)//inserts name at index in hash table
{
	if(collisions < size)
	{
		int index = hash(n);
	
		if(HashTable[index]->GetName() == " ")
		{
			HashTable[index]->SetName(n);
		}
	
		else
		{
			Collision(n);
		}
	
	//	cout << n << " inserted at index " << index << endl;
	}
	
	else 
	{
		cout << "Insert rejected." << endl;
	}
}

void Hash::Search(string n)//tells if name exists in hash table
{
	int x = 1;
	
	if(collisions < size)
	{	
		int index = hash(n);
		
		if(HashTable[index]->GetName() == " ")
		{
			cout << n << " does not exist." << endl;
		}
		
		else if(HashTable[index]->GetName() == n)
		{
			cout << n << " exists." << endl;
		}
		
		else
		{
			node* ptr = HashTable[index];
			
			while(ptr->GetNext() != NULL)
			{
				ptr = ptr->GetNext();
				
				if(ptr->GetName() == n)
				{
					cout << n << " exists." << endl;
					
					break;
				}
				
				cout << n << " does not exist." << endl;
			}
		}
	}
	
	else 
	{
		cout << n << " does not exist." << endl;
	}
}

void Hash::Delete(string n)//deletes name from hash table
{
	if(collisions < size)
	{
		int index = hash(n);
		
		if(HashTable[index]->GetName() == " ")//bucket empty
		{
			cout << n << " does not exist." << endl;
		}
		
		else if(HashTable[index]->GetName() == n && HashTable[index]->GetNext() == NULL)//1 item has matching name
		{
			HashTable[index]->SetName(" ");
			HashTable[index]->SetTomb(1);
			
			cout << n << " was deleted" << endl;
		}
		
		else if(HashTable[index]->GetName() == n)//1st item match but more in bucket
		{
			node* ptr = HashTable[index];
			
			HashTable[index] = HashTable[index]->GetNext();
			
			delete ptr;
			
			HashTable[index]->SetTomb(1);
			
			cout << n << " was deleted" << endl;
		}
		
		else //1st item not match but more in bucket
		{
			node* p1 = HashTable[index]->GetNext();
			node* p2 = HashTable[index];
			
			while(p1 != NULL && p1->GetName() != n)
			{
				p2 = p1;
				
				p1 = p1->GetNext();
			}
			
			if(p1 == NULL)//no match
			{
				cout << n << " does not exist." << endl;
			}
			
			else//match found
			{
				node* temp = p1;
				
				p1 = p1->GetNext();
				
				p2->SetNext(p1);
				
				delete temp;
				
				HashTable[index]->SetTomb(1);
				
				cout << n << " was deleted" << endl;
			}
		}
	}
	
	else 
	{
		cout << n << " does not exist" << endl;
	}
}

void Hash::Print()//outputs hash table's values
{
	node* p1;
	
	cout << "Index:\t" << "Tombstone (0 = none):\t"<< "Name(s):\n" << endl;
	
	for(int i = 0; i < size; i++)
	{		
		p1 = HashTable[i];
		
		cout << i << "\t" << p1->GetTomb() << "\t\t\t" << p1->GetName();
		
		while(p1->GetNext() != NULL)
		{
			p1 = HashTable[i]->GetNext();
			
			cout << "\t" << p1->GetName();
		}
		
		cout << endl;
	}
	
	cout << endl;
}