//
// Created by Keshav Bhandari on 2/13/24.
//

#ifndef SORTING_CARDS_H
#define SORTING_CARDS_H

#include <iostream>
#include <random>
#include <unordered_map>
#include <iomanip>
#include <vector>
#include <set>

using namespace std;

struct Card{
    string suit;
    int rank;
    Card(const string& s, int r) : suit(s), rank(r) {}
    int getValue() const;
    int getID() const;
    string getCard() const;
};

struct Deck{
    vector<Card> cards;
    bool initialized = false;
    void createOrResetDeck(bool randomized = true);
    void showDeck();
    void showValue();
    void shuffleDeck();
    void burnDeck();
    Card dealCard();
};

struct Poker{
    Deck deck;
    vector<string> players;
    vector<string> turn_cards;
    vector<Card> community_cards;
    unordered_map<string, vector<Card>> hands;
    Poker(const vector<string>& p) : players(p){setUp();};
    void setUp();
    void dealCards();
    void showHands();
    void showCommunity();
    void showStats();
};

Card getRandomCard();

#endif //SORTING_CARDS_H
