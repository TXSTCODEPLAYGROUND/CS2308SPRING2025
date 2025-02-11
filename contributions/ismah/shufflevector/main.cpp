#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>
// TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
int main() {

    std::vector<std::string> cards;

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 9; j++) {
            if (i == 0) {
                cards.push_back("Hearts " + std::to_string(j + 2));
            }
            else if (i == 1) {
                cards.push_back("Diamonds " + std::to_string(j + 2));;
            }
            else if (i == 2) {
                cards.push_back("Spades " + std::to_string(j + 2));
            }
            else if (i == 3) {
                cards.push_back("Clubs " + std::to_string(j + 2));
            }
        }
    }

    for (int i = 9; i < 52; i += 13) {
        for (int j = 0; j < 4; j++) {
            if (i == 9) {
                cards.insert(cards.begin() + i, "Jack of Hearts");
                cards.insert(cards.begin() + i, "Queen of Hearts");
                cards.insert(cards.begin() + i, "King of Hearts");
                cards.insert(cards.begin() + i, "Ace of Hearts");
            }
            if (i == 22) {
                cards.insert(cards.begin() + i, "Jack of Diamonds");
                cards.insert(cards.begin() + i, "Queen of Diamonds");
                cards.insert(cards.begin() + i, "King of Diamonds");
                cards.insert(cards.begin() + i, "Ace of Diamonds");
            }
            if (i == 25) {
                cards.insert(cards.begin() + i, "Jack of Spades");
                cards.insert(cards.begin() + i, "Queen of Spades");
                cards.insert(cards.begin() + i, "King of Spades");
                cards.insert(cards.begin() + i, "Ace of Spades");
            }
            if (i == 44) {
                cards.insert(cards.begin() + i, "Jack of Clubs");
                cards.insert(cards.begin() + i, "Queen of Clubs");
                cards.insert(cards.begin() + i, "King of Clubs");
                cards.insert(cards.begin() + i, "Ace of Clubs");
            }
        }
    }

    // Better way to do it

    std::vector<std::string> deck;
    std::vector<std::string> suits = {"Hearts", "Diamonds", "Spades", "Clubs"};
    std::vector<std::string> ranks = {"2", "3", "4", "5", "6", "7", "8",
        "9", "10", "Jack", "Queen", "King", "Ace"};

    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 13; j++) {
            deck.push_back(ranks.at(j) + " of " + suits.at(i));
        }
    }

    // Copy/paste random number generator
    std::random_device rd;
    std::mt19937 g(rd());

    std::shuffle(cards.begin(), cards.end(), g);
    std::shuffle(deck.begin(), deck.end(), g);

    for (const std::string& card : cards) {
        std::cout << card << ", ";
    }

    std::cout << std::endl;

    for (const std::string& card : deck) {
        std::cout << card << ", ";
    }

    std::cout << std::endl;

    return 0;
}

// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.