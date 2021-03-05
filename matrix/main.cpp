#include <iostream>
#include "Diagonal.h"
#include "LowerTriangular.h"

using namespace std;

// Diagonal Matrix computation
void Diagonal::set(int i, int j, int new_val){
    if(i ==j ){
        A[i - 1] = new_val;
    }
}
int Diagonal::get(int i , int j ){
    return (i == j) ? A[i - 1] : 0;
}
void Diagonal::display(){
    int i, j;
    for (i = 0; i < n; i++){
        for (j = 0; j<n; j++){
            if(i == j){
                cout << A[i] <<"\t";
            }else{
                cout << "0\t";
            }
        }
        cout << endl;
    }
    cout << endl;
}

// LowerTriangular Matrix computation
void LowerTriangular::set(int i, int j, int new_val){
    if(i >=j ){
        A[n*(j-1)-(j-2)*(j-1)/2+i-j] = new_val;
    }
}
int LowerTriangular::get(int i , int j ){
    return (i >= j) ? A[n*(j-1)-(j-2)*(j-1)/2+i-j] : 0;
}
void LowerTriangular::display(){
    int i, j;
    for (i = 1; i <= n; i++){
        for (j = 1; j<= n; j++){
            if(i >= j){
                cout << A[n*(j-1)-(j-2)*(j-1)/2+i-j] <<"\t";
            }else{
                cout << "0\t";
            }
        }
        cout << endl;
    }
    cout << endl;
}

int main() {
    int n_dimension, option, i, j, val;
    cout << "Enter desired dimension: ";
    cin >> n_dimension;
    Diagonal diagonal_matrix(n_dimension);
    LowerTriangular lt_matrix(n_dimension);
    cout << "Choose a number to compute matrix operation:"<<endl;
    cout << "1 - to compute Diagonal Matrix" << endl;
    cout << "2 - to comput Triangular Matrix" << endl;
    cin >> option;

    switch (option){
        case 1:
            cout << "Diagonal Matrix:" << endl;
            cout << "Enter All Elements:"<<endl;
            for (i = 1; i<= n_dimension; i++){
                for (j = 1; j <= n_dimension; j++){
                    cin >> val;
                    diagonal_matrix.set(i, j, val);
                }
            }
            cout << "Output:" << endl;
            diagonal_matrix.display();
            break;
        case 2:
            cout << "Lower Triangular Matrix:" << endl;
            
            for (i = 1; i<= n_dimension; i++){
                for (j = 1; j <= n_dimension; j++){
                    cin >> val;
                    lt_matrix.set(i, j, val);
                }
            }
            cout << "Output:" << endl;
            lt_matrix.display();
            break;
            
    }   
}