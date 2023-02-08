
#include<iostream>
using namespace std;
/*
✔️⭐ [Approach 2  Recursive] BUBBLE SORT 

    explanation : Step 1 :base case - when array has single element, then its sorted i.e round == 1 == size, also if array has size 0 then also its already sorted
                  step 2 : manage a bool variable swapped initially with value false, to optimise the algorithm to O(N) time in the best case
                  step 3 : solving single case i.e filling the last index with the element it deserves
                      step 4 : swap the pair and mark swapped as true if we swap a pair
                  step 5 : when the i loop breaks check if we swapped is false or not is so then return the function as the array is sorted - for optimisation 
                  step 6 : recursion will place rest elements at their right position they belong to 
                  
                  // ARRAY SORTED

    T : O(N^2) - worst case, O(N) - best case
    S : O(N) - rec call stack

*/

// -- function to print the array at any instance
void printArray(int arr[], int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << ' '; 
    } 
    cout << endl;
}

// use this function when the original swap stl method is not working
void swapFun(int *arr, int i, int j){
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
    
// this is recursive function for bubble sort
void recBubbleSort(int *arr, int size, int rounds){
    
    // Step 1 :base case - when array has single element, then its sorted i.e round == 1 == size, also if array has size 0 then also its already sorted
    if(size == 0 || rounds == size) return;
    
    // step 2 : manage a bool variable swapped initially with value false, to optimise the algorithm to O(N) time in the best case
    bool swapped = false;
    
    // step 3 : solving single case i.e filling the last index with the element it deserves
    for(int j = 0; j <= size - rounds - 1; j++){
        
        // step 4 : mark swapped as true if we swap a pair
        if(arr[j+1] < arr[j]){
            swapFun(arr, j, j+1);
            swapped = true;
        } 
        
    }
    
    // step 5 : when the i loop breaks check if we swapped is false or not is so then return the function as the array is sorted - for optimisation 
    if(swapped == false) return;
    
    // step 6 : recursion will place rest elements at their right position they belong to 
    recBubbleSort(arr, size, ++rounds);
    
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

    int rounds = 1;
    recBubbleSort(arr,size, rounds);

    cout << "Using bubble Sort : ";
    printArray(arr,size);
    
    cout << "- - - - - - - - - - - - - - - - - - " << endl;

}
