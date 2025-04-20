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

#include "generator.h"
#include "sudoku.h"
#include <algorithm>
#include <random>
#include <vector>

using namespace std;

int** getEmptyBoard() {
    int** board = new int*[9];
    for (int i = 0; i < 9; i++) {
        board[i] = new int[9]{0};
    }
    return board;
}

vector<int> getShuffledVector() {
    vector<int> numbers(9);
    iota(numbers.begin(), numbers.end(), 1);
    random_device rd;
    mt19937 rng(rd());
    shuffle(numbers.begin(), numbers.end(), rng);
    return numbers;
}

void fillBoardWithIndependentBox(int** BOARD) {
    for (int box = 0; box < 3; box++) {
        vector<int> nums = getShuffledVector();
        int idx = 0;
        int rowStart = box * 3;
        int colStart = box * 3;
        for (int i = 0; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                BOARD[rowStart + i][colStart + j] = nums[idx++];
            }
        }
    }
}

void deleteRandomItems(int** BOARD, const int& n) {
    int clearCount = std::clamp(n, 1, 81);
    vector<pair<int, int>> cells;
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            cells.emplace_back(i, j);
        }
    }
    random_device rd;
    mt19937 rng(rd());
    shuffle(cells.begin(), cells.end(), rng);
    for (int i = 0; i < clearCount; i++) {
        BOARD[cells[i].first][cells[i].second] = 0;
    }
}

int** generateBoard(const int& empty_boxes) {
    int** board = getEmptyBoard();
    fillBoardWithIndependentBox(board);
    if (solve(board, false)) {
        deleteRandomItems(board, empty_boxes);
        return board;
    }
    // If solving fails, cleaning up and returning the nullptr
    for (int i = 0; i < 9; i++) delete[] board[i];
    delete[] board;
    return nullptr;
}

