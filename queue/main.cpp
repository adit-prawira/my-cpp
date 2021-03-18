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

void create_circular(struct Queue *q, int size){
    q->size = size;
    q->front = q->rear = 0;
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

void enqueue_circular(struct Queue *q, int val){
    if((q->rear+1)%q->size == q->front){
        cout << "Queue is full" << endl;
    }else{
        q->rear = (q->rear+1)%q->size;
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

int dequeue_circular(struct Queue *q){
    int x = -1;
    if(q->front == q->rear){
        cout << "Cannot Delete: Queue is already empty" << endl;
    }else{
        q->front = (q->front+1)%q->size;
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

void display_circular(struct Queue q){
    int i = q.front +1;
    do{
        cout << q.Q[i] << " ";
        i = (i + 1) % q.size;
    } while (i != (q.rear + 1) % q.size);
    cout << endl;
};

void queue_normal(){
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
}
void queue_circular(){
    struct Queue queue;
    create_circular(&queue, 5);
    enqueue_circular(&queue, 10);
    enqueue_circular(&queue, 20);
    enqueue_circular(&queue, 30);
    enqueue_circular(&queue, 40);
    dequeue_circular(&queue);
    display_circular(queue);
}
int main()
{
    //queue_normal();
    queue_circular();
    return 0;
}