#include <iostream>
using namespace std;
class animal {
    public:
    void eat(){ cout<<"any animal is eating....."<<endl;}
};
class dog {
    public:
    void eat(){ cout<<"dog is eating....."<<endl;}
};
class cat {
    public:
    void eat(){ cout<<"cat is eating....."<<endl;}
};
int main(){
    animal a;
    dog d;
    cat c;
    a.eat();
    d.eat();
    c.eat();
    return 0;
}      // wrong code nigga

