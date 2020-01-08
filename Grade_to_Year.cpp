#include <iostream>
using namespace std;

int main() {

    int schoolYear;
    string conf;
    cout << "What grade are you in? " << endl << "Grade: ";
    cin >> schoolYear;
    if ((schoolYear >= 0) && (schoolYear <= 5)) {
     cout << "You are in Elementary School" << endl << "Was I correct?!  ";
     cin >> conf;
     if (conf == "Yes" || conf == "yes") {
         cout << "I KNEW IT!! I AM A GENIUS COMPUTER.. wait that means I'm like all other computers.. DRAT!!" << endl;
     }
      else {
       cout << "Mission Failed: We'll get 'em next time chief" << endl;  
      }
    }
    else if ((schoolYear >= 6) && (schoolYear <= 8)) {
     cout << "You are in Middle school" << endl << "Was I correct?!  ";  
     cin >> conf;
     if (conf == "Yes" || conf == "yes") {
         cout << "I KNEW IT!! I AM A GENIUS COMPUTER.. wait that means I'm like all other computers.. DRAT!!" << endl;
     }
      else {
       cout << "Mission Failed: We'll get 'em next time chief" << endl;  
      }
    }
    else if ((schoolYear >= 9) && (schoolYear <= 12)) {
     cout << "You are in High school" << endl << "Was I correct?!  ";  
     cin >> conf;
     if (conf == "Yes" || conf == "yes") {
         cout << "I KNEW IT!! I AM A GENIUS COMPUTER.. wait that means I'm like all other computers.. DRAT!!" << endl;
     }
      else {
       cout << "Mission Failed: We'll get 'em next time chief" << endl;  
      }
    }
    else if ((schoolYear >= 13) && (schoolYear <= 16)) {
     cout << "You are in College" << endl << "Was I correct?!  ";  
     cin >> conf;
     if (conf == "Yes" || conf == "yes") {
         cout << "I KNEW IT!! I AM A GENIUS COMPUTER.. wait that means I'm like all other computers.. DRAT!!" << endl;
     }
      else {
       cout << "Mission Failed: We'll get 'em next time chief" << endl;  
      }
    }
    else if (schoolYear >= 17) {
       cout << "You are in Post-secondary" << endl << "Was I correct?!  ";
       cin >> conf;
     if (conf == "Yes" || conf == "yes") {
         cout << "I KNEW IT!! I AM A GENIUS COMPUTER.. wait that means I'm like all other computers.. DRAT!!" << endl;
     }
      else {
       cout << "Mission Failed: We'll get 'em next time chief" << endl;  
      }
    }
    else {
     cout << "That is an Invalid Year... Come on now!" << endl;  
     cin >> conf;
      cout << "Was I correct?!  ";
      cin >> conf;
     if (conf == "Yes" || conf == "yes") {
         cout << "I KNEW IT!! I AM A GENIUS COMPUTER.. wait that means I'm like all other computers.. DRAT!!" << endl;
     }
      else {
       cout << "Mission Failed: We'll get 'em next time chief" << endl;  
      }
    }
    
   return 0;
}
