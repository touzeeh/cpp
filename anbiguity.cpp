#include <iostream>
using namespace std;
class A {
public:
    void show() {
        cout << "A";
    }
};

class B {
public:
    void show() {
        cout << "B";
    }
};
int main(){
    A a1;
    a1.show();
    B b1;
    b1.show();
    return 0;
}