
#include "stdafx.h"
#include "iostream"
#include "Data.h"
#include "DynamicArrayN.h"
#include "CashTransaction.h"
//#include "vld.h"
//#include "vld_def.h"
#include <chrono>

using namespace std;

int main()
{
	DynamicArray db;

	//inserting a record
	int index = 0;
	long long int count = 256*256*100;

	auto start_time = chrono::high_resolution_clock::now();
	for (int record_counter = 1; record_counter <= count; record_counter++)
	{
		index = db.insert_data(new CashTransaction(record_counter));
	}
	auto end_time = chrono::high_resolution_clock::now();

	std::cout << "Data count:" << count << std::endl;
	auto insertion_duration_micro = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
	auto insertion_duration_mili = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
	std::cout << "insertion time: " << "mili sec:" << insertion_duration_mili.count() << "  "
		<< "micro sec:" << insertion_duration_micro.count() << std::endl;

	start_time = chrono::high_resolution_clock::now();
	//fetch the record based on index //searching a record
	Data *record = db.fetch_data((int)(count));
	end_time = chrono::high_resolution_clock::now();

	auto search_duration_micro = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
	auto search_duration_mili = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
	std::cout << "searching time: " << "mili sec:" << search_duration_mili.count() << "  "
		<< "micro sec:" << search_duration_micro.count() << std::endl;

	//displaying a record
	if(record)
		record->display_record();

	//deleting a record based on index
	if (db.delete_data(count - 2))
		std::cout << "Successfully deleted data at index:" << count - 2 << std::endl;

	std::cout << "Total record:" << db.total_record();
	getc(stdin);
	return 0;
}
