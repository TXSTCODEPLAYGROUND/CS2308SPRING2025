#include <iostream>
#include <vector>
#include <iomanip> // For std::setw

using namespace std;

// Function 1: Passing vector by value vs reference
void modifyVectorByValue(vector<int> vec) {
    vec.push_back(100);
}

void modifyVectorByReference(vector<int>& vec) {
    vec.push_back(100);
}

// Function 2: Demonstrate memory allocation and doubling behavior
void demonstrateMemoryAllocation() {
    vector<int> vec;
    cout << setw(10) << "Index" << setw(10) << "Size" << setw(15) << "Capacity" << endl;
    for (int i = 0; i < 100; ++i) {
        vec.push_back(i);
        cout << setw(10) << i << setw(10) << vec.size() << setw(15) << vec.capacity() << endl;
    }
}

// Function 3: Optimized memory allocation using reserve
void optimizedMemoryAllocation() {
    vector<int> vec;
    vec.reserve(100);
    cout << setw(10) << "Index" << setw(10) << "Size" << setw(15) << "Capacity" << endl;
    for (int i = 0; i < 100; ++i) {
        vec.push_back(i);
        cout << setw(10) << i << setw(10) << vec.size() << setw(15) << vec.capacity() << endl;
    }
}

// Function 4: Demonstrate shrink_to_fit and resize
void shrinkAndResizeDemo() {
    vector<int> vec(20, 5); // Initialize with 20 elements, all set to 5
    cout << "Initial size: " << vec.size() << ", capacity: " << vec.capacity() << endl;

    vec.resize(10); // Resize to 10 elements
    cout << "After resize (to 10): size = " << vec.size() << ", capacity = " << vec.capacity() << endl;

    vec.shrink_to_fit(); // Shrink capacity to fit the size
    cout << "After shrink_to_fit: size = " << vec.size() << ", capacity = " << vec.capacity() << endl;
}

// Function 5: Insert one vector into another
void insertVectorDemo() {
    vector<int> vec1 = {1, 2, 3};
    vector<int> vec2 = {4, 5, 6};

    vec1.insert(vec1.end(), vec2.begin(), vec2.end()); // Insert vec2 into vec1 at the end

    cout << "Vector after insertion: ";
    for (int val : vec1) {
        cout << val << " ";
    }
    cout << endl;
}

// Function 6: Vector iterator invalidation
void iteratorInvalidationDemo() {
    vector<int> vec = {1, 2, 3, 4, 5};
    cout << "Original vector: ";
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;

    // Invalidating iterators by inserting elements
    auto it = vec.begin() + 1;
    vec.insert(it, 99);

    cout << "After insertion (iterator invalidated): ";
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;

    // Invalidating iterators by removing elements
    it = vec.begin() + 2;
    vec.erase(it);

    cout << "After erasure (iterator invalidated): ";
    for (int val : vec) {
        cout << val << " ";
    }
    cout << endl;
}

int main() {
    // Passing vector by value vs reference
    vector<int> myVec = {1, 2, 3};
    modifyVectorByValue(myVec);
    cout << "After modifyVectorByValue, size of vector: " << myVec.size() << endl;

    modifyVectorByReference(myVec);
    cout << "After modifyVectorByReference, size of vector: " << myVec.size() << endl;

    // Demonstrate vector memory allocation
    cout << "\nDemonstrating memory allocation and doubling behavior:\n";
    demonstrateMemoryAllocation();

    // Optimized memory allocation
    cout << "\nOptimized memory allocation using reserve:\n";
    optimizedMemoryAllocation();

    // Shrink and resize
    cout << "\nDemonstrating shrink_to_fit and resize:\n";
    shrinkAndResizeDemo();

    // Insert vector
    cout << "\nDemonstrating vector insertion:\n";
    insertVectorDemo();

    // Iterator invalidation
    cout << "\nDemonstrating iterator invalidation:\n";
    iteratorInvalidationDemo();

    return 0;
}
