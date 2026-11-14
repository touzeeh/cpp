#include <iostream>
using namespace std;
class counter{
    public:
    static int count;
    static void showcount(){
        cout<<count;
    }
};
int counter::count=10;
int main(){
    counter c1,c2;
    counter::showcount();
    return 0;
}