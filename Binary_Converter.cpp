#include <iostream>
#include <string>
using namespace std;

string IntegerToReverseBinary(int integerValue) {
    string integerValues;
    while (integerValue > 0) {
        int x = integerValue % 2;
        if (x == 1) {
            integerValues += "1";
        }
        else {
            integerValues += "0";
        }
        //cout << x;
        //integerValues += 
        integerValue /= 2;
    }
    return integerValues;
}
string ReverseString(string userString) {
    //IntegerToReverseBinary(integerValue);
    string reverse = "";
    for (int i = userString.size() - 1; i >= 0; i--) {
        reverse += userString.at(i);
    }
    cout << reverse << endl;

    return reverse;

}
int main() {
    int integerValue;
    string userString;
    cout << "What decimal number would you like to convert to binary?? (Enter 0 to quit!)" << endl << "Decimal Number: ";
    cin >> integerValue;
    cout << endl;
    while (integerValue != 0) {
        cout << "Converted to binary, " << integerValue << " is ";
        IntegerToReverseBinary(integerValue);
        //userString = integerValues;
        ReverseString(IntegerToReverseBinary(integerValue));
        cout << endl;
        cout << "What other number would you like to convert to binary?" << endl << "Decimal Number: ";
        cin >> integerValue;
        cout << endl;
    }
    if (integerValue == 0)
        cout << "Thank you for using this converter!" << endl;

    return 0;
}
