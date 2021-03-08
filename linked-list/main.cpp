#include <iostream>
#include <array>
using namespace std;
// linked list is initially NULL
struct Node{
    int data;
    struct Node *next;
} * first = NULL;

void create(int A[], int n){
    int i;
    struct Node *temp, *last;

    //Zeroth element is created
    first = (struct Node *)malloc(sizeof(struct Node));
    first->data = A[0];
    first->next = NULL;
    last = first;

    // Creating the next elements
    for (i = 1; i < n; i++){
        temp = (struct Node *)malloc(sizeof(struct Node));
        temp->data = A[i];
        temp->next = NULL;
        // set next value of the the latest last which is 0th Node .next = 1th Node value
        // then change the last value as 1th Node, where the 1th Node.next = NULL.
        // Then set next value of the the latest last which is 1th Node .next = 2nd Node value
        // then change the last value as 2nd Node, where the 2nd Node.next = NULL, and so on.
        last->next = temp;
        last = temp;
    }
}

void display(struct Node *node){
    while(node != NULL){
        cout << node->data << " ";

        // move tot he next node
        node = node->next;
    }
    cout << endl;
}

//recursive display
void rec_display(struct Node *node){
    if(node != NULL){
        cout << node->data << " ";
        return rec_display(node->next);
    }
    cout << endl; //
}

int count(struct Node *node){
    if(node != NULL){
        return count(node->next) + 1;
    }else{
        return 0;
    }
}


int sum(struct Node *node){
    if(node != NULL){
        return sum(node->next) + node->data;
    }else{
        return 0;
    }
}

int max(struct Node *node){
    int temp_max = 0;
    if (node != NULL)
    {
        // temp is the value return by max method when analyzing the next Node
        temp_max = max(node->next);
        if(temp_max > node->data){
            return temp_max;
        }else{
            return node->data;
        }
    }
    return INT32_MIN;
}

int min(struct Node *node){
    int temp_min = 0;
    if (node != NULL)
    {
        // temp is the value return by max method when analyzing the next Node
        temp_min = min(node->next);
        if(temp_min < node->data){
            return temp_min;
        }else{
            return node->data;
        }
    }
    return INT32_MAX;
}

// Linear Search
struct Node * LinearSearch(struct Node *node, int key){
    if(node != NULL){
        if(key == node -> data){
            return node;
        }
        return LinearSearch(node->next, key);
    }
    return NULL;
}
int main()
{
    struct Node *temp;
    int A[] = {3, 5, 7, 10, -100, 80, 15, 8, 12, 20};
    int n = sizeof(A) / sizeof(A[0]);
    create(A, n);
    cout << "Iterative display: ";
    display(first);
    cout << "\nRecursive display: ";
    rec_display(first);
    cout << "\nNumber of elements: " << count(first) << endl;
    cout << "\nSum of elements: " << sum(first) << endl;
    cout << "\nMaximum value: " << max(first) << endl;
    cout << "\nMinimum value: " << min(first) << endl;
    temp = LinearSearch(first, 6);
    if(temp){
        cout << "\nFound value of " << temp->data << " in linked list"<< endl;
    }else{
        cout << "Searched value not found" << endl;
    }
    return 0;
} 