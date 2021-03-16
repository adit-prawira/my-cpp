#include <iostream>
#include "stack.h"
using namespace std;

void Stack::push(int val){
    Node *temp = new Node;
    if(temp == NULL){
        cout << "Stack is Full" << endl;
    }else{
        temp->data = val;
        temp->next = top;
        top = temp;
    }
}
int Stack::pop(){
    int x = -1;
    if (top == NULL)
    {
        cout << "Stack is empty" << endl;
    }else{
        x = top->data;
        Node *temp = top;
        top = top->next;
        delete temp;
    }
    return x; 
}

void Stack::display(){
    Node *iterator = top;
    while(iterator != NULL){
        cout << iterator->data << " ";
        iterator = iterator->next;
    }
    cout << endl;
}
int main(){
    Stack stack;
    stack.push(10);
    stack.push(20);
    stack.push(30);
    stack.push(40);
    stack.push(50);
    stack.push(60);
    stack.display();
    stack.pop();
    stack.display();
    return 0;
}