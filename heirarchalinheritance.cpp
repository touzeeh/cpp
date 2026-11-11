#include <iostream>
using namespace std;
class animal {
    public:
    void eat(){ cout<<"nigga"<<endl;}
};
class dog: public animal {
    public:
    void bark(){cout<<"bhau bhau nigga nigga"<<endl;}
};
class cat:public animal {
    public:
    void meow(){cout<<"meow meow nigga nigga"<<endl;}
};
int main(){
    animal a;
    dog d;
    cat c;
    a.eat();
    d.eat();
    d.bark();
    c.eat();
    c.meow();
    return 0;
}