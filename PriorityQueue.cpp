//
// Created by yusuf on 26.05.2026.
//

#include "PriorityQueue.h"

void PriorityQueue::heapifyUp(int index) {

    while (index > 0) {
        int parent = (index - 1) / 2;
        if (heap[parent]-> freq > heap[index]-> freq ) {
            std::swap(heap[parent], heap[index]);
            index = parent;
        }
        else {
            break;
        }
    }

}

void PriorityQueue::heapifyDown(int index) {

    int smallest = index;
    int left = 2 * index + 1;
    int right = 2 * index + 2;
    if (left < heap.size() && heap[left]-> freq < heap[smallest]-> freq ) {
        smallest = left;
    }

    if (right < heap.size() && heap[right]-> freq < heap[smallest]-> freq ) {
        smallest = right;

    }
    if (smallest != index) {
        std::swap(heap[index], heap[smallest]);
        heapifyDown(smallest);
    }


}

PriorityQueue::PriorityQueue() {
}

PriorityQueue::~PriorityQueue() {
}

void PriorityQueue::insert(Node *node) {
    heap.push_back(node);
    heapifyUp(heap.size() - 1);

}

Node* PriorityQueue::extractMin() {
    Node* minNode = heap[0];
    std::swap(heap[0], heap[heap.size() - 1]);
    heap.pop_back();
    heapifyDown(0);
    return minNode;
}

int PriorityQueue::size() {
    return heap.size();
}

bool PriorityQueue::isEmpty() {
    return heap.size() == 0;

}
