//
// Created by yusuf on 26.05.2026.
//

#ifndef NODE_H
#define NODE_H



class Node {

    public:
    Node* left;
    Node* right;
    char data;
    Node(char data,int freq);
    ~Node();
    int freq;

};



#endif //NODE_H
