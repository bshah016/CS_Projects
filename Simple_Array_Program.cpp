//include any standard libraries needed
#include <fstream>
#include <iostream>

using namespace std;

//  - Passes in an array along with the size of the array.
//  - Returns the mean of all values stored in the array.
double mean(const double array[], int arraySize) {
    double avg = 0.0;
    double sum = 0.0;
    double num = 0.0;
    for (int i = 0; i < arraySize; ++i) {
        sum += array[i];
        num += 1.0;
    }

    avg = sum / num;
    return avg;
}

//  - Passes in an array, the size of the array by reference, and the index of a value to be removed from the array.
//  - Removes the value at this index by shifting all of the values after this value up, keeping the same relative order of all values not removed.
//  - Reduces arraySize by 1.
void remove(double array[], int& arraySize, int index) {
    for (int i = 0; i < arraySize - 1; ++i) {
        double temp = array[index];
        if (i >= index) {
            array[i] = array[i + 1];
        }
        else if(i == index) {
            array[i + 1] = temp;
        }
      
    }
    arraySize -= 1;

}


// - Passes in an array and the size of the array.
// - Outputs each value in the array separated by a comma and space, with no comma, space or newline at the end.
void display(const double array[], int arraySize) {
    for (int i = 0; i < arraySize; ++i) {
        if (i == arraySize - 1) {
            cout << array[i];
        }
        else {
            cout << array[i] << ", ";
        }
    }
}


const int ARR_CAP = 100;

int main(int argc, char *argv[]) {
    double num;
    int counter = 0;
    int index;
   // verify file name provided on command line
    ifstream inFS;

   // open file and verify it opened
    inFS.open(argv[1]);
    if (!inFS.is_open()) {
        cerr << "Error opening file: " << argv[1] << endl;
    }
   // Declare an array of doubles of size ARR_CAP.
    double array[ARR_CAP];
    
   // Fill the array with up to ARR_CAP doubles from the file entered at the command line.
    while (inFS >> num) {
        array[counter] = num;
        counter++;
    }
   // Call the mean function passing it this array and output the 
   // value returned.
    cout << "Mean: " << mean(array, counter) << endl;
   // Ask the user for the index (0 to size - 1) of the value they want to remove.
    cout << "Enter index of value to be removed (0 to " << counter - 1 << "): ";
    cin >> index;
    cout << endl;
	
   // Call the display function to output the array.
    cout << "Before removing value: ";
        display(array, counter);
        cout << endl;

        // Call the remove function to remove the value at the index
        // provided by the user.
        remove(array, counter, index);
    
   // Call the display function again to output the array
   // with the value removed.
        cout << "After removing value: ";
        display(array, counter);
        cout << endl;
   
   // Call the mean function again to get the new mean
        cout << "Mean: " << mean(array, counter);
   
	return 0;
}