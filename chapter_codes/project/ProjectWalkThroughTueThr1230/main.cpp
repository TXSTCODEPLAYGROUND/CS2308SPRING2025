#include <iostream>
// #include <some basic stupidity>
using namespace std;//stupid

int ROWS = 9, COLS = 9;

int BOARD[9][9] = {
    //j    0  1  2    3  4  5     6  7  8      i
        {5, 0, 8,   0, 0, 0,    0, 0, 0}, // 0
        {1, 0, 7,   0, 0, 6,    0, 0, 0}, // 1
        {0, 0, 0,   0, 0, 0,    6, 8, 0}, // 2

        {0, 0, 0,   0, 0, 5,    0, 0, 2}, // 3
        {0, 0, 0,   0, 3, 1,    4, 7, 0}, // 4
        {0, 0, 0,   0, 6, 7 ,   0, 3, 0}, // 5

        {4, 0, 3,   0, 5, 0,    0, 0, 0}, // 6
        {0, 0, 1,   9, 0, 0,    0, 0, 0}, // 7
        {0, 0, 0,   0, 0, 8,    0, 0, 5}  // 8
};

 // rowid = 4, colid =3
bool isValid(int rowid, int colid, int key) {
    // check row
    for (int j = 0; j < COLS; j++) {
        if(BOARD[rowid][j] == key) return false;
    }
    // check col
    for (int i = 0; i < ROWS; i++) {
        if(BOARD[i][colid] == key) return false;
    }
    // check box
    for (int i = (rowid/3)*3; i < (rowid/3)*3+3; i++) {
        for (int j = (colid/3)*3; j<(colid/3)*3+3; j++) {
            if(BOARD[i][j] == key) return false;
        }
    }
    return true;
}

void printBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << BOARD[i][j] << "\t";
            if ((j+1)%3==0) cout << "\t\t";
        }
        cout << endl;
        if ((i+1)%3==0) cout << endl;
    }
}

int main() {
    printBoard();
    cout << isValid(1, 4, 2)<<endl;
    return 0;
}