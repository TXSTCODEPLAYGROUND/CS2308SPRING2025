#include <iostream>
using namespace std;

int main() {
    int num;
    cin >> num;

    if (num == 0 ){
        cout << "Not a power of two";
    }
    if ((num & (num-1)) == 0){
        cout << "It is a power of two";
    }
    return 0;
}