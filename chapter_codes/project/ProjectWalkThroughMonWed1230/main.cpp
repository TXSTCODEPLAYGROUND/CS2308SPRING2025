#include <iostream>
using namespace std;
int GLOBALCOUNTS = 0;
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
//isvalid(5, 5, 3);
bool isValid(int row, int col, int key){
    // Duty1: Check if it is valid in row;
    for(int j = 0; j < COLS; j++){
        if(BOARD[row][j] == key) return false;
    }
    // Duty2: Check if it is valid in col;
    for(int i = 0; i < ROWS; i++){
        if(BOARD[i][col] == key) return false;
    }
    // Duty3: Check if it is valid in local;
    for(int i = 3 * (row/3); i< 3 * (row/3) + 3; i++){
        for(int j = 3 * (col/3); j < 3 * (col/3) + 3; j++){
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

bool solveBoard(int r, int c){
    GLOBALCOUNTS++;
    std::cout << "Press Enter to continue..." << std::endl;
    std::cin.get();
    if(r == 9)                return true;
    if(c == 9)           return solveBoard(r+1, 0);
    if(BOARD[r][c] != 0) return solveBoard(r, c+1);
    else{
        for(int value = 1; value < 10; value++){
            cout << "***************************************************" << endl;
            cout << "***************************************************" << endl;
            printBoard(r, c, value);
            if(isValid(r, c, value)){
                BOARD[r][c] = value;
                if(solveBoard(r, c+1)) return true;
            }
        }
        BOARD[r][c] = 0;
        return false;
    }
}

int main() {
    printBoard();
    solveBoard(0, 0);
    cout << "Global Iteration Counts: " << GLOBALCOUNTS << endl;
    printBoard();
    // Check the validity of the board
    int key = 0;
    bool valid = true;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            key = BOARD[i][j];
            BOARD[i][j] = 0;
            if(!isValid(i, j, key)) {
                cout << "(" << i << ", " << j << ") = " << key << " Invalid" << endl;
                valid = false;
            }
            BOARD[i][j] = key;
        }
    }
    if(valid) {
        cout << "Valid solution!" << endl;
    }
    return 0;
}

