class LowerTriangular{
    private:
        int *A;
        int n;
    public: 
        // default contructor
        LowerTriangular(){
            n = 2;
            A = new int[2*(2+1)/2];
        }
        // custom constructor
        LowerTriangular(int n ){
            this->n = n;
            A = new int[n*(n+1)];
        }
        // reset matrix
        ~LowerTriangular(){
            delete[] A;
        }

        void set(int i, int j, int new_val);
        int get(int i, int j);
        void display();
};