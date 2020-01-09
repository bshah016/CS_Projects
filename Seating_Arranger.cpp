#include <iostream>
using namespace std;

int main() {
    int numRows;
    int numColumns;
    int currentRow;
    int currentColumn;
    char currentColumnLetter;
    cout << "How many rows? " << endl << "Rows: ";
    cin >> numRows;
    cout << endl;
    cout << "How many columns?" << endl << "Columns: ";
    cin >> numColumns;
    cout << endl << endl;
    cout << "Seating arrangement: " << endl;


    for (currentRow = 1; currentRow <= numRows; currentRow++) {
        for (currentColumn = 0; currentColumn <= numColumns; currentColumn++) {

            currentColumnLetter = currentColumn + 65;
            cout << currentRow << currentColumnLetter << " ";
        }
    }

    cout << endl;

    return 0;
}