#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>
using namespace std;

int deal_card(){
    vector<int> list_of_cards {11, 2, 3, 4, 5, 6, 7, 8, 9, 10, 10, 10};
    return list_of_cards[rand() % 12];
}

int calculate_score(vector<int> &cards) {
    int total_sum = 0;
    for (int i = 0; i < cards.size(); i++) {
        total_sum += cards[i];
    }

    if (total_sum == 21 && cards.size() == 2) {
        return 0;
    }
    else if (total_sum > 21) {
        for (int i= 0; i < cards.size(); i++) {
            if (cards[i] == 11) {
                cards[i] = 1;
            }
            total_sum = 0;
            for (int j = 0; j < cards.size(); j++) {
                total_sum += cards[j];
            }
        }
    }
    return total_sum;
}

void winorlose(int u, int c) {
    if (u==c) {
        cout << "Draw" << endl;
    }
    else if (u==0) {
        cout << "You win, Blackjack" << endl;
    }
    else if (c==0) {
        cout << "You lose, Computer has a Blackjack" << endl;
    }
    else if (u > 21) {
        cout << "You lose, You went over" << endl;
    }
    else if (c > 21) {
        cout << "You win, Computer went over" << endl;
    }
    else if (u > c) {
        cout << "You win" << endl;
    }
    else {
        cout << "You lose" << endl;
    }
}

void playgame() {
    vector<int> usercard;
    vector<int> compcard;
    int c = -1, u = -1;
    bool game_over = false;

    for (int i = 0; i < 2; i++) {
        usercard.push_back(deal_card());
        compcard.push_back(deal_card());
    }

    while (!game_over) {
        u = calculate_score(usercard);
        c = calculate_score(compcard);
        cout << "Your cards: " << " [";
        for (int i = 0; i < usercard.size(); i++) {
            cout << usercard[i] << ", ";
        }
        cout << "]" << endl;
        cout << "Computer's cards: " << " [";
        for (int i = 0; i < compcard.size(); i++) {
            cout << compcard[i] << ", ";
        }
        cout << "]" << endl;
        if (u==0 || c== 0 || u >21) {
            game_over = true;
        }
        else {
            string again;
            cout << "Do you want more cards?(y/n) ";
            cin >> again;
            if (again == "y") {
                usercard.push_back(deal_card());
            }
            else {
                game_over = true;
            }
        }
    }

    while (c!= 0 && c <17) {
        compcard.push_back(deal_card());
        c = calculate_score(compcard);
    }

    u = calculate_score(usercard);
    c = calculate_score(compcard);
    cout << "Your final cards: " << " [";
    for (int i = 0; i < usercard.size(); i++) {
            cout << usercard[i] << ", ";
    }
    cout << "]" << ", Your final score: " << u <<endl;
    cout << "Computer's final cards: " << " [";
    for (int i = 0; i < usercard.size(); i++) {
            cout << usercard[i] << ", ";
    }
    cout << "]" << ", Computer's final score: " << c << endl;
    winorlose(u, c);
}

int main() {
    string play;
    cout << "Do you want to play the Blackjack game?(y/n) : ";
    cin >> play;
    while(play == "y") {
        cout << "\n";
        playgame();
        cout << endl << endl;
        cout << "Do you want to play the Blackjack again?(y/n) :";
        cin >> play;
    }
}
