#include <iostream>

extern bool isPrime(int);

int main() {
    std::cout << "Is 17 a prime number?  " << isPrime(17) << std::endl;
    return 0;
}