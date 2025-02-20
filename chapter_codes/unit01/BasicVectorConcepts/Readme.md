# Vector Concepts in C++

This program demonstrates key concepts of `std::vector` in C++, covering common operations and behaviors, including memory management, resizing, iterator invalidation, and more. It is designed to help learners understand how vectors work and optimize their usage.

---

## **Concepts and Functions**

### 1. Passing Vector by Reference vs Value
- **Functions**:
    - `modifyVectorByValue()`
    - `modifyVectorByReference()`
- **What It Demonstrates**:
    - **By Value**: Modifications do not affect the original vector.
    - **By Reference**: Modifications directly affect the original vector.

---

### 2. Memory Allocation and Doubling Behavior
- **Function**: `demonstrateMemoryAllocation()`
- **What It Demonstrates**:
    - Vectors dynamically grow by doubling their capacity when the size exceeds the current capacity.
    - Output includes the **index**, **size**, and **capacity**, formatted using `std::setw` for better readability.

---

### 3. Optimized Memory Allocation with `reserve()`
- **Function**: `optimizedMemoryAllocation()`
- **What It Demonstrates**:
    - Pre-allocating memory using `reserve()` avoids the overhead of dynamic resizing.
    - The capacity remains fixed after reserving memory.

---

### 4. Shrink and Resize
- **Function**: `shrinkAndResizeDemo()`
- **What It Demonstrates**:
    - **`resize`**: Adjusts the size of the vector, either truncating or expanding it.
    - **`shrink_to_fit`**: Reduces the capacity to match the current size, releasing unused memory.

---

### 5. Inserting One Vector into Another
- **Function**: `insertVectorDemo()`
- **What It Demonstrates**:
    - Inserts elements of one vector into another at a specified position using `insert()`.

---

### 6. Iterator Invalidation
- **Function**: `iteratorInvalidationDemo()`
- **What It Demonstrates**:
    - Shows how adding or removing elements invalidates iterators, causing undefined behavior if used afterward.

---