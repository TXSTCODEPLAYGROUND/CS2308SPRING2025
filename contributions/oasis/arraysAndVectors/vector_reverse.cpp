#include <iostream>
#include <vector>
using namespace std;

void swap(int &a, int &b){
    int tempval;
    tempval = a;
    a = b;
    b = tempval;
}

void reverse(vector<int> &nums){
    int start = 0;
    int end = nums.size() - 1; // MISTAKE: use nums.size() instead of sizeof(num);
    while (start < end){
        swap(nums[start], nums[end]);
        start++;
        end--;
    }
}

int main(){
    vector<int> nums = {1,2,3,4,5,6,7};
    reverse(nums);
    for (int numbers : nums){
        cout << numbers << endl;
    }

    return 0;
}