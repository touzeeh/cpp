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
class c: public A, public B {
public:
    void show() {
        cout << "c";
    }
};
int main(){
   c obj;
   obj.show();
    return 0;
}