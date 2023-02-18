#include <stdio.h>
#include "../CL/Assert.h"
#include "ClassFile.h"

namespace JVM
{
	const char* CONSTANT_POOL_TAG_STRING(CONSTANT_POOL_TAG tag)
	{
		switch (tag)
		{
#define __ENUMERATE_CONSTANT_POOL_TAG(x, y) case CONSTANT_POOL_TAG::x: return #x;
			ENUMERATE_CONSTANT_POOL_TAGS
#undef __ENUMERATE_CONSTANT_POOL_TAG
		default:
			ASSERT_NOT_REACHED();
		}
	}

	uint16_t make_uint16_t(uint8_t a, uint8_t b)
	{
		return (a << 8) | b;
	}

	uint32_t make_uint32_t(uint8_t a, uint8_t b, uint8_t c, uint8_t d)
	{
		return (make_uint16_t(a, b) << 16) | make_uint16_t(c, d);
	}

	uint8_t ClassFile::next_uint8_t()
	{
		uint8_t val = m_bytes[m_byte_pos];
		m_byte_pos += 1;
		return val;
	}

	uint16_t ClassFile::next_uint16_t()
	{
		uint16_t val = make_uint16_t(m_bytes[m_byte_pos], m_bytes[m_byte_pos + 1]);
		m_byte_pos += 2;
		return val;
	}

	uint32_t ClassFile::next_uint32_t()
	{
		uint8_t a = m_bytes[m_byte_pos];
		uint8_t b = m_bytes[m_byte_pos + 1];
		uint8_t c = m_bytes[m_byte_pos + 2];
		uint8_t d = m_bytes[m_byte_pos + 3];
		uint32_t val = make_uint32_t(a, b, c, d);
		m_byte_pos += 4;
		return val;
	}

	void ClassFile::copy_next_bytes(void* dst, void* src, size_t n)
	{
		memcpy(dst, src, n);
		m_byte_pos += n;
	}

	ClassFile::ClassFile(uint8_t* buffer)
	{
		m_byte_pos = 0;
		m_bytes = buffer;

		magic = next_uint32_t();
		printf("magic: %08x\n", magic);

		minor_version = next_uint16_t();
		printf("minor_version: %d\n", minor_version);

		major_version = next_uint16_t();
		printf("major_version: %d\n", major_version);

		constant_pool_count = next_uint16_t();
		printf("constant_pool_count: %d\n", constant_pool_count);

		for (size_t c = 0; c < constant_pool_count - 1; c++) {
			cp_info _cp_info;
			uint8_t tag = next_uint8_t();
			_cp_info.tag = tag;

			CONSTANT_POOL_TAG pool_tag = (CONSTANT_POOL_TAG)tag;
			printf("tag: %d -> %s	\n", tag, CONSTANT_POOL_TAG_STRING((CONSTANT_POOL_TAG)pool_tag));
			
			switch (pool_tag)
			{
			case CONSTANT_POOL_TAG::CONSTANT_Utf8:
			{
				uint16_t length = next_uint16_t();
				_cp_info.info.CONSTANT_Utf8_info.length = length;
				_cp_info.info.CONSTANT_Utf8_info.bytes = new uint8_t[length];
				copy_next_bytes(_cp_info.info.CONSTANT_Utf8_info.bytes, &m_bytes[m_byte_pos], length);
				break;
			}
			case CONSTANT_POOL_TAG::CONSTANT_Integer:
				TODO();
			case CONSTANT_POOL_TAG::CONSTANT_Float:
				TODO();
			case CONSTANT_POOL_TAG::CONSTANT_Long:
				TODO();
			case CONSTANT_POOL_TAG::CONSTANT_Double:
				TODO();
			case CONSTANT_POOL_TAG::CONSTANT_Class:
			{
				_cp_info.info.CONSTANT_Class_info.name_index = next_uint16_t();
				break;
			}
			case CONSTANT_POOL_TAG::CONSTANT_String:
				TODO();
			case CONSTANT_POOL_TAG::CONSTANT_Fieldref:
				TODO();
			case CONSTANT_POOL_TAG::CONSTANT_Methodref:
			{
				_cp_info.info.CONSTANT_Methodref_info.class_index = next_uint16_t();
				_cp_info.info.CONSTANT_Methodref_info.name_and_type_index = next_uint16_t();
				break;
			}
			case CONSTANT_POOL_TAG::CONSTANT_InterfaceMethodref:
				TODO();
			case CONSTANT_POOL_TAG::CONSTANT_NameAndType:
			{
				_cp_info.info.CONSTANT_NameAndType_info.name_index = next_uint16_t();
				_cp_info.info.CONSTANT_NameAndType_info.descriptor_index = next_uint16_t();
				break;
			}
			case CONSTANT_POOL_TAG::CONSTANT_MethodHandle:
				TODO();
			case CONSTANT_POOL_TAG::CONSTANT_MethodType:
				TODO();
			case CONSTANT_POOL_TAG::CONSTANT_Dynamic:
				TODO();
			case CONSTANT_POOL_TAG::CONSTANT_InvokeDynamic:
				TODO();
			case CONSTANT_POOL_TAG::CONSTANT_Module:
				TODO();
			case CONSTANT_POOL_TAG::CONSTANT_Package:
				TODO();
			default:
				ASSERT_NOT_REACHED();
			}

			constant_pool.push_back(_cp_info);
		}

		//access_flags = make_uint16_t(buffer[i], buffer[i + 1]);
		//i += 2;
		//printf("access_flags: %04x\n", access_flags);
	}

	ClassFile::~ClassFile()
	{
	}


}