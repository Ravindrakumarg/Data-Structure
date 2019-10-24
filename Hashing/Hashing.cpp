
#include <iostream>
#include "SimpleChaining.h"
#include "LinearProbe.h"
#include "QuadraticProbe.h"

void CheckSimpleChaining();
void CheckOpenAddressing();
void checkLinearProbe();
void checkQuadraticProbe();

int main()
{
	CheckSimpleChaining();
	CheckOpenAddressing();

	getchar();
}

void CheckSimpleChaining()
{
	SimpleChain *obj = new SimpleChain();

	obj->insert(10);
	obj->insert(12);
	obj->insert(14);
	obj->insert(20);
	obj->insert(11);
	obj->insert(30);
	obj->insert(24);
	obj->insert(15);

	if (obj->search(10)) { std::cout << "data found\n"; } else { std::cout << "data not found\n"; }
	if (obj->search(16)) { std::cout << "data found\n"; } else { std::cout << "data not found\n"; }
	if (obj->search(20)) { std::cout << "data found\n"; } else { std::cout << "data not found\n"; }

	if (obj->delete_data(10)) { std::cout << "data deleted\n"; }
	else { std::cout << "data not found\n"; }
	if (obj->delete_data(16)) { std::cout << "data deleted\n"; }
	else { std::cout << "data not found\n"; }
	if (obj->delete_data(20)) { std::cout << "data deleted\n"; }
	else { std::cout << "data not found\n"; }
	if (obj->delete_data(15)) { std::cout << "data deleted\n"; }
	else { std::cout << "data not found\n"; }

	//delete obj;
}

void CheckOpenAddressing()
{
	checkLinearProbe();
	checkQuadraticProbe();
}

void checkLinearProbe()
{
	LinearProbe * obj = new LinearProbe();

	obj->insert(10);
	obj->insert(20);
	obj->insert(30);
	obj->insert(11);
	obj->insert(15);
	obj->insert(16);
	obj->insert(19);
	obj->insert(29);
	obj->insert(49);
	obj->insert(346);
	obj->insert(3134);

	if (obj->search(20)) { std::cout << "data found\n"; }
	else { std::cout << "data not found\n"; }
	if (obj->search(10)) { std::cout << "data found\n"; }
	else { std::cout << "data not found\n"; }
	if (obj->search(40)) { std::cout << "data found\n"; }
	else { std::cout << "data not found\n"; }
	if (obj->search(16)) { std::cout << "data found\n"; }
	else { std::cout << "data not found\n"; }
	if (obj->search(18)) { std::cout << "data found\n"; }
	else { std::cout << "data not found\n"; }
	if (obj->search(20)) { std::cout << "data found\n"; }
	else { std::cout << "data not found\n"; }

	if (obj->delete_data(20)) { std::cout << "data deleted\n"; }
	else { std::cout << "data not found\n"; }
	if (obj->delete_data(10)) { std::cout << "data deleted\n"; }
	else { std::cout << "data not found\n"; }
	if (obj->delete_data(16)) { std::cout << "data deleted\n"; }
	else { std::cout << "data not found\n"; }
	if (obj->delete_data(18)) { std::cout << "data deleted\n"; }
	else { std::cout << "data not found\n"; }
	if (obj->delete_data(20)) { std::cout << "data deleted\n"; }
	else { std::cout << "data not found\n"; }
}

void checkQuadraticProbe()
{
	QuadraticProbe *obj = new QuadraticProbe();

	obj->insert(10);
	obj->insert(20);
	obj->insert(30);
	obj->insert(11);
	obj->insert(15);
	obj->insert(16);
	obj->insert(19);
	obj->insert(29);
	obj->insert(49);
	obj->insert(346);
	obj->insert(3134);

	if (obj->search(20)) { std::cout << "data found\n"; }
	else { std::cout << "data not found\n"; }
	if (obj->search(10)) { std::cout << "data found\n"; }
	else { std::cout << "data not found\n"; }
	if (obj->search(40)) { std::cout << "data found\n"; }
	else { std::cout << "data not found\n"; }
	if (obj->search(16)) { std::cout << "data found\n"; }
	else { std::cout << "data not found\n"; }
	if (obj->search(18)) { std::cout << "data found\n"; }
	else { std::cout << "data not found\n"; }
	if (obj->search(20)) { std::cout << "data found\n"; }
	else { std::cout << "data not found\n"; }

	if (obj->delete_data(20)) { std::cout << "data deleted\n"; }
	else { std::cout << "data not found\n"; }
	if (obj->delete_data(10)) { std::cout << "data deleted\n"; }
	else { std::cout << "data not found\n"; }
	if (obj->delete_data(16)) { std::cout << "data deleted\n"; }
	else { std::cout << "data not found\n"; }
	if (obj->delete_data(18)) { std::cout << "data deleted\n"; }
	else { std::cout << "data not found\n"; }
	if (obj->delete_data(20)) { std::cout << "data deleted\n"; }
	else { std::cout << "data not found\n"; }
}