#include <iostream>
using namespace std;

int main() {

   double mpg;
   double dpg;
   int miles;
   cout << "Miles per gallon for your car: ";
   cin >> mpg;
   cout << "Dollars per gallon in your area: ";
   cin >> dpg;
   cout << "How many miles do you want to test? (Enter 0 to quit)";
   cin >> miles;
   cout << (miles / mpg) * dpg << endl;
   while (miles != 0) {
    cout << "How many miles do you want to test? (Enter 0 to quit)";
    cin >> miles;
    cout << (miles / mpg) * dpg << endl;
   }
   
   

   return 0;
}
