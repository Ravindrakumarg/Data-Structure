#ifndef __INDEX__
#define __INDEX__

#include <vector>


class Index
{
	// index will start from 1 and last index will show how many data is available currentlly
	// after every insert an increamented index need to push back to list.

	std::vector<int> _index_list;
	static int _current_block_index;

public:

	Index()
	{
		_index_list.clear();
	}

	void set_index(int index)
	{
		_index_list.push_back(index);
	}

	void increament_index()
	{
		_index_list.push_back((int)_index_list.size() + 1);
	}

	int get_lastest_index()
	{
//		return _index_list.at(_index_list.size()-1);
		return (int)_index_list.size();
	}

	bool validate_index(int index)
	{
		if (get_lastest_index() < index)
			return false;

		return true;
	}

	int get_current_block_index()
	{
		return _current_block_index;
	}

	void increment_current_block_index()
	{
		_current_block_index += 1;
	}

	void reset_current_block_index()
	{
		_current_block_index = 0;
	}

	void set_current_block_index(int index)
	{
		_current_block_index = index;
	}
};

//int Index::_current_block_index = 0;
#endif //__INDEX__