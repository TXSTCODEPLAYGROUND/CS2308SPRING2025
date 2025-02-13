//
// Created by Keshav Bhandari on 2/13/24.
//
#include <iostream>
#include <random>
#include <unordered_map>
#include <iomanip>
#include <vector>
#include <set>
#include "../header/cards.h"
using namespace std;

string SUITS[] = {"D", "H", "C", "S"};
int RANKS[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};

Card getRandomCard(){
    random_device rd;
    mt19937 gen(rd());
    uniform_int_distribution<int> suitsGeneration(0,3);
    uniform_int_distribution<int> ranksGeneration(0, 12);
//    int suit =
    return Card(SUITS[suitsGeneration(gen)], RANKS[ranksGeneration(gen)]);
}

int Card::getValue() const {
    /* return 14 if rank == 1, else return default rank*/
    return (1/rank)*13 + rank;
}

int Card::getID() const {
    /* return ID 1 to 52, order(asc) of higher card DIAM->HEART->CLUB->SPD*/
    if     (suit == "D") return 0*13 + rank;
    else if(suit == "H") return 1*13 + rank;
    else if(suit == "C") return 2*13 + rank;
    else                 return 3*13 + rank;
}

string Card::getCard() const {
    string card, symbol;
    // get card
    if     (rank ==  1) card = " A";
    else if(rank  < 10) card = " "+to_string(rank);
    else if(rank == 10) card = to_string(rank);
    else if(rank == 11) card = " J";
    else if(rank == 12) card = " Q";
    else                card = " K";
    // get symbol
    if     (suit == "D") symbol = "\x1B[31m\u2666\x1B[0m";
    else if(suit == "H") symbol = "\x1B[31m\u2665\x1B[0m";
    else if(suit == "C") symbol = "\u2664";
    else                 symbol = "\u2667";
    // return card
    return "[" + card + symbol + "]";
}

void Deck::createOrResetDeck(bool randomized){
    for(int i = 0; i < 4; i++){
        for(int j = 0; j < 13; j++){
            // Traditionally you will do something like
            // deck.push_back(Card(SUITS[i], RANKS[j))
            // since deck is vector<Card>, it can construct card automatically with arguments
            // So you can now pass arguments directly
            cards.emplace_back(SUITS[i], RANKS[j]);
        }
    }
    if(randomized){
        cout << "Deck Created with random shuffle" << endl;
        random_device rd;
        mt19937 gen(rd());
        shuffle(cards.begin(), cards.end(), gen);
    }else{
        cout << "Deck Created without shuffle" << endl;
    }
    initialized = true;
}
void Deck::showDeck(){
    if(!initialized) createOrResetDeck();
    cout << "---CARDS---------------------------------------------------------------------" << endl;
    // You may not have all the cards at some point so
    // Print empty spaces if you already dealt the cards
    int card_dealt = 52 - cards.size();
    for(int i = 0; i < card_dealt; i++){
        cout << "     " << " ";
        if((i+1)%13 == 0) cout << endl;
    }
    for(int i=0; i < cards.size(); i++){
        cout << cards[i].getCard() << " ";
        if((i+1+card_dealt)%13 == 0) cout << endl;
    }
    cout << "-----------------------------------------------------------------------------" << endl;
}
void Deck::shuffleDeck(){
    // Shuffle here
    random_device rd;
    mt19937 gen(rd());
    shuffle(cards.begin(), cards.end(), gen);

    cout << "---DECKS SHUFFLED------------------------------------------------------------" << endl;
    for(int i=0; i < 52; i++){
        cout << "[ ? ] ";
        if((i+1)%13 == 0) cout << endl;
    }
    cout << "-----------------------------------------------------------------------------" << endl;
}

void Deck::burnDeck(){
    // Get the top Card
    Card card = cards[0];
    // erase the begining of the deck
    cards.erase(cards.begin());
    // push_back the top card to the deck
    cards.push_back(card);
}


