/*
    Q. Given a sorted and rotated array arr[] of distinct elements, the task is to find the index of a target key.  
       If the key is not present in the array, return -1.


    Example 1:
        Input: arr[] = [5, 6, 7, 8, 9, 10, 1, 2, 3], key = 3
        Output: 8
        Explanation: 3 is found at index 8.

    Example 2:
        Input: arr[] = [3, 5, 1, 2], key = 6
        Output: -1
        Explanation: There is no element that has value 6.

    Example 3:
        Input: arr[] = [33, 42, 72, 99], key = 42
        Output: 1
        Explanation: 42 is found at index 1.
*/

#include <bits/stdc++.h>

using namespace std;

int search(vector<int>& arr, int n, int k)
{
    int l = 0, r = n-1;

    while(l <= r) {
        int mid = l + ((r-l)>>1);

        if(arr[mid] == k) return mid;

        if(arr[l] <= arr[mid]) {
            if(arr[l] <= k && k <= arr[mid]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        } else {
            if(arr[mid] <= k && k <= arr[r]) {
                l = mid + 1; 
            } else {
                r = mid - 1;
            }
        }
    }

    return -1;
}


int main() {
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;

    vector<int> arr(n);
    for(int i=0; i<n; i++)
    cin >> arr[i];

    int target;
    cout << "Enter the target to search in the array : ";
    cin >> target;

    int result = search(arr, n, target);

    cout << "Index for the target result in the given array : " << result << endl;

    return 0;
}

// Time complexity - O(logn)
// Space complexity - O(1)
