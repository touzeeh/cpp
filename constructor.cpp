#include <iostream>
using namespace std;

class Demo {
public:
    Demo() { cout << "Constructor called\n"; }
    ~Demo() { cout << "Destructor called\n"; }
};

int main() {
    Demo obj; // Calls constructor now, destructor at end of main()
    return 0;
}