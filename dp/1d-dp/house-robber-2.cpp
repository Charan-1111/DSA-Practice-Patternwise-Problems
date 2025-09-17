/*
    Q. You are given an array arr[] which represents houses arranged in a circle, where each house has a certain value. A thief aims to maximize the total stolen value without robbing two adjacent houses.
       Determine the maximum amount the thief can steal.

       Note: Since the houses are in a circle, the first and last houses are also considered adjacent.

    Example 1:
        Input: arr[] = [2, 3, 2]
        Output: 3
        Explanation: arr[0] and arr[2] can't be robbed because they are adjacent houses. Thus, 3 is the maximum value thief can rob.
    
    Example 2:
        Input: arr[] = [1, 2, 3, 1]
        Output: 4
        Explanation: Maximum stolen value: arr[0] + arr[2] = 1 + 3 = 4

    Example 3:
        Input: arr[] = [2, 2, 3, 1, 2]
        Output: 5
        Explanation: Maximum stolen value: arr[0] + arr[2] = 2 + 3 = 5 or arr[2] + arr[4] = 3 + 2 = 5
*/

#include <bits/stdc++.h>

using namespace std;

long long int solve(int i, int n, vector<int> &arr, vector<long long int> &dp) {
    if(i >= n) return 0;

    if(dp[i] != -1) return dp[i];

    // don't select the current index
    long long int no_select = solve(i+1, n, arr, dp);

    // select the current index
    long long int select = arr[i] + solve(i+2, n, arr, dp);

    return dp[i] = max(select, no_select);
}

int maxValue(vector<int>& arr) {
    // your code here
    int n = arr.size();

    if(n == 1) return arr[0];

    vector<long long int> dp1(n, -1);
    vector<long long int> dp2(n, -1);

    // leaving the last element
    long long int ans1 = solve(0, n-1, arr, dp1);
    long long int ans2 = solve(1, n, arr, dp2);

    return max(ans1, ans2);
}

int main() {
    int n;
    cout << "Enter the number of the houses : ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the amount that present in each house in order : ";
    for(int i=0; i<n; i++)
    cin >> arr[i];

    int result = maxValue(arr);

    cout << "The maximum value we can achieve is : " << result << endl;

    return 0;
}


// Recursion time complexity - O(n^2)
// Recursion space complexity - O(n^2)


// DP time complexity - O(n)
// Dp space complexity - O(n)
