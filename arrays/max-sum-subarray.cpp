/*
    Q. Given an integer array arr[], find the subarray (containing at least one element) which has the maximum possible sum, 
       and return that sum.

       Note: A subarray is a continuous part of an array.

    Example 1:
        Input: arr[] = [2, 3, -8, 7, -1, 2, 3]
        Output: 11
        Explanation: The subarray [7, -1, 2, 3] has the largest sum 11.

    Example 2:
        Input: arr[] = [-2, -4]
        Output: -2
        Explanation: The subarray [-2] has the largest sum -2.

    Example 3:
        Input: arr[] = [5, 4, 1, 7, 8]
        Output: 25
        Explanation: The subarray [5, 4, 1, 7, 8] has the largest sum 25.
*/

#include <bits/stdc++.h>

using namespace std;

int maxSubarraySum(vector<int> arr, int n)
{
    int sum = 0;
    int maxSum = -1000000;

    for(int elem : arr) {
        sum += elem;

        maxSum = max(maxSum, sum);

        if(sum < 0)
        sum = 0;
    }

    return maxSum > 0 ? maxSum : 0;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array : ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array in order : ";
    for(int i=0; i<n; i++)
    cin >> arr[i];

    int maxSum = maxSubarraySum(arr, n);
    
    cout << "Maximum sum in the subarray : " << maxSum << endl;

    return 0;
}

// Time complexity - O(n)
// Space complexity - O(1)
