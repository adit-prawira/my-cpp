
#include <iostream>
#include<stdio.h>
#include "tree.h"
using namespace std;

int main()
{
    Tree t;
    t.create();
    cout<<"Pre order: ";
    t.pre_order();
    cout<<endl;
    cout<<"In order: ";
    t.in_order();
    cout<<endl;
    cout<<"Post order: ";
    t.post_order();
    cout<<endl;
    return 0;
}