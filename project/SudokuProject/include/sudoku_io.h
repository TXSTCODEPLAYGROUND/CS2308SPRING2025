/**
 * @file sudoku_io.h
 * @brief Input/Output utility functions for handling Sudoku puzzles.
 *
 * This header file declares functions for reading, writing, displaying,
 * and managing Sudoku puzzles. It includes utilities to:
 * - Print Sudoku boards to the console with color-coded hints.
 * - Read and write Sudoku puzzles from/to files.
 * - Parse and extract numbers from text representations.
 * - Generate and solve multiple Sudoku puzzles.
 * - Handle file system operations to read puzzle sets from directories.
 *
 * The functions work with a dynamically allocated 9x9 Sudoku board
 * represented as `int**`, where empty cells are denoted by 0.
 *
 * @author
 * Keshav Bhandari
 *
 * @date
 * February 7, 2025
 */

#ifndef SUDOKUPROJECT_SUDOKUIO_H
#define SUDOKUPROJECT_SUDOKUIO_H

#include <vector>
#include <string>
using namespace std;

void printBoard(int** BOARD, const int& r=0, const int& c=0, int k=0, const bool& color=false);
void boardToString(int** BOARD, string& content);
bool writeSudokuToFile(int** BOARD, const string& filename);
void replaceCharacter(string& str, char oldChar, char newChar);
void extractNumbers(const string& input, vector<int>& numbers);
void fillBoard(const vector<int>& numbers, int** BOARD);
int** readSudokuFromFile(const string& filename);
bool checkIfSolutionIsValid(int** BOARD);
vector<string> getAllSudokuInFolder(const string& folderPath);
void createAndSaveNPuzzles(const int& num_puzzles, const int& complexity_empty_boxes, const string& destination, const string& prefix);
void solveAndSaveNPuzzles(const int& num_puzzles, const string& source, const string& destination, const string& prefix);
int** deepCopyBoard(int** original);
void compareSudokuSolvers(const int& experiment_size, const int& empty_boxes);

#endif //SUDOKUPROJECT_SUDOKUIO_H
