#include<iostream>
using namespace std;
class nigga{
    public:
    static int count;
    nigga(){count++;}
};
int nigga::count =0;
int main(){
    nigga n1,n2,n3,n4;
    cout<<nigga::count;
    return 0;
}