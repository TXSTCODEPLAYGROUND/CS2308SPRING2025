//
// Created by Keshav Bhandari on 2/8/24.
//

#include "utils.h"
#include <filesystem>
#include <sstream>
#include <iomanip>

void deallocateBoard(int** BOARD, const int& rows) {
    if (!BOARD) return;
    for (int i = 0; i < rows; i++) delete[] BOARD[i];
    delete[] BOARD;
}

void createFolder(const std::string& folderPath) {
    std::filesystem::create_directories(folderPath);
}

void initDataFolder() {
    createFolder("data/puzzles");
    createFolder("data/solutions");
}

std::string getFileName(const int& index, const std::string& destination, const std::string& prefix) {
    std::ostringstream oss;
    oss << destination << "/" << std::setw(4) << std::setfill('0') << index << "_" << prefix << ".txt";
    return oss.str();
}
