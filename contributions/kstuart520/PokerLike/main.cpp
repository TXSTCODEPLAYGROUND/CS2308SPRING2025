#include <iostream>
#include "header/cards.h"

int main(int argc, char const *argv[]) {
    vector <string> players;
    if(argc < 2){
        players = {"Keshav", "Anar", "James", "John", "Evry"};
    } else {
        for(int i = 0; i < argc; i++){
            players.emplace_back(argv[i]);
        }
    }
    Poker game(players);
    game.deck.showDeck();
    game.deck.showValue();
    cout << "Hit Enter to begin the game..." << endl;
    cin.ignore();
    game.dealCards();
    game.showHands();
    game.showCommunity();
    game.deck.showDeck();
    game.showStats();
    return 0;
}