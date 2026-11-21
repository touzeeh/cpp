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
    };
int main(){
   c obj;
  // obj.show();  
   obj.A :: show();
   obj.B :: show(); //error AMBIGUOUS
    return 0;
}}}