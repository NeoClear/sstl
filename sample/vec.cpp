#include <sstl/all.h>
#include <iostream>

using namespace std;

int main() {
    sstl::vector<int> s{1, 2, 3, 4, 5};
    for (int i = 0; i < s.size(); i++)
        cout << s[i] << endl;
}
