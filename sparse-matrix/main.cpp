#include <iostream>
#include "SparseMatrix.h"
using namespace std;

void SparseMatrix::read(){
    cout << "Enter non-zero elements:"<< endl;
    for (int i = 0; i< num; i++){
        cin >> elements[i].row >> elements[i].col >> elements[i].val;
    }
}

void SparseMatrix::display(){
    int k = 0;
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++){
            if(elements[k].row == i && elements[k].col == j){
                cout << elements[k++].val << "\t";
            }else{
                cout << "0" << "\t";
            }
        }
        cout << endl;
    }
}

int main(){
    SparseMatrix matrix1(5, 5, 5);
    matrix1.read();
    matrix1.display();
    return 0;
}