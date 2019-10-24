
#include <iostream>
#include "LinkedList.h"

using namespace std;

void LinkedList::addNode(int data)
{
	Node* node = new Node(data);

	if (head == NULL)
		head = node;
	else
	{
		Node* temp = head;
		while (temp->next != NULL)
			temp = temp->next;

		temp->next = node;
	}
}

void LinkedList::deleteNode(int data)
{
	if (searchNode(data) == -1)
	{
		cout << "Data is not available" << endl;
		return;
	}
	if (head->get_data() == data)
	{
		if (head->next == NULL)
		{
			delete head;
			head = NULL;
			return;
		}
		else
		{
			Node* temp = head;
			head = head->next;
			delete temp;
			return;
		}
	}
	Node* temp = head, *ptemp;
	while (temp->get_data() != data)
	{
		ptemp = temp;
		temp->next = temp;
	}
	ptemp->next = temp->next;
	delete temp;
	temp = NULL;
}

int LinkedList::searchNode(int data)
{
	if (head == NULL)
	{
		cout << endl << "List is empty";
		return -1;
	}
	else
	{
		Node* temp = head;
		while (temp != NULL)
		{
			if (temp->get_data() == data)
			{
				cout << "Data found" << endl;
				return 0;
			}
			temp = temp->next;
		}
		cout << "Data not found" << endl;
		return -1;
	}
	return 0;
}

void LinkedList::display_list()
{
	if (head == NULL)
		cout << endl << "List is empty";
	else
	{
		cout << "List is: ";
		Node* temp = head;
		while (temp->next != NULL)
		{
			cout << temp->get_data() << ",";
			temp = temp->next;
		}
		cout << temp->get_data();
	}
}