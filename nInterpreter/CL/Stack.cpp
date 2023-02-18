#include "Stack.h"

namespace CL
{
	Stack::Stack()
	{
	}

	Stack::~Stack()
	{
	}

	void Stack::push(int8_t val)
	{
		m_stack.push_back(val);
	}

	int8_t Stack::pop()
	{
		int8_t val = m_stack.back();
		m_stack.pop_back();
		return val;
	}
}
