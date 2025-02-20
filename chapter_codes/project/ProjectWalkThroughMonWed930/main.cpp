#include <iostream>
using namespace std;

int ROWS = 9, COLS = 9;

int BOARD[9][9] = {
    //     0  1  2    3  4  5     6  7  8
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
//row_id = 0
bool isValid(int row_id, int col_id, int candidate) {
    // check the row
    for (int j = 0; j < COLS; j++)
        if (BOARD[row_id][j] == candidate) return false;
    // check the column
    for (int i = 0; i < ROWS; i++)
        if (BOARD[i][col_id] == candidate) return false;
    // check the box

}

void printBoard() {
    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {
            cout << BOARD[i][j];
            if (j == 2 || j == 5) cout << "\t";
            else cout << " ";
        }
        cout << endl;
        if (i == 2 || i == 5) cout << endl;
    }
}


int main(){
    printBoard();
}