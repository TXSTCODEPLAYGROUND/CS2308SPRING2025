# Using Pointers to Create N-Dimensional Arrays in C++

This project demonstrates **how pointers** can be used to dynamically allocate **1D, 2D, and 3D arrays** using **pointer-to-pointer operations**.

---

## 🌟 Key Concepts Demonstrated

1. **Dynamic Memory Allocation**  
   - `new` is used to allocate memory for **1D, 2D, and 3D arrays**.  
   - `delete[]` should be used to free allocated memory.

2. **Pointer to Pointer Operations**  
   - 1D: `int* arr = new int[size];`  
   - 2D: `int** array2D = new int*[rows];`  
   - 3D: `int*** array3D = new int**[depth];`

3. **Memory Organization**  
   - Each pointer points to another dynamically allocated pointer, forming a **multi-dimensional structure**.

---

## 🚀 How Does This Work?

### **1️⃣ Creating a 1D Array**
```cpp
int* create1DArray(int size) {
    int* arr = new int[size];  // ✅ Allocate memory dynamically
    for (int i = 0; i < size; i++)
        arr[i] = randNum();  // ✅ Fill array with random numbers
    return arr;
}
```

### **2️⃣ Creating a 2D Array (Pointer to Pointer)**
```cpp
int** create2DArray(int rows, int cols) {
    int** array2d = new int*[rows];  // ✅ Allocate memory for row pointers
    for (int i = 0; i < rows; i++)
        array2d[i] = create1DArray(cols);  // ✅ Allocate each row separately
    return array2d;
}
```

### **3️⃣ Creating a 3D Array (Pointer to Pointer to Pointer)**
```cpp
int*** create3DArray(int depth, int rows, int cols) {
    int*** array3d = new int**[depth];  // ✅ Allocate memory for depth pointers
    for (int i = 0; i < depth; i++)
        array3d[i] = create2DArray(rows, cols);  // ✅ Allocate each 2D layer separately
    return array3d;
}
```

---

## 🎯 **Challenge for Students: Improve the `display` Function!**
Currently, the `display` function is limited:
- **It requires multiple manual calls for each row and layer**.
- **It does not provide depth labeling in the 3D array**.
- **It does not format the output for better readability**.

### ❓ Can you improve it?
Modify the `display` function to:
1. **Automatically iterate through a 2D or 3D array** instead of manually calling it for each row.
2. **Label depths for 3D arrays** (`Depth 1:`, `Depth 2:`).
3. **Format the output nicely** for better readability.

### 🛠️ Example of an Improved Display
Instead of:
```sh
---3D---
5, 3, 2, 
1, 9, 7, 
6, 8, 4, 
```
Try formatting like:
```sh
--- 3D Array ---
Depth 1:
5  3  2
1  9  7
6  8  4

Depth 2:
4  7  6
3  2  9
8  1  5
```
This makes the array **easier to read and understand**.

---

## 🔥 Expected Output Example (With Current Code)

```sh
---1D---
3, 7, 2, 9, 1, 

---2D---
5, 8, 6, 
4, 2, 7, 
9, 3, 1, 

---3D---
5, 3, 2, 
1, 9, 7, 
6, 8, 4, 

4, 7, 6, 
3, 2, 9, 
8, 1, 5, 
```

---

## 🛠️ Compile & Run:
```sh
g++ main.cpp -o array_pointers
./array_pointers
```

---

🚀 **Can you optimize the `display` function and make the output more readable?** Submit your improvements! Happy coding! 😊

---

### **✅ Summary**
- The program follows the **original display style**.
- Students are **challenged to improve the `display` function**.
- The **README.md encourages students to contribute with formatting improvements**.

This version stays **true to your style** while making it **engaging for students**. 🚀 Let me know if you need refinements! 😊