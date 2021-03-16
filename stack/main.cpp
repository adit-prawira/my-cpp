#include <iostream>
using namespace std;

struct Stack{
    int size;
    int top;
    int *S;
};

void create(struct Stack *stack){
    cout << "Enter size: ";
    cin >> stack->size;
    stack->top = -1;
    stack->S = (int *)malloc(stack->size * sizeof(int));

}

void display(struct Stack stack){
    int i;
    for (i = stack.top; i >= 0; i--){
        cout << stack.S[i] << " ";
    }
    cout << endl;
}

// Add new value to the next index of current top index
void push (struct Stack *stack, int val){
    if(stack->top == stack->size - 1){
        cout << "Stack overflow" << endl;
    }else{
        stack->top++;
        stack->S[stack->top] = val;
    }
}

int pop(struct Stack *stack){
    int x = -1;
    if(stack -> top == -1){
        cout << "Stack underflow" << endl;
    }else{
        // take the deleted value which was hold within the last index
        x = stack->S[stack->top--];
    }
    return x;
}

int peek(struct Stack stack, int index){
    int x = -1;
    if(stack.top-index+1 < 0){
        cout << "Invalid index" << endl;
    }
    x = stack.S[stack.top - index+1];
    return x;
}

int isEmpty(struct Stack stack){
    return stack.top == -1;
};

int isFull(struct Stack stack){
    return stack.top == stack.size - 1;
};

int stack_top(struct Stack stack){
    if(!isEmpty(stack)){
        return stack.S[stack.top];
    }
    return -1;
}

int main()
{   

    struct Stack stack;
    create(&stack);
    for (int i = 0; i < 11; i++){
        push(&stack, i);
    }
    pop(&stack);
    cout << "Stack is empty?  " << isEmpty(stack)<< endl;
    cout << "Stack is full?  " << isFull(stack)<< endl;
    cout << "Stack Top value: " << stack_top(stack)<< endl;
    cout << "Peek value: " << peek(stack, 5)<< endl;
    display(stack);
    return 0;
}