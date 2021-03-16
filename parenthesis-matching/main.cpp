#include <iostream>
#include <cstring>
#include "stack.h"
#include <stack>
using namespace std;
void Stack::push(char c){
    if(is_full()){
        cout << "Stack overflow" << endl;
    }else{
        S[++top] = c;
    }
}

char Stack::pop(){
    char c = -1;
    if (is_empty())
    {
        cout << "Stack underflow" << endl;
    }
    else
    {
        c = S[top--];
    }
    return c;
}
char Stack::peek(int index){
    char c = -1;

    if (top - index + 1 < 0 || top - index + 1 == size)
    {
        cout << "INVALID INDEX" << endl;
    }else{
        c = S[top - index + 1];
    }
    return c;
}
char Stack::stack_top(){
    return (is_empty()) ? -1 : S[top];
}
void Stack::display()
{
    for (int i = top; i >= 0; i--){
        cout << S[i] << " ";
    }
    cout << endl;
}
int Stack::is_full(){
    return top == size - 1;
};
int Stack::is_empty(){
    return top == -1;
}

bool is_balanced(char *C){
    Stack stack(strlen(C));
    for (int i = 0; i < strlen(C); i++){
        if(C[i] == '('){
            stack.push(C[i]);
        }else if(C[i] == ')'){
            if(stack.is_empty()){
                return false;
            }else{
                // confirmed balanced parenthesis
                // if current stack has ( and then the character that is being iterated meet )
                // then pop the last element in stack which is ( and the goal is to make stack empty
                stack.pop();
            }
        }
    }
    return stack.is_empty() ? true : false;
}

int out_precedence(char c){
    if (c == '+' || c == '-'){
        return 1;
    } else if (c == '*' || c == '/'){
        return 3;
    } else if (c == '^'){
        return 6;
    } else if (c == '('){
        return 7;
    } else if (c == ')'){
        return 0;
    }
    return -1;
}
int in_precedence(char c){
    if (c == '+' || c == '-'){
        return 2;
    } else if (c == '*' || c == '/'){
        return 4;
    } else if (c == '^'){
        return 5;
    } else if (c == '('){
        return 0;
    }
    return -1;
}

int is_operand(char c){
    return (c == '+' || c == '-' || c == '*' || c == '/' ||
        c == '^' || c == '(' || c == ')');
}

char * infix_to_postfix(char *infix){
    int i = 0, j = 0;
    char *postfix = new char[strlen(infix)];
    Stack stack(strlen(infix));
    while(infix[i] != '\0'){
        if(is_operand(infix[i])){
            postfix[j++] = infix[i++];
        }else{
            if(stack.is_empty() || out_precedence(infix[i]) > in_precedence(stack.stack_top())){
                stack.push(infix[i++]);
            }else if (out_precedence(infix[i]) == in_precedence(stack.stack_top())){
                stack.pop();
            }else{
                postfix[j++] = stack.stack_top();
                stack.pop();
            }
        }
    }
    while(!stack.is_empty() && stack.stack_top() != ')'){
        postfix[j++] = stack.stack_top();
        stack.pop();
    }
    postfix[j] = '\0';
    return postfix;
}

int evaluate(char *postfix){
    
}
int main()
{
    
    char E[] = "((a+b)*(c-d))";
    cout << is_balanced(E) << endl;

    char F[] = "((a+b)*(c-d)))";
    cout << is_balanced(F) << endl;

    char G[] = "(((a+b)*(c-d))";
    cout << is_balanced(G) << endl;

    char infix[] = "a+b*c";
    cout << infix_to_postfix(infix) << endl;

    return 0;
}