//
// Created by ASUS on 2/5/2025.
//


#include <iostream>
#include <vector>
#include <string>
#include <ctime>
#include <cstdlib>


std::vector<std::string> deckInitializer() {
    int n;
    std::string element;
    std::vector<std::string> deck;
    std::vector<std::string> suits ={"c", "d", "h", "s"};
    for (std::string i : suits) {

        for (int j = 1; j<14; j++) {
            element = i + std::to_string(j);
            deck.push_back(element);
        }
    }
    for (n=0; n<deck.size(); n++) {
        std::cout<<deck[n]<<" ";
        if ((n+1)%13==0) {
            std::cout<<std::endl;
        }
    }
    return deck;
}

std::vector<std::string> handsDealt(int numPlayers, std::vector<std::string>deck) {
    int randomNumber;
    int count = 52;
    if (numPlayers>23) {
        std::cout<<"You can't deal with more than 23 players!"<<std::endl;
        exit(1);
    }
    for (int i =0; i<numPlayers; i++){
        std::cout<<"playerHand"<<i+1<<": ";
        for (int j =0; j<2; j++) {
            srand(time(0));
            randomNumber = (rand()%count);
            count = count - 1;
            std::cout<<deck[randomNumber]<<" ";
            deck.erase(deck.begin() + randomNumber);
        }
        std::cout<<std::endl;
    }
    return deck;
}

int communityCard(std::vector<std::string> deck) {
    int randomNumber;
    if (deck.size()<=5) {
        std::cout<<"community cards: ";
        for (std::string element:deck) {
            std::cout<<element<<" ";
        }
        std::cout<<std::endl;
    }else {
        std::cout<<"community cards: ";
        int remainingCards = deck.size();
        for (int j =0; j<5; j++) {
            srand(time(0));
            randomNumber = rand()%remainingCards;
            remainingCards = remainingCards - 1;
            std::cout<<deck[randomNumber]<<" ";
            deck.erase(deck.begin() + randomNumber);
        }
        std::cout<<std::endl;
    }
}

int main() {
    int numPlayers;
    std::cout<<"input number of players: ";
    std::cin>>numPlayers;
    std::vector<std::string> deck = deckInitializer();
    std::vector<std::string> remainingDeck = handsDealt(numPlayers,deck);
    std::cout<<communityCard(remainingDeck);
}


// TIP See CLion help at <a
// href="https://www.jetbrains.com/help/clion/">jetbrains.com/help/clion/</a>.
//  Also, you can try interactive lessons for CLion by selecting
//  'Help | Learn IDE Features' from the main menu.