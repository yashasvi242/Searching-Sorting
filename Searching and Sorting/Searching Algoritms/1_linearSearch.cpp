/* ✔️ Linear Search Algorithm (Time : O(n) , Space : O(1)) */

#include <iostream>
using namespace std;

// -- this function will return index of target element if present, else if not present then it will return -1
int linearSearch(int *arr, int size, int &elementToFind){

    for(int i = 0; i < size; i++) 
        if(arr[i] == elementToFind) return i;
    
    return -1;
}

// MAIN FUNCTION
int main(){

    cout << "- - - - - - - - - - - - - - - - - - " << endl; // for better output

    int arr[] = {10, 20, -10, 21, 5, 3, 11};
    int size = sizeof(arr)/sizeof(int);
    
    /* Test Cases */
    int elementToFind = 21;   // TestCase-1 (output : 3)
    // int elementToFind = -10; //TestCase-2 (output : 2)
    //int elementToFind = -100; //TestCase-3 (output : 2)

    // calling function linearSearch
    int ans = linearSearch(arr, size, elementToFind);

    if(ans != -1) cout << elementToFind <<" is present at index : " << ans << endl;
    else cout << elementToFind << " is not present in the array. " << endl;

    
    cout << "- - - - - - - - - - - - - - - - - - " << endl; // for better output

}