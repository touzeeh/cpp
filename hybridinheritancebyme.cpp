#include <iostream>
using namespace std;
class a{
    public:
    void heyfora(){ cout<<"hey i am a"<<endl;}
};
class b: public a{
    public:
    void heyforb(){ cout<<"hey i am b"<<endl;}
};
class c:public b{
    public:
    void heyforc(){ cout<<"hey i am c"<<endl;}
};
class d:public a{
    public:
    void heyford(){ cout<<"hey i am d"<<endl;}
}; 
int main(){
    a a1;
    b b1;
    c c1;
    d d1;
    a1.heyfora();
    b1.heyforb();
    c1.heyforc();
    d1.heyford();


}