#pragma once
#include <stdint.h>
#include <vector>

#define ENUMERATE_CONSTANT_POOL_TAGS \
    __ENUMERATE_CONSTANT_POOL_TAG(CONSTANT_Utf8, 1) \
    __ENUMERATE_CONSTANT_POOL_TAG(CONSTANT_Integer, 3) \
    __ENUMERATE_CONSTANT_POOL_TAG(CONSTANT_Float, 4) \
    __ENUMERATE_CONSTANT_POOL_TAG(CONSTANT_Long, 5) \
    __ENUMERATE_CONSTANT_POOL_TAG(CONSTANT_Double, 6) \
    __ENUMERATE_CONSTANT_POOL_TAG(CONSTANT_Class, 7) \
    __ENUMERATE_CONSTANT_POOL_TAG(CONSTANT_String, 8) \
    __ENUMERATE_CONSTANT_POOL_TAG(CONSTANT_Fieldref, 9) \
    __ENUMERATE_CONSTANT_POOL_TAG(CONSTANT_Methodref, 10) \
    __ENUMERATE_CONSTANT_POOL_TAG(CONSTANT_InterfaceMethodref, 11) \
    __ENUMERATE_CONSTANT_POOL_TAG(CONSTANT_NameAndType, 12) \
    __ENUMERATE_CONSTANT_POOL_TAG(CONSTANT_MethodHandle, 15) \
    __ENUMERATE_CONSTANT_POOL_TAG(CONSTANT_MethodType, 16) \
    __ENUMERATE_CONSTANT_POOL_TAG(CONSTANT_Dynamic, 17) \
    __ENUMERATE_CONSTANT_POOL_TAG(CONSTANT_InvokeDynamic, 18) \
    __ENUMERATE_CONSTANT_POOL_TAG(CONSTANT_Module, 19) \
    __ENUMERATE_CONSTANT_POOL_TAG(CONSTANT_Package, 20)

namespace JVM
{
    enum class CONSTANT_POOL_TAG
    {
#define __ENUMERATE_CONSTANT_POOL_TAG(x, y) x = y,
        ENUMERATE_CONSTANT_POOL_TAGS
#undef __ENUMERATE_CONSTANT_POOL_TAG
    };


    struct cp_info
    {
        uint8_t tag;

        union
        {
            struct {
                uint16_t name_index;
            } CONSTANT_Class_info;

            struct {
                uint16_t class_index;
                uint16_t name_and_type_index;
            } CONSTANT_Fieldref_info;

            struct {
                uint16_t class_index;
                uint16_t name_and_type_index;
            } CONSTANT_Methodref_info;

            struct {
                uint16_t class_index;
                uint16_t name_and_type_index;
            } CONSTANT_InterfaceMethodref_info;

            struct {
                uint16_t string_index;
            } CONSTANT_String_info;

            struct {
                uint32_t bytes;
            } CONSTANT_Integer_info;

            struct {
                uint32_t bytes;
            } CONSTANT_Float_info;

            struct {
                uint32_t high_bytes;
                uint32_t low_bytes;
            } CONSTANT_Long_info;

            struct {
                uint32_t high_bytes;
                uint32_t low_bytes;
            } CONSTANT_Double_info;

            struct {
                uint16_t name_index;
                uint16_t descriptor_index;
            } CONSTANT_NameAndType_info;

            struct {
                uint16_t length;
                uint8_t* bytes; // len: length
            } CONSTANT_Utf8_info;

            struct {
                uint8_t reference_kind;
                uint16_t reference_index;
            } CONSTANT_MethodHandle_info;

            struct {
                uint16_t descriptor_index;
            } CONSTANT_MethodType_info;

            struct {
                uint16_t bootstrap_method_attr_index;
                uint16_t name_and_type_index;
            } CONSTANT_Dynamic_info;

            struct {
                uint16_t bootstrap_method_attr_index;
                uint16_t name_and_type_index;
            } CONSTANT_InvokeDynamic_info;

            struct {
                uint16_t name_index;
            } CONSTANT_Module_info;

            struct {
                uint16_t name_index;
            } CONSTANT_Package_info;
        } info;
    };
}