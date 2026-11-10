#include<iostream>
using namespace std;
class hellna{
    public:
    static int x;
    hellna(){ x++ ;}
    int hellna::x = 0;
};
    
int main(){
    hellna h1,h2,h3;
    cout<<hellna::x;
    return 0;
}