#include <iostream>
#include <vector>
using namespace std;

vector<int> pairsum(vector<int> nums, int target){
    vector<int> ans;
    int n= nums.size();

    for(int i = 0; i < n; i++){
        for(int j =i+1; j< n; j++){
            if(nums[i] + nums[j]== target){
                ans.push_back(nums[i]);
                ans.push_back(nums[j]);
                return ans;
            }
        }
    }   
    return ans;
}

int main(){
    int target = 6;
    vector<int> nums = {1,5,6,2,11};
    // vector<int> answer = pairsum(nums, target);
    vector<int> answer =  pairsum(nums,target);
    cout << answer[0]  << " " << answer[1] <<  endl;
    return 0;
}