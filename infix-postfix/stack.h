#include <iostream>
#include "node.h"
class Stack{
    private:
        Node* top;
    public:
        Stack(){
            top = nullptr;
        };
        ~Stack(){
            Node* p = top;
            while (top){
                top = top->next;
                delete p;
                p = top;
            }
        };
        void push(int x);
        int pop();
        int peek(int index);
        int is_empty();
        int is_full();
        int stack_top();
};
