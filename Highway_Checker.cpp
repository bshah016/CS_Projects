#include <iostream>
using namespace std;

int main() {
   int highwayNumber;
   cout << "~~~~~~~~~~~~~Highway Checker~~~~~~~~~~~~~~~~~~~~~~~~" << endl;
   cout << "What highway would you like to check?" << endl << "Highway Number: ";
   cin >> highwayNumber;

   if ((highwayNumber % 2 == 1) && (highwayNumber <= 99) && (highwayNumber >= 1)) {
    cout << "The " << highwayNumber << " is primary, going north/south." << endl;  
   }
   else if ((highwayNumber % 2 == 0) && (highwayNumber <= 99) && (highwayNumber >= 1)) {
    cout << "The " << highwayNumber << " is primary, going east/west." << endl;  
   }
   else if ((highwayNumber % 2 == 1) && (highwayNumber <= 999) && (highwayNumber >= 100)) {
      int finale = (highwayNumber % 100);
    cout << "The " << highwayNumber << " is auxiliary, serving the " << finale << ", going north/south." << endl;  
   }
   else if ((highwayNumber % 2 == 0) && (highwayNumber <= 999) && (highwayNumber >= 100)) {
      int finales = (highwayNumber % 100);
    cout << "The " << highwayNumber << " is auxiliary, serving the " << finales << ", going east/west." << endl;  
   }
   else {
    cout << highwayNumber << " is not a valid interstate highway number." << endl;  
   }

   return 0;
}
