#include <iostream>
#include <cmath>
using namespace std;

int main() {

   int change;
   int dollars;
   //int dollaramt;
   int quarters;
   //int quarteramt;
   int dimes;
   //int dimeamt;
   int nickels;
   //int nickelamt;
   int penny;
   //int pennyamt;
   cout << "~~~~~~~~~~~~~~~~~~~~~~~Welcome to the Exact Change Calculator~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
   cout << "How much do you want to convert to exact change?" << endl << "Amount: ";
   cin >> change;
    if (change <= 0) {
    cout << "No Change" << endl;  
    }
    if (change / 100 != 0) {
       dollars = change / 100;
     change = change - (dollars * 100);
     if (dollars == 1) {
      cout << dollars << " dollar" << endl;  
     }
     else {
      cout << dollars << " dollars" << endl;  
     }
    }
    if (change / 25 != 0) {
     quarters = change / 25;
     change = change - (quarters * 25);
     if (quarters == 1) {
      cout << quarters << " quarter" << endl;  
     }
     else {
      cout << quarters << " quarters" << endl;  
     }
    }
    if (change / 10 != 0) {
       dimes = change / 10;
     change = change - (dimes * 10);
     if (dimes == 1) {
      cout << dimes << " dime" << endl;  
     }
     else {
      cout << dimes << " dimes" << endl;  
     }
    }
    if (change / 5 != 0) {
       nickels = change / 5;
     change = change - (nickels * 5);
     if (nickels == 1) {
      cout << nickels << " nickel" << endl;  
     }
     else {
      cout << nickels << " nickels" << endl;  
     }
    }
    if (change / 1 != 0) {
       penny = change / 1;
     change = change - (penny * 1);
     if (penny == 1) {
      cout << penny << " penny" << endl;  
     }
     else {
      cout << penny << " pennies" << endl;  
     }
    }
    
   

   return 0;
}