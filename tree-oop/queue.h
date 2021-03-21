#include <iostream>
#include "node.h"
using namespace std;

#ifndef queue_h
#define queue_h
class Queue{
    private:
        int front;
        int rear;
        int size;
        Node *(*Q);
    public:
        Queue(){
            front = rear = -1;
            size = 10;
            Q = new Node *[size];
        }

        Queue(int size){
            front = rear = -1;
            this->size = size;
            Q = new Node*[this->size];
        }

        void enqueue(Node *val);
        Node *dequeue();
        int is_empty(Queue q);
};

void Queue::enqueue(Node *val){
    if(rear == size-1){
        cout << "Queue is full" << endl;
    }else{
        Q[++rear] = val;
    }
}

Node* Queue::dequeue(){
    Node *val = NULL;
    if(front == rear){
        cout << "Queue is empty" << endl;
    }else{
        val = Q[front++];
    }
    return val;
}

int Queue::is_empty(Queue q)
{
    return q.front==q.rear;
}
#endif