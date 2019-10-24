
#include "SimpleChaining.h"

void SimpleChain::insert(int data)
{
	int key = hash_func(data);
	
	if (_data[key] != nullptr)
	{
		insert_in_list(_data[key], data);
	}
	else
	{
		_data[key] = new Node(data);
	}
}

bool SimpleChain::search(int data)
{
	int key = hash_func(data);

	if (_data[key] != nullptr)
	{
		return search_in_list(_data[key], data);
	}

	return false;
}

bool SimpleChain::delete_data(int data)
{
	int key = hash_func(data);

	if(!search(data))
	{
		return false;
	}

	return delete_in_list(_data[key], data);
}

int SimpleChain::hash_func(int data)
{
	return (data % 10);
}

void SimpleChain::insert_in_list(Node * head, int data)
{
	while (head->_next != nullptr)
		head = head->_next;

	head->_next = new Node(data);
}

bool SimpleChain::search_in_list(Node * head, int data)
{
	while (head != nullptr)
	{
		if (head->_data == data)
			return true;
	
		head = head->_next;
	}

	return false;
}

bool SimpleChain::delete_in_list(Node * head, int data)
{
	Node * temp_head = head;
	Node * phead = head;

	while (head != nullptr)
	{
		if (head->_data == data)
			break;
		phead = head;
		head = head->_next;
	}

	if (temp_head == head)
	{
		_data[hash_func(data)] = head->_next;
		delete head;
	}
	else
	{
		phead->_next = head->_next;
		delete head;
	}
	return true;
}