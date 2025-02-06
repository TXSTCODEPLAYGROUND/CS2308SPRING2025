#include <iostream>
using namespace std;

void fibonacci(int num){
    int a = 0, b = 1, next;
    int sequence;
    if (num >= 1) {
        cout << a << " "; // Print the first Fibonacci number
    }
    if (num >= 2) {
        cout << b << " "; // Print the second Fibonacci number
    }
    for (int i=3; i<= num; i++){
        sequence += i;
        cout << sequence << " ";
    }
}

int main(){
    fibonacci(5);
    return 0;
}