#include <iostream>
#include <vector>
using namespace std;

int main(){
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
    return 0;
}


