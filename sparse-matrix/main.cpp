#include <iostream>
#include "SparseMatrix.h"
using namespace std;

int main(){
    SparseMatrix matrix1(5, 5, 5);
    cin >> matrix1;
    cout << matrix1;
    return 0;
}