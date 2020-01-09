#include <iostream>
#include <vector>
#include <string>
using namespace std;

string GetPhoneNumber(vector<string> nameVec, vector<string> phoneNumberVec, string contactName) {
    for (unsigned int i = 0; i < nameVec.size(); ++i) {
        if (nameVec.at(i) == contactName) {
            cout << phoneNumberVec.at(i);
            return phoneNumberVec.at(i);
        }
    }
    return contactName;
}

int main() {
    string userInput;
    int size;
    cout << "How many contacts would you like to check?" << endl << "Number of Contacts: ";
    cin >> size;
    cout << endl;
    vector<string> nameVec(size);
    vector<string> phoneNumberVec(size);
    for (int i = 0; i < size; i++) {
        cout << "Enter your first name!" << endl;
        cin >> userInput;
        nameVec.at(i) = userInput;
        cout << "Enter their phone number!" << endl;
        cin >> userInput;
        phoneNumberVec.at(i) = userInput;
    }

    string name;
    cout << "Enter the name you want the number for!" << endl << "Name: ";
    cin >> name;
    cout << endl << name << "'s number is ";
    GetPhoneNumber(nameVec, phoneNumberVec, name);
    cout << endl;

    return 0;
}
