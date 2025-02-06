#include <iostream>
#include <cmath>
using namespace std;

bool isPrime(int num){
    if(num<=1){
        return false;
    }
    
    for(int i=2; i<=sqrt(num); i++){
        if (num % i == 0){
            return false;
        }
    }
    return true;
}

int main(){
    int num;
    cin >>num;
    for (int i=2; i<= num; i++){
        if (isPrime(i) == true){
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}