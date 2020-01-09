#include <iostream>
using namespace std;

bool IsLeapYear(int userYear) {
   bool isLeapYear = false;
   
   if ((userYear % 100 == 0) && (userYear % 400 == 0)) { 
      isLeapYear = true;
   }
   else if ((userYear % 4 == 0) && (userYear % 100 != 0)) {
      //cout << inputYear << " is a leap year." << endl;
      isLeapYear = true;
   }
   else {
    //cout << inputYear << " is not a leap year." << endl;  
    isLeapYear = false;
   }  
   
   return isLeapYear;
   
}

int main() {
   int userYear;
   cin >> userYear;
   if (IsLeapYear(userYear) == true) {
   cout << userYear << " is a leap year." << endl;
   }
   else {
    cout << userYear << " is not a leap year." << endl;  
   }

   return 0;
}
