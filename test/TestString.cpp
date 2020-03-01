#include "../sstl/All.h"
#include <gtest/gtest.h>
#include <iostream>

using namespace sstl;
using namespace sstl::Console;
using namespace std;

TEST(TestString, Init) {
    String s1 = "Timba", s2 = "Pimba";
    ASSERT_STREQ("Timba", s1.cStr());
    ASSERT_STREQ("Pimba", s2.cStr());
}

TEST(TestString, Compare) {
    String s1 = "Inno", s2 = "inno";
    ASSERT_EQ(-1, s1.compareTo(s2));
    ASSERT_NE(0, s1.compareTo(s2));
}

int main(int argc, char *argv[]) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
