#include <iostream>
using namespace std;

int main() {
   long long phoneNumber;
   
   cout << "Enter phone number with no special characters (i.e '-', ',')" << endl;
   cin >> phoneNumber;
   
   int first = (phoneNumber % 10000000) / 10000;
   int second = phoneNumber % 10000;
   int third = phoneNumber / 10000000;
   cout << third << "-" << first << "-" << second << endl;
   
   return 0;
}
