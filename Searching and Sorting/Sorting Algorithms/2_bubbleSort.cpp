/*️✔️⭐ [Approach 2  Recursive] BUBBLE SORT 

    explanation : Step 1 :base case - when array has single element, then its sorted i.e round == 1 == size, also if array has size 0 then also its already sorted
                  step 2 : manage a bool variable swapped initially with value false, to optimise the algorithm to O(N) time in the best case
                  step 3 : solving single case i.e filling the last index with the element it deserves
                      step 4 : swap the pair and mark swapped as true if we swap a pair
                  step 5 : when the i loop breaks check if we swapped is false or not is so then return the function as the array is sorted - for optimisation 
                  step 6 : recursion will place rest elements at their right position they belong to 
                  
                  // ARRAY SORTED

    T : O(N^2) - worst case, O(N) - best case
    S : O(N)
 
*/


#include<iostream>
using namespace std;

// -- function to print the array at any instance
void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << ' '; 
    } 
    cout << endl;
}

// -- in case swap stl doesnt work
void swapFun(int *arr, int i, int j){

    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;

}

// -- bubble sort iterative function
void bubbleSort(int *arr, int size){

    // step 1 : run a loop from 1 to n-1 (n-1 because it will handle the worst cases like 10, 9, 8, 7, 6, 5)
        for(int round = 1; round <= size - 1; round++){
            
        // step 2 : create a boolean variable 'swapped', and initiallize it with false
        bool swapped = false;

        // step 3 : run a loop from (0 to N-round)th element
        for(int j = 0; j <= size-round-1; j++){

            // step 4 : if the (j+1)th element is smaller than the jth element than swap, and mark bool 'swapped' as true
            if(arr[j+1] < arr[j]){
                swapFun(arr, j, j+1);
                swapped = true;
            } 
        }

        // step 5 : as the jth loop completes, check if the bool 'swapped' is false, if so than break the 'round' loop also because the arrray is now sorted
        if(swapped == false) break;
    }

    // ARRAY SORTED
}

// -- main function
int main(){

    cout << "- - - - - - - - - - - - - - - - - - " << endl;
    
    /* Test Cases */
    
    //int arr[] = {10, 21, 17, -5, 3, 2, 11};  // testCase - 1 ☑️
    //int arr[] = {10,7,17,6,9,1,5};  // testCase - 2 ☑️
    int arr[] = {1, 2, 3, 4, -10, -9, -8 };  // testCase - 3 ☑️
    //int arr[] = {1,2,3,4,5}; // testCase - 4 ☑️
    
    int size=sizeof(arr)/sizeof(int);

    cout << "Original Array : " ;
    printArray(arr,size);

    bubbleSort(arr,size);

    cout << "Using bubble Sort : ";
    printArray(arr,size);
    
    cout << "- - - - - - - - - - - - - - - - - - " << endl;

}
