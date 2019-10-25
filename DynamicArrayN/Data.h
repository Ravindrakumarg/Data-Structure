
#ifndef __DATA__
#define __DATA__

#define BLOCK_SIZE	256
#define MAX_SIZE	3



//Class Data to store actual data
class Data
{
public:
	Data(){}
	virtual void display_record() = 0;
	virtual ~Data() {}
};

//Class DataBlock to hold block of data
class DataBlock : public Data
{
public:
	//to hold a block of data
	Data* _block_number[BLOCK_SIZE];

public:
	DataBlock()
	{
		for (int index = 0; index < BLOCK_SIZE; index++)
			_block_number[index] = nullptr;
	}

	//faking it //need to ask
	void display_record() {}

	~DataBlock()
	{
		for (int index = 0; index < BLOCK_SIZE; index++)
		{
			if (_block_number[index] != nullptr)
				delete _block_number[index];
		}
	}
};

#endif