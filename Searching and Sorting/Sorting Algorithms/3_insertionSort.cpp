/* ✔️⭐Approach - 1 (iterative) :-  Insertion Sort 

    explanation :- step 1 : run an i loop from (1 to n-1)th element
                       
                       step 2 : store the ith index element in a variable "tempVar"
                       step 3 : run a j loop from (i-1 to 0)th index 
                           
                           step 4 : if any jth elemnt is found which is greater than the tempVar element, then perform "arr[j+1] = arr[j]"
                           step 5 : else if any jth elemnt found which is smaller or equal to the tempVar element then break the jth loop
                       
                       step 6 : when the jth loop is complete/breaks than perform "arr[j+1] = tempVar"
                   
                   // when both the loop completes/breaks than array is SORTED.

    T : O(N^2) 
    S : O(1)

*/

#include<iostream>
using namespace std;


// -- function to print the array at any given instance 
void printArray(int *arr, int size){

    for(int i = 0; i < size; i++) cout << arr[i] << ' ';
    cout << endl;

}

// -- selection sort iterative function
void insertionSort(int *arr, int size){

    // step 1 : run an i loop from (1 to n-1)th element
    for(int i = 1; i < size; i++){
        
        // step 2 : store the ith index element in a variable "tempVar"
        int tempVar = arr[i];

        // step 3 : run a j loop from (i-1 to 0)th index 
        int j = i-1;   // to use it later
        for( ; j >= 0; j--){

            // step 4 : if any jth elemnt is found which is greater than the tempVar element, then perform "arr[j+1] = arr[j]"
            if(tempVar < arr[j]) arr[j+1] = arr[j];
            
            // step 5 : else if any jth elemnt found which is smaller or equal to the tempVar element then break the jth loop
            else break;
        } 

        // step 6 : when the jth loop is complete/breaks than perform "arr[j+1] = tempVar"
        arr[j+1] = tempVar;

    }

    // when both the loop completes/breaks than array is SORTED.
}

// -- MAIN Function
int main(){

    cout << "- - - - - - - - - - - - - - - - - - -" << endl;

    //int arr[] = {10, 21, 17, -5, 3, 2, 11};  // testCase - 1 ☑️
    int arr[] = {1, 7, -9, -10, 20};  // testCase - 2 ☑️
    //int arr[] = {10, 11, 12, 13, 14};  // testCase - 3 ☑️

    int size = sizeof(arr)/sizeof(int);

    cout << "Input Array : ";
    printArray(arr, size);

    insertionSort(arr, size);

    cout << "Output Array : ";
    printArray(arr, size);

    cout << "- - - - - - - - - - - - - - - - - - -" << endl;

}


// ☑️solved at gfg(both iteratively & recursively) : https://practice.geeksforgeeks.org/problems/insertion-sort/1
