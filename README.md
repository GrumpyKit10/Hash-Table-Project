# Hash Table Project

**Author:** Matthew Wilson
**Course:** CSCE 2110.002
**Date:** 10/29/21

## Overview

This project implements a simple **hash table** in C++ that stores strings using **chaining** to handle collisions. It provides basic operations including insertion, search, deletion, and printing the contents of the table.

---

## Features

* **Insert**: Add a string to the hash table.
* **Search**: Check if a string exists in the table.
* **Delete**: Remove a string from the table.
* **Print**: Display the contents of the table, including collision chains and tombstone flags.
* **Collision handling**: Uses **linked lists** (chaining) for buckets with multiple entries.
* **Tombstones**: Marks deleted nodes to maintain table integrity.

---

## Files

| File       | Description                                         |
| ---------- | --------------------------------------------------- |
| `main.cpp` | User interface for interacting with the hash table. |
| `hash.h`   | Declares the `Hash` class and its member functions. |
| `hash.cpp` | Implements the hash table operations.               |
| `node.h`   | Declares the `node` class for linked list buckets.  |
| `node.cpp` | Implements the `node` class.                        |
| `Makefile` | Compiles the project using `g++`.                   |

---

## Build Instructions

1. Open a terminal in the project directory.
2. Compile the project using the provided Makefile:

   ```bash
   make
   ```
3. Run the program:

   ```bash
   ./hash
   ```

To clean up object files and the executable:

```bash
make clean
```

---

## Usage

When the program runs, you will see a menu:

```
Enter choice:
0 - Insert
1 - Search
2 - Delete
3 - Print
4 - Quit
```

* Enter `0` to insert a string.
* Enter `1` to search for a string.
* Enter `2` to delete a string.
* Enter `3` to print the current state of the table.
* Enter `4` to quit the program.

---

## Notes

* The hash table is fixed at size 10.
* Collisions are handled via **linked list chaining**.
* Deleted nodes are tracked with a tombstone flag to maintain insertion and deletion integrity.

---

## Example

```
Enter choice:
0 - Insert
1 - Search
2 - Delete
3 - Print
4 - Quit
0
Enter a name to insert: Alice
0
Enter a name to insert: Bob
3
Index:  Tombstone:  Name(s):
0      0           Alice
1      0           Bob
...
```
