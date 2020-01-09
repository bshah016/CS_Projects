// This program implements the Monte Carlo Method for estimating the value of Pi.

#include <iostream>
#include <cstdlib>
#include <cmath>

using namespace std;


bool isInside(double x, double y, double r) {
    if ((pow((x), 2) + pow((y), 2)) <= pow(r, 2)) {
        return true;
    }
    else {
        return false;
    }
}
bool throwDart(int s) {
    int x, y;
    x = s / 2 - rand() % (s + 1);
    y = s / 2 - rand() % (s + 1);
    return isInside(x, y, s / 2);
}

int main() {
    srand(333);
    int squareSide = 0;  
    int totalTries = 0; 

    cout << "How long is one side of the square?" << endl;
    cin >> squareSide;
    cout << endl;
    cout << "How many times would you like to try?" << endl;
    cin >> totalTries;
    cout << endl << endl;

    int inCircleCount = 0; 
    for (int i = 0; i < totalTries; ++i) {
        if (throwDart(squareSide) == true)
            inCircleCount++;
    }
    cout << "Based on data provided, pi is estimated to be " << 4 * (static_cast<double>(inCircleCount) / static_cast<double>(totalTries)) << "." << endl;

    return 0;
}