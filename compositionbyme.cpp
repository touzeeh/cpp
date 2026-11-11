#include <iostream>
using namespace std;
class Engine{
    public:
    Engine(){
        cout<<" engine is created"<< endl;
    }
    ~Engine(){
        cout<<" engine is destroyed " << endl;
    }
};
class Car{
    private:
    Engine engine;
    public :
    Car(){
        cout<< " Car is created " << endl;}
    ~Car(){
        cout<< " Car is destroyed " << endl;
    }
    };
int main ()
{
    Car c;
    return 0;
}