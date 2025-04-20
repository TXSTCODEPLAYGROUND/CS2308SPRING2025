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

int** getEmptyBoard() {
    int** board = new int*[9];
    for (int i = 0; i < 9; i++) {
        board[i] = new int[9]{0};
    }
    return board;
}

std::vector<int> getShuffledVector() {
    std::vector<int> numbers(9);
    for (int i = 0; i < 9; ++i) numbers[i] = i + 1;
    std::random_device rd;
    std::mt19937 rng(rd());
    std::shuffle(numbers.begin(), numbers.end(), rng);
    return numbers;
}

void fillBoardWithIndependentBox(int** BOARD) {
    for (int box = 0; box < 3; box++) {
        std::vector<int> nums = getShuffledVector();
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
    int clearCount = n;
    if (clearCount < 1) clearCount = 1;
    if (clearCount > 81) clearCount = 81;
    std::vector<std::pair<int, int>> cells;
    for (int i = 0; i < 9; i++)
        for (int j = 0; j < 9; j++)
            cells.push_back({i, j});
    std::random_device rd;
    std::mt19937 rng(rd());
    std::shuffle(cells.begin(), cells.end(), rng);
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
    // Clean up if solving fails
    for (int i = 0; i < 9; i++) delete[] board[i];
    delete[] board;
    return nullptr;
}
