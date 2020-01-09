#include <iostream>
#include <vector>
using namespace std;

void SortVector(vector<int>& myVec) {
    for (unsigned int i = 0; i < myVec.size(); ++i) {
        for (unsigned int j = i + 1; j < myVec.size(); ++j) {
            if (myVec.at(i) != 0) {
                if (myVec.at(i) > myVec.at(j)) {
                    swap(myVec.at(i), myVec.at(j));
                }
            }
        }
        if (i != myVec.size() - 1)
            cout << myVec.at(i) << ", ";
        else {
            cout << myVec.at(i);
        }
    }
}

int main() {
    int input;
    int size;
    cout << "Enter the size of the vector!" << endl << "Size: ";
    cin >> size;
    vector<int> myVec(size);
    for (int i = 0; i < size; ++i) {
        cout << "Enter the value at index " << i << "!" << endl << "Value: ";
        cin >> input;
        myVec.at(i) = input;
    }
    cout << "Here is what the vector looks like before it gets sorted. Take a look!" << endl << "<";
    for (int j = 0; j < size; ++j) {
        if (j != myVec.size() - 1)
            cout << myVec.at(j) << ", ";
        else {
            cout << myVec.at(j);
        }
    }
    cout << ">" << endl << endl;
    //myVec.push_back(10000);
    cout << "This is the sorted vector!" << endl << "<";
    SortVector(myVec);
    cout << ">" << endl;

    return 0;
}
