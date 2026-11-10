#include <iostream>
using namespace std;
class animal{
    public:
    void eat(){ cout<<"hey i am animal pro max"<<endl;}
};
class dog: public animal {
    void bark(){ cout<<" meow meow meow " << endl;}
};
int main(){
    dog d1;
    return 0;
}