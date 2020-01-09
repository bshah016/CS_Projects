#include <iostream>
using namespace std;

int main() {

    int trunkWidth;
    int trunkHeight;
    int leavesWidth;
    
    cout << "Enter trunk height: " << endl;
    cin >> trunkHeight;
    cout << "Enter trunk width: " << endl;
    cin >> trunkWidth;
    while ((trunkWidth % 2) != 1) {
       cout << "Please enter an odd number for the width: " << endl;
       cin >> trunkWidth;
    }
    cout << "Enter leaves width: " << endl;
    cin >> leavesWidth;
    while ((leavesWidth % 2) != 1) {
       cout << "Please enter an odd number for the width: " << endl;
       cin >> leavesWidth;
    }
    
    cout << endl;
    
    for (int i = 1; i <= leavesWidth; i += 2) {
       for (int j = 1; j <= (leavesWidth - i) / 2; j++) {
          cout << " ";
       }
       for (int t = 1; t <= i; t++) {
        cout << "*";  
       }
       cout << endl;
    }
    
    //drawing trunk
    
    for (int i = 1; i <= trunkHeight; i++) {
       for (int j = 1; j <= (leavesWidth - trunkWidth) / 2; j++) {
          cout << " ";
       }
       for (int t = 1; t <= trunkWidth; t++) {
        cout << "*";  
       }
       cout << endl;
    }
    
    
    
    
    
    
    
    
    
    /*
    
    
    cout << "  *"   << endl;
    cout << " ***"  << endl;
    cout << "*****" << endl;

    // Draw trunk
    cout << " ***" << endl;
    cout << " ***" << endl;
    cout << " ***" << endl;
    cout << " ***" << endl;
    */

    return 0;
}
