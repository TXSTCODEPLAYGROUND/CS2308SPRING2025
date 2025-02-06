#include <iostream>
#include<vector>
#include <cstdlib>
#include<ctime>
using namespace std;

vector<string>createDeck(){
    vector<string>deck;
    vector<string> ranks={"Ace","1","2","3","4","5","6","7","8","9","10","J","Q","K"};
    vector<string> suits={"diamond", "heart", "spades", "clubs"};


    for(string card : ranks){
        for(string suit : suits){
            deck.push_back(card + " of " + suit);
        }
    }
    return deck;
}

void shuffleDeck(vector<string> &deck){
    int random;
    srand(time(0));
    for(int i=0; i<deck.size(); i++){
        random = rand() % deck.size();
        swap(deck[i], deck[random]);
    }
}

int main(){
    vector<string> deck = createDeck();
    shuffleDeck(deck);
    for(string card : deck){
        cout << card << endl;
    }
    return 0;
}
