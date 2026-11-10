#include<iostream>
using namespace std;
class niggapro{
    public:
    static int count;
    niggapro(){count++;}
    static void show(){cout<<"TOTAL OBJECTS ARE AS FOLLOWS NIGGA WATCH THIS"<<count;}
};
int niggapro::count=0;
int main(){
    niggapro n1,n2;
    niggapro::show();
    return 0;
}