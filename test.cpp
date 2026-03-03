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


int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}
