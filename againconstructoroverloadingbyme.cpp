#include <iostream>
using namespace std;
class nigga{
    public:
    nigga(){ cout<<"hey";}
    nigga( int a , int b){ cout<<"Constructor overloading";}
};
int main(){
    nigga n;
    nigga n1(10,20);
    return 0;
} // constructor overloading done