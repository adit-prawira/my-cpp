#include "node.h"
#include <iostream>

class Stack{
    private:
        Node *top;
        
    public:
        Stack(){
            top = NULL;
        }

        void push(int val);
        int pop();
        void display();
};