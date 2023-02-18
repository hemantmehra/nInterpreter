#include <stdio.h>
#include "LibJVM/ByteCode.h"
#include "LibJVM/Interpreter.h"

int main()
{
	uint8_t bytes[] = {
		(uint8_t)JVM::ByteCode::_iconst_1,
		(uint8_t)JVM::ByteCode::_ireturn
	};

	JVM::Interpreter interpreter = JVM::Interpreter(bytes, 2);

	while (true)
	{
		JVM::ByteCode bytecode = interpreter.next_exec();
		printf("%s\n", JVM::ByteCodeString(bytecode));

		if (bytecode == JVM::ByteCode::_ireturn) {
			printf("RESULT: %d\n", interpreter.get_last_val());
			break;
		}
	}

	return 0;
}
