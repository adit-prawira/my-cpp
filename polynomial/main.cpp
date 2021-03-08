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

struct Polynomial *add(struct Polynomial *p1, struct Polynomial *p2){
    int i,j,k;
    struct Polynomial *sum_polynomial;
    sum_polynomial = (struct Polynomial *)malloc(sizeof(struct Polynomial));
    sum_polynomial->terms = (struct Term*)malloc((p1->n + p2->n)*sizeof(struct Term));
    i = j = k = 0;

    while(i < p1->n && j < p2->n){
        if(p1->terms[i].exponent >  p2->terms[j].exponent){
            sum_polynomial->terms[k++] = p1->terms[i++];
        }else if(p1->terms[i].exponent < p2->terms[j].exponent){
            sum_polynomial->terms[k++] = p2->terms[j++];
        }else{
            // add coefficient when exponent of both polynomial term are equal
            sum_polynomial->terms[k].exponent = p1->terms[i].exponent;
            sum_polynomial->terms[k++].coefficient = p1->terms[i++].coefficient + p2->terms[j++].coefficient;
        }
    }

    // copy the rest of the polynomials
    for (; i < p1->n;i++){
        sum_polynomial->terms[k++] = p1->terms[i];
    }
    for (; j < p2->n; j++){
        sum_polynomial->terms[k++] = p2->terms[j];
    }
    sum_polynomial->n = k;
    return sum_polynomial;
}

int main()
{
    struct Polynomial polynomial1, polynomial2, *total_polynomial;
    create(&polynomial1);
    create(&polynomial2);
    total_polynomial = add(&polynomial1, &polynomial2);
    cout << "First Polynomial:" << endl;
    display(polynomial1);
    cout << "Second Polynomial:" << endl;
    display(polynomial2);
    cout << "Total Polynomial:" << endl;
    display(*total_polynomial);
}