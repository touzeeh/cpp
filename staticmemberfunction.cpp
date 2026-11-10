#include<iostream>
using namespace std;
class nigga{
    public:
    static int count;
    nigga(){count++;}
    static void show() { cout << " Total objects: " << count; }
};
int nigga::count=0;
int main(){
    nigga n1;

    cout<<nigga::count;
    nigga::show();
    return 0;
}