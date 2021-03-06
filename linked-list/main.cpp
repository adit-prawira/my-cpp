#include <iostream>
#include <array>
using namespace std;
// linked list is initially NULL
struct Node{
    int data;
    struct Node *next;
} *first = NULL, *second = NULL, *third=NULL;

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

void create_second(int A[], int n){
    int i;
    struct Node *temp, *last;

    //Zeroth element is created
    second = (struct Node *)malloc(sizeof(struct Node));
    second->data = A[0];
    second->next = NULL;
    last = second;

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
    struct Node *new_node;
    if (index < 0 || index > count(node))
    {
        return;
    }

    new_node = (struct Node*)malloc(sizeof(struct Node));
    new_node->data = new_value;
    if(index == 0){
        new_node->next = first;
        first = new_node;
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
        new_node->next = node->next;
        node->next = new_node;
    }
}

// insert element in sorted manner
void sort_insert(struct Node *node, int new_value){

    struct Node *new_node, *tail=NULL;
    new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->data = new_value;
    new_node->next = NULL;

    // Want to know if it is the first node that is being created which means first is hasn't been created yet
    if(first == NULL){
        first = new_node;
    }else{
        // node is defined and the data value of the current node is less than the new_value
        // then set the next value of the new_value is the next value of the node and set the next value of the node as the new value.
        while(node && node->data < new_value){
            tail = node;
            node = node->next;
        }
        if(node == first){
            new_node->next = first;
            first = new_node;
        }else{
            new_node->next = tail->next;
            tail->next = new_node;
        }
    }
}
int delete_node(struct Node *node, int index){
    struct Node *tail=NULL;
    int x = -1;
    int i;
    // validate index
    if(index < 1 || index > count(node)){
        cout << "Out of range index" << endl;
        return -1;
    }
    // the condition where we want to delete the first node
    if(index == 1){
        tail = first;
        x = first->data;
        first = first->next;
        delete tail;
        cout << "Deleting " << x << " from index " << index;
        return x;
    }else{
        for (i = 0; i < index - 1; i++){
            tail = node;
            node = node->next;
        }
        tail->next = node->next;
        x = node->data;
        cout << "Deleting " << x << " from index " << index;
        delete node;
        return x;
    }
}

int is_sorted(struct Node *node){
    // minimum value of 4-byte integer
    int x = -65536;
    while(node != NULL){
        if(node->data < x){
            return 0;
        }
        x = node->data;
        node = node->next;
    }
    return 1;
}

void test1(){
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
}
void test2(){
    int A[] = {10, 20, 30, 40, 50};
    int n = sizeof(A) / sizeof(A[0]);
    create(A, n);
    sort_insert(first, 35);
    sort_insert(first, 15);
    cout << "\nSorted Insert: ";
    display(first);
    cout << endl;

    delete_node(first, 2);
    cout << "\nNew node: ";
    display(first);
    cout << endl;
    if(is_sorted(first) == 1){
        cout << "Linked list is sorted" << endl;
    }else{
        cout << "Linked list is not sorted" << endl;
    }
}

void remove_duplicate(struct Node *node){
    // node is the tail pointer for temp_node
    struct Node *temp_node = node->next;
    
    while(temp_node != NULL){
        if(node->data != temp_node->data){
            node = temp_node;
            temp_node = temp_node->next;
        }else{
            node->next = temp_node->next;
            delete temp_node;
            temp_node = node->next;
        }
    }
}

void reverse(struct Node *node){
    int *A, i=0;
    struct Node *traverse_node = node;

    //create array of size of length of the linked list
    A = (int *)malloc(sizeof(int) * count(node));

    //copying elements from linked list to array
    while(traverse_node != NULL){
        A[i] = traverse_node->data;
        traverse_node = traverse_node->next;
        i++;
    }
    traverse_node = node;
    i--;

    //copying element from array to linked list
    while(traverse_node != NULL){
        traverse_node->data = A[i];
        traverse_node = traverse_node->next;
        i--;
    }
}

