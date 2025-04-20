//
// Created by Keshav Bhandari on 2/19/25.
//

/**
 * @file generator.cpp
 * @brief Implementation of functions to generate random solvable Sudoku boards.
 *
 * This file should contain logic to:
 * - Create empty Sudoku boards.
 * - Fill independent diagonal boxes.
 * - Solve the filled board to complete it.
 * - Randomly remove cells to create solvable Sudoku puzzles.
 *
 * - Replace the dummy code section with appropriate logic
 *
 * You should provide detailed function descriptions in the corresponding header file.
 *
 * @author
 * Keshav Bhandari
 *
 * @date
 * February 7, 2025
 */

#include "../include/generator.h"
#include "../include/sudoku.h"
#include <random>
#include <algorithm>
#include <chrono>

using namespace std;

int** getEmptyBoard() {
    int** board = new int*[9];
    for(int i = 0; i < 9; i++){
        board[i] = new int[9]{0};
    }
    return board;
}

std::vector<int> getShuffledVector() {
    vector<int> numbers = {1, 2, 3, 4, 5, 6, 7, 8, 9};
    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(numbers.begin(), numbers.end(), default_random_engine(seed));
    return numbers;
}

void fillBoardWithIndependentBox(int** BOARD) {
    for (int box = 0; box < 3; box++) {
        vector<int> numbers = getShuffledVector();
        int index = 0;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                BOARD[box*3 + i][box*3 + j] = numbers[index++];
            }
        }
    }
}

void deleteRandomItems(int** BOARD, const int& n) {
    if (n < 1 || n > 81) return;

    vector<pair<int, int>> cells;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (BOARD[i][j] != 0) {
                cells.emplace_back(i, j);
            }
        }
    }

    unsigned seed = chrono::system_clock::now().time_since_epoch().count();
    shuffle(cells.begin(), cells.end(), default_random_engine(seed));

    for (int i = 0; i < min(n, static_cast<int>(cells.size())); i++) {
        BOARD[cells[i].first][cells[i].second] = 0;
    }
}

int** generateBoard(const int& empty_boxes) {
    int** board = getEmptyBoard();
    fillBoardWithIndependentBox(board);

    if (solve(board)) {
        deleteRandomItems(board, empty_boxes);
        return board;
    }

    // Cleanup if solving fails
    for (int i = 0; i < 9; i++) {
        delete[] board[i];
    }
    delete[] board;
    return getEmptyBoard();
}