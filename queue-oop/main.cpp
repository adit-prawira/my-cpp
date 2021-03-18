#include <iostream>
#include "queue.h"

using namespace std;


void Queue::enqueue(int val){
    if(rear == size - 1){
        cout << "Cannot Insert: Queue is full" << endl;
    }else{
        rear++;
        Q[rear] = val;
    }
}

int Queue::dequeue(){
    int x = -1;
    if (front == rear)
    {
        cout << "Cannot Delete: Queue is already empty" << endl;
    }
    else
    {
        front++;
        x = Q[front];
        
    }
    return x;
}

void Queue::display(){
    for(int i = front+1 ; i <= rear; i++){
        cout << Q[i] << " ";
    }
    cout << endl;
}
int main() {
    Queue q(5);
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.dequeue();
    q.display();
    return 0;
}