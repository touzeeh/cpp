#include <iostream>
using namespace std;
class animal{
    public:
    void eat(){ cout<<"hey i am an animal"<<endl;
    }
};
class dog : public animal {
    public : 
    void gay(){
    cout<<"i am a dog"<<endl;}
};
class fish : public dog {
    public:
    void notgay(){
    cout<<"i am a fih" << endl;}
};
int main() {
    dog d1;
    fish f1;
    d1.eat();
    d1.gay();
    f1.eat();
    f1.gay();
    f1.notgay();
    return 0;
}