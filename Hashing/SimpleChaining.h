#pragma once

#define HEAP_MAX_SIZE 10

class Node
{
public:
	int _data;
	Node * _next;
public:
	Node()
	{
		_next = nullptr;
	}
	Node(int data)
	{
		_data = data;
		_next = nullptr;
	}
	~Node()
	{ 
		_next = nullptr;
	}
};

class SimpleChain
{
	Node * _data[HEAP_MAX_SIZE] = {nullptr};
public:
	SimpleChain()
	{
	}
	~SimpleChain()
	{
		delete[] _data;
	}

public:
	void insert(int);
	bool search(int);
	bool delete_data(int);

private:
	int hash_func(int);
	void insert_in_list(Node *, int);
	bool search_in_list(Node *, int);
	bool delete_in_list(Node *, int);
};