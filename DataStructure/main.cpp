#include <iostream>
#include "DataStructureTest.h"


using namespace std;

int main()
{
    DataStructureTest *test = new DataStructureTest();

    test->testLinkedList();		//to check linked list feature
    test->testStack();			//to check stack feature
    test->testBT();				//to check binary tree
    test->testBST();			//to check binary search tree feature

	delete test;

    return 0;
}
