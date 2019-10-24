#pragma once

class Data
{
public:
	Data() {}
	virtual ~Data(){}
};

class SBBSTNode
{
public:
	int height; 
	int data;
	SBBSTNode *left, *right;
	/* Constructor */
	SBBSTNode()
	{
		left = nullptr;
		right = nullptr;
		data = 0;
		height = 0;
	}

	/* Constructor */
	SBBSTNode(int n)
	{
		left = nullptr;
		right = nullptr;
		data = n;
		height = 0;
	}
};