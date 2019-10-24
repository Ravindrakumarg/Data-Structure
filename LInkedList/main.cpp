
#include <iostream>
#include "LinkedList.h"

using namespace std;

void manual_test();
void auto_test();

int main()
{
	manual_test();
	auto_test();
	return 0;
}

void manual_test()
{
	LinkedList *list = new LinkedList();
	int chioce, data;
	std::cout << "1.Push 2.Delete 3.Search 4.Display 0.Exit";
	while (1)
	{
		cout << endl << "Enter your choice: ";
		cin >> chioce;
		switch (chioce)
		{
		case 1:

			cout << endl << "Enter data: ";
			cin >> data;
			list->addNode(data);
			break;
		case 2:
			cout << endl << "Enter data you want to delete: ";
			cin >> data;
			list->deleteNode(data);
			break;
		case 3:
			cout << "Enter the number you want to search: ";
			cin >> data;
			list->searchNode(data);
			break;
		case 4:
			list->display_list();
			break;
		case 0:
			exit(0);
			break;
		default:
			cout << endl << "Kindly enter correct option:";
		}
	}
}

void auto_test()
{
	LinkedList *list = new LinkedList();
	list->addNode(10);
}