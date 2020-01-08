#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

int main() {
   
   string pass;
   cout << "Want to make your password stronger?" << endl << "Enter your current password and let's see if we can make it stronger!" << endl << "Current Password: ";
   getline(cin, pass);
   cout << "Strengthened Password: ";
   unsigned int i;
   unsigned int a;
   unsigned int m;
   unsigned int b;
   unsigned int o;
   i = pass.find('i'); 
   a = pass.find('a'); 
   m = pass.find('m');
   b = pass.find('B');
   o = pass.find('o');
   
   if (i <= pass.size()) {
    replace(pass.begin(), pass.end(), 'i', '!');  
   }
   if (a <= pass.size()) {
    replace(pass.begin(), pass.end(), 'a', '@');  
   }
   if (m <= pass.size()) {
    pass.replace(m, m + 1, "M");  
   }
   if (b <= pass.size()) {
    replace(pass.begin(), pass.end(), 'B', '8');  
   }
   if (o <= pass.size()) {
    replace(pass.begin(), pass.end(), 'o', '.'); 
   }
   
   
   cout << pass << endl;
   cout << "Now your password is very strong!!" << endl;
   
   

   return 0;
}