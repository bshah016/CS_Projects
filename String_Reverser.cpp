#include <iostream>
using namespace std;

int main() {

   string userInput;
   string reverse;
   
   getline(cin, userInput);
   
   while((userInput != "quit") && (userInput != "q") && (userInput != "Quit")){
    reverse = "";
    for (int i = userInput.size() - 1; i >= 0; i--) {
     reverse += userInput.at(i);  
    }
    cout << reverse << endl;
    getline(cin, userInput);
   }

   return 0;
}
