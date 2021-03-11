#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
} * Head;

void create(int A[], int n){
    int i;
    struct Node *new_node, *last;

    Head = (struct Node*)malloc(sizeof(struct Node));
    Head->data = A[0];
    Head->next = Head;
    last = Head;
    for (i = 1; i < n; i++){
        new_node = (struct Node*)malloc(sizeof(struct Node));
        new_node->data = A[i];
        new_node->next = last->next;
        last->next = new_node;
        last = new_node;
    }
}

void display(struct Node *head){
    static int flag = 0;
    if(head != Head || flag ==0){
        flag = 1;
        cout << head->data << " ";
        display(head->next);
    }else{
        cout << endl;
    }
    flag = 0;
}
int length(struct Node *pointer){
    int count = 0;
    do{
        count++;
        pointer = pointer -> next;
    } while (pointer != Head);
    return count;
}

void insert(struct Node *pointer, int index, int val){
    struct Node *temp;
    int i;
    if(index < 0 || index > length(pointer)){
        return;
    }
    if(index ==0){
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = val;

        // if null then it indcates that we want to insert the first node
        if(Head == NULL){
            Head = temp;
            Head->next = Head;
        }else{
            while(pointer -> next != Head){
                pointer = pointer->next;
            }
            pointer->next = temp;
            temp->next = Head;
            Head = temp;
        }
    }else{
        for (i = 0; i < index - 1; i++){
            pointer = pointer->next;
        }
        temp = (struct Node*)malloc(sizeof(struct Node));
        temp->data = val;
        temp->next = pointer->next;
        pointer->next = temp;
    }
}

int delete_item(struct Node *pointer, int index){
    struct Node *dummy;
    int i, x;
    if (index < 0 || index > length(pointer))
    {
        return -1;
    }
    if(index == 0){
        while(pointer->next != Head) pointer = pointer->next;
        x = Head->data;
        if(Head == pointer){
            delete Head;
            Head = NULL;
        }else{
            pointer->next = Head->next;
            delete Head;
            Head = pointer->next;
        }
    }else{
        for (i = 0; i < index - 1; i++)
            pointer = pointer->next;
        dummy = pointer->next;
        pointer->next = dummy->next;
        x = dummy->data;
        delete dummy;
    }
    return x;
}   

int main(){
    int A[] = {2, 3, 4, 5, 6};
    create(A, 5);
    insert(Head, 3, 10);
    delete_item(Head, sizeof(A)/sizeof(A[0]));
    display(Head);
    return 0;
}