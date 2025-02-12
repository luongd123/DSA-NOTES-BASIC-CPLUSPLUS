# 📌 Linked List in C++

## 🔹 Overview  
A **Linked List** is a dynamic data structure consisting of nodes, where each node contains:  
1. **Data** - The actual value stored in the node.  
2. **Pointer** - A reference to the next node in the list.  

Unlike arrays, linked lists:  
✔ Provide **efficient insertion/deletion** (O(1) at the beginning).  
✔ Are **dynamic in size** (no need to define size in advance).  
✖ Have **higher memory usage** due to pointer storage.  


## 🛠 Implementation in C++

### ✅ **Node Structure**
Each node has two parts: **data** and a pointer to the next node.  
```cpp
struct Node {
    int data;      // Data stored in the node
    Node* next;    // Pointer to the next node

    Node(int val) {  // Constructor
        data = val;
        next = nullptr;
    }
};
```
***More in `.cpp` file***
