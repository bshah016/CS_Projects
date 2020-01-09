#include <iostream>
using namespace std;

double DrivingCost(double drivenMiles, double milesPerGallon, double dollarsPerGallon) {
   double cost = 0;
   double cost1 = 0;
   
      cost1 = drivenMiles / milesPerGallon;
      cost = cost1 * dollarsPerGallon;
      
   return cost;
   
}

int main() {
   //double numMiles;
   double mpg;
   double dpg;
   int miles;
   cout << "Miles per Gallon?" << endl << "mpg: ";
   cin >> mpg; 
   cout << "How much does gas cost per the gallon?" << endl << "Gas Price: ";
   cin >> dpg;
   cout << "How many miles would you like to test? (Enter '0' to exit!)" << endl << "Miles: ";
   cin >> miles;
   cout << endl;
   while (miles != 0) {
      cout << DrivingCost(miles, mpg, dpg) << " dollars for " << miles << " miles!" << endl;
      cin >> miles;
   }
   cout << endl;
   

   return 0;
}
