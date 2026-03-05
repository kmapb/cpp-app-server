/* 
 * Copyright 2026, Pebblebed Mgmt, LLC. All Rights Reserved.
 *
 * Author: Keith Adams <kma@pebblebed.com>
 */

#pragma once

#include <inttypes.h>
#include <string>
#include <vector>
#include <ranges>
#include <format>
#include <iostream>
#include <unordered_map>

/* Utilities */

[[noreturn]] inline void UNREACHED() {
#ifdef __GNUC__ // GCC and Clang
        __builtin_unreachable();
#elif defined(_MSC_VER)
            __assume(false);
#endif
}

#ifndef NDEBUG
#define dprintf(...) do { std::cerr << std::format(__VA_ARGS__); } while(0);
#else
#define dprintf(...) do { } while(0);
#endif

/* Dynamic data types */
enum Type {
    STR,
    INT
};

struct DynVal {
    Type type;
    std::string s;
    int64_t i;

    bool operator==(const DynVal&) const = default;
};

struct Col {
    Type type;
    bool nullable;
};

typedef std::unordered_map<std::string, Col> Schema;
typedef std::unordered_map<std::string, DynVal> DynEvent;

static inline DynVal
parse_val(Type type, std::string sval) {
    switch (type) {
        case INT: {
            DynVal retval { INT, "", 0 };
            retval.i = strtoll(sval.c_str(), nullptr, 10);
            return retval;
        };
        case STR: {
            DynVal retval { STR, "", 0 };
            retval.s = sval;
            return retval;
        }
    }
    UNREACHED();
}

/*
 * Some string handling
 */

#if 0
template<typename String>
std::ranges<std::string_view>
splice_inplace(const String& str, char delim) {
    return str |
       std::ranges::views::split(delim) |
       std::views::transform([](auto r) {return std::string_view{r.begin(), r.end() });
}
#endif

extern DynEvent parse_line(const Schema& schema, std::string line);
