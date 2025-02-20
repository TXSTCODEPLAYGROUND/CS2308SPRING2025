# Returning Arrays from Functions in C++

This project demonstrates why **returning a statically allocated array** from a function is problematic while using **dynamic memory allocation** is the correct approach.

## ❌ Returning a Static (Stack) Array - Why It Fails?

1. In C++, arrays declared inside functions **exist only within that function's stack frame**.
2. Once the function ends, **the stack memory is flushed**, leaving a dangling pointer.
3. If we try to return such an array, the pointer points to an **invalid memory location**, leading to **undefined behavior**.

### 🔴 Problematic Code:
```cpp
int* createArrayUsingStaticArray(int size) {
    int staticArray[size];  // ❌ Stored in stack, disappears after function exits

    for (int i = 0; i < size; i++) {
        staticArray[i] = i * 2;
    }

    return staticArray;  // ❌ Stack memory is released, this will cause unpredictable results!
}
```

### 🚨 Why This Doesn't Work?
- The returned pointer refers to memory that **no longer exists** after the function exits.
- When accessed in `main()`, it **may contain garbage values** or cause crashes.

---

## ✅ Correct Approach: Using Dynamic Memory Allocation (Heap)
Instead of using stack memory, we can allocate memory on the **heap** using `new`.

### ✅ Correct Code:
```cpp
int* createArrayUsingDynamicMemoryAllocation(int size) {
    int* dynamicArray = new int[size];  // ✅ Allocated on heap, persists after function returns

    for (int i = 0; i < size; i++) {
        dynamicArray[i] = i * 2;
    }

    return dynamicArray;  // ✅ Safe to return
}
```

### 🟢 Why This Works?
- Memory allocated using `new` **persists** until explicitly deleted.
- The array remains valid even after the function ends.

### 🔥 **But Don't Forget to Free Memory!**
Since heap memory is **not automatically managed**, we must free it manually using:
```cpp
delete[] dynamicArray;  // ✅ Prevents memory leaks
```

---

## ⚙️ How to Compile and Run
```sh
g++ main.cpp -o array_demo
./array_demo
```

### Expected Output:
```sh
Invalid array output (stack memory flushed, unpredictable values): 4 120 -8388608 4195744 0  
Valid array output (heap memory allocated correctly): 0 2 4 6 8  
```
*(First output is unreliable due to stack memory flush!)*

---

## 📌 Key Takeaways
✔ **Stack memory is temporary** – don't return local arrays!  
✔ **Heap memory persists** – use `new` but remember to `delete` it!  
✔ **Variable-Length Arrays (VLA) are non-standard** – don't rely on them in C++!

---

### **✅ Summary**
- **Why returning a static array fails?**  
  - It uses stack memory, which disappears after the function exits.
- **How does dynamic memory allocation fix this?**  
  - It uses heap memory, which remains valid until explicitly deleted.
- **Why do we need `delete[]`?**  
  - To avoid memory leaks!

This example provides **a practical demonstration** of memory management in C++. 🚀 Let me know if you need any refinements! 😊