// This file is explaining all operation and concepts related to BIT

/* There is total 6 bit operator in C/C++:
 & (AND) - The result of AND is 1 only if both bits are 1 otherwise 0
 | (OR)  - The result of OR is 1 if any of the two bits is 1.
 ^ (XOR) - The result of XOR is 1 if the two bits are different.
<< (left shift) - takes two numbers, left shifts the bits of the first operand, the second operand decides the number of places to shift.
>> (right shift)- takes two numbers, right shifts the bits of the first operand, the second operand decides the number of places to shift.
 ~ (NOT) - inverts all bits of it
*/

#include<iostream>

void BasicBitOperation();
void PRINT(const char* msg, int num);
int main()
{
	BasicBitOperation();

	getchar();
	return 0;
}

void BasicBitOperation()
{
	int a = 2;	PRINT("a", a);
	int b = 5;	PRINT("b", b);

	PRINT("a|b",  a|b);
	PRINT("a&b",  a&b);
	PRINT("b>>2", b>>2);
	PRINT("b<<2", b<<2);
	PRINT("a^b",  a^b);
	PRINT("~a",   a=~a);
}

void PRINT(const char* msg, int num)
{
	std::cout << msg << ": ";
	int arr[8] = { 0 };
	int i = 0, temp = num;
	while (num)
	{
		arr[i] = num % 2;
		num = num / 2;
		i++;
	}
	i = 7;
	while (i >= 0)
	{
		std::cout << arr[i];
		i--;
	}

	std::cout <<"(" <<temp<< ")"<< std::endl;
}