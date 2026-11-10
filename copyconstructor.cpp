#include <iostream>
using namespace std;

class Box {
public:
    int size;
    Box() { size = 10; }                  // 1. Default
    Box(int s) { size = s; }              // 2. Parameterized
    Box(Box &b) { size = b.size; }        // 3. Copy
};

int main() {
    Box b1;        // Calls Default
    Box b2(20);    // Calls Parameterized
    Box b3(b2);    // Calls Copy
    cout << b1.size << " " << b2.size << " " << b3.size;
    return 0;
}