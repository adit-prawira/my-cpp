#include <iostream>
using namespace std;

#ifndef node_h
#define node_h
class Node {
    public:
        Node *left_child;
        int data;
        Node *right_child;
};
#endif