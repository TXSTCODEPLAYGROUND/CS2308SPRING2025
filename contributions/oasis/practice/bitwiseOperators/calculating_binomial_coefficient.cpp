#include <iostream>
using namespace std;

int factorial(int num){
    int fact = 1;
    for(int i=1; i<=num; i++){
        fact = fact * i;
    }
    return fact;
}

int main(){
    int n,r;
    double bi_co;
    cout << "Enter your n: ";
    cin >> n;

    cout << "Enter your r: ";
    cin >>r;

    bi_co = factorial(n)/((factorial(r))*factorial(n-r));
    cout << bi_co;
    return 0;
}