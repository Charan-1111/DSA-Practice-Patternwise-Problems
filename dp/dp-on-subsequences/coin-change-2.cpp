/*
    Q. Given an integer array coins[ ] representing different denominations of currency and an integer sum, 
       find the number of ways you can make sum by using different combinations from coins[ ]. 
       Note: Assume that you have an infinite supply of each type of coin. Therefore, you can use any coin as many times as you want.
       Answers are guaranteed to fit into a 32-bit integer. 

    Example 1:
        Input: coins[] = [1, 2, 3], sum = 4
        Output: 4
        Explanation: Four Possible ways are: [1, 1, 1, 1], [1, 1, 2], [2, 2], [1, 3].

    Example 2:
        Input: coins[] = [2, 5, 3, 6], sum = 10
        Output: 5
        Explanation: Five Possible ways are: [2, 2, 2, 2, 2], [2, 2, 3, 3], [2, 2, 6], [2, 3, 5] and [5, 5].

    Example 3:
        Input: coins[] = [5, 10], sum = 3
        Output: 0
        Explanation: Since all coin denominations are greater than sum, no combination can make the target sum.
*/

#include <bits/stdc++.h>

using namespace std;


int solve(int i, int sum, int n, vector<int> &arr, vector<vector<int>> &dp) {
    if(sum == 0) return 1;
    
    if(i >= n) return sum == 0;
    
    if(dp[i][sum] != -1) return dp[i][sum];
    
    
    int left = 0, right = 0;
    
    // don't consider the current coin
    left = solve(i+1, sum, n, arr, dp);
    
    // consider the current coin
    if(arr[i] <= sum)
    right = solve(i, sum-arr[i], n, arr, dp);
    
    
    return dp[i][sum] = left + right;
}

int count(vector<int>& coins, int sum) {
    int n = coins.size();
    
    vector<vector<int>> dp(n, vector<int>(sum+1, -1));
    return solve(0, sum, n, coins, dp);
}

int main() {
    int n;
    cout << "Enter the number of coins : ";
    cin >> n;

    vector<int> coins(n);
    cout << "Enter the coins in order : ";
    for(int i=0; i<n; i++)
    cin >> coins[i];

    int sum;
    cout << "Enter the target sum : ";
    cin >> sum;


    int result = count(coins, sum);

    cout << "Number of ways in which we can get the change : " << result << endl;
    
    return 0;
}

// Recursion time complexity - O(2^n)
// Recursion space complexity - O(2^n)

// DP time complexity - O(n^2)
// DP space complexity - O(n^2)
