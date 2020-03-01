#include "../sstl/All.h"
#include <gtest/gtest.h>

using namespace sstl;
using namespace sstl::Console;
using namespace std;

class Widget : public Printable {
public:
    String<> t = "Gei Ye Pa";
    String<> toString() override {
        return t;
    }
};

int main(int argc, char *argv[]) {
    // print("fdsa\n");
    // print(432987);
    // print(432.432);
    Widget w;
    print(w.toString().length());
    print(w);
    // testing::InitGoogleTest(&argc, argv);
    // return RUN_ALL_TESTS();
}
