/*
Name:	Matthew Wilson
Course:	CSCE 2110.002
Date:	10/29/21

This program takes a string input from user and stores it in  a hash table.
*/

#include"hash.h"

int main()
{
	Hash NameList;//hash table of string names
	string name;//holds name
	int choice;//holds user choice
		
	while(choice != 4)//loops until quit
	{
		cout << "Enter choice: " << endl;
		cout << "0 - Insert\n1 - Search\n2 - Delete\n3 - Print\n4 - Quit\n";
		cin >> choice;//reads choice from menu
		
		cin.ignore();
		
	switch(choice)
	{
		case 0://insert
		{	
			cout << "Enter a name to insert: ";
			getline(cin, name);
			
			NameList.Insert(name);
			
			break;
		}
		
		case 1://search
		{
			cout << "Enter a name to search: ";
			getline(cin, name);
			
			NameList.Search(name);
		
			break;
		}
		
		case 2://delete
		{
			cout << "Enter a name to delete: ";
			getline(cin, name);
			
			NameList.Delete(name);
		
			break;
		}
		
		case 3://output
		{
			NameList.Print();
			
			break;
		}
		
		case 4://quit
		{
			cout << "Done!" << endl;
			
			break;
		}
		
		default://wrong input
		{		
			cout << "Invalid choice. Try again." << endl;
		}
	}
	}
	
	return 0;
}