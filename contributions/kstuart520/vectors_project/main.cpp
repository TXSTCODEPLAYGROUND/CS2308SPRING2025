#include <iostream> // Required for cout/cin
#include <vector> // Required for std::vector
#include "scores.h" // Include function declaration


int main(){
    std::vector<int> scores;
    int input;

    std::cout << "Enter student scores (-1 to finish): " << std::endl;
    while (std::cin >> input && input != -1){
        addScore(scores, input);
    }

    if(scores.empty()){
        std::cout << "No scores entered. Exiting..." << std::endl;
        return -1;
    }

    displayScores(scores);
    std::cout << "Average Score: " << calculateAverage(scores) << std::endl;
    std::cout << "Highest Score: " << findMaxScore(scores) << std::endl;
    std::cout << "Lowest Score: " << findMinScore(scores) << std::endl;

    sortScores(scores);
    std::cout << "Sorted Scores: ";
    displayScores(scores);

    return 0;
}