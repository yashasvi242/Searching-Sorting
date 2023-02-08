/* 
✔️⭐ SELECTION SORT [Approach 2 - Recurssive]
    
        explanation : step 1 : base case - if array has size 1 or 0, then its already sorted
                      step 2 : solving 1 case i.e filling the 0th index with the deserving element using swap()
                      step 3 : since we solved a case, rest recursion will sort, recurssive call -> selectionSort(++arr, size-1);

        T : O(n^2) 
        S : O(N) - recurssive call stack 
    
*/

#include<iostream>
using namespace std;

// -- this function will print the array at any instance
void printArray(int *arr, int size){

    for(int i = 0; i < size; i++) cout << arr[i] << ' ';
    cout << endl;

}

void selectionSort(int *arr, int size){

    // step 1 : base case - if array has size 1 or 0, then its already sorted
    if(size == 0 || size == 1) return;

    // step 2 : solving 1 case i.e filling the 0th index with the deserving element
    int minIndex = 0;
    for(int j = 1; j <= size-1; j++){
        if(arr[j] < arr[minIndex]) minIndex = j;
    } 

    swap(arr[0], arr[minIndex]);

    // step 3 : since we solved a case, rest recursion will sort
    selectionSort(++arr, size-1);

}

int main(){

    cout << "- - - - - - - - - - - - - - - - - - - " << endl;

    /* TEST CASES */

    //int arr[] = {10, 21, 17, -5, 3, 2, 11}; // test case 1 ☑️
	//int arr[] = {6, 2, 8 ,4 ,10};           // test case 2 ☑️
	int arr[] = {18, -1, -3, -10, 100, 81, 95, 28}; // test case 3 ☑️  

    int size = sizeof(arr)/sizeof(int);

    cout << "Input Array : ";
    printArray(arr, size);

    // sorting the array
    selectionSort(arr, size);

    cout << "Output Array : ";
    printArray(arr, size);

    cout << "- - - - - - - - - - - - - - - - - - - " << endl;



}

    