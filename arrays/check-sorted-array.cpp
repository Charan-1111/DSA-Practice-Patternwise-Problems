/*
    Q. You have been given an array ‘a’ of ‘n’ non-negative integers.You have to check whether the given array is sorted in 
       the non-decreasing order or not.

       Your task is to return 1 if the given array is sorted. Else, return 0.

    Example 1:
        Input : 0 0 0 1
        Output : 1

    Example 2:
        Input :  4 5 4 4 4
        Output : 0
*/

#include <bits/stdc++.h>

using namespace std;

int isSorted(int n, vector<int> arr) {
    int last_elem = arr[0];

    for(int i=1; i<n; i++){
        if(arr[i] < arr[i-1]) return false;
    }

    return true;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array : ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array in order : ";
    for(int i=0; i<n; i++)
    cin >> arr[i];

    int res = isSorted(n, arr);

    return 0;
}

// Time complexity - O(n)
// Space complexity - O(1)
