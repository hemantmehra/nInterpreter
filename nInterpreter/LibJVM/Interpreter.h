#pragma once
#include <stdint.h>
#include "..\CL\Stack.h"
#include "ByteCode.h"

#define JVM_MAX_PROGRAM_LENGTH 1024
#define JVM_MAX_LOCAL_VARS 1024

namespace JVM
{
	class Interpreter
	{
	public:
		Interpreter(uint8_t bytes[], size_t length);
		~Interpreter();
		ByteCode next_exec();
		int8_t get_last_val();

	private:
		uint8_t next_byte();

		uint8_t m_program[JVM_MAX_PROGRAM_LENGTH];
		uint64_t m_pc;
		CL::Stack m_stack;
		uint8_t m_localVars[JVM_MAX_LOCAL_VARS];
		int8_t m_last_val;
	};
}