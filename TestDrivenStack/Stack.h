#pragma once
#include <iostream>
#include <vector>
class StackUnderflowError : public std::exception {
public:
	const char* what() {
		return "Stack Underflow";
	}
};
class Stack
{
	std::vector<int> items;
public:
	void Push(int value);
	int Pop();
	bool IsEmpty();
	int Peek();
	int GetTop();
};

