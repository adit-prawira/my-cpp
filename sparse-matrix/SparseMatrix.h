#include <iostream>
#include <stdio.h>
#include <string>
#include "Element.h"
using namespace std;
class SparseMatrix{
    private:
        int m;
        int n;
        int num;
        Element *elements;
    public:
        // Contructor
        SparseMatrix(int m, int n, int num){
            this->m = m;
            this->n = n;
            this->num = num;
            elements = new Element[this->num];
        }

        // Destructor
        ~SparseMatrix(){
            delete [] elements;
        }
        friend istream & operator >>(istream &is, SparseMatrix &s);
        friend ostream &operator<<(ostream &os, SparseMatrix &s);
};
istream & operator >>(istream &is, SparseMatrix &s){
    cout << "Enter non-zero elements:"<< endl;
    for (int i = 0; i< s.num; i++){
        cin >> s.elements[i].row >> s.elements[i].col >> s.elements[i].val;
    }
    return is;
};
ostream &operator<<(ostream &os, SparseMatrix &s){
    int k = 0;
    for (int i = 0; i < s.m; i++)
    {
        for (int j = 0; j < s.n; j++){
            if(s.elements[k].row == i && s.elements[k].col == j){
                cout << s.elements[k++].val << "\t";
            }else{
                cout << "0" << "\t";
            }
        }
        cout << endl;
    }
    return os;
}