#include<arrayAndVectors.h>
#include <iostream>
#include <vector>
using namespace std;

void vectorSizeDemo() {
    vector<int> myVector = {1,2,3,4,5};
    std::cout<<"Using the SizeOfOperator: "<<sizeof(myVector)<<std::endl;//24
    //There are 5 elements in the vector and the total size of the vector should be 5*4=20, but why is it 24?
    //Vector store data in a heap memory and it is dynamic memory allocation.
    //sizeof(myVector) will return the size of the vector object, not the size of the data it contains.
    //The size of the vector object is 24 bytes on a 64-bit system, which includes the size of the pointer to the data, the size of the size_t variable that stores the number of elements in the vector, and the size of the capacity_t variable that stores the capacity of the vector.

    //To get the size of the data stored in the vector, we can use the size() function
    std::cout<<"Using the Size() Function: "<<myVector.size()<<std::endl; //5
    //size() function returns the number of elements in the vector.
    //To get the total size of the data stored in the vector, we can use the size() function and multiply it by the size of each element
    std::cout<<"Total Size of the Data: "<<myVector.size()*sizeof(myVector[0])<<std::endl; //20
}
// ------------------------------------------------------------------------------------------------------
//  Q.What is the sum of all the dates in a 30 day month?

// the question simply asks to find the sum from 1 to 30 right? because date starts from 1 and we aren't that dumb to start from 0

//So we have different ways to do it, we can do it with loop,then let's do it
int sumUsingLoop(int n) {
    int sum= 0;
    for(int i=1;i<=n;i++){
        sum+=i;
    }
    return sum;
}
//But let's think, what if i want to find the sum of first 1000 natural numbers?
//Upto 30 we iterated thirty times, so for 1000 are we going to iterate 1000 times?
//No, it's going to be slower and we don't have much time because we are busy scrolling reels
//So to save time for scrolling reels, let's try the other way
//Let's use the formula n*(n+1)/2(We all read this formula to find the sum, if not, read again,you dumb!!!!!!!)
//So let's use the formula
int sumUsingFormula(int n) {
    return n*(n+1)/2;
}

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

//We saved a lot of time and now you are free, go scroll the reels now...................................
