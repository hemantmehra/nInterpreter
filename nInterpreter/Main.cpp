#include <stdio.h>
#include "LibJava/ByteCode.h"
#include "LibJava/Interpreter.h"

int main()
{
	uint8_t bytes[] = {
		(uint8_t)JVM::ByteCode::_iconst_0,
		(uint8_t)JVM::ByteCode::_istore_1,
		(uint8_t)JVM::ByteCode::_goto,
		(uint8_t) 0,
		(uint8_t) 8,
		(uint8_t)JVM::ByteCode::_iinc,
		(uint8_t) 1,
		(uint8_t) 1,
		(uint8_t)JVM::ByteCode::_iload_1,
		(uint8_t)JVM::ByteCode::_bipush,
		(uint8_t) 100,
		(uint8_t)JVM::ByteCode::_if_icmplt,
		(uint8_t) 0,
		(uint8_t) 5,
		(uint8_t)JVM::ByteCode::_iload_1,
		(uint8_t)JVM::ByteCode::_ireturn
	};

	JVM::Interpreter interpreter = JVM::Interpreter(bytes, 16);

	while (true)
	{
		JVM::ByteCode bytecode = interpreter.next_exec();
		/*printf("%s\n", JVM::ByteCodeString(bytecode));*/

		if (bytecode == JVM::ByteCode::_ireturn) {
			printf("RESULT: %d\n", interpreter.get_last_val());
			break;
		}
	}

	return 0;
}
