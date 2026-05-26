//
// Created by yusuf on 26.05.2026.
//

#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H
#include <vector>

#include "Node.h"


class PriorityQueue {
    private:
    std::vector<Node*> heap;
    void heapifyUp(int index);
    void heapifyDown(int index);

    public:
    PriorityQueue();
    ~PriorityQueue();
    void insert(Node* node);
    Node* extractMin();
    int size();
    bool isEmpty();
};



#endif //PRIORITYQUEUE_H
