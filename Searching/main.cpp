// This projest explains all method of searching with code
/* Search Type
1. Linear Search - it is like sequential search in array or linked list.
2. Interval Search - 
	-> Binary Search - Here search is based on devide and conquer algo.
	-> Interpolation Search
*/

#include <iostream>

void LinearSearch();
void BinarySearch();

int main()
{
	LinearSearch();
	BinarySearch();

	return 0;
}

void LinearSearch()
{
	int data[] = { 2, 5, 7, 8, 3, 10, 77, 78, 45, 23, 43, 6, 7 };
	int num, size;
	bool isFound = false;

	std::cout << "Enter data to search:" << std::endl;
	std::cin >> num;

	size = sizeof(data) / sizeof(int);

	for (int i = 0; i < size; i++)
	{
		if (data[i] == num)
		{
			isFound = true;
			break;
		}
	}
	if (isFound)
		std::cout << "Data found" << std::endl;
	else
		std::cout << "Data not found" << std::endl;
}

void BinarySearch()
{

}