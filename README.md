# 🌟 Advanced Data Structures Mini-Project
**Course:** Advanced Data Structures (4040) — Fall 2025  
**Topic:** Ordered Lists & Efficiency Analysis  

---

## 📌 Overview
This project explores different strategies for maintaining **ordered lists** using arrays of pointers. The goal is to analyze **efficiency trade-offs** in insertion and removal operations under various approaches.

---

## 🛠 Features
### ✅ Task 1: `OrderedList<T>`
- Template-based ordered list using an array of pointers
- Maintains order by shifting elements from the **front**
- Includes:
  - `AddItem`, `RemoveItem`, `IsEmpty`, `IsFull`, `MakeEmpty`
- Tracks **comparisons** and **moves**

### ✅ Task 2: `EndOrderedList<T>`
- Derived from `OrderedList<T>`
- Starts insertion from the **end** to reduce shifts

### ✅ Task 3: `GapOrderedList<T>`
- Derived from `OrderedList<T>`
- Leaves **gaps** to minimize moves during insertion
- Removal does **not** shift elements
- Gap-aware print method

### ✅ Task 4: Test Program
- Inserts **30 random integers** and removes **25 randomly**
- Runs **100 iterations** for array sizes: `20`, `50`, `10`
- Displays **average comparisons and moves** for each approach

---
