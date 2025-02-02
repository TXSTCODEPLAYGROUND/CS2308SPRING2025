#include <iostream>
using namespace std;
#include "functions/utils.h"

int main()
{
    int number;
    cout << "Enter a positive integer: ";
    cin >> number;

    // Check if the number is prime
    if (isPrime(number))
        cout << number << " is a prime number." << endl;
    else
        cout << number << " is not a prime number." << endl;

    // Check if the number is a right-truncated prime
    if (isRTPrime(number))
        cout << number << " is a right-truncated prime." << endl;
    else
        cout << number << " is not a right-truncated prime." << endl;

    // Check if the number is a left-truncated prime
    if (isLTPrime(number))
        cout << number << " is a left-truncated prime." << endl;
    else
        cout << number << " is not a left-truncated prime." << endl;

    return 0;
}