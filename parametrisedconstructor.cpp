#include<iostream>
using namespace std;
class demo{
    public:
    demo(int x){
        cout<<"the value of x is "<<x<<endl;
    }
};
int main(){
    demo d1(10);
    return 0;
}