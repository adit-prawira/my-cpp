//
// Created by Aditya Prawira on 13/2/21.
//

#include <iostream>

void tower_of_hanoi(int n, int A, int B, int C){
    if(n > 0){
        tower_of_hanoi(n-1, A, C, B);
        printf("(%d, %d)\n", A, C);
        tower_of_hanoi(n-1, B, A, C);
    }
}
int main(){
    std::cout<<"Your Tower of Hanoi:"<< std::endl;
    tower_of_hanoi(2, 1, 2, 3);
    return 0;
}