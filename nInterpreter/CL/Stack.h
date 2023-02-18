#pragma once

#include <vector>

namespace CL
{
	class Stack
	{
	public:
		Stack();
		~Stack();
		void push(int8_t val);
		int8_t pop();

	private:
		std::vector<int8_t> m_stack;
	};
}