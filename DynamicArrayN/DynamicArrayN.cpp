// DynamicArrayN.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <math.h>
#include "DynamicArrayN.h"
#include <queue>

using namespace std;

DataBlock* DynamicArray::_head = nullptr;
int DynamicArray::_level = 0;
int Index::_current_block_index = 0;

DynamicArray::~DynamicArray()
{
	if (_head != nullptr)
	{
		delete_array();
	}
	if (_index != nullptr)
	{
		delete _index;
		_index = nullptr;
	}
}

unsigned int DynamicArray::insert_data(Data* data)
{
	if (_head == nullptr)
	{
		_head = new DataBlock();
		_head->_block_number[0] = data;

		_current_block = _head;
		_index->set_index(1);
		_index->set_current_block_index(1);
		_level = 1;
		_max_element = power(BLOCK_SIZE, _level);
	}
	else
	{
		bool is_level_shift_needed = check_for_new_level();

		if (is_level_shift_needed) // true case  //Need to change level
		{
			DataBlock* data_block = new DataBlock();	
			data_block->_block_number[0] = _head;		//head became the second level
			
			DataBlock* temp=nullptr, *ptemp=nullptr;
			for (int level = 0; level < _level; level++)	//creating n level hierarchy
			{
				DataBlock *data_block = new DataBlock();
				if (level == 0)
				{
					temp = data_block;
					ptemp = data_block;
				}
				else
				{
					ptemp->_block_number[0] = data_block;
					ptemp = data_block;
				}
			}

			data_block->_block_number[1] = temp;
			ptemp->_block_number[0] = data;
			_index->increament_index();

			_current_block = ptemp;
			_index->set_current_block_index(1);

			_head = data_block;			
			_level += 1;
			_max_element = power(BLOCK_SIZE, _level);
		}
		else //false case //need to insert data at same level //no need to change level
		{	
			if(_index->get_current_block_index() != (BLOCK_SIZE))
			{
				_current_block->_block_number[_index->get_current_block_index()] = data;
				_index->increament_index();
				_index->increment_current_block_index();
			}
			else
			{
				int index = _index->get_lastest_index();
				int level = _level - 1;
				DataBlock* temp = _head;

				for (int i = level; i >= 0; i--)
				{
					int quot = index / power(BLOCK_SIZE, level);

					if (temp->_block_number[quot] == nullptr && level != 0)
					{
						DataBlock* new_block = new DataBlock();
						temp->_block_number[quot] = new_block;
						temp = new_block;
					}
					else
					{
						if (i != 0)
							temp = dynamic_cast<DataBlock*>(temp->_block_number[quot]);
						else
						{
							temp->_block_number[quot] = data;
							_current_block = temp;
							_index->increament_index();
							_index->reset_current_block_index();
							_index->increment_current_block_index();
						}
					}

					index = index - power(BLOCK_SIZE, level) * quot;
					level = level - 1;
				}
			}
		}
	}

	return _index->get_lastest_index();
}

bool DynamicArray::check_for_new_level()
{
	if (_max_element == _index->get_lastest_index())
		return true;

	return false;
}

Data* DynamicArray::fetch_data(int index)
{
	if (!_index->validate_index(index))
	{
		std::cout << "Invalid index::index does not exist" << std::endl;
		return nullptr;
	}
	else
	{
		index = index - 1;

		int block_count = index / BLOCK_SIZE;
		int block_index = index % BLOCK_SIZE;

		if (block_count == 0 && _level == 1)
		{
			return _head->_block_number[block_index];
		}
		else
		{
			int level = _level - 1;
			DataBlock* temp = _head;

			for (int i = level; i >= 0; i--)
			{
				int quot = index / power(BLOCK_SIZE, level);

				if (i != 0)
					temp = dynamic_cast<DataBlock*>(temp->_block_number[quot]);
				else
					return temp->_block_number[quot];

				index = index - power(BLOCK_SIZE, level) * quot;
				level = level - 1;
			}
		}
	}

	return nullptr;
}

