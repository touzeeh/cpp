#include <iostream>
using namespace std;
class animal{
    public:
    void eat(){ cout<<"hey i eat"<<endl;}
};
class dog{
    public:
    void bark(){ cout<<"hey i bark"<<endl;}
};

// animal and dogs combination will give us puppy.
class puppy : public animal , public dog { public:
    void cute(){ cout<<"hey i am puppy"<<endl;}
};
int main(){
    animal a;
    dog d;
    puppy p;
    a.eat();
    d.bark();
    p.cute();
    return 0;
}