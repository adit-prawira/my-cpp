#include <iostream>
#include "queue.h"

using namespace std;

struct Node *root = NULL;

void tree_create(){
    struct Node *p,*t;
    int x;
    struct Queue q;
    create(&q,100);
    cout << "Enter root value: ";
    cin >> x;
    root = (Node *)malloc(sizeof(struct Node));
    root->data = x;
    root->left_child = root->right_child = NULL;
    enqueue(&q, root);
    while(!empty(q)){
        p = dequeue(&q);
        cout << "Enter left child of "<< p->data << ": ";
        cin >> x;
        if(x != -1){
            t = (Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->left_child = t->right_child = NULL;
            p->left_child = t;
            enqueue(&q, t);
        }
        cout << "Enter right child "<< p->data << ": ";
        cin >> x;
        if(x != -1){
            t = (Node *)malloc(sizeof(struct Node));
            t->data = x;
            t->right_child = t->left_child = NULL;
            p->right_child = t;
            enqueue(&q, t);
        }
    }
}

void pre_order(struct Node *p){
    if(p){
        cout << p->data << " ";
        pre_order(p->left_child);
        pre_order(p->right_child);
    }
}
void in_order(struct Node *p){
    if(p){
        in_order(p->left_child);
        cout << p->data << " ";
        in_order(p->right_child);
    }
}
void post_order(struct Node *p){
    if(p){
        post_order(p->left_child);
        post_order(p->right_child);
        cout << p->data << " ";
    }
}
int main (){
    tree_create();
    pre_order(root);
    cout << endl;
    post_order(root);
    cout << endl;
    in_order(root);
    cout << endl;
    return 0;
}