void Deck::showValue(){
    if(!initialized) createOrResetDeck();
    cout << "---VALUES--------------------------------------------------------------------" << endl;
    for(int i=0; i < 52; i++){
        cout << "[" << setw(3) << cards[i].getValue() << "]" << " ";
        if((i+1)%13 == 0) cout << endl;
    }
    cout << "-----------------------------------------------------------------------------" << endl;
}

Card Deck::dealCard() {
    Card card = cards[0];
    cards.erase(cards.begin());
    return card;
}


void Poker::setUp() {
    deck = Deck();
    cout << "Initializing Deck..." << endl;
    deck.createOrResetDeck(false);
    cout << "Show Deck..." << endl;
    deck.showDeck();
    cout << "Shuffle Deck.." << endl;
    deck.shuffleDeck();
    for(string& player:players)
        hands[player] = {};
    // Initialize Community Cards
    community_cards = {};
}

void Poker::dealCards(){
    // Visualize All Cards
    deck.showDeck();
    // Deal 2 cards to each player
    for(int round = 0; round < 2; round++){
        for(int i=0; i<players.size(); i++){
            Card card = deck.dealCard();
            hands[players[i]].push_back(card);
        }
    }
    // Burn the card before dealing community card
    deck.burnDeck();
    // Deal 3 community cards called as flop
    for(int i=0; i<3; i++){
        community_cards.push_back(deck.dealCard());
    }
    deck.burnDeck();
    // Deal 1 card for flop now
    community_cards.push_back(deck.dealCard());
    // Burn the card before dealing the river
    deck.burnDeck();
    community_cards.push_back(deck.dealCard());
}

void Poker::showHands(){
    cout << "---HANDS CARDS---------------------------------------------------------------" << endl;
    for(int i=0; i<players.size(); i++){
        cout << setw(20) << players[i] << " : ";
        vector<Card> cards = hands[players[i]];
        for(int j=0; j<cards.size(); j++)
            cout << cards[j].getCard() << " ";
        cout << endl;
    }
    cout << "-----------------------------------------------------------------------------" << endl;
}

void Poker::showCommunity(){
    cout << "---COMMUNITY CARDS-----------------------------------------------------------" << endl;
    int i = 0;
    for(const Card& card:community_cards){
        string community;
        if(i == 0)
            cout << setw(20) << "Turn" <<" : ";
        if(i == 3)
            cout << setw(20) << "River" <<" : ";
        if(i > 3)
            cout << setw(20) << "Flop" <<" : ";

        cout << card.getCard() << " ";
        if(i > 1) cout << endl;
        i++;
    }
    cout << endl;
}

void Poker::showStats(){
    cout << "---STATS---------------------------------------------------------------------" << endl;
    unordered_map<string, int> player_score;
    unordered_map<string, vector<Card>> player_valid_cards;
    int min_score = numeric_limits<int>::max();

    set<int> cset = {}; //community card value set
    for(const Card& card : community_cards)
        cset.insert(card.getValue());

    for(const string& player: players){
        set<int> pset = {}; // player card value set
        for(const Card& card: hands[player]){
            // If found
            if(cset.find(card.getValue()) != cset.end()) {
                pset.insert(card.getValue());
            }
        }
        player_valid_cards[player] = {};
        player_score[player] = 0;
        for(const Card& card: community_cards){
            // If not found
            if(pset.find(card.getValue()) == pset.end()) {
                player_valid_cards[player].push_back(card);
                player_score[player] += card.getValue();
            }
        }
        if(min_score >= player_score[player])
            min_score = player_score[player];
    }

    for(string& player:players){
        cout << setw(20) << player << ": " <<"[" << player_score[player] <<"] | ";
        for(const Card& card:player_valid_cards[player]){
            cout << card.getCard() << " ";
        }
        cout << endl;
    }
    cout << "---WINNERS-------------------------------------------------------------------" << endl;
    cout << setw(20) << "Congratulations!! ";
    for(string& player:players){
        if(player_score[player] == min_score)
            cout << player << ", ";
    }
    cout << "\b\b" << endl;
}