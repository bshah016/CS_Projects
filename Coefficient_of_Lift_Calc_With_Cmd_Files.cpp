#include <iostream>
#include <vector>
#include <fstream>

using namespace std;

void readData(const string& flight, vector<double>& v, vector<double>& vv) {
    ifstream inFS;
    inFS.open(flight);
    if (!inFS.is_open()) {
        cout << "Error opening " << flight << endl;
        exit(1);
    }
    double nums;
    double dubs;
    while (!inFS.eof()) {
        inFS >> nums;
        if (!inFS.fail()) {
            v.push_back(nums);
            inFS >> dubs;
            vv.push_back(dubs);
        }
    }
}
double interpolation(double qst, const vector<double>& v, const vector<double>& vv) {
    double desr = 0.0;
    double lower_angle = 0.0;
    double low_coeff = 0.0;
    double high_angle = 0.0;
    double high_coeff = 0.0;
    for (unsigned int i = 0; i < v.size(); ++i) {
        if (v.at(i) == qst) {
            //cout << vv.at(i);
            return vv.at(i);

        }
        else {
            for (unsigned int i = 0; i < v.size(); ++i) {
                if (v.at(i) < qst) {
                    lower_angle = v.at(i);
                    low_coeff = vv.at(i);
                    //break;
                }
            }
            for (unsigned int j = 0; j < v.size(); ++j) {
                if (v.at(j) > qst) {
                    high_angle = v.at(j);
                    high_coeff = vv.at(j);
                    break;
                }
                }
                
            }
        desr = low_coeff + ((qst - lower_angle) / (high_angle - lower_angle)) * (high_coeff - low_coeff);
    }
    return desr;

}
bool isOrdered(const vector<double>& v) {
    if (v.size() > 1) {
        for (unsigned int i = 0; i < v.size() - 1; ++i) {
            if (v.at(i) > v.at(i + 1)) {
                return false;
            }
        }
    }
    return true;
}
void reorder(vector<double>& v, vector<double>& vv) {
    //int temp;
    //int temp2;
    for (unsigned int i = 0; i < v.size(); ++i) {
        for (unsigned int j = i + 1; j < v.size(); ++j) {
            if (v.at(i) != 0) {
                if (v.at(i) > v.at(j)) {
                    swap(v.at(i), v.at(j));
                    swap(vv.at(i), vv.at(j));
                }
            }
        }
    }
}
int main(int argc, char* argv[]) {
    vector<double> v;
    vector<double> vv;
    double thing;
    string answer;
    string file1;
    file1 = argv[1];
    readData(file1, v, vv);
    cout << "What thing would you like to interpolate? : ";
    cin >> thing;
    cout << endl;
    reorder(v, vv);
    cout << interpolation(thing, v, vv);
    cout << "Would you like to do it again? " << endl;
    cin >> answer;
    while (answer == "Yes" || answer == "yes") {
        cout << "enter value" << endl;
        cin >> thing;
        cout << "Value is " << interpolation(thing, v, vv) << endl;
        cout << "Would you like to do it again? " << endl;
        cin >> answer;
    }


}