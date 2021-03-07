#include <iostream>
#include "SparseMatrix.h"
using namespace std;

int main(){
    SparseMatrix matrix1(5, 5, 5);
    SparseMatrix matrix2(5, 5, 5);
    cin >> matrix1;
    cin >> matrix2;
    SparseMatrix sum = matrix1 + matrix2;
    cout << "First Matrix" << endl << matrix1;
    cout << "Second Matrix" << endl << matrix2;
    cout << "Sum Matrix" << endl << sum;
    return 0;
}