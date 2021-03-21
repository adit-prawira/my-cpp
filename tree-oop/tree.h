#include <iostream>
#include "queue.h"
using namespace std;

#ifndef tree_h
#define tree_h
class Tree
{
    Node *root;

    public:
        Tree(){root=NULL;}
        void create();
        void pre_order(){pre_order(root);}
        void pre_order(Node *p);
        void post_order(){post_order(root);}
        void post_order(Node *p);
        void in_order(){in_order(root);}
        void in_order(Node *p);
        void level_order(){level_order(root);}
        void level_order(Node *p);
        int height(){return height(root);}
        int height(Node *root);
};
void Tree::create()
{
    Node *p,*t;
    int x;
    Queue q(100);

    cout << "Enter root value: ";
    cin >> x;
    root = new Node;
    root->data=x;
    root->left_child=root->right_child=NULL;
    q.enqueue(root);

    while(!q.is_empty())
    {
        p=q.dequeue();
        cout << "Enter left child of " << p->data << ": ";
        cin >> x;
        if (x != -1)
        {
            t=new Node;
            t->data=x;
            t->left_child=t->right_child=NULL;
            p->left_child=t;
            q.enqueue(t);
        }
        cout << "Enter right child of " << p->data << ": ";
        cin >> x;
        if(x!=-1)
        {
            t=new Node;
            t->data=x;
            t->left_child=t->right_child=NULL;
            p->right_child=t;
            q.enqueue(t);
        }
    }
}
void Tree::pre_order(struct Node *p)
{
    if(p)
    {
        cout << p->data << " ";
        pre_order(p->left_child);
        pre_order(p->right_child);
    }
}
void Tree::in_order(struct Node *p)
{
    if(p)
    {
        in_order(p->left_child);
        cout << p->data << " ";
        in_order(p->right_child);
    }
}
void Tree::post_order(struct Node *p)
{
    if(p)
    {
        post_order(p->left_child);
        post_order(p->right_child);
        cout << p->data << " ";
    }
}
void Tree::level_order(struct Node *root)
{
    Queue q(100);

    cout << root->data << " ";
    q.enqueue(root);

    while(!q.is_empty())
    {
        root=q.dequeue();
        if(root->left_child)
        {
            cout << root->left_child->data << " ";
            q.enqueue(root->left_child);
        }
        if(root->right_child)
        {
            cout << root->right_child->data << " ";
            q.enqueue(root->right_child);
        }
    }
}
int Tree::height(struct Node *root)
{
    int x=0,y=0;
    if(root==0)
        return 0;
    x=height(root->left_child);
    y=height(root->right_child);
    if(x>y)
        return x+1;
    else
        return y+1;
}
#endif