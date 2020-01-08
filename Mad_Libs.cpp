#include <iostream>
#include <string>
using namespace std;

int main() {
   string firstName;
   string genericLocation;
   int wholeNumber;
   string pluralNoun;
   string collegeName;
   int randomNum;
   string major;
   
   cin >> firstName >> genericLocation >> wholeNumber >> pluralNoun >> collegeName >> randomNum >> major;
   
   cout << firstName << " went to " << genericLocation << " to buy " << wholeNumber << " different types of " << pluralNoun << "." << endl;
   cout << "Then, " << firstName << "started to attend " << collegeName << ", majoring in " << major << ". It has been " << " days since he has started." << endl;

   return 0;
}