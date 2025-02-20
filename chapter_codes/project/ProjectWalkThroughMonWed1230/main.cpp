#include <iostream>
using namespace std;


int ROWS = 9, COLS = 9;

// int box_i = (rowid/3)*3;
// int box_j = (colid/3)*3;

int BOARD[9][9] = {
    //     0  1  2    3  4  5     6  7  8
        {5, 0, 8,   0, 0, 0,    0, 0, 0}, // 0
        {1, 0, 7,   0, 0, 6,    0, 0, 0}, // 1
        {0, 0, 0,   0, 0, 0,    6, 8, 0}, // 2

        {0, 0, 0,   0, 0, 5,    0, 0, 2}, // 3
        {0, 0, 0,   0, 3, 1,    4, 7, 0}, // 4
        {0, 0, 0,   0, 6, 7,    0, 3, 0}, // 5

        {4, 0, 3,   0, 5, 0,    0, 0, 0}, // 6
        {0, 0, 1,   9, 0, 0,    0, 0, 0}, // 7
        {0, 0, 0,   0, 0, 8,    0, 0, 5}  // 8
};

void printBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << BOARD[i][j] << "\t";
            if ((j+1)%3 == 0) cout << "\t\t";
        }
        cout << endl;
        if ((i+1)%3 == 0) cout << endl;

    }
}

// rowid = 5
bool isValid(int rowid, int colid, int candidate) {
    // Check if candidate exists in row
    for (int j = 0; j < COLS; j++)
        if(BOARD[rowid][j] == candidate) return false;
    // Check if candidate exists in col
    for (int i = 0; i < ROWS; i++)
        if(BOARD[i][colid] == candidate) return false;

    // Check if candidate exists in box
    int box_i = (rowid/3)*3;
    int box_j = (colid/3)*3;
    for (int i = box_i; i < box_i + 3; i++) {
        for (int j = box_j; j < box_j + 3; j++) {
            if(BOARD[i][j] == candidate) return false;
        }
    }
    return true;
}

int main() {
    printBoard();
    cout << isValid(0, 1, 2) << endl;
    return 0;
}