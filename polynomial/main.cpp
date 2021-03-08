#include <iostream>
using namespace std;

struct Term{
    int coefficient;
    int exponent;
};

struct Polynomial{
    int n;
    struct Term *terms;
};


void create(struct Polynomial *p){
    int i;
    cout << "Number of terms: ";
    cin >> p->n;

    // creating array from heap
    p->terms = (struct Term*)malloc(p->n * sizeof(struct Term));

    cout << "Enter number of terms: " << endl;
    for (i = 0; i < p->n; i++){
        cin >> p->terms[i].coefficient >> p->terms[i].exponent;
    }
};

void display(struct Polynomial p){
    int i;
    for (i = 0; i < p.n; i++){
        if(i == p.n -1){
            cout << p.terms[i].coefficient << "x^" <<p.terms[i].exponent << endl;
        }else{
            cout << p.terms[i].coefficient << "x^" <<p.terms[i].exponent << " + ";
        }
    }
}

int main()
{
    struct Polynomial polynomial;
    create(&polynomial);
    display(polynomial);
}