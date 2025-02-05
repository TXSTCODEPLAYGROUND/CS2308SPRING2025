#include <iostream>
using namespace std;

int reverse(int num){
    int number = 0;
    while(num != 0){
        int remainder = num % 10;
        num /= 10;
        number = number * 10 + remainder;
    }
    return number;
}

int main() {
    int num;
    cin >> num;

    cout << reverse(num);

    return 0;
}