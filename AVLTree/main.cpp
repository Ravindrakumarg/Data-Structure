
#include "stdafx.h"
#include "iostream"
#include "AVLTree.h"
#include <chrono>

int main()
{
	SelfBalancingBinarySearchTree sbbst;

	int i = 0;
	long long int count = 256 * 256 * 256;
	auto start_time = chrono::high_resolution_clock::now();
	for ( i = 0; i < count; i++)
		sbbst.insert(i);
	auto end_time = chrono::high_resolution_clock::now();

	std::cout << "Data count:" << count << std::endl;
	auto insertion_duration_micro = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
	auto insertion_duration_mili = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
	std::cout << "insertion time: " << "mili sec:" << insertion_duration_mili.count() << "  "
									<< "micro sec:" << insertion_duration_micro.count() << std::endl;

	start_time = chrono::high_resolution_clock::now();
	if (sbbst.search(count-1))
		std::cout << "Data found::"<<count << std::endl;
	else
		std::cout << "Data not found" << std::endl;
	end_time = chrono::high_resolution_clock::now();

	auto search_duration_micro = std::chrono::duration_cast<std::chrono::microseconds>(end_time - start_time);
	auto search_duration_mili = std::chrono::duration_cast<std::chrono::milliseconds>(end_time - start_time);
	std::cout << "searching time: " << "mili sec:" << search_duration_mili.count() << "  "
		<< "micro sec:" << search_duration_micro.count() << std::endl;

	getc(stdin);

	return 0;
}