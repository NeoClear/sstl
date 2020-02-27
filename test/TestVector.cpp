#include "../sstl/all.h"
#include <gtest/gtest.h>

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

TEST(TestVector, InitWithList) {
    sstl::vector<int> arr{1, 2, 3, 4, 5};
    EXPECT_EQ(arr[1], 2);
}

TEST(TestVector, InitWithObjects) {
    sstl::vector<Widget> widgets{Widget(2333), Widget(7483)};
    EXPECT_EQ(widgets[0].getVal(), 2333);
    EXPECT_EQ(widgets[1].getVal(), 7483);
}

TEST(TestVector, Pushback) {
    sstl::vector<Widget> widgets;
    widgets.push_back(Widget(432));
    widgets.push_back(Widget(123));
    EXPECT_EQ(widgets[0].getVal(), 432);
    EXPECT_EQ(widgets[1].getVal(), 123);
}

TEST(TestVector, Size) {
    sstl::vector<Widget> widgets{Widget(0), Widget(0)};
    EXPECT_EQ(widgets.size(), 2);
    widgets.pop_back();
    EXPECT_EQ(widgets.size(), 1);
}

int main(int argc, char *argv[]) {
    std::vector<int>::iterator t;
    
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
