//
// Created by yusuf on 26.05.2026.
//


#include "Node.h"


Node::Node(char data, int freq) {
    this->data = data;
    this->freq = freq;
    this->right = nullptr;
    this->left = nullptr;
}

Node::~Node() {

    delete right;
    delete left;
}
