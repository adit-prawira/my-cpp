class Stack{
    private:
        int size;
        int top;
        char *S;

    public:
        Stack(int size){
            this->size = size;
            top = -1;
            S = new char[size];
        }
        ~Stack(){
            delete []S;
        };
        void push(char c);
        char pop();
        char peek(int index);
        int is_empty();
        int is_full();
        void display();
        char stack_top();
};