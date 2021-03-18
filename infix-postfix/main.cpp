#include <iostream>
#include "stack.h"
#include <stack>
using namespace std;

void Stack::push(int x) {
    Node* t = new Node;
    if (t == nullptr){
        cout << "Stack Overflow!" << endl;
    } else {
        t->data = x;
        t->next = top;
        top = t;
    }
}

int Stack::pop() {
    Node* p;
    int x = -1;
    if (top == nullptr){
        cout << "Stack Underflow!" << endl;
    } else {
        p = top;
        x = p->data;
        top = top->next;
        delete p;
    }
    return x;
}

int Stack::is_full() {
    Node* t = new Node;
    int r = t ? 1 : 0;
    delete t;
    return r;
}

int Stack::is_empty() {
    return top ? 0 : 1;
}

int Stack::stack_top() {
    if (top){
        return top->data;
    }
    return -1;
}

int Stack::peek(int index) {
    if (is_empty()){
        return -1;
    } else {
        Node* p = top;

        for (int i=0; p != nullptr && i<index-1; i++){
            p = p->next;
        }

        if (p != nullptr){
            return p->data;
        } else {
            return -1;
        }
    }
}


int is_operand(char x){
    if (x == '+' || x == '-' || x == '*' || x == '/'){
        return 0;
    }
    return 1;
}

int operation(char op, int x, int y){
    if (op == '+'){
        return x + y;
    } else if (op == '-'){
        return x - y;
    } else if (op == '*'){
        return x * y;
    } else if (op == '/'){
        return x / y;
    }else{
        return 0;
    }
}

int postfix_evaluate(char* postfix){
    stack<int> stack;
    int x;
    int y;
    int result;
    for (int i=0; postfix[i]!='\0'; i++){
        if (is_operand(postfix[i])){
            // int typecast would not work because of char so subtract '0'
            stack.push(postfix[i]-'0');
        } else {
            y = stack.top();
            stack.pop();
            x = stack.top();
            stack.pop();
            result = operation(postfix[i], x, y);
            stack.push(result);
        }
    }
    result = stack.top();
    stack.pop();
    return result;
}

int evaluate(char* postfix){
    Stack stack;
    int x;
    int y;
    int result;
    for (int i=0; postfix[i]!='\0'; i++){
        if (is_operand(postfix[i])){
            // int typecast would not work because of char so subtract '0'
            stack.push(postfix[i]-'0');
        } else {
            y = stack.pop();
            x = stack.pop();
            result = operation(postfix[i], x, y);
            stack.push(result);
        }
    }
    result = stack.pop();
    return result;
}
int main(){
    char postfix[] = "35*62/+4-";
    cout << evaluate(postfix) << endl;
    cout << postfix_evaluate(postfix) << endl;
    return 0;
}