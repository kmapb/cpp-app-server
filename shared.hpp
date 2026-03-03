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

static inline DynVal
parse_val(Type type, string sval) {
    switch (type) {
        case INT: {
            DynVal retval { INT, "", 0 };
            retval.i = strtoll(sval.c_str(), sval.c_str() + sval.size(), 10);
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

