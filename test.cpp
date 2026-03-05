#include <gtest/gtest.h>
#include "shared.hpp"

using namespace std;

TEST(DynVal, empty_str) {
    auto ret = parse_val(STR, "");
    EXPECT_EQ(ret.type, STR);
    EXPECT_EQ(ret.s, string(""));
}

TEST(DynVal, nonempty_str) {
    auto ret = parse_val(STR, "Tomaco");
    EXPECT_EQ(ret.type, STR);
    EXPECT_EQ(ret.s, string("Tomaco"));
}

TEST(DynVal, posinteger) {
    auto ret = parse_val(INT, "10789");
    EXPECT_EQ(ret.type, INT);
    EXPECT_EQ(ret.i, 10789);
}


const auto kTestSchema = Schema {
    { "field0", { INT } },
    { "field1", { STR } },
    { "nullable", { STR, true } },
};

DynVal dstr (const char* s) {
    return DynVal { STR, s, 0 };
};
DynVal dint(int64_t i) {
    return DynVal { INT, "", i };
}
TEST(Parsing, parseline) {
    const auto kStr = "   field0=666      field1=snoot nullable=boot   ";
    auto ret = parse_line(kTestSchema, kStr);
    DynEvent exp {
        { "field0", dint(666) },
        { "field1", dstr("snoot") },
        { "nullable", dstr("boot") },
    };
    EXPECT_EQ(ret, exp);
}

TEST(Parsing, parseline_required) {
    const auto kStr = "   field0=666    nullable=boot   ";
    EXPECT_THROW(parse_line(kTestSchema, kStr), std::runtime_error);
}

TEST(Parsing, parseline_bogus) {
    const auto kStr = "   field1=cowabunga field1000=666    nullable=boot   ";
    EXPECT_THROW(parse_line(kTestSchema, kStr), std::runtime_error);
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}
