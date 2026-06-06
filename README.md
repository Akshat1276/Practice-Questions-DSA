# 📚 DSA Practice Questions — Akshat1276

![Language](https://img.shields.io/badge/Language-C%2B%2B-blue)
![Status](https://img.shields.io/badge/Status-Active-brightgreen)
![License](https://img.shields.io/badge/License-MIT-yellow)

A structured collection of Data Structures & Algorithms problems solved in C++. This repository serves as a personal practice log aimed at building strong problem-solving skills for SDE interviews and competitive programming.

---

## 📂 Directory Structure

```
Practice-Questions-DSA/
│
├── Arrays/                  # Array manipulation, sliding window, prefix sums
├── LinkedLists/             # Singly, doubly, circular linked lists
├── Stacks_Queues/           # Stack & queue problems, monotonic structures
├── Trees/                   # Binary trees, BSTs, traversals
├── Graphs/                  # BFS, DFS, shortest paths, topological sort
├── Dynamic_Programming/     # Memoization, tabulation, classic DP patterns
├── Strings/                 # String manipulation, pattern matching
├── Sorting_Searching/       # Sorting algorithms, binary search variants
├── Recursion_Backtracking/  # Recursive solutions, backtracking problems
├── Heaps/                   # Min/max heaps, priority queue problems
├── Hashing/                 # Hash maps, frequency counting
├── Miscellaneous/           # Problems not fitting neatly elsewhere
│
├── templates/
│   └── solution_template.cpp  # Standard template for all solutions
│
├── .gitignore
├── LICENSE
└── README.md
```

---

## 🛠️ How to Compile & Run

All solutions are self-contained `.cpp` files. Use the following commands:

### Using g++
```bash
# Compile
g++ -std=c++17 -O2 -o solution <filename>.cpp

# Run
./solution
```

### Example
```bash
g++ -std=c++17 -O2 -o dynamic_array Arrays/dynamic_array.cpp
./dynamic_array
```

### Online Compilers (no local setup needed)
- [Compiler Explorer](https://godbolt.org/)
- [OnlineGDB](https://www.onlinegdb.com/online_c++_compiler)

---

## 📋 Problem Index

| # | Problem | Topic | Difficulty | File |
|---|---------|-------|------------|------|
| 1 | Dynamic Array | Arrays | Easy | [dynamic_array.cpp](dynamic_array.cpp) |

> *(Table will be updated as more solutions are added)*

---

## ✅ Topics Covered

- [x] Arrays
- [ ] Linked Lists
- [ ] Stacks & Queues
- [ ] Trees
- [ ] Graphs
- [ ] Dynamic Programming
- [ ] Strings
- [ ] Sorting & Searching
- [ ] Recursion & Backtracking
- [ ] Heaps & Priority Queues
- [ ] Hashing

---

## 🧠 Code Style & Conventions

Each solution file follows a consistent structure:
- **Problem statement** in a top comment block
- **Approach explanation** (brief intuition)
- **Time & Space complexity** analysis
- **Test cases** included in `main()`

See [`templates/solution_template.cpp`](templates/solution_template.cpp) for the standard format.

---

## 🎯 Goals

- Solve at least one problem per day
- Cover all major DSA topics before placement season
- Document time/space complexity for every solution
- Progress toward SDE interview readiness

---

## 📄 License

This project is licensed under the [MIT License](LICENSE).
