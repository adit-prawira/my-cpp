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
        root = new_node;
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

// Search and return node of the given key if exist within the tree
struct Node* search(int key){
    struct Node *temp = root;
    while(temp != NULL){
        if(key == temp->data ){
            return temp;
        }else if(key < temp->data){
            temp = temp->left_child;
        }else{
            temp = temp->right_child;
        }
    }
    return NULL;
}
struct Node * recursive_insert(struct Node *p, int key){
    if(p == NULL){
        struct Node *temp;
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = key;
        temp->left_child = temp->right_child = NULL;
        return temp;
    }
    if(key < p->data){
        p->left_child = recursive_insert(p->left_child, key);
    }else if (key > p->data){
        p->right_child = recursive_insert(p->right_child, key);
    }
    return p;
}

int height(struct Node*p){
    int x, y;
    if (p == NULL)
    {
        return 0;
    }
    x = height(p->left_child);
    y = height(p->right_child);
    return x > y ? x + 1 : y + 1;
}

struct Node* in_predecessor(struct Node *p){
    while(p && p->right_child != NULL){
        p = p->right_child;
    }
    return p;
}

struct Node* in_successor(struct Node *p){
    while(p && p->left_child != NULL){
        p = p->left_child;
    }
    return p;
}
struct Node* delete_node(struct Node*p, int key){

    struct Node *q;
    if (p == NULL)
    {
        return NULL;
    }
    if(p->left_child == NULL && p->right_child==NULL){
        if(p==root){
            root = NULL;
        }
        delete p;
        return NULL;
    }
    if(key < p->data){
        p->left_child = delete_node(p->left_child, key);
    }else if(key > p->data){
        p->right_child = delete_node(p->right_child, key);
    }else{
        if(height(p->left_child) > height(p->right_child)){
            q = in_predecessor(p->left_child);
            p->data = q->data;
            p->left_child = delete_node(p->left_child, q->data);
        }else{
            q = in_predecessor(p->right_child);
            p->data = q->data;
            p->right_child = delete_node(p->right_child, q->data);
        }
    }
    return p;
}

void test1(){
    struct Node *searched_value;
    int key = 20;
    insert(10);
    insert(5);
    insert(20);
    insert(8);
    insert(30);
    cout << "Tree: ";
    in_order(root);
    cout << endl;
    searched_value = search(key);
    if(searched_value != NULL){
        cout << "Value of " << key << " is found in tree" << endl;
    }else{
        cout << "Value of " << key << " is not found" << endl;
    }
    struct Node *deleted_element;
    deleted_element = delete_node(root, key);
    if(deleted_element != NULL){
        cout << "Deleted " << key << " from tree" << endl;
    }else{
        cout << "Value of " << key << " is not found" << endl;
    }
    cout << "New Tree: ";
    in_order(root);
    cout << endl;
}
void test2(){
    struct Node *searched_value;
    int key = 200;
    root= recursive_insert(root, 10);
    recursive_insert(root, 5);
    recursive_insert(root, 20);
    recursive_insert(root, 8);
    recursive_insert(root, 30);
    in_order(root);
    cout << endl;
    searched_value = search(key);
    if(searched_value != NULL){
        cout << "Value of " << key << " is found in tree" << endl;
    }else{
        cout << "Value of " << key << " is not found" << endl;
    }
}
int main()
{
    int choice;
    cout << "Choose test options: ";
    cin >> choice;
    switch(choice){
        case 1:
            test1();
            break;
        case2:
            test2();
            break;
    }

    return 0;
}