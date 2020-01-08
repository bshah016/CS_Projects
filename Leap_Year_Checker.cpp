#include <iostream>
using namespace std;

int main() {
   int inputYear;
   //bool isLeapYear = false;
   cout << "~~~~~~~~~~~~~~~~~~Welcome to the Leap Year Checker!~~~~~~~~~~~~~~~~" << endl;
   cout << "What year do you want to test?" << endl << "Year: ";
   cin >> inputYear;
   
   if ((inputYear % 100 == 0) && (inputYear % 400 == 0)) {
      cout << inputYear << " is a leap year!!" << endl; 
      //isLeapYear = true;
   }
   else if ((inputYear % 4 == 0) && (inputYear % 100 != 0)) {
      cout << inputYear << " is a leap year!!" << endl;
      //isLeapYear = true;
   }
   else {
    cout << inputYear << " is not a leap year!!" << endl;  
    //isLeapYear = false;
   }

   return 0;
}