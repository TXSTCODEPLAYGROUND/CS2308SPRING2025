#include <iostream>
using namespace std;

//function to check if a number is prime
bool isPrime(int num){  //function to check if a number is prime; returns in boolean

    if (num <=2 || num % 2 == 0)    //if number is less than or equal to 2 or number is divisible by 2
        return num == 2;    //return true if number is 2

    for (int i = 3; i * i <= static_cast<int>(sqrt(num)); i += 2){  //loop to check if number is prime
        if (num % i == 0)   //if number is divisible by i
            return false;   //return false
    }
    return true;    //return true if number is prime
}

//function to check if a number is right-truncatable prime
//Example of right-truncatable prime: 3797, 379, 37, 3

bool isRTPrime(int num){
    return isPrime(num) ? isRTPrime(num / 10) : num == 0;
}

//function to check if a number is left-truncatable prime
//Example of left-truncatable prime: 3797, 797, 97, 7

bool isLTPrime(int num){ //return boolean
    int divisor = 1;    
    while (divisor <= num)  
        divisor *= 10;  
    while (isPrime(num)){   
        divisor /=10;
        num %= divisor; //remove the first digit
    }
    return num == 0;
}


//function to count the number of digits in a number
//Example: 1234 has 4 digits

int countDigits(int num){
    int digitCount = 0;
    while(num > 0){
        digitCount++;
        num /= 10;
    }
    return digitCount;
}

//function to check if a number is left-truncatable prime with digits count
//Example: 3797, 797, 97, 7; 3797 has 4 digits

bool isLTPrimeWithCountDigits(int num){
    int digitCount = countDigits(num);
    while(digitCount > 0){
        if(!isPrime(num))
            return false;
        num %= static_cast<int>(pow(10, digitCount - 1));
        digitCount--;
    }

    return true;

}


int main() {
    
    int num = 3797;
    cout << "isPrime(" << num << ") = " << isPrime(num) << endl;
    cout << "isRTPrime(" << num << ") = " << isRTPrime(num) << endl;
    cout << "isLTPrime(" << num << ") = " << isLTPrime(num) << endl;
    cout << "countDigits(" << num << ") = " << countDigits(num) << endl;
    cout << "isLTPrimeWithCountDigits(" << num << ") = " << isLTPrimeWithCountDigits(num) << endl;

    return 0;
}
