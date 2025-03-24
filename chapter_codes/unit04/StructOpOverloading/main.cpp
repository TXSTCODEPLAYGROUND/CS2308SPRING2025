// Make sure you are using c++17
// g++ -std=c++17 overloading.cpp 
#include <iostream>
#include <map>
#include <iomanip>

using namespace std;
struct GameCard;
ostream& operator<<(ostream&, GameCard&);
GameCard operator+(GameCard&, GameCard&);

struct GameCard {
    map<string, int> games;
    int score = 0;
    GameCard(map<string, int> games) : games(games){
        for(const auto& [game, score] : games){
            this->score += score;
        }
    }
    int& operator->(){
        return this->score;
    }
    void operator+=(GameCard& card){
        for(const auto& [game, score] : card.games){
            this->score += score;
            this->games[game] = score;
        }     
    }
    void operator-=(GameCard& card){
        for(const auto& [game, score] : card.games){
            auto key = this->games.find(game);
            if (key != this->games.end()) {
                // Delete the item using the iterator
                this->games.erase(key);
                this->score -= score;
            }
        }
    }
};

ostream& operator<<(ostream& COUT, GameCard& card){
    cout << setw(25) << "Games" 
         << setw(10) << "Score"
         << endl;
    cout << setw(35) << setfill('-') << "" << endl;
    cout << setfill(' ');
    for(const auto& [game, score] : card.games){
        cout << setw(25) << game
             << setw(10) << score
             << endl;
    }
    cout << setw(35) << setfill('-') << "" << endl;
    cout << setfill(' ');
    cout << setw(25) << "Total Score" 
         << setw(10) << card.score
         << endl;
    return COUT;
}
GameCard operator+(GameCard& card0, GameCard& card1){
    GameCard card = GameCard({});
    for(const auto& [game, score] : card0.games){
            card.games[game] = score;
            card.score += score;
    }
    for(const auto& [game, score] : card1.games){
            card.games[game] = score;
            card.score += score;
    }
    return card;
}

void showInfo(const string& info, GameCard& card){
    cout << info << endl;
    cout << card;
    cout << setw(35) << setfill('~') << "" << endl;
    cout << setfill(' ');
}

int main()
{
    GameCard card0 = GameCard(
        {
            {"Resident Evil-4, Village", 1100},
            {"Assasin Creed, Mirage", 800},
            {"Assasin Creed, Valhalla", 1300},
            {"GTA-V", 2500},
        }
    );
    GameCard card1 = GameCard(
        {
            {"Tom Clancy's, Ghost Recon", 100},
            {"Sniper Elite 5", 3800},
        }
    );

    GameCard card2 = GameCard(
        {
            {"Limbo", 1000},
        }
    );
    GameCard card = card0 + card1;
    showInfo("CARD: card0", card0);
    showInfo("CARD: card1", card1);
    showInfo("CARD: card2", card2);
    showInfo("CARD: card = card0+card1", card);
    card += card2;    
    showInfo("CARD: card += card2", card);
    card -= card0;
    showInfo("CARD: card -= card0", card);
    return 0;
}
