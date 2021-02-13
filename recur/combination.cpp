#include <iostream>

int factorial(int n ){
    if(n == 0){
        return 1;
    }else{
        return factorial(n-1)*n;
    }
}
int combination(int n, int r){
    int numerator, denominator;
    numerator = factorial(n);
    denominator = factorial(n-r)*factorial(r);
    return numerator/denominator;
}

int rec_combination(int n, int r){
    if(n == r || r == 0){
        return 1;
    }else{
        return rec_combination(n-1, r-1) + rec_combination(n-1, r);
    }
}

int main() {
    std::cout << "Your Combination nCr" << std::endl;
    printf("Combination calling factorial program: %d\n", combination(4, 2));
    printf("Recursive Combination: %d\n", rec_combination(4, 2));
    return 0;
}

