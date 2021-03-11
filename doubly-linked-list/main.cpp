#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *previous, *next;
} *first = NULL;

void create(int A[], int n){
    int i;
    struct Node *new_node, *last;
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->previous = first->next = NULL;
    last = first;
    for (i = 1; i < n; i++){
        new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = A[i];
        // where current last->next = NULL
        new_node->next = last->next;
        
        // set the previous value by the latest value before the new node insertion
        new_node->previous = last;
        last->next = new_node;
        last = new_node;
    }
}
void display(struct Node *pointer){
    while(pointer){
        cout << pointer->data << " ";
        pointer = pointer -> next;
    }
    cout << endl;
}

int length(struct Node *pointer){
    int count = 0;
    while(pointer){
        count ++;
        pointer = pointer->next;
    }
    return count;
}
void insert(struct Node *pointer, int index, int val){
    int i;
    struct Node *new_node;

    if (index < 0 || index > length(pointer))
    {
        return;
    }
    if(index == 0){
        new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = val;
        new_node -> previous = NULL;
        new_node->next = first;
        first -> previous = new_node;
    }else{
        for (i = 0; i< index - 1; i++){
            pointer = pointer->next;
        }
        new_node = (struct Node *)malloc(sizeof(struct Node));
        new_node->data = val;
        new_node->previous = new_node;
        new_node->next = pointer->next;
        if(pointer -> next)
            (pointer->next)->previous = new_node;
        pointer->next = new_node;
    }
}

int delete_item(struct Node *pointer, int index){
    int i, x = -1;
    if (index < 0 || index > length(pointer))
    {
        return -1;
    }
    if(index == 0){
        first = first->next;
        if(first)
            first->previous = NULL;
        x = pointer->data;
        delete pointer;
    }else{
        for (i = 0; i < index-1; i++){
            pointer = pointer->next;
        }
        (pointer->previous)->next = pointer->next;
        if(pointer -> next != NULL){
            (pointer->next)->previous = pointer->previous;
        }
        x = pointer->data;
        delete pointer;
    }
    return x;
}

void reverse(struct Node *pointer){
    struct Node *temp;
    while(pointer != NULL){
        temp = pointer->next;
        pointer->next = pointer->previous;
        pointer->previous = temp;
        pointer = pointer->previous;
        if(pointer != NULL && pointer -> next == NULL){
            first = pointer;
        }
    }
}
int main()
{
    int A[] = {10, 20, 30, 40, 50};
    create(A, 5);
    insert(first, 3, 70);
    insert(first, 1, 80);
    insert(first, 0, 15);
  
    cout << "\nLinked list with length of " << length(first) << endl;
    cout << "Linked List elements: ";
    display(first);
    cout << "\nReversed linked list: ";
    reverse(first);
    display(first);
    return 0;
}