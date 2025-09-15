/*
    Q. Given an integer array height[] where height[i] represents the height of the i-th stair, 
       a frog starts from the first stair and wants to reach the top. From any stair i, 
       the frog has two options: it can either jump to the (i+1)th stair or the (i+2)th stair. 
       The cost of a jump is the absolute difference in height between the two stairs. 
       Determine the minimum total cost required for the frog to reach the top.



    Example 1 :
        Input: heights[] = [20, 30, 40, 20] 
        Output: 20
        Explanation:  Minimum cost is incurred when the frog jumps from stair 0 to 1 then 1 to 3:
        jump from stair 0 to 1: cost = |30 - 20| = 10
        jump from stair 1 to 3: cost = |20-30|  = 10
        Total Cost = 10 + 10 = 20
    
    Example 2 :
        Input: heights[] = [30, 20, 50, 10, 40]
        Output: 30
        Explanation: Minimum cost will be incurred when frog jumps from stair 0 to 2 then 2 to 4:
        jump from stair 0 to 2: cost = |50 - 30| = 20
        jump from stair 2 to 4: cost = |40-50|  = 10
        Total Cost = 20 + 10 = 30
*/


#include <bits/stdc++.h>

using namespace std;

int solve(int n, vector<int>  &arr, vector<int> &dp) {
    if(n == 0) return 0;

    if(dp[n] != -1) return dp[n];

    // 1 step
    int step1 = abs(arr[n]-arr[n-1]) + solve(n-1, arr, dp);

    int step2 = INT_MAX;
    // 2 step
    if(n > 1)
    step2 = abs(arr[n] - arr[n-2]) + solve(n-2, arr, dp);

    return dp[n] = min(step1, step2);
}

int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n, -1);
    return solve(n-1, heights, dp);
}


int main() {
    int n;
    cout << "Enter the total number of heights : ";
    cin >> n;

    vector<int> heights(n);
    cout << "Enter the heights : ";
    for(int i=0; i<n; i++)
    cin >> heights[i];

    int minCost = frogJump(n, heights);

    cout << "Minimum cost is : " << minCost << endl;
    return 0;
}

// Recursion time complexity - O(2^n)
// Recursion space complexity - O(2^n)

// DP time complexity - O(n^2)
// DP space complexity - O(n + n)
