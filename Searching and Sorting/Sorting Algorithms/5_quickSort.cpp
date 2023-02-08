/* ✔️⭐(Approach 1 - Recursive) - QUICK SORT 

    explanation :-   Quick Sort Function 

                    step 1 : base case - when there is single elemnt left than array is already sorted
               |--- step 2 : find the pivot index using function 'pivotIndexFinder'
               |    step 3 : now do recursive call for left part of array
               |    step 4 : do recursive call for right part of the array
               |
               |-->   PIVOT INDEX Finder

                   step 1 : take starting index as the pivot of the array 
                   step 2 : count number of elements smaller or equal to the pivot element
                   step 3 : swap the pivotElement and (pivotElement + count)th element.
                   step 4 : declare 2 variables i = start and j = end, and run a loop untill i becomes equal to pivotIndex or j becomes equal to pivotIndex.
                        step 5 : run a loop untill ith element is equal or smaller than the pivotIndex element
                        step 6 : run a loop untill jth element is greater than the pivotIndex element
                        step 7 : swap the ith and jth element if index i is smaller than the pivotIndex and index j is greater than the pivot index.
                   step 8 : return pivot Index.


    T :  O(n^2) - worst case, O(n*log(n)) - best case
        
        - best case is normal unsorted array.  (10, 9, -1, 5, -4, 8)
        - worst case is when array is already sorted.  (1, 2, 3, 4, 5)
       
    S :  O(n) - recursive call stack in worst case and o(log(n)) in normal case
    
*/

#include <iostream>
using namespace std;

// -- function to print the array at any instance
void printArray(int *arr, int size){
    for(int i = 0; i < size; i++) cout << arr[i] << ' ';
    cout << endl;
}

// -- pivotIndexFinder Function -> this fuction will return the pivot element
int pivotIndexFinder(int *arr, int start, int end){

    // step 1 : take starting index as the pivot of the array 
    int pivotIndex = start;

    // step 2 : count number of elements smaller or equal to the pivot element
    int count = 0;
    for(int i = start+1; i < end +1; i++){
        if(arr[i] <= arr[pivotIndex]) count++;
    }

    // step 3 : swap the pivotElement and (pivotElement + count)th element.
    swap(arr[pivotIndex], arr[pivotIndex + count]);
    pivotIndex = start + count;

    // step 4 : declare 2 variables i = start and j = end, and run a loop untill i becomes equal to pivotIndex or j becomes equal to pivotIndex.
    int i = start, j = end;
    while(i < pivotIndex && j > pivotIndex){

        // step 5 : run a loop untill ith element is equal or smaller than the pivotIndex element
        while(arr[i] <= arr[pivotIndex]) i++;
        // step 6 : run a loop untill jth element is greater than the pivotIndex element
        while(arr[j] > arr[pivotIndex]) j--;

        // step 7 : swap the ith and jth element if index i is smaller than the pivotIndex and index j is greater than the pivot index.
        if(i < pivotIndex && j > pivotIndex) swap(arr[i++], arr[j--]);

    }

    // step 8 : return pivot Index.
    return pivotIndex;

}

// -- quick Sort function 
void quickSort(int *arr, int start, int end){

    // step 1 : base case - when there is single elemnt left than array is already sorted
    if(start >= end) return;

    
    // step 2 : find the pivot index using function 'pivotIndexFinder'
    int pivotIndex = pivotIndexFinder(arr, start, end);

    // step 3 : now do recursive call for left part of array
    quickSort(arr, start, pivotIndex-1);

    // step 4 : do recursive call for right part of the array
    quickSort(arr, pivotIndex+1, end);

}

int main(){

    cout << "- - - - - - - - - - - - - - - - - - - - -" << endl;
    
    //int arr[] = {10, 12, -3, -5, 6, -1};  // test case 1 ☑️
    //int arr[] = {1, 2, 3, -3, -2, -1};  // test case 2 ☑️
    int arr[] = {1, 2, 3, 4, 5, 6, 7, -2, -3, 4, 10, 4};  // test case 3 ☑️

    int size = sizeof(arr)/sizeof(int);

    cout << "Input Array : ";
    printArray(arr, size);

    int start = 0, end = size - 1;
    quickSort(arr, start, end);

    cout << "Output Array : ";
    printArray(arr, size);


    cout << "- - - - - - - - - - - - - - - - - - - - -" << endl;

}

