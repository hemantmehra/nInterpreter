#pragma once
#include <stdint.h>
#include <vector>
#include "ConstantPool.h"

namespace JVM
{
    class attribute_info {
    public:
        uint16_t attribute_name_index;
        uint32_t attribute_length;
        uint8_t* info; // len: attribute_length
    };

    class field_info {
    public:
        uint16_t        access_flags;
        uint16_t        name_index;
        uint16_t        descriptor_index;
        uint16_t        attributes_count;
        attribute_info* attributes; // len: attributes_count
    };

    class method_info {
        uint16_t         access_flags;
        uint16_t         name_index;
        uint16_t         descriptor_index;
        uint16_t         attributes_count;
        attribute_info*  attributes; // len: attributes_count
    };

    class ClassFile {
    public:
        uint32_t                    magic;
        uint16_t                    minor_version;
        uint16_t                    major_version;
        uint16_t                    constant_pool_count;
        std::vector<cp_info>        constant_pool; // len: constant_pool_count - 1
        uint16_t                    access_flags;
        uint16_t                    this_class;
        uint16_t                    super_class;
        uint16_t                    interfaces_count;
        uint16_t*                   interfaces;   // len: interfaces_count
        uint16_t                    fields_count;
        field_info*                 fields;       // len: fields_count
        uint16_t                    methods_count;
        method_info*                methods;      // len: methods_count
        uint16_t                    attributes_count;
        attribute_info*             attributes;   // len: attributes_count

        ClassFile(uint8_t* buffer);
        ~ClassFile();
    private:
        uint8_t next_uint8_t();
        uint16_t next_uint16_t();
        uint32_t next_uint32_t();
        void copy_next_bytes(void* dst, void* src, size_t n);
        size_t m_byte_pos;
        uint8_t* m_bytes;
    };
}
