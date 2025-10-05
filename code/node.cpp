/*
Name:	Matthew Wilson
Course:	CSCE 2110.002
Date:	10/29/21

This program defines the member functions of the node object.
*/

#include"node.h"

node::node()
{
	name = " ";
	next = NULL;
	tomb = 0;
}

void node::SetName(string n)
{
	name = n;
}

void node::SetNext(node* n)
{
	next = n;
}

void node::SetTomb(int t)
{
	tomb = t;
}
		
string node::GetName()
{
	return name;
}

node* node::GetNext()
{
	return next;
}

int node::GetTomb()
{
	return tomb;
}