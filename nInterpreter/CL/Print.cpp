#pragma once
#include <stdio.h>
namespace CL
{
	void PrintStringWithLength(char* str, size_t length)
	{
		for (size_t i = 0; i < length; i++) {
			printf("%c", str[i]);
		}
	}
}
