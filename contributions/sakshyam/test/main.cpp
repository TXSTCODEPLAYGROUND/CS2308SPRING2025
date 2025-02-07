//
// Created by ASUS on 2/5/2025.
//


#include <iostream>
#include <vector>
#include <string>
#include <vector>
#include <vector>
#include <vector>

std::vector<std::string> DeckInitializer() {
    std::string element;
    std::vector<std::string> deck;
    std::vector<std::string> suits ={"c", "d", "h", "s"};
    for (std::string i : suits) {

        for (int j = 1; j<14; j++) {
            element = i + std::to_string(j);
            deck.push_back(element);
        }

    }
    for (int n=0; n<deck.size()-1; n++) {
        std::cout<<deck[n]<<" ";
        std::string ce = deck[n];
        std::string ne = deck[n+1];
        if (ce.at(0)!=ne.at(0)) {
            std::cout<<std::endl;
        }
    }
    std::cout<<std::endl;
    return deck;
}

void HandsDealt(int NumPlayers, std::vector<std::string>deck) {
    bool newGenerated;
    int randomNumber;
    std::vector<int> dealtNumbers;
    if (NumPlayers>23) {
        std::cout<<"You can't deal with more than 23 players!"<<std::endl;
        return;
    }
    for (int i =0; i<NumPlayers; i++){
        std::cout<<"playerHand"<<i+1<<": ";
        for (int j =0; j<2; j++) {
            do {
                newGenerated = true;
                randomNumber = 1 + (rand()%51);
                for (int num : dealtNumbers) {
                    if (num==randomNumber) {
                        newGenerated = false;
                    }
                }
            }while (!newGenerated);
            std::cout<<deck[randomNumber]<<" ";
            deck.erase(deck.begin() + randomNumber);
            dealtNumbers.push_back(randomNumber);
        }
        std::cout<<std::endl;

    }

}

int main() {
    std::vector<std::string> deck = DeckInitializer();
    HandsDealt(20,deck);
}


// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.