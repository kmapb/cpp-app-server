#pragma once

#include <inttypes.h>

[[noreturn]] inline void unreachable() {
#ifdef __GNUC__ // GCC and Clang
        __builtin_unreachable();
#elif defined(_MSC_VER)
            __assume(false);
#endif
}

enum Type {
    STR,
    INT
};

struct DynVal {
    Type type;
    std::string s;
    int64_t i;
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
    unreachable();
}

static inline
DynEvent parse_line(const Schema& schema, std::string line) {
    DynEvent retval;
    auto cstr = line.c_str();
    for (auto *next = strchr(cstr, ' '); ; cstr = next) {
        auto valcstr = strchr(cstr, '=');
        if (!valcstr) {
            throw std::runtime_error("malformed key/value pair");
        }
        std::string valstr(valcstr);
        std::string left(cstr);
        left.resize(valcstr - cstr - 1);
        auto pcol = schema.find(left);
        if (pcol == schema.end()) {
            throw std::runtime_error("unknown key");
        }
        valstr.resize(std::min(size_t(next - valcstr), strlen(valcstr)));
        retval[left] = parse_val(pcol->second.type, valstr);
        if (!next) {
            break;
        }
    }
    return retval;
}

