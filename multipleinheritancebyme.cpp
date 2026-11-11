#include <iostream>
using namespace std;

class Camera {
public:
    void takePhoto() { cout << "Taking a photo..." << endl; }
};

class Phone {
public:
    void makeCall() { cout << "Calling..." << endl; }
};

// Smartphone combines features of both
class Smartphone : public Camera, public Phone {
public:
    void browseInternet() { cout << "Browsing web..." << endl; }
};

int main() {
    Smartphone sp;
    sp.takePhoto();       // from Camera
    sp.makeCall();        // from Phone
    sp.browseInternet();  // from Smartphone
    return 0;
}