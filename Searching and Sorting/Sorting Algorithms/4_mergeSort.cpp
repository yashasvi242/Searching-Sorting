/* ✔️⭐Approach - 1(Recursive) : Merge Sort 

    explanation :-  DIVIDE Function 
    
                    step 1 : base case - if start becomes equal to end i.e when array size is 1 then its already sorted, just return the function 
                    step 2 : find the mid element for the given start and end at an instance
                    step 3 : sort the left part of the array
                    step 4 : sort the right part of the array
                <-- step 5 : now since both the parts are sorted, just merge the 2 arrays
                |   //array sorted.
                |   
                |
                --> CONQUER Function
                
                   step 1 : create an array 'left' of length1 (mid-start+1)
                   step 2 : create an arary 'right' of length2 (end - mid)
                   step 3 : now push the first half elements of original array into array 'left'.
                   step 4 : now push the second half elements of original array into array 'right'.
                   step 5 : now using 2 pointer variables approach, push the 2 sorted arrays(left & right) into original array 
                   step 6 : when either one of left or right sorted array's all elements are pushed and others are still left then push all elements of non empty array into original array.
                   // now the 2 sorted arrays are merged.


    T : O( n*log(n) ) - best & worst case
    S : O(N) - recursive call stack

*/

#include<iostream>
using namespace std;

void printArray(int *arr, int size){
    for(int i=0; i<size; i++) cout << arr[i] << ' ';
    cout << endl;
}

// -- function to merge the 2 sorted arrays.
void merge(int *arr, int start, int mid, int end){

    // step 1 : create an array 'left' of length1 (mid-start+1)
    int length1 = mid - start + 1;
    int *left = new int[length1];

    // step 2 : create an arary 'right' of length2 (end - mid)
    int length2 = end - mid;
    int *right = new int[length2];

    // step 3 : now push the first half elements of original array into array 'left'.
    int originalIndex = start; // to not loose the indexes of original array 
    for(int i = 0; i < length1; i++) left[i] = arr[originalIndex++];

    // step 4 : now push the second half elements of original array into array 'right'. 
    for(int i = 0; i < length2; i++) right[i] = arr[originalIndex++];

    // step 5 : now using 2 pointer variables approach, push the 2 sorted arrays(left & right) into original array 
    int i = 0, j = 0;
    originalIndex = start;
    while(i < length1 && j < length2){
        if(left[i] < right[j]) arr[originalIndex++] = left[i++];
        else arr[originalIndex++] = right[j++];
    }

    // step 6 : when either one of left or right sorted array's all elements are pushed and others are still left then push all elements of non empty array into original array
    while(i < length1) arr[originalIndex++] = left[i++];
    while(j < length2) arr[originalIndex++] = right[j++];

    // now the 2 sorted arrays are merged.
}

// -- this function will divide the array into parts untill a single element is left
void divide(int *arr, int start, int end){

    // step 1 : base case - if start becomes equal to end i.e when array size is 1 then its already sorted, just return the function 
    if(start >= end) return;

    // step 2 : find the mid element for the given start and end at an instance
    int mid = start + (end - start)/2;

    // step 3 : sort the left part of the array
    divide(arr, start, mid);
    // step 4 : sort the right part of the array
    divide(arr, mid + 1, end);

    // step 5 : now since both the parts are sorted, just merge the 2 arrays
    merge(arr, start, mid, end);

    // array sorted.
}

int main(){

    cout << "- - - - - - - - - - - - - - - - - - - - - - -" << endl;

    // int arr[] = {10, -1, -5, 6, 12, 3}; // TestCase 1 ☑️
    // int arr[] = {1, 2, 3, -1, 4, 5, 8, -5}; // TestCase 2 ☑️
    int arr[] = {1, 2, 3, 4, -4, -3, -2, -1}; // TestCase 3 ☑️
    //int arr[] = {1, 2, 3, 4};  // TestCase 4 ☑️
    int size = sizeof(arr)/sizeof(int);

    int start = 0, end = size - 1;

    cout <<"Input Array : ";
    printArray(arr,size);

    // calling the mergeSort function divide
    divide(arr, start, end);

    cout <<"Output Array : ";
    printArray(arr,size);

    cout << "- - - - - - - - - - - - - - - - - - - - - - -" << endl;
}