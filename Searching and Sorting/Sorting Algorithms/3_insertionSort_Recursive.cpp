/* ✔️⭐Approach - 2 (Recursive) :-  Insertion Sort 

    explanation :- step 1 : base case : when i equals n i.e the arrays last element is already processed, then array is sorted
                   step 2 : lets solve single case i.e lets place ith element at its right positio
                   step 3 : create a tempVar having value of elemnt at the ith index
                   step 4 : run a loop from i-1 to 0th index in reverse order, and whenever find an element which is greater than 'tempVar' then perform "arr[j+1] = arr[j]", else break the loop 
                   step 5 : whenever loop breaks, simply perform "arr[j+1] = tempVar".
                   step 6 : rest elements recursion will place at their correct position, and sort the array 
                
                  //Array Sorted

    T : O(N^2)  
    S : O(N) - recursive call stack 

*/

#include<iostream>
using namespace std;


// -- function to print the array at any given instance 
void printArray(int *arr, int size){

    for(int i = 0; i < size; i++) cout << arr[i] << ' ';
    cout << endl;

}


// -- selection sort recursive function
void recInsertionSort(int *arr, int size, int i){

    // step 1 : base case : when i equals n i.e the arrays last element is already processed, then array is sorted
    if(i == size) return;

    // step 2 : lets solve single case i.e lets place ith element at its right position

    // step 3 : create a tempVar having value of elemnt at the ith index
    int tempVar = arr[i];

    // step 4 : run a loop from i-1 to 0th index in reverse order, and whenever find an element which is greater than 'tempVar' then perform "arr[j+1] = arr[j]", else break the loop 
    int j = i - 1;
    for( ; j >= 0; j--){
        if(tempVar < arr[j]) arr[j+1] = arr[j];
        else break;
    }

    // step 5 : whenever loop breaks, simply perform "arr[j+1] = tempVar".
    arr[j+1] = tempVar;

    // step 6 : rest elements recursion will place at their correct position, and sort the array 
    recInsertionSort(arr, size, ++i);

}

// -- MAIN Function
int main(){

    cout << "- - - - - - - - - - - - - - - - - - -" << endl;

    int arr[] = {10, 21, 17, -5, 3, 2, 11};  // testCase - 1 ☑️
    //int arr[] = {1, 7, -9, -10, 20};  // testCase - 2 ☑️
    //int arr[] = {10, 11, 12, 13, 14};  // testCase - 3 ☑️

    int size = sizeof(arr)/sizeof(int);

    cout << "Input Array : ";
    printArray(arr, size);

    int i = 1;
    recInsertionSort(arr, size, i);

    cout << "Output Array : ";
    printArray(arr, size);

    cout << "- - - - - - - - - - - - - - - - - - -" << endl;

}


// ☑️solved at gfg(both iteratively & recursively) : https://practice.geeksforgeeks.org/problems/insertion-sort/1
