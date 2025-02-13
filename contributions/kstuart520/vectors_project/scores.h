#ifndef SCORES_H // If SCORES_H is not defined
#define SCORES_H // define it to prevent multiple inclusions

#include <vector>

// Function declarations
void addScore(std::vector<int>& scores, int score);
void displayScores(const std::vector<int>& scores);
double calculateAverage(const std::vector<int>& scores);
int findMaxScore(const std::vector<int>& scores);
int findMinScore(const std::vector<int>& scores);
void sortScores(std::vector<int>& scores);

#endif // SCORES_H