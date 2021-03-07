#include <iostream>
#include "Polynomial.h"
#include "Term.h"
using namespace std;

void Polynomial::create(Polynomial *p){

    cout << "Number of terms";
    cin >> p->n;

    p->terms = new Term[p->n];
}

int main(){

}                                           