#include "Stack.h"

void Stack::Push(int value)
{
	this->items.push_back(value);
}

int Stack::Pop()
{
	if (this->items.empty())
		throw StackUnderflowError();
	int item = this->items.back();
	this->items.pop_back();
	return item;
}

bool Stack::IsEmpty()
{
	return this->items.size() == 0;
}

int Stack::Peek()
{
	return 0;
}

int Stack::GetTop()
{
	return this->items.size();
}
