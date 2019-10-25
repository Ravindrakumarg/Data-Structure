#ifndef __CASH_TRANSACTION__
#define __CASH_TRANSACTION__

#include <iostream>
#include "Data.h"

class CashTransaction : public Data
{
	int _id;
//	double _amount;

public:
	CashTransaction()
	{
		_id = -9999;
//		_amount = -9999;
	}
	CashTransaction(int id)
	{
		_id = id;
	}
	CashTransaction(int id, double amount)
	{
		_id = id;
//		_amount = amount;
	}

	void display_record()
	{
		std::cout << "Cast Transaction" << std::endl;
		std::cout << "================" << std::endl;
		std::cout << "ID:" << _id << std::endl;
//		std::cout << "Amount:" << _amount << std::endl;
	}

	~CashTransaction()
	{}
};

#endif //__CASH_TRANSACTION__