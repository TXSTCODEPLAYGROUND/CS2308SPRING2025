#include <iostream>
#include <vector>
#include <climits>
using namespace std;

int main(){
    
    int n=7;
    int sum = 0;
    int max_sum= INT_MIN;

    vector<int> arr= {3,-4,5,4,-1,7,-8};
    for(int st=0; st<n; st++){
        sum += arr[st];
        max_sum = max(sum,max_sum);
        if(sum < 0){
            sum = 0;
        }
    }

    cout << max_sum;
    return 0;
}