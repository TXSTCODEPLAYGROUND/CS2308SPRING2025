#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> numbers = {1,2,3,4,5,6,7,8,9,0};
    int num;
    int index =0 ;
    cout<< "what do you wanna search?: ";
    cin >> num;
    
    for(int number : numbers){
        if(num==number){
            cout << index;
        }
        index++;
    }
    return 0;
}