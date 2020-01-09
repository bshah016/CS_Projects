#include <iostream>
using namespace std;


double PyramidVolume(double baseLength, double baseWidth, double pyramidHeight) {
    double baseArea = baseLength * baseWidth;
    double volume = baseArea * pyramidHeight * (static_cast<double>(1) / 3);
    return volume;
}


int main() {
    double userLength;
    double userWidth;
    double userHeight;
    cout << "What is the length of the base of the pyramid? " << endl << "Length of Base: ";
    cin >> userLength;
    cout << endl;
    cout << "What is the width of the base of the pyramid? " << endl << "Width of Base: ";
    cin >> userWidth;
    cout << endl;
    cout << "What is the height of the base of the pyramid? " << endl << "Height of Pyramid: ";
    cin >> userHeight;
    cout << endl;

    cout << "Volume of Pyramid: " << PyramidVolume(userLength, userWidth, userHeight) << "units cubed" << endl;

    return 0;
}