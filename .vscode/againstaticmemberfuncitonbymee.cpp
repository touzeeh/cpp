#include <iostream>
using namespace std;
class counter{
    public:
    static int count;
    static void showcount(){ cout << count;}
};
int counter::count =100;
int main(){
    counter::showcount();
    return 0;
}