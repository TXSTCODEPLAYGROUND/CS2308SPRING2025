//  Q.What is the sum of all the dates in a 30 day month?

// the question simply asks to find the sum from 1 to 30 right? because date starts from 1 and we aren't that dumb to start from 0

#include<iostream>
using namespace std;

int main(){
    int n =30;
    //So we have different ways to do it, we can do it with loop,then let's do it
    int sum= 0;
    for(int i=1;i<=n;i++){
        sum+=i;
    }
    cout<<"Sum of all dates:"<<sum<<endl;//run it and the answer is 465, I know it, yeah!!!!
    //But let's think, what if i want to find the sum of first 1000 natural numbers?
    //Upto 30 we iterated thirty times, so for 1000 are we going to iterate 1000 times?
    //No, it's going to be slower and we don't have much time because we are busy scrolling reels
    //So to save time for scrolling reels, let's try the other way
    //Let's use the formula n*(n+1)/2(We all read this formula to find the sum, if not, read again,you dumb!!!!!!!)
    //So let's use the formula
    int sum1 = n*(n+1)/2;
    cout<<"Sum of all dates using formula:"<<sum1<<endl;//run it and the answer is 465, I know it, yeah!!!!
    //We saved a lot of time and now you are free, go scroll the reels now...................................
    return 0;
}


