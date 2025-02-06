#include <iostream>
#include <cmath>
using namespace std;

int binary_to_dec(int num){
    int number=0;
    int i=0;
    int remainder;

    while(num!=0){
        remainder = num %10;
        num /= 10;
        number += remainder * pow(2,i);
        i++;
    }
    return number;
}

int main(){
    int num;
    cin >> num;

    cout << binary_to_dec(num);
}