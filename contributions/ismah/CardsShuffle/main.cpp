#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

std::vector<std::string> deckCreation() {
    std::vector<std::string> cards;
    std::vector<std::string> suits = {"Hearts", "Diamonds", "Spades", "Clubs"};
    std::vector<std::string> numbers = {"2", "3", "4", "5", "6", "7", "8",
        "9", "10", "Jack", "Queen", "King", "Ace"};

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            cards.push_back(numbers.at(j) + " of " + suits.at(i));
        }
    }
    return cards;
}

void shuffle(std::vector<std::string>& cards) {
    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(cards.begin(), cards.end(), g);
}

void printDeck(std::vector<std::string>& cards) {
    for (const std::string& card : cards) {
        std::cout << card << ", ";
    }
    std::cout << std::endl;
}


// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {

    std::vector<std::string> cards = deckCreation();

    shuffle(cards);

    printDeck(cards);

    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.