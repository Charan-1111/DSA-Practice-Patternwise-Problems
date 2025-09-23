/*
    Q. You are given an integer array 'A' of size 'N', sorted in non-decreasing order. 
       You are also given an integer 'target'. Your task is to write a function 
       to search for 'target' in the array 'A'. If it exists, return its index in 0-based indexing. 
       If 'target' is not present in the array 'A', return -1.


    Example 1:
        Input: arr[] = [1, 2, 3, 4, 5], k = 4
        Output: 3
        Explanation: 4 appears at index 3.

    Example 2:
        Input: arr[] = [11, 22, 33, 44, 55], k = 445
        Output: -1
        Explanation: 445 is not present.

    Example 3:
        Input: arr[] = [1, 1, 1, 1, 2], k = 1
        Output: 0
        Explanation: 1 appears at index 0.
*/

#include <bits/stdc++.h>

using namespace std;

int search(vector<int> &nums, int target) {
    int l = 0;
    int r = nums.size()-1;

    while(l <= r) {
        int mid = l + ((r-l)>>1);

        if(nums[mid] == target) {
            return mid;
        } else if(nums[mid] < target) {
            l = mid + 1;
        } else {
            r = mid - 1;
        }
    }

    return -1;
}

int main() {
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array in order : ";
    for(int i=0; i<n; i++)
    cin >> arr[i];

    int target;
    cout << "Enter the target to find : ";
    cin >> target;

    int result = search(arr, target);

    cout << "index of the target : " << result << endl;
    return 0;
}


// Time complexity - O(logn)
// Space complexity - O(1)
