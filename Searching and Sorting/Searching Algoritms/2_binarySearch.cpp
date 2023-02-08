/* ✔️Binary Search (Time : O(log(n)), Space : O(1) ) */

#include<iostream>
using namespace std;

// -- this function will return the index of the target element if present, else it will return -1 if element is not found in the given array
int binarySearch(int *arr, int size, int target){

    // step 1 : create 3 variables low, mid, high
    int low = 0, high = size - 1, mid;

    while(low <= high){
        // step 2 : find mid index from the current low and high 
        mid = low + (high - low)/2;

        // step 3 : if the mid element is the target element then return the mid index 
        if(arr[mid] == target) return mid;

        // step 4 : if the mid element is smaller than the target, then search in the right half of the array 
        else if(arr[mid] < target) low = mid + 1;

        // step 5 : if the mid element is greater than the target, then search in the left half of the array 
        else high = mid - 1;

    }

    // step 6 : if loop completes then return -1, i.e no target element present in the given array
    return -1;

}

// -- main function 
int main(){


    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;

    int arr[] = {10, 12, 15, 19, 21, 26, 28};
    int size = sizeof(arr)/sizeof(int);

    /* TEST CASES */

    //int target = 21;  // testCase - 1 (output : 4)
    // int target = 28;  // testCase - 2 (output : 6)
    //int target = 122221;  // testCase - 3 (output : -1)
    //int target = 10;  // testCase - 4 (output : 0)
    int target = 19;  // testCase - 5 (output : 3)
    

    int ans = binarySearch(arr, size, target);

    if(ans != -1) cout << target <<" is present at index " << ans << endl;
    else cout << target << " not present in the array." << endl;   


    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
    
}


