# 📚 Library Catalog System 

![C++](https://img.shields.io/badge/Language-C++-00599C?style=for-the-badge&logo=c%2B%2B)
![Data Structure](https://img.shields.io/badge/Data_Structure-Binary_Search_Tree-brightgreen?style=for-the-badge)

A lightweight, terminal-based Library Catalog System built in C++ that efficiently stores, manages, and retrieves book records using a **Binary Search Tree (BST)**. 

Books are stored as nodes in the BST, using the unique `Book ID` as the primary key for lightning-fast insertions, deletions, and lookups[cite: 1].

## ✨ Features

This mini-project implements all core catalog operations:
* **➕ Add Books:** Insert new books into the catalog with their ID, Title, Author, and ISBN[cite: 1].
* **🗑️ Delete Books:** Efficiently remove outdated or lost books from the system while maintaining the BST structure[cite: 1].
* **🔍 Search:** Quickly find a specific book by its Book ID[cite: 1].
* **📖 Sorted Display:** View the entire library catalog in ascending order based on Book ID using an inorder traversal[cite: 1].
* **📊 Live Tracking:** Keep an active count of the total number of books currently in the system[cite: 1].

## 🛠️ Tech Stack & Concepts
* **Language:** C++ (`<iostream>`, `<string>`, `<iomanip>`)
* **Core Data Structure:** Binary Search Tree (BST)
* **Algorithms:** Inorder Traversal, BST Insertion, BST Deletion (including inorder successor replacement)

## 🚀 Getting Started

### Prerequisites
You will need a C++ compiler installed on your system (such as `g++` for Linux/Mac or MinGW for Windows).

### Installation & Execution

1. **Clone the repository:**
   ```bash
   git clone [https://github.com/YOUR_USERNAME/bst-library-catalog-cpp.git](https://github.com/YOUR_USERNAME/bst-library-catalog-cpp.git)
   cd bst-library-catalog-cpp
