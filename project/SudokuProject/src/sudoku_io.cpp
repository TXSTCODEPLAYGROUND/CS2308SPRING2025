/**
 * @file sudoku_io.cpp
 * @brief Input/Output utility functions for handling Sudoku puzzles.
 *
 * Contains implementations for:
 * - Console printing with color coding
 * - File I/O operations for Sudoku boards
 * - Batch puzzle generation/solving
 * - Performance comparison of solvers
 *
 * @author Keshav Bhandari
 * @date February 7, 2025
 */

#include "../include/sudoku_io.h"
#include "../include/generator.h"
#include "../include/sudoku.h"
#include "../include/utils.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <regex>
#include <filesystem>
#include <chrono>
#include <iomanip>
#include <string>

using namespace std;
using namespace std::chrono;

void printBoard(int** BOARD, const int& r, const int& c, int k, const bool& color) {
    /**
     * @brief Prints the Sudoku board with optional highlighting
     */
    if(BOARD[r][c] > 0) k = 0;

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            string cell;
            if (BOARD[i][j] == 0) {
                cell = color ? "\x1B[93m-\x1B[0m" : "-"; // Yellow empty cells
            } else {
                cell = to_string(BOARD[i][j]); // White filled cells
            }

            if (i == r && j == c && k != 0) {
                if (isValid(BOARD, r, c, k)) {
                    cell = color ? "\x1B[32m" + to_string(k) + "\x1B[0m" : to_string(k);
                } else {
                    cell = color ? "\x1B[31m" + to_string(k) + "\x1B[0m" : to_string(k);
                }
            }

            cout << cell;
            if (j == 2 || j == 5) cout << " | ";
            else cout << " ";
        }
        if (i == 2 || i == 5) {
            cout << endl;
            for (int l = 0; l < 21; l++)
            cout << ".";
        }
        cout << endl;
    }
}

void boardToString(int** BOARD, string& content) {
    /** @brief Converts board to string with grid separators */
    content.clear();
    for(int i = 0; i < 9; i++) {
        for(int j = 0; j < 9; j++) {
            content += (BOARD[i][j] == 0) ? "-" : to_string(BOARD[i][j]);
            if (j == 2 || j == 5) content += " | ";
            else content += " ";
        }
        if (i == 2 || i == 5) {
            content += "\n";
            content += string(21, '.');
        }
        content += "\n";
    }
}

bool writeSudokuToFile(int** BOARD, const string& filename) {
    /** @brief Serializes board to file with error handling */
    string content;
    boardToString(BOARD, content);

    ofstream file(filename);
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        return false;
    }

    file << content;
    file.close();
    return true;
}

void replaceCharacter(string& str, char oldChar, char newChar) {
    /** @brief Replaces all instances of a character in a string */
    for (char& ch : str) {
        if (ch == oldChar) ch = newChar;
    }
}

void extractNumbers(const string& input, vector<int>& numbers) {
    /** @brief Extracts integers from text using regex */
    numbers.clear();
    regex pattern("\\d+");
    sregex_iterator it(input.begin(), input.end(), pattern);
    sregex_iterator end;

    while (it != end) {
        numbers.push_back(stoi(it->str()));
        ++it;
    }
}

void fillBoard(const vector<int>& numbers, int** BOARD) {
    /** @brief Populates board from number vector */
    int idx = 0;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            BOARD[i][j] = numbers[idx++];
        }
    }
}

int** readSudokuFromFile(const string& filename) {
    /** @brief Loads Sudoku board from text file */
    ifstream file(filename);
    if (!file) {
        cerr << "Error opening file: " << filename << endl;
        return nullptr;
    }

    string content((istreambuf_iterator<char>(file)),
                  istreambuf_iterator<char>());
    replaceCharacter(content, '-', '0');

    vector<int> numbers;
    extractNumbers(content, numbers);

    if (numbers.size() != 81) {
        cerr << "Invalid puzzle format in: " << filename << endl;
        return nullptr;
    }

    int** board = getEmptyBoard();
    fillBoard(numbers, board);
    return board;
}

bool checkIfSolutionIsValid(int** BOARD) {
    /** @brief Validates complete Sudoku solution */
    for (int r = 0; r < 9; r++) {
        for (int c = 0; c < 9; c++) {
            int temp = BOARD[r][c];
            BOARD[r][c] = 0;
            if (!isValid(BOARD, r, c, temp)) {
                BOARD[r][c] = temp;
                return false;
            }
            BOARD[r][c] = temp;
        }
    }
    return true;
}

