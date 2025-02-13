#include "scores.h"
#include <iostream>
#include <algorithm>
#include <numeric>
#include <vector>

void addScore(std::vector<int>& scores, int score){
    scores.push_back(score);
}

void displayScores(const std::vector<int>& scores){
    std::cout << "Scores: ";
    for(int score : scores){
        std::cout << score << " ";
    }
    std::cout << std::endl;
}

double calculateAverage(const std::vector<int>& scores){
    if(scores.empty()) return 0.0;
    return std::accumulate(scores.begin(), scores.end(), 0.0) / scores.size();
}

int findMaxScore(const std::vector<int>& scores){
    return *std::max_element(scores.begin(), scores.end());
}

int findMinScore(const std::vector<int>& scores){
    return *std::min_element(scores.begin(), scores.end());
}

void sortScores(std::vector<int>& scores){
    std::sort(scores.begin(), scores.end());
}
