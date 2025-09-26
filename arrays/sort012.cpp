/*
    Q. Given an array arr[] containing only 0s, 1s, and 2s. Sort the array in ascending order.
       Note: You need to solve this problem without utilizing the built-in sort function.

    Example 1:
        Input: arr[] = [0, 1, 2, 0, 1, 2]
        Output: [0, 0, 1, 1, 2, 2]
        Explanation: 0s, 1s and 2s are segregated into ascending order.

    Example 2:
        Input: arr[] = [0, 1, 1, 0, 1, 2, 1, 2, 0, 0, 0, 1]
        Output: [0, 0, 0, 0, 0, 1, 1, 1, 1, 1, 2, 2]
        Explanation: 0s, 1s and 2s are segregated into ascending order.
*/

#include <bits/stdc++.h>

using namespace std;

void sortArray(vector<int>& arr, int n){
    int l = 0, mid = 0, r = arr.size()-1;

    while(mid <= r) {
        if(arr[mid] == 0) {
            swap(arr[l], arr[mid]);
            l++;
            mid++;
        } else if(arr[mid] == 2) {
            swap(arr[r], arr[mid]);
            r--;
        } else {
            mid++;
        }
    }
}

int main() {
    int n;
    cout << "Enter the number of elements in the array : ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array in order : ";
    for(int i=0; i<n; i++)
    cin >> arr[i];

    sortArray(arr, n);

    return 0;
}

// Time complexity - O(n)
// Space complexity - O(1)
