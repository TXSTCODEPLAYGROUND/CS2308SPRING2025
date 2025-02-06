#include <iostream>
#include <chrono>
#include <thread>
#include <cstdlib>

using namespace std;

// This is a stupid piece of code, use it wisely

// Function to convert ASCII values back to strings
string decode(const int arr[], int size) {
    string result = "";
    for (int i = 0; i < size; ++i) {
        result += static_cast<char>(arr[i]);
    }
    return result;
}

// Function to add suspense with a delay
void suspensePrint(const string &message, int delay = 800) {
    for (char c : message) {
        cout << c << flush;
        this_thread::sleep_for(chrono::milliseconds(delay / message.size()));
    }
    cout << endl;
}

// Function to print loading dots with delay
void loadingDots(int count = 3, int delay = 700) {
    for (int i = 0; i < count; ++i) {
        cout << ".";
        cout.flush();
        this_thread::sleep_for(chrono::milliseconds(delay));
    }
    cout << endl;
}

// Function to show funny ASCII art
void showFunnyAscii() {
    int bugSlayer[] = {32, 32, 32, 32, 32, 40, 92, 95, 95, 47, 41, 10, 32, 32, 32, 32, 32, 40, 61, 39, 46, 39, 61, 41, 32, 32, 60, 45, 45, 32, 77, 101, 32, 102, 105, 120, 105, 110, 103, 32, 98, 117, 103, 115, 32, 97, 116, 32, 51, 32, 65, 77, 10, 32, 32, 32, 32, 32, 40, 34, 41, 95, 40, 34, 41};
    suspensePrint(decode(bugSlayer, sizeof(bugSlayer)/sizeof(bugSlayer[0])), 1000);
}

int main() {
    srand(time(0));

    int welcomeMsg[] = {87, 101, 108, 99, 111, 109, 101, 32, 116, 111, 32, 116, 104, 101, 32, 117, 108, 116, 105, 109, 97, 116, 101, 32, 67, 43, 43, 32, 102, 117, 110, 32, 99, 104, 97, 108, 108, 101, 110, 103, 101, 33, 32, 240, 159, 154, 128};
    suspensePrint(decode(welcomeMsg, sizeof(welcomeMsg)/sizeof(welcomeMsg[0])), 1500);

    int joke1[] = {87, 104, 121, 32, 100, 111, 110, 39, 116, 32, 112, 114, 111, 103, 114, 97, 109, 109, 101, 114, 115, 32, 108, 105, 107, 101, 32, 110, 97, 116, 117, 114, 101, 63};
    suspensePrint(decode(joke1, sizeof(joke1)/sizeof(joke1[0])), 1500);
    loadingDots(3, 500);

    int punchline1[] = {66, 101, 99, 97, 117, 115, 101, 32, 105, 116, 32, 104, 97, 115, 32, 116, 111, 111, 32, 109, 97, 110, 121, 32, 98, 117, 103, 115, 33, 32, 240, 159, 144, 155, 240, 159, 152, 130};
    suspensePrint(decode(punchline1, sizeof(punchline1)/sizeof(punchline1[0])), 1500);

    suspensePrint("\nTime for some fun surprises!", 1500);
    showFunnyAscii();

    int thanksMsg[] = {84, 104, 97, 110, 107, 115, 32, 102, 111, 114, 32, 112, 108, 97, 121, 105, 110, 103, 33, 32, 75, 101, 101, 112, 32, 99, 111, 100, 105, 110, 103, 32, 97, 110, 100, 32, 115, 116, 97, 121, 32, 97, 119, 101, 115, 111, 109, 101, 33, 32, 240, 159, 148, 140};
    suspensePrint(decode(thanksMsg, sizeof(thanksMsg)/sizeof(thanksMsg[0])), 2000);

    return 0;
}
