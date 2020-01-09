#include <iostream>
#include <string>
#include <cctype>
using namespace std;
string CreateAcronym(string userPhrase) {
    string output;
    for (unsigned int i = 0; i < userPhrase.size(); ++i) {
        if (isupper(userPhrase.at(i))) {
            output += userPhrase.at(i);
        }
    }
    return output;
}

int main() {
    string output;
    cout << "What phrase would you like to create an acronym for?" << endl << "Phrase: ";
    getline(cin, output);
    cout << endl;
    cout << "Acronym: " << CreateAcronym(output) << endl;;

    return 0;
}