#include <iostream>
using namespace std;
class nigga{
    public:
    static int count;
    nigga(){ count++;}  
};
int nigga:: count =0;
int main(){
    nigga n1,n2;
    cout<<"Total objects"<< nigga::count;
    return 0;
}