#include <iostream>

void fun(int n){
    if(n > 0){
        printf("%d ", n );
        fun(n-1);
        fun(n-1);
    }
}
int main() {
    std::cout << "Your Tree Recursion:" << std::endl;
    fun(3);
    printf("\n");
    return 0;
}

