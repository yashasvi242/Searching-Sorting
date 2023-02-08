/* 
✔️⭐ SELECTION SORT [Approach 1 - iterative]
    
        explanation : step 1 : run a loop from 0 to n-2 th element of array
                          
                          step 2 : store the ith index in a variable named 'minIndex' 
                          step 3 : run a loop from (i+1 to n-1)th element 
                              
                              step 4 : compare the jth element with the element at 'minIndex' and if jth element is smaller than it then update the minIndex with jth index
                         
                          step 5 : after the j the loop completes, swap the ith index element with the minIndex element
                      
                      step 6 : after the i th loop also completes, the array is now sorted.      
                        
        T : O(n^2) 
        S : O(1) 
    
*/
    
#include <iostream>
using namespace std;

// -- this function will print the array at any instance
void printArray(int *arr, int size){

    for(int i = 0; i < size; i++) cout << arr[i] << ' ';
    cout << endl;

}

// -- this function will sort the array
void selectionSort(int *arr, int size){

    // step 1 : run a loop from 0 to n-2 th element of array
    for(int i = 0; i <= size-2; i++){

        // step 2 : store the ith index in a variable named 'minIndex' 
        int minIndex = i;

        // step 3 : run a loop from (i+1 to n-1)th element 
        for(int j = i + 1; j <= size-1; j++){

            // step 4 : compare the jth element with the element at 'minIndex' and if jth element is smaller than it then update the minIndex with jth index
            if(arr[j] < arr[minIndex]) minIndex = j;

        } 

        // step 5 : after the j the loop completes, swap the ith index element with the minIndex element
        swap(arr[i], arr[minIndex]);

    }

    // step 6 : after the i th loop also completes, the array is now sorted.

}

// -- Main Function 
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