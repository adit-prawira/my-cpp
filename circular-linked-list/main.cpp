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
    do{
        cout << head->data << " ";
        head = head->next;
    } while (head != Head);
    cout << endl;
}
int main(){
    int A[] = {2, 3, 4, 5, 6};
    create(A, 5);
    display(Head);
    return 0;
}