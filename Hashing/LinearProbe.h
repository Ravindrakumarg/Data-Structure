#pragma once

#define HASH_TABLE_MAX_SIZE	10
#define UNIQUE_VALUE		-9999

class LinearProbe
{
	int hash_table[HASH_TABLE_MAX_SIZE];
public:
	LinearProbe()
	{
		for (int i = 0; i < HASH_TABLE_MAX_SIZE; i++)
			hash_table[i] = UNIQUE_VALUE;
	}
	~LinearProbe()
	{}

	bool insert(int data);
	bool search(int data);
	bool delete_data(int data);

private:
	int hash_func(int data);
};