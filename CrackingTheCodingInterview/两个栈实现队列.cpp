#pragma once

#include "header.h"

class Solution
{
public:
	void push(int node) 
	{
		stack1.push(node);
	}

	int pop() 
	{
		this->move1To2();
		int result = stack1.top();
		stack1.pop();
		this->move2To1();
		return result;
	}

private:
	void move1To2()
	{
		size_t length= stack1.size();
		for (size_t i = 0; i < length-1; i++)
		{
			stack2.push(stack1.top());
			stack1.pop();
		}
	}
	void move2To1()
	{
		size_t length = stack2.size();
		for (size_t i = 0; i < length; i++)
		{
			stack1.push(stack2.top());
			stack2.pop();
		}
	}
	stack<int> stack1;
	stack<int> stack2;
};