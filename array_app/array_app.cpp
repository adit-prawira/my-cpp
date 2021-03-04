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
        // correct index allocation by 1 index to the right.
        for (i = arr->length; i > index; i--){
            arr->A[i] = arr->A[i - 1];
        };
        arr->A[index] = x;
        arr->length++;
    }else{
        printf("Element x = %d at index %d is being added due to out of range index", x, index);
    };
};

// Deleted element at the specified index
int Delete(struct Array *arr, int index)
{
    int x = 0;
    int i;
    if (index >= 0 && index < arr->length)
    {
        x = arr->A[index];
        // Loop to shift all non targeted elements in array to the correct index allocation by 1 index to the left.
        for (i = index; i < arr->length - 1; i++){
            arr->A[i] = arr->A[i + 1];
        }
        arr->length--;
        // return value that being deleted at the specified index early when it has been found.
        return x;
    };
    return 0;
};
// Linear Search: the function will take a value and return index value when the element that being given is contained in the Array
// Don't need arr as an address because we don't modify any of its data.
int LinearSearch(struct Array arr, int key){
    int i;
    for(i = 0; i< arr.length; i++){
        if(key == arr.A[i]){
            printf("%d is found at index %d", key, i);
            return i;
        }
    }
    printf("%d is not found\n", key);
    return -1;
};

// Linear Search with transposition
// In this case arr need to be an address because we need to modify data in Array.
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
};
int AdvancedLinearSearch(struct Array *arr, int key){
    int i;
    for(i = 0; i< arr->length; i++){
        if(key == arr->A[i]){
            // Example: 2 3 7 5 6 10, want to find 6
            // 6 is found and swap is value will its preceding value which is 5
            // Then, 2 3 7 6 5 10
            swap(&arr->A[i], &arr->A[i - 1]);
            printf("%d is found at index %d", key, i);
            return i;
        }
    }
    printf("%d is not found\n", key);
    return -1;
};
int main()
{
    // array  in this case is arr
    // size = 10
    // length 5 which is the current length and there are 5 spaces left to reach maximum elemnts which is 10
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};
    Append(&arr, 10); // 2 3 4 5 6 10
    Insert(&arr, 3, 7); // 2 3 4 7 5 6 10
    printf("Element of %d is being deleted from Array\n", Delete(&arr, 2)); // Current array 2 3 7 5 6 10
    printf("\nLinear Search: Element of %d in array\n", LinearSearch(arr, 6));
    printf("\nAdvanced Linear Search: Element of %d in array\n", AdvancedLinearSearch(&arr, 6)); // Current array 2 3 7 6 5 10 
    Display(arr);
    return 0;
};