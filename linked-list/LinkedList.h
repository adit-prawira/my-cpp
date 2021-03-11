#include <iostream>
using namespace std;
#include "Node.h"
class LinkedList
{
    private:
        Node *first;
    public:
        // Non parameterized linked list.
        LinkedList(){
            first = NULL;
        }

        // parameterized linked list.
        LinkedList(int A[], int n);

        // destructor
        ~LinkedList();

        void display();
        void insert(int index, int value);
        int delete_item(int index);
        int length();
};