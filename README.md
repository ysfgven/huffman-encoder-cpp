# huffman-encoder-cpp

A Huffman encoding implementation in C++ built from scratch — no STL priority queue, custom min-heap and tree.

## What it does

Reads an input string, calculates character frequencies, builds a Huffman tree, and prints the binary code for each character.

```
Test : huffman coding c++ platform test
--------------------------------
  ' ' : 000
  'a' : 1110
  'c' : 0110
  'f' : 10110
  ...
```

## How it works

1. Count character frequencies
2. Insert each character as a leaf node into a min-heap
3. Repeatedly extract the two lowest-frequency nodes, merge them into a parent node, reinsert
4. Traverse the resulting tree — left edge = `0`, right edge = `1`

## Complexity

| Step | Time |
|------|------|
| Frequency count | O(n) |
| Build heap | O(k log k) |
| Build tree | O(k log k) |
| Print codes | O(k) |

`n` = input length, `k` = unique character count. Overall: **O(n + k log k)**

## Project structure

```
├── main.cpp
├── Node.h / Node.cpp          # Tree node
└── PriorityQueue.h / PriorityQueue.cpp   # Min-heap
```

## Build & run

```bash
g++ -std=c++17 main.cpp Node.cpp PriorityQueue.cpp -o huffman
./huffman
```

## Notes

- Internal (non-leaf) nodes use `'$'` as a placeholder character
- Memory is managed via destructor — `~Node()` recursively frees the tree
