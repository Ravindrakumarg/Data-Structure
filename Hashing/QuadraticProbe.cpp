
#include "iostream"
#include "QuadraticProbe.h"

bool QuadraticProbe::insert(int data)
{
	int key = hash_func(data);

	if (hash_table[key] == UNIQUE_VALUE)
	{
		hash_table[key] = data;
	}
	else
	{
		int i = 1;
		while (i < HASH_TABLE_MAX_SIZE)
		{
			int key = hash_func(hash_func(data) + i*i);	// (hash(x) + 1*1) % S - S is table size
														// (hash(x) + 2*2) % S - S is table size
			if (hash_table[key] == UNIQUE_VALUE)
			{
				hash_table[key] = data;
				break;
			}
			i++;
		}
		if (i == HASH_TABLE_MAX_SIZE)
		{
			std::cout << "hash table full \n";
		}
	}
	return true;
}

bool QuadraticProbe::search(int data)
{
	int key = hash_func(data);

	if (hash_table[key] == UNIQUE_VALUE)
		return false;
	else
	{
		int i = 0;
		while (i < HASH_TABLE_MAX_SIZE)
		{
			int key = hash_func(hash_func(data) + i*i);

			if (hash_table[key] == data)
				return true;

			i++;
		}
		if (i == HASH_TABLE_MAX_SIZE)
			return false;
	}
}

bool QuadraticProbe::delete_data(int data)
{
	if (!search(data))
		return false;
	else
	{
		int i = 0;
		while (i < HASH_TABLE_MAX_SIZE)
		{
			int key = hash_func(hash_func(data) + i*i);

			if (hash_table[key] == data)
			{
				hash_table[key] = UNIQUE_VALUE;
				return true;
			}
			i++;
		}
	}
}

int QuadraticProbe::hash_func(int data)
{
	return (data % HASH_TABLE_MAX_SIZE);
}
