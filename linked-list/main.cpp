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


// Move to front operation linear search node
struct Node * MoveToFrontLinearSearch(struct Node *node, int key){
    struct Node *temp;
    while(node != NULL){
        if(key == node -> data){
            // when target node has been found, then move it to the front
            temp->next = node->next;
            node->next = first;
            first = node;
            return node;
        }
        temp = node;
        node = node->next;
    }
    return NULL;
}


// Insert method
void insert(struct Node *node, int index, int new_value){
    int i;
    struct Node *temp;
    if (index < 0 || index > count(node))
    {
        return;
    }

    temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = new_value;
    if(index == 0){
        temp->next = first;
        first = temp;
    }else{
        // 1 2 5 3
        // insert 4 at index 2
        // therfore
        // 1 2 4 5 3
        // this happens because it sets the next value of 4 to be the next value of 2 which is 5 initially
        // then set 2 to have the next value of 4.
        for (i = 0; i < index - 1; i++){
            node = node->next;
        }
        temp->next = node->next;
        node->next = temp;
    }
}

int main()
{
    struct Node *temp, *temp2;
    int A[] = {3, 5, 7, 10, -100, 80, 15, 8, 12, 20};
    int n = sizeof(A) / sizeof(A[0]);
    create(A, n);
    insert(first, 4, 90);
    cout << "Iterative display: ";
    display(first);
    cout << "\nRecursive display: ";
    rec_display(first);
    cout << "\nNumber of elements: " << count(first) << endl;
    cout << "\nSum of elements: " << sum(first) << endl;
    cout << "\nMaximum value: " << max(first) << endl;
    cout << "\nMinimum value: " << min(first) << endl;
    temp = LinearSearch(first, 12);
    temp2 = MoveToFrontLinearSearch(first, 80);

    if (temp)
    {
        cout << "\nRecursive linear search: Found value of " << temp->data << " in linked list"<< endl;
    }
    else
    {
        cout << "Recursive linear search: Searched value not found" << endl;
    }

    if (temp2)
    {
        cout << "\nMove to front linear search: Found value of " << temp2->data << " in linked list"<< endl;
    }
    else
    {
        cout << "Move to front linear search: Searched value not found" << endl;
    }
    
    display(first);
    return 0;
} 