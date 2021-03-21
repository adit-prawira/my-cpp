#include <iostream>
#include "queue.h"
using namespace std;

#ifndef tree_h
#define tree_h
class Tree{
    public:
        Node *root;
        Tree(){
            root = NULL;
        }
        void create();
        void pre_order(Node *p);
        void in_order(Node *p);
        void post_order(Node *p);
        void level_order(Node *p);
        void height(Node *root);
};
void Tree::create(){
    Node *p,*t;
    Queue q(100);
    int x;
    cout << "Enter root value: ";
    cin >> x;
    root = new Node;
    root->data = x;
    root->left_child = root->right_child = NULL;
    q.enqueue(root);
    while(!q.is_empty(q)){
        p = q.dequeue();
        cout << "Enter left child of "<< p->data << ": ";
        cin >> x;
        if(x != -1){
            t = new Node;
            t->data = x;
            t->left_child = t->right_child = NULL;
            p->left_child = t;
            q.enqueue(t);
        }
        cout << "Enter right child "<< p->data << ": ";
        cin >> x;
        if(x != -1){
            t = new Node;
            t->data = x;
            t->right_child = t->left_child = NULL;
            p->right_child = t;
            q.enqueue(t);
        }
    }
}

void pre_order(Node *p){
    if(p){
        cout << p->data << " ";
        pre_order(p->left_child);
        pre_order(p->right_child);
    }
}
void in_order(Node *p){
    if(p){
        in_order(p->left_child);
        cout << p->data << " ";
        in_order(p->right_child);
    }
}
void post_order(Node *p){
    if(p){
        post_order(p->left_child);
        post_order(p->right_child);
        cout << p->data << " ";
    }
}
#endif