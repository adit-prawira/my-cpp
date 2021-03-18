#include <iostream>
using namespace std;

struct Queue{
    int size;
    int front;
    int rear;
    int *Q;
};
void create(struct Queue *q, int size){
    q->size = size;
    q->front = q->rear = -1;
    q->Q = (int *)malloc(q->size * sizeof(int));
};

// insert a queue
void enqueue(struct Queue *q, int val){
    if(q->rear == q->size-1){
        cout << "Queue is full" << endl;
    }else{
        q->rear++;
        q->Q[q->rear] = val;
    }
}

// delete queue from the front
int dequeue(struct Queue *q){
    int x = -1;
    if(q->front == q->rear){
        cout << "Cannot Delete: Queue is already empty" << endl;
    }else{
        q->front++;
        x = q->Q[q->front];
    }
    return x;
}

void display(struct Queue q){
    int i;
    for (i = q.front+ 1; i <= q.rear; i++){
        cout << q.Q[i] << " ";
    }
    cout << endl;
}

int main()
{
    struct Queue queue;
    create(&queue, 5);
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);
    enqueue(&queue, 50);

    // delete element from the front. Hence 10 is deleted
    dequeue(&queue);
    display(queue);
    return 0;
}