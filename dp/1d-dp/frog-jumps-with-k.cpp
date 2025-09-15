// Frog Jump with k distances

/*
    Q. Given an integer array height[] where height[i] represents the height of the i-th stair, 
       a frog starts from the first stair and wants to reach the top. From any stair i, 
       the frog is allowed to jump up to ‘K’ steps at a time. If K=4, the frog can jump 1,2,3, or 4 steps at every index. 
       The cost of a jump is the absolute difference in height between the two stairs. 
       Determine the minimum total cost required for the frog to reach the top.



    Example 1 :
        Input: heights[] = [20, 30, 40, 20], k=2
        Output: 20
        Explanation:  Minimum cost is incurred when the frog jumps from stair 0 to 1 then 1 to 3:
        jump from stair 0 to 1: cost = |30 - 20| = 10
        jump from stair 1 to 3: cost = |20-30|  = 10
        Total Cost = 10 + 10 = 20
    
    Example 2 :
        Input: heights[] = [30, 20, 50, 10, 40], k=2
        Output: 30
        Explanation: Minimum cost will be incurred when frog jumps from stair 0 to 2 then 2 to 4:
        jump from stair 0 to 2: cost = |50 - 30| = 20
        jump from stair 2 to 4: cost = |40-50|  = 10
        Total Cost = 20 + 10 = 30
*/


#include <bits/stdc++.h>

using namespace std;

int solve(int n, int k, vector<int>&arr, vector<int> &dp) {
    if(n == 0) return 0;

    if(dp[n] != -1) return dp[n];

    for(int i=1; i<=k; i++) {
        if(n > i)
        dp[n] = min(dp[n], abs(arr[n] - arr[n-i]) + solve(n-1, k, arr, dp));
    }

    return dp[n];
}

int frogJump(int n, vector<int> &heights, int k)
{
    vector<int> dp(n, -1);
    return solve(n-1, k, heights, dp);
}


int main() {
    int n;
    cout << "Enter the total number of heights : ";
    cin >> n;

    vector<int> heights(n);
    cout << "Enter the heights : ";
    for(int i=0; i<n; i++)
    cin >> heights[i];

    int k;
    cout << "Enter the max stones frog can jump : ";
    cin >> k;

    int minCost = frogJump(n, heights, k);

    cout << "Minimum cost is : " << minCost << endl;
    return 0;
}

// Recursion time complexity - O(k^n)
// Recursion space complexity - O(k^n)

// DP time complexity - O(n^2*k^2)
// DP space complexity - O(n + n)
