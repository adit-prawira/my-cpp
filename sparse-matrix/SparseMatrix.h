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
        SparseMatrix operator+(SparseMatrix &s);
        friend istream &operator>>(istream &is, SparseMatrix &s);
        friend ostream &operator<<(ostream &os, SparseMatrix &s);
};

// cin >> matrix, where matrix is type of Sparse Matrix.
istream &operator>>(istream &is, SparseMatrix &s)
{
    cout << "Enter non-zero elements:"<< endl;
    for (int i = 0; i< s.num; i++){
        cin >> s.elements[i].row >> s.elements[i].col >> s.elements[i].val;
    }
    return is;
};
// cout << matrix, where matrix is type of Sparse Matrix.
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

SparseMatrix SparseMatrix::operator+(SparseMatrix &s){
    int i, j, k;
    if(m != s.m || n != s.n){
        return SparseMatrix(s.m, s.n, 0);
    }
    SparseMatrix *sum = new SparseMatrix(m, n, num + s.num);
    i = j = k = 0;
    while(i < num && j < s.num){
        if(elements[i].row < s.elements[j].row){
            sum->elements[k++]= elements[i++];
        }else if (elements[i].row > s.elements[j].row){
            sum->elements[k++] = elements[j++];
        }else{
            if(elements[i].col < s.elements[j].col){
                sum->elements[k++]= elements[i++];
            }else if (elements[i].col > s.elements[j].col){
                sum->elements[k++] = elements[j++];
            }else{
                sum->elements[k] = elements[i];
                sum->elements[k++].val = elements[i++].val + s.elements[j++].val;
            }
        }
    }
    // whatever value of i as long as it is less than num
    for (; i < num; i++){
        sum->elements[k++] = elements[i];
    }
    for (; j < s.num; j++){
        sum->elements[k++] = s.elements[j];
    }
    sum->num = k;
    return *sum;
}