Data* DynamicArray::fetch_data_queue_method(int index)
{
	if (!_index->validate_index(index))
	{
		std::cout << "Invalid index::index does not exist" << std::endl;
		return nullptr;
	}
	else
	{
		//index //blocksize
		int block_count = (index - 1) / BLOCK_SIZE;
		int block_index = (index - 1) % BLOCK_SIZE;

		if (block_count == 0 && _level == 1)
		{
			return _head->_block_number[block_index];
		}
		else
		{
			DataBlock *block_ptr = get_block_address(block_count, false);
			return block_ptr->_block_number[block_index];
		}
	}
}


bool DynamicArray::delete_data(int index)
{
	int rc = delete_data_internal(index);

	if (rc == DELETION_FAILED)
	{
		std::cout << "deletion failed at index(" << index << ")" << std::endl;
		return false;
	}
	else if (rc == INVALID_INDEX)
	{
		std::cout << "Invalid index::index does not exist" << std::endl;
		return false;
	}
	else if (rc == INDEX_ALREADY_EMPTY)
	{
		std::cout << "Duplicate operation::index data already deleted" << std::endl;
		return false;
	}
	else if (rc == EXCEPTION_IN_DELETION)
	{
		std::cout << "Exception cought while deletion" << std::endl;
		return false;
	}

	return true;
}

int DynamicArray::delete_data_internal(int index)
{
	if (!_index->validate_index(index))
	{
		std::cout << "Invalid index::index does not exist" << std::endl;
		return INVALID_INDEX;
	}
	else
	{
		try
		{
			index = index - 1;

			int block_count = index / BLOCK_SIZE;
			int block_index = index % BLOCK_SIZE;

			DataBlock* temp = _head;
			int level = _level - 1;

			for (int i = level; i >= 0; i--)
			{
				int quot = index / power(BLOCK_SIZE, level);

				if (i != 0)
					temp = dynamic_cast<DataBlock*>(temp->_block_number[quot]);
				else
				{
					if (temp->_block_number[quot] != nullptr)
						temp->_block_number[quot] = nullptr;
					else
						return INDEX_ALREADY_EMPTY;
				}

				index = index - power(BLOCK_SIZE, level) * quot;
				level = level - 1;
			}
		}
		catch (...)
		{
			return EXCEPTION_IN_DELETION;
		}
	}

	return true;
}

bool DynamicArray::delete_array()
{
	std::queue<Data*> datablock_queue;

	DataBlock* temp = _head;

	return false;
}


DataBlock * DynamicArray::get_block_address(int block_count, bool spcl_flag)
{
	std::queue<Data*> datablock_queue;


		datablock_queue.push(_head->_block_number[0]);
		datablock_queue.push(_head->_block_number[1]);
		datablock_queue.push(_head->_block_number[2]);

	int queue_operation_count = power(BLOCK_SIZE, _level - 2);

	Data* last_parent = nullptr;

	for (int level = 1; level < _level - 1; level++)
	{
		for(int queue_loop = 0; queue_loop < queue_operation_count ; queue_loop++)
		{
			Data *data = datablock_queue.front();
			datablock_queue.pop();
			if (data == nullptr)
				break;

			last_parent = data;
			DataBlock* db_ptr = dynamic_cast<DataBlock*>(data);

			for (int j = 0; j < BLOCK_SIZE; j++)
			{
				datablock_queue.push(db_ptr->_block_number[j]);
			}
		}
	}

	if (spcl_flag)
	{
		if (_level == 2)
			return _head;
		else
			return dynamic_cast<DataBlock*>(last_parent);
	}

	//fetching the exact block from queue based on block_count

	Data* data = nullptr;
	for (int i = 0; i <= block_count; i++)
	{
		data = datablock_queue.front();
		datablock_queue.pop();
	}
	DataBlock* data_block = dynamic_cast<DataBlock*>(data);

	return data_block;
}

unsigned int DynamicArray::total_record()
{
	return _index->get_lastest_index();
}

int DynamicArray::power(int value, int power)
{
	int result = 1;
	for (int i = 0; i < power; i++)
		result = result * value;

	return result;
}