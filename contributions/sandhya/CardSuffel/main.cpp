#include <iostream>
#include <vector>
#include <algorithm>
#include <random>
//display the players' cards
void displaycards(const std::vector<std::pair<std::string, int>>& Players, const std::string& name) {
    std::cout<<name<<": ";
    for(const auto& card:Players) {
        std::cout<<card.second<<"of"<<card.first<<", ";
    }
    std::cout<<std::endl;
}

int main() {
    std::vector<std::string>shapes={"Heart", "Diamond","spades", "Clubs" };
    std::vector<std::pair<std::string, int>> cards;

//create vector holding tw0 different data types
     for(std::string suits:shapes) {
         for(int i=1; i<=13;i++){
             cards.emplace_back(suits, i);
         }
     }
    // Step 2: Shuffle using a random number generator in the same line
    std::shuffle(cards.begin(), cards.end(), std::mt19937{std::random_device{}()});

    // Step 3: Distribute cards between 4 players
         std::vector<std::pair<std::string, int >> player1, player2,player3,player4;
         for (size_t i = 0; i < cards.size(); ++i) {
             switch (i % 4) {
                 case 0:
                     player1.emplace_back(cards[i]);
                 break;
                 case 1:
                     player2.emplace_back(cards[i]);
                 break;
                 case 2:
                     player3.emplace_back(cards[i]);
                 break;
                 case 3:
                     player4.emplace_back(cards[i]);
                 break;
             }
         }
//calling function to display the cards.
    displaycards(player1,"player1");
    displaycards(player2,"player2");
    displaycards(player3,"player3");
    displaycards(player4,"player4");

    return 0;
}


