#include <iostream>
using namespace std;
class a{
    public:
    void showa(){cout<<"this is a"<<endl;}
};
class b: virtual public a {
    public:
    void showb(){cout<<"this is b"<<endl;}
};
class c:virtual public a {
    public:
    void showc(){cout<<"this is c"<<endl;}
};
class d:virtual public b, virtual public c {
    public:
    void showd(){cout<<"this is d"<<endl;}
};
int main(){
    d d1;
    d1.showa();
     d1.showb();
      d1.showc();
       d1.showd();
        return 0;
}
