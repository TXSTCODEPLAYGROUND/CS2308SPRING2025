#include <iostream>
#include <vector>
using namespace std;

int uniqueNum(vector<int> &nums){
    int ans = 0;
    for(int val:nums){//Using the range-based for loop
        ans = ans ^ val;//We are using XOR operation between the current value and the value of ans
    }
    //XOR operation gives 1 if the bits are different, 0 if the bits are same
    //Before entering the loop, we have ans = 0
    //ans = 0^1 i.e 1(0^01=1)
    //ans = 1^2 i.e 3(01^10 = 11)
    //ans = 3^2 i.e 1(11^10 = 01 = 1)
    //ans = 1^3 i.e 2(01^11= 10 = 2)
    //ans = 2^3 i.e 1(10^11 = 01 =1)
    //Therefore the answer is 1 
    return ans;
}

int main(){
    vector <int> numbers =  {1,2,2,3,3};//Every vector has one unique element, find the unique element in that vector
    //We are not going to use nested loop, because we want to maintain linear runtime complexity(O(1))
    cout<<uniqueNum(numbers)<<endl;
    return 0;
}