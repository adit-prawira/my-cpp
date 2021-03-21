#include <iostream>
using namespace std;

#ifndef queue_h
#define queue_h
struct Node
{
    struct Node *left_child;
    int data;
    struct Node *right_child;
};
struct Queue
{
    int size;
    int front;
    int rear;
    struct Node **Q;
};
void create(struct Queue *q,int size)
{
    q->size=size;
    q->front=q->rear=0;
    q->Q=(struct Node **)malloc(q->size*sizeof(struct Node *));
}
void enqueue(struct Queue *q,struct Node *x)
{
    if((q->rear+1)%q->size==q->front){
        cout << "Queue is Full" << endl;
    }
    else{
        q->rear=(q->rear+1)%q->size;
        q->Q[q->rear]=x;
    }
}
struct Node * dequeue(struct Queue *q)
{
    struct Node* x=NULL;

    if(q->front==q->rear){
        cout << "Queue is Empty" << endl;
    }else
    {
        q->front=(q->front+1)%q->size;
        x=q->Q[q->front];
    }
    return x;
}
int empty(struct Queue q)
{
    return q.front==q.rear;
}
#endif