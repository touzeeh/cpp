#include <iostream>
using namespace std;
class a{
    public:
    void heyfora(){ cout<<"hey i am a"<<endl;}
};
class b: virtual public a{
    public:
    void heyforb(){ cout<<"hey i am b"<<endl;}
};
class c:virtual public b{
    public:
    void heyforc(){ cout<<"hey i am c"<<endl;}
};
class d:virtual public b, virtual public c{
    public:
    void heyford(){ cout<<"hey i am d"<<endl;}
}; 
int main(){
    d obj;
    obj.heyfora(); // Accessible without ambiguity due to virtual inheritance
    obj.heyforb();
    obj.heyforc();
    obj.heyford();
    return 0;
}