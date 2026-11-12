#include <iostream>
using namespace std;
class myclass{
    public:
    int size;
    myclass(){ size = 10;}
    myclass(int a){ size = a;}
    myclass(myclass &c){ size = c.size ;}
};
int main(){
    myclass m;
    myclass m1(190);
    myclass m2(m1);
    cout<<m.size<<m1.size<<m2.size<<endl;
    return 0;
}