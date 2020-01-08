#include <iostream>
using namespace std;

int main() {
   cout << "--------------------Welcome to the Calorie Calculator------------------------------" << endl;
   double age;
   double weight;
   double hr;
   double time;
   double calMen;
   double calWomen;
   string gender;
   cout << "Male or Female? " << endl << "Gender: ";
   cin >> gender;
   cout << endl;
   cout << "What is your age? " << endl << "Age: ";
   cin >> age;
   cout << endl;
   cout << "How much do you weigh(in pounds)?" << endl << "Weight: ";
   cin >> weight;
   cout << endl;
   cout << "What was your average heart rate(beats per minute)?" << endl << "HR in BPM: ";
   cin >> hr;
   cout << endl;
   cout << "How long did you work out for (minutes)?" << endl << "Time: ";
   cin >> time;
   cout << endl;
   
   //cin >> age >> weight >> hr >> time;
  
   calMen = ((age * 0.2017) - (weight * 0.09036) + (hr * 0.6309) - 55.0969) * time / 4.184;
   calWomen = ((age * 0.074) - (weight * 0.05741) + (hr * 0.4472) - 20.4022) * time / 4.184;
    if (gender == "Male" || gender == "male") {
       cout << "~ ~ ~ Calories Burned ~ ~ ~ " << endl;
       if (calMen > 0)
       cout << calMen << " calories." << endl;
       else {
        cout << "You burned a very minute amount of calories!! Start working out more if you want to lose weight!!!" << endl;  
       }
    }
    if (gender == "Female" || gender == "female") {
       cout << "~ ~ ~ Calories Burned ~ ~ ~ " << endl;
       if (calWomen > 0)
       cout << calWomen << " calories." << endl;
       else {
        cout << "You burned a very minute amount of calories!! Start working out more if you want to lose weight!!!" << endl;  
       }
    }
   
   return 0;
}
