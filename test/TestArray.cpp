#include "../sstl/All.h"
#include <gtest/gtest.h>

using namespace sstl;
using namespace sstl::Console;

class Widget {
    private:
        int val = 0;
    public:
        Widget(int val) {
            this->val = val;
        }
        int getVal() {
            return val;
        }
    };

TEST(TestArray, InitWithList) {
    sstl::Array<int> arr{1, 2, 3, 4, 5};
    EXPECT_EQ(arr[1], 2);
}

TEST(TestArray, InitWithObjects) {
    sstl::Array<Widget> widgets{Widget(2333), Widget(7483)};
    EXPECT_EQ(widgets[0].getVal(), 2333);
    EXPECT_EQ(widgets[1].getVal(), 7483);
}

TEST(TestArray, Pushback) {
    sstl::Array<Widget> widgets;
    widgets.push(Widget(432));
    widgets.push(Widget(123));
    EXPECT_EQ(widgets[0].getVal(), 432);
    EXPECT_EQ(widgets[1].getVal(), 123);
}

TEST(TestArray, Size) {
    sstl::Array<Widget> widgets{Widget(0), Widget(0)};
    EXPECT_EQ(widgets.size(), 2);
    widgets.pop();
    EXPECT_EQ(widgets.size(), 1);
}

TEST(TestArray, ForEach) {
    Array<int> t{1, 2, 3, 4, 5};
    for (const auto& it : t) {
        print(it);
        print('\n');
    }
}

int main(int argc, char *argv[]) {
    std::vector<int>::iterator t;
    
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
