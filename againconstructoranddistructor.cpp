#include <iostream>
using namespace std;
class nigga{ 
    public:
    nigga(){
        cout<<"hey this is constructor"<<endl;
    }
    ~nigga(){
        cout<<"This is distructor"<<endl;
    }
};
int main(){
    nigga n;
    return 0;
}