void advance_reverse(struct Node *node){
    struct Node *q = NULL, *r = NULL;

    while(node != NULL){
        r = q;
        q = node;
        node = node->next;
        q->next = r;
    }
    first = q;
}

void recursive_reverse(struct Node *previous_node, struct Node *current_node){
    if(current_node){
        recursive_reverse(current_node, current_node->next);
        current_node->next = previous_node;
    }else{
        first = previous_node;
    }
}

void concat(struct Node *node1, struct Node *node2){
    third = node1;
    while(node1->next != NULL){
        node1 = node1->next;
    }
    node1->next = node2;
}

void merge(struct Node *node1, struct Node *node2){
    struct Node *last;
    if(node1 -> data < node2 -> data){
        third = last = node1;
        node1 = node1->next;
        third->next = NULL;
    }else{
        third = last = node2;
        node2 = node2->next;
        third->next = NULL;
    }

    while(node1 && node2){
        if(node1->data < node2->data){
            last->next = node1;
            last = node1;
            node1 = node1->next;
            last->next = NULL;
        }else{
            last->next = node2;
            last = node2;
            node2 = node2->next;
            last->next = NULL;
        }
    }
    if(node1){
        last->next = node1;
    }
    if(node2){
        last->next = node2;
    }
}

int is_loop(struct Node *f){
    struct Node *p, *q;
    p = q = f;

    // stop the process when p is equal to q because thats when the loop has been discovered.
    // otherwise return 0 because the linked list has no loop.
    do{
        p = p->next;
        q = q->next;
        q = q ? q->next : q;
    }while(p && q && p != q);
    if(p == q){
        return 1;
    }else{
        return 0;
    }
}

void test3(){
    int A[] = {10, 10,10, 20, 20, 20, 30, 40,40,40, 50};
    int n = sizeof(A) / sizeof(A[0]);
    create(A, n);
    remove_duplicate(first);
    display(first);
}

void test4(){
    int A[] = {10, 20, 30, 40, 50};
    int n = sizeof(A) / sizeof(A[0]);
    create(A, n);
    // reverse(first);
    //advance_reverse(first);
    recursive_reverse(NULL, first);
    display(first);
}

void test5(){
    int A[] = {10, 20, 30, 40, 50};
    int B[] = {1,2,3,4,5};
    int n_A = sizeof(A) / sizeof(A[0]);
    int n_B = sizeof(B) / sizeof(B[0]);

    create(A, n_A);
    create_second(B, n_B);  
    cout << "First LinkedList: ";
    display(first);
    cout <<"\nSecond LinkedList: ";
    display(second);

    concat(second,first);
    cout << "\nConcatinated linkedlist: ";
    display(third);
}

void test6(){
    int A[] = {10,20,30,40,50};
    int B[] = {5,15,25,35,45};
    int n_A = sizeof(A) / sizeof(A[0]);
    int n_B = sizeof(B) / sizeof(B[0]);

    create(A, n_A);
    create_second(B, n_B);  
    merge(first,second);
    cout << "\nMerged linkedlist: ";
    display(third);
}

// test to check if the linked list is having a loop
void test7(){
    struct Node *temp1, *temp2;
    int A[] = {10, 20, 30, 40, 50, 60};
    int n = sizeof(A) / sizeof(A[0]);
    create(A, n);
    temp1 = first->next->next;
    temp2 = first->next->next->next->next;
    temp2->next = temp1;
    cout << "\nLinked list is a loop? " << is_loop(first) << endl;
}
int main()
{
    int choice;
    cout << "Enter test number: ";
    cin >> choice;
    
    switch(choice){
        case 1:
            test1();
            break;
        case 2:
            test2();
            break; 
        case 3:
            test3();
            break;
        case 4:
            test4();
            break;
        case 5:
            test5();
            break;
        case 6:
            test6();
            break;
        case 7:
            test7();
            break;
        default:
            test1();
    }
    return 0;
} 