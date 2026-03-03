#include <gtest/gtest.h>
#include "shared.hpp"

using namespace std;

TEST(DynVal, empty_str) {
    auto ret = parse_val(STR, "");
    EXPECT_EQ(ret.type, STR);
    EXPECT_EQ(ret.s, string(""));
}

int main(int argc, char** argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();

}
