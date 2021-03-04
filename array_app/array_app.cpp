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
    printf("\nElements are: ");
    for (i = 0; i< arr.length; i++){
        printf("%d ", arr.A[i]);
    };
    cout << endl;
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
        cout << "\nSet value of " << newVal << " to index " << index << endl;
    }else{
        cout << "\nIndex is out of range";
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

void CopyReverse(struct Array *arr){
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

    cout << "\nArray is copied and reversed" << endl;
};

void SwapReverse(struct Array *arr){
    int i, j;
    // j start at the end, and i start at the start.
    // for loop will stop when i == j;
    for (i = 0, j = arr->length-1; i < j; i++, j--)
    {
        swap(&arr->A[i], &arr->A[j]);
    }
    cout << "\nArray is reversed by swapping" << endl;
};

// Insert Element in sorted order
void InsertSort(struct Array *arr, int newVal){
    int i = arr->length-1;
    if (arr->length == arr->size)
    {
        // return early because there are no space left
        return;
    }
    while(i >= 0 && arr->A[i] > newVal){
        // as long as element in A is larger than the new value then shift those element to the right
        // and if index reaches 0, the loop will be terminated
        arr->A[i + 1] = arr->A[i];
        i--;
    }
    // i will be any of the last value of i when loop being ended
    arr->A[i + 1] = newVal;
    arr->length++;
    cout << "\nInsert value of " << newVal << " at index " << i+1;
};

int isSorted(struct Array arr){
    int i;
    for (i = 0; i < arr.length - 1; i++){
        if(arr.A[i] > arr.A[i+1]){
            return 0;
        }
    }
    return 1;
}

int partition(int a[], int low, int high){
    int i, j, pivot;
    pivot = a[high];
    i = (low - 1);
    for(j = low; j< high; j++){
        if(a[j] <= pivot){
            i++;
            swap(&a[i], &a[j]);
        }
    }
    swap(&a[i+1], &a[high]);
    return (i + 1);

};
void QuickSort(struct Array *arr, int low, int high)
{
    if(low < high){
        int pi = partition(arr->A, low, high);
        QuickSort(arr, low, pi -1);
        QuickSort(arr, pi+1, high);
    }
};

// Merge 2 array in sorted manner
struct Array* Merge(struct Array *arr1, struct Array *arr2){
    int i, j, k;
    i = j = k = 0;
    // Create arr3 from Heap
    struct Array *arr3 = (struct Array *)malloc(sizeof(struct Array));
    // compare values of arr1[i] and arr2[j] if the value if arr1[i] < arr2[j]
    // then in arr3[k], value of arr1[i] comes first before arr2[j] 
    while(i < arr1 -> length && j < arr2 -> length){
        if(arr1->A[i] < arr2->A[j]){
            arr3->A[k++] = arr1->A[i++];
        }else{
            arr3->A[k++] = arr2->A[j++];
        }
    }
    for(; i<arr1->length; i++){
        arr3->A[k++] = arr1->A[i];
    }
    for(; j<arr2->length; j++){
        arr3->A[k++] = arr2->A[j];
    }
    arr3->length = (arr1->length) + (arr2->length);
    arr3->size = 10;
    return arr3;
};
void test1()
{
    // array  in this case is arrs
    // size = 10
    // length 5 which is the current length and there are 5 spaces left to reach maximum elemnts which is 10
    struct Array arr = {{2, 3, 4, 5, 6}, 10, 5};
    struct Array arr2 = {{2, 3, 5, 6}, 10, 4};
    struct Array arr3 = {{2, -3, 25, 10, -15, -7}, 10, 6};
    int index = 5;
    Append(&arr, 10);   // 2 3 4 5 6 10
    Insert(&arr, 3, 7); // 2 3 4 7 5 6 10
    // printf("Element of %d is being deleted from Array\n", Delete(&arr, 2)); // Current array 2 3 7 5 6 10
    // printf("\nLinear Search: Item found at index %d in array\n", LinearSearch(arr, 6));
    // printf("\nAdvanced Linear Search: Item found at index %d in array\n", AdvancedLinearSearch(&arr, 6)); // Current array 2 3 7 6 5 10 
    // printf("\nBinary Search: Item found at index %d in array\n", BinarySearch(arr, 6)); 
    // printf("\nRecursive Binary Search: Item found at index %d in array\n", RecursiveBinarySearch(arr.A, 0, arr.length, 6));
    Display(arr);
    cout << "\nGet value at " << index << Get(arr, index);
    cout << "\nMaximum value: " << Max(arr);
    cout << "\nMinimum value: " << Min(arr);
    cout << "\nSum: " << Sum(arr);
    cout << "\nAverage: " << Average(arr);
    Set(&arr, index, 9);
    Display(arr);
    cout << "\nAverage: " << Average(arr);
    CopyReverse(&arr);
    Display(arr);
    SwapReverse(&arr);
    Display(arr);
    InsertSort(&arr2, 1);
    InsertSort(&arr2, 10);
    InsertSort(&arr2, 8);
    InsertSort(&arr2, 9);
    InsertSort(&arr2, 4);
    InsertSort(&arr2, 7);
    Display(arr2);
    cout << "\nArray 1 is sorted: " << isSorted(arr);
    cout << "\nArray 2 is sorted: " << isSorted(arr2);
    QuickSort(&arr3, 0, arr3.length-1);
    Display(arr3);
}

void test2(){
    struct Array arr1 = {{2, 6, 10, 5, 25}, 10, 5};
    struct Array arr2 = {{3, 4, 7, 18, 20}, 10, 5};
    struct Array *arr3;
    arr3 = Merge(&arr1, &arr2);
    Display(*arr3);
}

int main()
{
    //test1();
    test2();
    return 0;
};