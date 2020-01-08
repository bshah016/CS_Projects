#include <iostream>
using namespace std;

int main() {
   
   int int1;
   int int2;
   int int3;
   cout << "Enter three numbers separated by spaces and I'll find the maximum: ";
   cin >> int1 >> int2 >> int3;
   
   if ((int1 >= int2) && (int1 >= int3)) {
    cout << "Maximum of " << int1 << ", " << int2 << ", and " << int3 << " is..... " << int1 << "!!!" << endl;  
   }
   else if ((int2 >= int1) && (int2 >= int3)) {
    cout << "Maximum of " << int1 << ", " << int2 << ", and " << int3 << " is..... " << int2 << "!!!" << endl;  
   }
   else if ((int3 >= int1) && (int3 >= int2)) {
    cout << "Maximum of " << int1 << ", " << int2 << ", and " << int3 << " is..... " << int3 << "!!!" << endl;  
   }
   return 0;
}