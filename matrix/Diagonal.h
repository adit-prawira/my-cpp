class Diagonal{
    private:
        int *A;
        int n;
    public: 
        // default contructor
        Diagonal(){
            n = 2;
            A = new int[2];
        }
        // custom constructor
        Diagonal(int n ){
            this->n = n;
            A = new int[n];
        }
        // reset matrix
        ~Diagonal(){
            delete[] A;
        }

        void set(int i, int j, int new_val);
        int get(int i, int j);
        void display();
};