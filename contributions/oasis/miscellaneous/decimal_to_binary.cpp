#include <iostream>
using namespace std;

int dec_to_bin(int num){
    int remainder;
    int number=0;
    int pow = 1;

    while(num!=0){
        remainder = num % 2;
        num /= 2;
        number += remainder * pow;
        pow *= 10;
    }
    return number;
}

int main(){
    int num;
    cin >> num;
    cout << dec_to_bin(500);
    return 0;

}