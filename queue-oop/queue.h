class Queue{
    int front;
    int rear;
    int size;
    int *Q;

    public:
        Queue(){
            front = rear = -1;
            Q = new int[size];
        }

        Queue(int size){
            front = rear = -1;
            this->size = size;
            Q = new int[this->size];
        }

        void enqueue(int val);
        int dequeue();
        void display();
};