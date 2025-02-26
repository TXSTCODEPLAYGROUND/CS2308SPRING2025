#include <iostream>
// #include <some basic stupidity>
using namespace std;//stupid

int ROWS = 9, COLS = 9;
int GLOBALCOUNTS = 0;
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

void printBoard(int row=0, int col=0, int key=0){
    /*Summary: Prints board in row, column fashion*/
    // Make sure you don't allow user to edit, if non-zero value exists
    // Logic is simple: force key to be 0, as we do nothing when key = 0;
    cout << GLOBALCOUNTS << endl;

    if(BOARD[row][col]>0){
        cout << "Can't replace [" << row << "," << col << "] because non zero value exists" << endl;
        key = 0;
    }
    for(int i = 0; i < ROWS; i++){
        for(int j = 0; j < COLS; j++){
            string temp = to_string(BOARD[i][j]);

            if((i == row && col == j) && (key > 0)){
                if(isValid(row, col, key)) temp = "\x1B[32m" + to_string(key) + "\x1B[0m"; // Green
                else                       temp = "\x1B[31m" + to_string(key) + "\x1B[0m"; // Red
            }
            cout << temp;
            if(j == 2 || j == 5) cout << "  |  ";
            else cout << "  ";
        }
        if(i == 2 || i == 5) cout << endl << "-------------------------------";
        cout << endl;
    }
}

bool solveBoard(int row, int col) {
    if (row == 9) return true; //board completed
    if (col == 9) return solveBoard(row+1, 0);//row completed
    if(BOARD[row][col] != 0) return solveBoard(row, col+1); //found a piece of garbage
    //case where you found [row][col]==0
    for (int key=1; key < 10; key++) {
        if(isValid(row, col, key)) {
            BOARD[row][col] = key;
            if(solveBoard(row, col+1)) return true;
        }
    }
    //
    BOARD[row][col] = 0;
    return false;
}

int main() {
    printBoard(0, 1, 2);
    cout << isValid(1, 4, 2)<<endl;
    return 0;
}