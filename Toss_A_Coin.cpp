#include <iostream>
#include <cstdlib>
#include <string>
using namespace std;

string HeadsOrTails()
{
  string thing = "";
  int toss = rand() % 2 + 1;
  if (toss == 1) {
    thing = "heads";
  }
  else {
    thing = "tails";
  }
  return thing;
}

int main() {
   
   srand(2);  // Unique seed
   int tosscount = 0;
   int numtosses = 0;
   cout << "How many tosses would you like to simulate?" << endl << "Tosses: ";
  cin >> numtosses;
  cout << endl;
  while (tosscount < numtosses)
  {
    if (HeadsOrTails() == "heads") {
      cout << "HEADS!!!!" << endl;
    }
    else {
      cout << "TAILS!!!!!" << endl;
    }
    tosscount++;
  }
  
   return 0;
}
