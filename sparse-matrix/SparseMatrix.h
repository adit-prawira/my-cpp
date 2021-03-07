#include "Element.h"

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

        void read();
        void display();
};
