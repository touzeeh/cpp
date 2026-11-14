#include <iostream>
using namespace std;
class Student {
public:
    static int count;

    static void showCount() {
        cout << count;
    }
};

int Student::count = 5;

int main() {
    Student::showCount();
    return 0;
};