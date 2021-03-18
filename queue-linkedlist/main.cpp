#include <iostream>
using namespace std;

struct Node{
    int data;
    struct Node *next;
} *front = NULL, *rear = NULL;

void enqueue(int val){
    struct Node *temp;
    temp = (struct Node *)malloc(sizeof(struct Node));
    if(temp == NULL){
        cout << "Queue is full" << endl;
    }else{
        temp->data = val;
        temp->next = NULL;
        if(front == NULL){
            front = rear = temp;
        }else{
            rear->next = temp;
            rear = temp;
        }
    }
}

int dequeue(){
    int x = -1;

    struct Node *temp;
    if(front == NULL){
        cout << "Cannot delete: Queue is already empty" << endl;
    }else{
        x = front->data;
        temp = front;
        front = front->next;
        delete temp;
    }
    return x;
}

void display(){
    struct Node *pointer = front;
    while(pointer != NULL){
        cout << pointer->data << " ";
        pointer = pointer->next;
    }
    cout << endl;
}
int main()
{
    enqueue(10);
    enqueue(20);
    enqueue(30);
    enqueue(40);
    enqueue(50);
    display();

    cout << "Deleted Element: " << dequeue() << endl;
    display();
    return 0;
}