#include <vector>
#include <iostream>
using namespace std;

const int PLAYER1 = 0;
const int PLAYER2 = 1;

void drawBoard(const vector < char >& gameBoard) {
    for (int i = 0; i < 9; i += 3) {
        cout << "  " << gameBoard.at(i) << "  |  " << gameBoard.at(i + 1) << "  |  "
            << gameBoard.at(i + 2) << "  " << endl;
        if (i < 6) {
            cout << "-----|-----|-----" << endl;
        }
    }
    cout << endl;
    return;
}
void initVector(vector <char>& v) {
    char spaces = 'a';
    for (int i = 0; i < v.size(); i++) {
        v.at(i) = spaces;
        spaces++;
    }
    return;
}
int convertPosition(char boardPosition) {
    char to_be_converted = 'a';
    for (int i = 0; i < 9; i++) {
        if (to_be_converted == boardPosition) {
            return i;
        }
        else {
            to_be_converted++;
        }
    }
    return -1;
}
bool validPlacement(const vector<char>& gameBoard, int positionIndex) {
    if (positionIndex > -1 && positionIndex < 9) {
        if (gameBoard.at(positionIndex) != 'X') {
            if (gameBoard.at(positionIndex) != 'O') {
                return true;
            }
        }
    }
    return false;
}
int getPlay(const vector<char>& gameBoard) {
    char letter_on_board;
    int num_for_vec;
    cout << "Please choose a position to mark: ";
    cin >> letter_on_board;
    cout << endl;
    num_for_vec = convertPosition(letter_on_board);
    while (!validPlacement(gameBoard, num_for_vec)) {
        drawBoard(gameBoard);
        cout << "Please choose a VALID position: ";
        cin >> letter_on_board;
        cout << endl;
        num_for_vec = convertPosition(letter_on_board);
    }
    return num_for_vec;
}
bool gameWon(const vector<char>& gameBoard) {
    for (unsigned int i = 0; i < 7; i += 3) {
        if (gameBoard.at(i) == gameBoard.at(i + 1)) {
            if (gameBoard.at(i) == gameBoard.at(i + 2)) {
                return true;
            }
        }
    }
    for (unsigned int i = 0; i < 3; i++) {
        if (gameBoard.at(i) == gameBoard.at(i + 3)) {
            if (gameBoard.at(i) == gameBoard.at(i + 6)) {
                return true;
            }
        }
    }
    if (gameBoard.at(0) == gameBoard.at(4)) {
        if (gameBoard.at(0) == gameBoard.at(8)) {
            return true;
        }
    }
    if (gameBoard.at(2) == gameBoard.at(4)) {
        if (gameBoard.at(2) == gameBoard.at(6)) {
            return true;
        }
    }
    return false;
}
bool boardFull(const vector<char>& gameBoard) {
    int counter = 0;
    for (unsigned int i = 0; i < gameBoard.size(); i++) {
        if (gameBoard.at(i) == 'X' || gameBoard.at(i) == 'O') {
            counter++;
        }
    }
    if (counter == 9) {
        return true;
    }
    return false;
}

int main() {

    vector<char> gameBoard(9);
    int currPlay;
    bool tie_game = false;
    char character;
    int counter = 0;

    cout << endl << "~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~  WELCOME TO BRIJ'S TIC TAC TOE  ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~ ~" << endl << endl;

    initVector(gameBoard);
    drawBoard(gameBoard);

    while (!boardFull(gameBoard)) {
        currPlay = getPlay(gameBoard);
        if (counter == 0) {
            character = 'X';
            counter++;
        }
        else {
            character = 'O';
            counter--;
        }
        gameBoard.at(currPlay) = character;
        if (gameWon(gameBoard)) {
            tie_game = true;
            break;
        }
        drawBoard(gameBoard);
    }

    if (tie_game) {
        drawBoard(gameBoard);
        if (counter == 1) {
            cout << "PLAYER 1 WINS!!! CONGRATULATIONS!!" << endl << endl;
        }
        else {
            cout << "PLAYER 2 WINS!!! CONGRATULATIONS!!" << endl << endl;
        }
    }

    else {
        cout << "TIE GAME!!! SCRATCH!!!!!!" << endl;
    }
    cout << "- - - - - - - - - - - - - - -  Thank you for playing my version of Tic-Tac-Toe!!  - - - - - - - - - - - - - - -" << endl << endl;


    return 0;
}