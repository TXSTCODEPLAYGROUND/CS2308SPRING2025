#include <iostream>
#include <vector>
#include <ctime>
#include <cstdlib>
using namespace std;

vector<string> create_deck(){
    vector<string> deck;
    vector<string> suits = {"diamond","hearts","spades","clubs"};
    vector<string> ranks ={"Ace","2","3","4","5","6","7","8","9","10","Jack","Queen","King"};
    for(string card : suits){
        for(string number : ranks){
            deck.push_back(number +" of " +card); 
        }
    }
    return deck;
}

int main(){

    vector<string> persons = {"P1","P2","P3","P4"};

    vector<string> deck = create_deck();
    srand(time(0));
    for(string person: persons){
        for(int i=0; i<2; i++){
            int random = rand() % 52;
            cout << person + ": " + deck[random] << " ";
            cout << endl;
        }
        
    }
    return 0;
}