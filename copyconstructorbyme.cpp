#include <iostream>
using namespace std;
class box{
    public:
    int size;
    box(){ size = 10 ;}
    box(int a){ size = a;}
    box(box &b){ size = b.size;}
};
int main(){
    box b1;
    box b2(30);
    box b3(b2);
    cout<<b1.size<<b2.size<<b3.size;
    return 0;
}