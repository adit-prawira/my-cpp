#include <iostream>

struct Array{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr){
    int i;
    printf("\nElements are\n");
    for (i = 0; i< arr.length; i++){
        printf("%d ", arr.A[i]);
    };
    printf("\n");
};

void Append(struct Array *arr, int x){
    if(arr->length < arr->size){
        // A[5] = x, update A[] in Array
        arr->A[arr->length++] = x;
    };
};

// Insert will insert new value at the specific index location.
// make sure index is valid which is within the max length of the array
void Insert(struct Array *arr, int index, int x){
    int i;
    if (index >= 0 && index <= arr->length)
    {
        // Loop to insert new elements in the specified index and then shift the other elements to the
        // index allocation.
        for (i = arr->length; i > index; i--){
            arr->A[i] = arr->A[i - 1];
        };
        arr->A[index] = x;
        arr->length++;
    }else{
        printf("Element x = %d at index %d is being added due to out of range index", x, index);
    };
};

int main()
{
    // array  in this case is arr
    // size = 10
    // length 5 which is the current length and there are 5 spaces left to reach maximum elemnts which is 10
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};
    Append(&arr, 10); // 2 3 4 5 6 10
    Insert(&arr, 9, 7); // 2 3 4 7 5 6 10
    Display(arr);
    return 0;
};