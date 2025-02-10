#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

struct Deck {
    const char* suits_arr[4] = {"Hearts", "Diamonds", "Clubs", "Spades"};
    const char* ranks_arr[13] = {"Ace", "King", "Qween", "Jack", "10", "9", "8", "7", "6", "5", "4", "3", "2"};
};

int main() {
    Deck deck;

    std::vector<std::string> main_deck;

    for (size_t i = 0; i < sizeof(deck.suits_arr)/sizeof(deck.suits_arr[0]); i++)
    {
        for (size_t j = 0; j < sizeof(deck.ranks_arr)/sizeof(deck.ranks_arr[0]); j++)
        {
            std::string card = std::string(deck.ranks_arr[j]) + " of " + deck.suits_arr[i];
            main_deck.push_back(card);
        }
    }

    //Shuffle the deck
    std::random_device seed;
    std::mt19937_64 g(seed());
    std::shuffle(main_deck.begin(), main_deck.end(), g);

    std::vector<std::string> p1_deck;
    std::vector<std::string> p2_deck;
    std::vector<std::string> p3_deck;
    std::vector<std::string> burner_deck;
    std::vector<std::string> flop_deck;
    
    int user_input, push_index=0;
    bool passFlag = false;

    std::cout << "<---------------------------------------------------->" << std::endl;
    std::cout << "--------------Texas Hold'em Poker---------------------" << std::endl;
    std::cout << "<---------------------------------------------------->" << std::endl;
    
    
    
    std::cout << "Menu:\n";
    std::cout << "Enter 1 to play\n";
    std::cout << "Enter -1 to exit\n";
    std::cout << "Choice: ";
    std::cin >> user_input;
    std::cout << "----------------------------------------------------" << std::endl;
    
    while (user_input != 1 && user_input != -1) {

        std::cout << "Please enter a valid input (-1/1): ";
        std::cin >> user_input;
    }  

    if (user_input==-1)
    {
        std::cout << "okay bye :D!";
        return -1;
    }
    
    p1_deck.push_back(main_deck[push_index]);
    push_index++;
    p2_deck.push_back(main_deck[push_index]);
    push_index++;
    p1_deck.push_back(main_deck[push_index]);
    push_index++;
    p2_deck.push_back(main_deck[push_index]);
    push_index++;

    burner_deck.push_back(main_deck[push_index]);
    push_index++;
    
    for (size_t i = 0; i < 3; i++)
    {
        flop_deck.push_back(main_deck[push_index]);
        push_index++;
    }

    // Display code
    std::cout << "Player 1 DECK: ";
    for (const auto& card : p1_deck) 
    {
        std::cout << card << " | ";
    }
    std::cout << std::endl;

    std::cout << "Player 2 DECK: ";
    for (const auto& card : p2_deck) 
    {
        std::cout << card << " | ";
    }
    std::cout << std::endl;

    do {   
        std::cout << "----------------------------------------------------" << std::endl;
        std::cout << "COMMUNITY CARDS: ";
        for (const auto& card : flop_deck) 
        {
        std::cout << card << " | ";
        }
        std::cout << std::endl;
        
        std::cout << "BURNED DECK: ";
        for (const auto& card : burner_deck) 
        {
        std::cout << card << " | ";
        }
        std::cout << std::endl;
        std::cout << "----------------------------------------------------" << std::endl;

        burner_deck.push_back(main_deck[push_index]);
        push_index++;

        flop_deck.push_back(main_deck[push_index]);
        push_index++;

        passFlag = false;

        if (flop_deck.size() > 5) break;
        std::cout << "Enter any key to continue (-1 to exit): ";
        std::cin >> user_input;
        passFlag = (user_input != -1);

    } while (passFlag);
    
    std::cout << std::endl;
    std::cout << "<---------------------------------------------------->" << std::endl;
    std::cout << "--------------Thank you for playing ;D----------------" << std::endl;
    std::cout << "<---------------------------------------------------->" << std::endl;
    return 0;
}