vector<string> getAllSudokuInFolder(const string& folderPath) {
    /** @brief Lists Sudoku files in directory */
    vector<string> files;
    for (const auto& entry : filesystem::directory_iterator(folderPath)) {
        if (entry.is_regular_file()) {
            files.push_back(entry.path().string());
        }
    }

    // Formatting output
    cout << "Found " << files.size() << " puzzles in: " << folderPath << endl;
    cout << setfill('-') << setw(55) << "\n" << setfill(' ');
    cout << setw(5) << "ID" << setw(50) << "Filename" << endl;
    cout << setfill('-') << setw(55) << "\n" << setfill(' ');

    for (size_t i = 0; i < files.size(); i++) {
        cout << setw(4) << i << " | " << files[i] << endl;
    }
    cout << setfill('-') << setw(55) << "\n" << setfill(' ');

    return files;
}

void createAndSaveNPuzzles(const int& num_puzzles, const int& complexity_empty_boxes,
                          const string& destination, const string& prefix) {
    /**
     * @brief Generates and saves multiple puzzles
     * Memory Management:
     * - Deallocates each board after writing to file
     */
    for (int i = 0; i < num_puzzles; ++i) {
        int** board = generateBoard(complexity_empty_boxes);
        string filename = getFileName(i+1, destination, prefix);

        if (writeSudokuToFile(board, filename)) {
            cout << "Saved puzzle: " << filename << endl;
        }

        deallocateBoard(board);  // Critical memory cleanup
    }
}

void solveAndSaveNPuzzles(const int& num_puzzles, const string& source,
                         const string& destination, const string& prefix) {
    /**
     * @brief Solves and saves multiple puzzles
     * Memory Management:
     * - Deallocates boards after processing
     */
    auto puzzles = getAllSudokuInFolder(source);
    int solved_count = 0;

    for (int i = 0; i < min(num_puzzles, (int)puzzles.size()); ++i) {
        int** board = readSudokuFromFile(puzzles[i]);
        if (!board) continue;

        if (solve(board, true)) {  // Use efficient solver
            string filename = getFileName(i+1, destination, prefix);
            if (writeSudokuToFile(board, filename)) {
                solved_count++;
            }
        }

        deallocateBoard(board);  // Prevent memory leak
    }

    cout << "Successfully solved " << solved_count << "/" << num_puzzles << " puzzles\n";
}

int** deepCopyBoard(int** original) {
    /** @brief Creates exact duplicate of Sudoku board */
    int** copy = new int*[9];
    for (int i = 0; i < 9; i++) {
        copy[i] = new int[9];
        for (int j = 0; j < 9; j++) {
            copy[i][j] = original[i][j];
        }
    }
    return copy;
}

void compareSudokuSolvers(const int& experiment_size, const int& empty_boxes) {
    /**
     * @brief Compares solver performance
     * Memory Management:
     * - Deallocates both boards after each experiment
     */
    int valid_basic = 0, valid_efficient = 0;
    double total_basic = 0, total_efficient = 0;

    for (int i = 0; i < experiment_size; ++i) {
        // Generate test boards
        int** board1 = generateBoard(empty_boxes);
        int** board2 = deepCopyBoard(board1);

        // Time basic solver
        auto start = high_resolution_clock::now();
        bool basic_ok = solve(board1, false);
        auto end = high_resolution_clock::now();
        total_basic += duration<double, milli>(end - start).count();
        if (basic_ok && checkIfSolutionIsValid(board1)) valid_basic++;

        // Time efficient solver
        start = high_resolution_clock::now();
        bool efficient_ok = solve(board2, true);
        end = high_resolution_clock::now();
        total_efficient += duration<double, milli>(end - start).count();
        if (efficient_ok && checkIfSolutionIsValid(board2)) valid_efficient++;

        // Cleanup
        deallocateBoard(board1);
        deallocateBoard(board2);

        // Progress tracking
        displayProgressBar(i+1, experiment_size);
    }

    // Results
    cout << fixed << setprecision(2);
    cout << "\nBasic Solver:    " << valid_basic << "/" << experiment_size
         << " valid | Avg: " << (total_basic/experiment_size) << " ms\n";
    cout << "Efficient Solver: " << valid_efficient << "/" << experiment_size
         << " valid | Avg: " << (total_efficient/experiment_size) << " ms\n";
}

void displayProgressBar(int current, int total, int barWidth) {
    /** @brief Displays a progress bar in the console */
    float progress = static_cast<float>(current) / total;
    int pos = static_cast<int>(barWidth * progress);

    cout << "\r[";
    for (int i = 0; i < barWidth; ++i) {
        if (i < pos) cout << "=";
        else if (i == pos) cout << ">";
        else cout << " ";
    }
    cout << "] " << setw(3) << int(progress * 100.0) << "%";
    cout.flush();
}
