#include <iostream>
using namespace std;

struct Node{
    struct Node *left_child;
    int data;
    struct Node *right_child;
}*root=NULL;


// Put greater value on the right child and the smaller value on the left child.
// Method won't insert anything if the given value is already exist in the tree.
void insert(int key){
    struct Node *t1 = root;
    struct Node *t2, *new_node;

    // checking if root is the very first Node which is initially still empty.
    if(root ==NULL){
        new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = key;
        new_node->left_child = new_node->right_child = NULL;
        // finish process after creating the very first Node
        return;
    }


    // Otherwise create a new node at the given position.
    while(t1 != NULL){
        t2 = t1;
        if(key < t1-> data){
            t1 = t1->left_child;
        }else if(key > t1->data){
            t1 = t1->right_child;
        }else{
            return;
        }
    }

    new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = key;
    new_node->left_child = new_node->right_child = NULL;

    if(key < t2->data){
        t2->left_child = new_node;
    }else{
        t2->right_child = new_node;
    }
}

void in_order(struct Node *p){
    if(p != NULL){
        in_order(p->left_child);
        cout << p->data << " ";
        in_order(p->right_child);
    }
}
int main()
{

    return 0;
}