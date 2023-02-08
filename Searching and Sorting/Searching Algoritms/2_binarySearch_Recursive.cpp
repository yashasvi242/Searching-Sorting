/* ✔️⭐[Approach 2 - Recursive] Binary Search  

    explanation :- step 1 : base case - if low becomes greater than high then that means target element not found in the array
                   step 2 : solving 1 case i.e finding mid for initial low and high and then returning index if it is the target element 
                   step 3.1 : else if the mid element is smaller than target then recursion will search for target in the right part and return the ans
                   step 3.2 : else if element is greater than the target element then recursion will search for target in the left part and return the ans

    T : O(log(N))
    S : O(N) - recursive call stack


*/

#include<iostream>
using namespace std;

// -- Recursive Binary Search Funtion 

int recBinarySearch(int *arr, int low, int high, int target){

    // step 1 : base case - if low becomes greater than high then that means target element not found in the array
    if(low > high) return -1;

    // step 2 : solving 1 case i.e finding mid for initial low and high and then returning index if it is the target element 
    int mid = low + (high - low)/2;

    if(arr[mid] == target) return mid;

    // step 3.1 : else if the mid element is smaller than target then recursion will search for target in the right part and return the ans
    else if(arr[mid] < target) return recBinarySearch(arr, mid+1, high, target);

    // step 3.2 : else if element is greater than the target element then recursion will search for target in the left part and return the ans
    else return recBinarySearch(arr, low, mid-1, target);

}

// -- main function 
int main(){


    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;

    int arr[] = {10, 12, 15, 19, 21, 26, 28};
    int size = sizeof(arr)/sizeof(int);

    /* TEST CASES */

    // int target = 21;  // testCase - 1 (output : 4) ☑️
    // int target = 28;  // testCase - 2 (output : 6)☑️
    // int target = 122221;  // testCase - 3 (output : -1)☑️
    // int target = 10;  // testCase - 4 (output : 0)☑️
    int target = 19;  // testCase - 5 (output : 3)☑️



    int low = 0, high = size-1;
    int ans = recBinarySearch(arr, low, high, target);

    if(ans != -1) cout << target <<" is present at index " << ans << endl;
    else cout << target << " not present in the array." << endl;   


    cout << "- - - - - - - - - - - - - - - - - - - - - - - - - - " << endl;
    
}
