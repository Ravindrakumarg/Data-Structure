
#ifndef __LINKED_LIST__
#define __LINKED_LIST__

class Node
{
	int data;
public:
	Node* next;
	Node()
	{
		data = 0;
		next = NULL;
	}
	Node(int value)
	{
		data = value;
		next = NULL;
	}
	int get_data()
	{
		return data;
	}
};

class LinkedList
{
	Node * head;
public:	
	LinkedList() 
	{ 
		head = NULL; 
	}
	
	void addNode(int);
	void deleteNode(int);
	int searchNode(int);
	void display_list();
};

#endif	//__LINKED_LIST__