#include<iostream>
using namespace std;
class myclass{
    public:
    int size;
    myclass(){ size = 10;}
    myclass(myclass &b){ size = b.size;}
};
int main(){
    myclass b2;
    myclass m(b2);
    cout<<m.size<<endl;
    return 0;
}