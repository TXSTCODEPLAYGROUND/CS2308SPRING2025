#include <iostream>
using namespace std;

int sum_of_digits(int num){
    int sum=0;
    while(num > 0){
        int lastDigit = num % 10;
        num = num/10;
        sum += lastDigit;
    }
    return sum;
}

int main(){
    int num;
    cin >> num;
    cout << sum_of_digits(num);
}