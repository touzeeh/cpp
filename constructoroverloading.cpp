#include<iostream>
using namespace std;
class myclass{
    public:
    myclass(){ cout<<"hey nigga"<<endl;}
    myclass(int a , int b){ cout<<"bye nigga"<<endl;
    }
};
int main(){
    myclass hey1;
    myclass hey2(10,70);
    return 0;
}