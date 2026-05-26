#include <iostream>
#include <string>
#include <unordered_map>
#include "PriorityQueue.h"

void printCodes(Node* root, std::string code) {
    if (!root) return;

    if (root->left == nullptr && root->right == nullptr) {
        std::cout << "  '" << root->data << "' : " << code << "\n";
    }

    printCodes(root->left, code + "0");
    printCodes(root->right, code + "1");
}

int main() {
    std::string text = "huffman coding c++ platform test";
    std::cout << "Test : " << text << "\n--------------------------------\n";

    std::unordered_map<char, int> freqMap;
    for (char ch : text) {
        freqMap[ch]++;
    }

    PriorityQueue pq;
    for (const auto& pair : freqMap){
        pq.insert(new Node(pair.first, pair.second));
    }

    while (pq.size() > 1) {
        Node* left = pq.extractMin();
        Node* right = pq.extractMin();

        Node* parent = new Node('$', left->freq + right->freq);
        parent->left = left;
        parent->right = right;

        pq.insert(parent);
    }

    if (!pq.isEmpty()) {
        Node* root = pq.extractMin();
        printCodes(root, "");
        delete root;
    }

    return 0;
}