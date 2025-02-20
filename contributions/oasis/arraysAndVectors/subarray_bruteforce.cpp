#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<int> arr = {1,2,3,4,5};
    int n = 5;
    int max_sum = 0;
    for (int i=0; i<n; i++){
        int current_sum = 0;
        for (int j=i; j<n; j++){
            current_sum += arr[j];
            max_sum = max(current_sum, max_sum);
        }
    }
    cout << max_sum;
    return 0;
}