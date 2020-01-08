#include <iostream>
using namespace std;

int main() {
   int x;
   cout << "----------Welcome to the Decimal to Binary Converter!----------------" << endl;
   cout << "What number do you want to convert to binary? " << endl << "Decimal Number: ";
   cin >> x;
   cout << endl;
   cout << "Binary Number: ";
   while(x > 0) {
    cout << x % 2;
    x = x / 2;
   }
   return 0;
}
