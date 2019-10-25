
#ifndef __DYNAMIC_ARRAY__
#define __DYNAMIC_ARRAY__

#include "Data.h"
#include "Index.h"

enum ERRORCODE
{
	INDEX_ALREADY_EMPTY = 101,
	INVALID_INDEX,
	DELETION_FAILED,
	EXCEPTION_IN_DELETION
};

class DynamicArray
{
	static int _level;
	static DataBlock* _head;
	DataBlock* _current_block;
	Index* _index;

public:
	DynamicArray()
	{
		_head = nullptr;
		_current_block = nullptr;
		_index = new Index();
		_max_element = 0;
	}

public:
	unsigned int insert_data(Data*);

	//search data based on index
	Data* fetch_data(int);
	Data* fetch_data_queue_method(int);
	unsigned int total_record();

	//deleting data based in index
	bool delete_data(int);

	//search a record by id and get index

private:
	DataBlock* get_block_address(int, bool);
	bool check_for_new_level();
	int power(int, int);
	unsigned int _max_element;
	int delete_data_internal(int);

	//deleting complete array //freeing memory
	bool delete_array();

public:
	~DynamicArray();
};

#endif //__DYNAMIC_ARRAY__