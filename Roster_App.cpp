#include <iostream>
#include <vector>
// FIXME include vector library
using namespace std;

// parameter order will always be jersey #s then ratings
int quit() {
    return 0;
}
void outputRoster(const vector<int>& num, const vector<int>& r) {
    int j = 1;
    cout << "ROSTER" << endl;
    for (unsigned int i = 0; i < num.size(); ++i) {
        cout << "Player " << j << " -- Jersey number: " << num.at(i) << ", Rating: " << r.at(i) << endl;
        j++;
    }
}
void addPlayer(vector<int>& num, vector<int>& r) {
    int j = num.size() + 1;
    int nums;
    cout << "Enter another player's jersey number:" << endl;
    cin >> nums;
    //num.resize(j);
    num.push_back(nums);
    cout << "Enter another player's rating:" << endl;
    cin >> nums;
    //r.resize(j);
    r.push_back(nums);
    j++;

}
void removePlayer(vector<int>& num, vector<int>& r) {
    int nums;
    //int rate;
    vector<int> v(num.size() - 1);
    vector<int> n(num.size() - 1);
    cout << "Enter a jersey number: " << endl;
    cin >> nums;
    for (unsigned int i = 0; i < num.size(); ++i) {
        if (num.at(i) == nums) {
            num.erase(num.begin() + i);
            r.erase(r.begin() + i);
        }

    }
}
void updatePlayerRating(const vector<int>& num, vector<int>& r) {
    int nums;
    int rate;
    cout << "Enter a jersey number:" << endl;
    cin >> nums;
    cout << "Enter a new rating for player:" << endl;
    cin >> rate;
    for (unsigned int i = 0; i < num.size(); ++i) {
        if (num.at(i) == nums)
            r.at(i) = rate;
    }
}
void outputPlayersAboveRating(const vector<int>& num, const vector<int>& r) {
    int rate;
    // int ind;
    unsigned int i = 0;
    // int j = 1;
    cout << "Enter a rating: " << endl;
    cin >> rate;
    cout << endl << endl;
    cout << "PLAYERS ABOVE RATING" << rate << ": " << endl;
    //while(r.at(i) > rate) {
    for (i = 0; i < r.size(); ++i) {
        if (r.at(i) > rate) {
            cout << "Player " << i + 1 << " -- Jersey number: " << num.at(i) << ", Rating: " << r.at(i) << endl;
            // i = i - 1;
        }
        //j = j + i;
    }
}


int main() {
    int jernum;
    int rate;
    char ch;
    vector<int> nums(5, 0);
    vector<int> rates(5, 0);
    int j = 1;
    for (unsigned int i = 0; i < nums.size(); ++i) {
        cout << "Enter player " << j << "'s jersey number:" << endl;
        cin >> jernum;
        nums.at(i) = jernum;
        cout << "Enter player " << j << "'s rating:" << endl;
        cin >> rate;
        rates.at(i) = rate;
        j++;
        cout << endl;
    }
    //cout << endl;
    outputRoster(nums, rates);

    cout << endl << "MENU" << endl;
    cout << "a - Add player" << endl << "d - Remove player" << endl << "u - Update player rating" << endl << "r - Output players above a rating" << endl;
    cout << "o - Output roster" << endl << "q - Quit" << endl << endl << "Choose an option:" << endl;
    cin >> ch;
    while (ch != 'q' || ch == 'Q') {
        if (ch == 'a' || ch == 'A') {
            addPlayer(nums, rates);
            cout << endl << "MENU" << endl;
            cout << "a - Add player" << endl << "d - Remove player" << endl << "u - Update player rating" << endl << "r - Output players above a rating" << endl;
            cout << "o - Output roster" << endl << "q - Quit" << endl << endl << "Choose an option:" << endl;
            cin >> ch;
        }
        else if (ch == 'd' || ch == 'D') {
            removePlayer(nums, rates);
            cout << endl << "MENU" << endl;
            cout << "a - Add player" << endl << "d - Remove player" << endl << "u - Update player rating" << endl << "r - Output players above a rating" << endl;
            cout << "o - Output roster" << endl << "q - Quit" << endl << endl << "Choose an option:" << endl;
            cin >> ch;
        }
        else if (ch == 'u' || ch == 'U') {
            updatePlayerRating(nums, rates);
            cout << endl << "MENU" << endl;
            cout << "a - Add player" << endl << "d - Remove player" << endl << "u - Update player rating" << endl << "r - Output players above a rating" << endl;
            cout << "o - Output roster" << endl << "q - Quit" << endl << endl << "Choose an option:" << endl;
            cin >> ch;
        }
        else if (ch == 'r' || ch == 'R') {
            outputPlayersAboveRating(nums, rates);
            cout << endl << "MENU" << endl;
            cout << "a - Add player" << endl << "d - Remove player" << endl << "u - Update player rating" << endl << "r - Output players above a rating" << endl;
            cout << "o - Output roster" << endl << "q - Quit" << endl << endl << "Choose an option:" << endl;
            cin >> ch;
        }
        else if (ch == 'o' || ch == 'O') {
            outputRoster(nums, rates);
            cout << endl << "MENU" << endl;
            cout << "a - Add player" << endl << "d - Remove player" << endl << "u - Update player rating" << endl << "r - Output players above a rating" << endl;
            cout << "o - Output roster" << endl << "q - Quit" << endl << endl << "Choose an option:" << endl;
            cin >> ch;
        }
    }


    return 0;
}