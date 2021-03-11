#include <iostream>
#include "LinkedList.h"
using namespace std;

LinkedList::LinkedList(int A[], int n){
    Node *last, *temp;
    int i = 0;

    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;

    for (i = 1; i < n; i++){
        temp = new Node;
        temp -> data = A[i];
        temp -> next = NULL;
        last->next = temp;
        last = temp;
    }
}

LinkedList::~LinkedList(){
    Node *node_iterator = first;
    while(first){
        first = first->next;
        delete node_iterator;
        node_iterator = first;
    }
}

void LinkedList::display(){
    Node *iterator = first;

    while(iterator){
        cout << iterator->data << " ";
        iterator = iterator->next;
    }
    cout << endl;
}

int LinkedList::length(){
    int count = 0;
    Node *iterator = first;
    while(iterator){
        count++;
        iterator = iterator->next;
    }
    return count;
}

void LinkedList::insert(int index, int val){
    Node *temp, *iterator = first;
    if(index < 0 || index > length()){
        return;
    }

    temp = new Node;
    temp->data = val;
    temp->next = NULL;

    if(index == 0){
        first = temp;
    }else{
        for (int i = 0; i < index - 1; i++){
            iterator = iterator->next;
        }
        temp->next = iterator->next;
        iterator->next = temp;
    }
}

int LinkedList::delete_item(int index){
    Node *dummy, *iterator= NULL;
    int x = -1;

    if(index < 1 || index > length()){
        return -1;
    }
    if(index == 1){
        dummy = first;
        first = first->next;
        x = dummy->data;
        delete dummy;
    }else{
        dummy = first;
        for (int i = 0; i < index - 1; i++){
            iterator = dummy;
            dummy = dummy->next;
        }
        iterator->next = dummy->next;
        x = dummy->data;
        delete dummy;
    }
    return x;
}

int main(){
    int A[] = {1, 2, 3, 4, 5};
    LinkedList linkedlist(A, 5);
    linkedlist.insert(3, 7);
    linkedlist.delete_item(2);
    linkedlist.display();
    return 0;
}