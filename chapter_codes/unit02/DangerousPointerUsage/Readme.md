# Incorrect Pointer Usage and Memory Leaks in C++

This project demonstrates:
1. **Memory leak due to incorrect pointer reassignment**.
2. **Copying arrays incorrectly, leading to double deletion errors**.
3. **How to correctly copy dynamic arrays** without memory leaks.

---

## ❌ Problem 1: Memory Leak from Pointer Reassignment

```cpp
int* ptr = new int[5];  // ✅ Allocate memory
ptr = new int[10];  // ❌ Lost first allocation (memory leak!)
```

- The first allocation is **not freed**, so it remains in memory without a reference.
- **Solution:** Always `delete[]` before reassigning a pointer.

---

## ❌ Problem 2: Copying Pointers Instead of Allocating New Memory

```cpp
int* arr1 = new int[5];
int* arr2 = arr1;  // ❌ arr2 points to the same memory as arr1
```

- Now **both pointers share the same memory**.
- **When deleting `arr1`, `arr2` becomes a dangling pointer**, leading to undefined behavior.

### ✅ Correct Way: Allocate a Separate Copy

```cpp
int* arr2 = new int[5];  // ✅ Allocate new memory
memcpy(arr2, arr1, 5 * sizeof(int));  // ✅ Copy values safely
```

---

## ❌ Problem 3: Double Deletion Error

```cpp
delete[] arr1;
delete[] arr2;  // ❌ Undefined behavior! arr2 was never separately allocated.
```

- **Solution:** Allocate new memory before copying and ensure each allocation is deleted separately.

---

## 🔥 Expected Output

```sh
Demonstrating incorrect usage (memory leak):
First allocation, ptr points to: 0 10 20 30 40 
Second allocation, ptr now points to: 0 20 40 60 80 100 120 140 160 180 

Demonstrating correct usage (no memory leak):
First allocation, ptr points to: 0 10 20 30 40 
Second allocation, ptr now points to: 0 20 40 60 80 100 120 140 160 180 

Demonstrating incorrect pointer copying (double delete error):
arr1: 1 2 3 4 5 
arr2 (same memory as arr1): 1 2 3 4 5 
[Program may crash here due to double delete!]

Demonstrating correct pointer copying (safe allocation & deletion):
arr1: 1 2 3 4 5 
arr2 (separate memory copy): 1 2 3 4 5 
```

---

## 🛠️ Compile & Run:
```sh
g++ main.cpp -o pointer_demo
./pointer_demo
```

### **✅ Summary**
- **Memory leaks occur when dynamic memory is lost without deletion.**
- **Pointer copying errors happen when two pointers share the same allocation.**
- **Always `delete[]` before reassigning and allocate fresh memory for copies.**

This version **clearly demonstrates** **memory mismanagement, copying issues, and proper fixes**. 🚀 Let me know if you need any refinements! 😊