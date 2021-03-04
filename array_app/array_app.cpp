#include <iostream>
#include <math.h>
#include <cstdlib>
using namespace std;
struct Array
{
    int A[10];
    int size;
    int length;
};

void Display(struct Array arr){
    int i;
    printf("Elements are: ");
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
            printf("\n%d is found at index %d", key, i);
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
            printf("\n%d is found at index %d", key, i);
            return i;
        }
    }
    printf("%d is not found\n", key);
    return -1;
};

// Binary Search
int BinarySearch(struct Array arr, int key){
    int low, mid, high;
    low = 0;
    high = arr.length - 1;
    while (low <= high)
    {
        mid = floor((low + high) / 2);
        if(key == arr.A[mid]){
            printf("\n%d is found at index %d", key, mid);
            return mid;
        }else if (key < arr.A[mid]){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    };
    printf("%d is not found", key);
    return -1;
};

// Recursive Binary Search
int RecursiveBinarySearch(int a[], int low, int high, int key){
    int mid;
    if(low <= mid){
        mid = floor((low + high) / 2);
        if(key == a[mid]){
            printf("\n%d is found at index %d", key, mid);
            return mid;
        }else if (key < a[mid]){
            return RecursiveBinarySearch(a, mid + 1, high, key);
        }
        else
        {
            return RecursiveBinarySearch(a, low, mid - 1, key);
        }
    }
    return -1;
};

// return value at the specified index
int Get(struct Array arr, int index){ 
    if(index >= 0 && index < arr.length){
        return arr.A[index];
    };
    return -1;
};

// set/change value at the specified index new value
void Set(struct Array *arr, int index, int newVal){
    if(index >=0 && index < arr->length){
        arr->A[index] = newVal;
        printf("Set value of %d to index %d\n", newVal, index);
    }else{
        printf("Index is out of range");
    };
}

// Function that will return maximum and minimum value of an array.
int Max(struct Array arr){
    int max = arr.A[0];
    int i;
    for (i = 0; i < arr.length; i++){
        if(arr.A[i] > max){
            max = arr.A[i];
        }
    };
    return max;
};
int Min(struct Array arr){
    int min = arr.A[0];
    int i;
    for (i = 0; i < arr.length; i++){
        if(arr.A[i] < min){
            min = arr.A[i];
        }
    };
    return min;
};

int Sum(struct Array arr){
    int sum = 0;
    int i;
    for (i = 0; i< arr.length; i++){
        sum += arr.A[i];
    }
    return sum;
};

float Average(struct Array arr){
    return (float) Sum(arr)/arr.length;
}

void Reverse(struct Array *arr){
    int *B; 
    int i,j;

    // Size of array B must be the same as Array A
    // Created array B from B.
    B = (int *)malloc(arr->length*sizeof(int));
    for (i = arr->length - 1, j = 0; i >= 0; i--, j++){
        B[j] = arr->A[i];
    };
    for(i = 0; i < arr -> length; i++){
        arr->A[i] = B[i];
    }

    cout << "\nArray is reversed" << endl;
};

int main()
{
    // array  in this case is arr
    // size = 10
    // length 5 which is the current length and there are 5 spaces left to reach maximum elemnts which is 10
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};
    int index = 5;
    Append(&arr, 10);   // 2 3 4 5 6 10
    Insert(&arr, 3, 7); // 2 3 4 7 5 6 10
    // printf("Element of %d is being deleted from Array\n", Delete(&arr, 2)); // Current array 2 3 7 5 6 10
    // printf("\nLinear Search: Item found at index %d in array\n", LinearSearch(arr, 6));
    // printf("\nAdvanced Linear Search: Item found at index %d in array\n", AdvancedLinearSearch(&arr, 6)); // Current array 2 3 7 6 5 10 
    // printf("\nBinary Search: Item found at index %d in array\n", BinarySearch(arr, 6)); 
    // printf("\nRecursive Binary Search: Item found at index %d in array\n", RecursiveBinarySearch(arr.A, 0, arr.length, 6));
    Display(arr);
    cout << "Get value at " << index << Get(arr, index) << endl;
    cout << "Maximum value: " << Max(arr);
    cout << "Minimum value: " << Min(arr);
    cout << "Sum: " << Sum(arr);
    cout << "Average: " << Average(arr);
    Set(&arr, index, 9);
    Display(arr);
    cout << "Average: " << Average(arr);
    Reverse(&arr);
    Display(arr);
    return 0;
};