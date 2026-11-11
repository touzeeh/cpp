#include <iostream>
using namespace std;
class a{ 
    public:
    void show(){ cout<< "A"<< endl;}
};
class b{ 
    public:
    void show(){ cout<< "B"<< endl;}
};

class c : public a, public b{ 
};
int main (){
    c obj;
    obj.a::show();
    obj.b::show();
    return 0;
}


