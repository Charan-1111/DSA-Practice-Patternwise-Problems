/*
    Q. Given a set of items, each with a weight and a value, represented by the array wt and val respectively. 
       Also, a knapsack with a weight limit capacity.
       The task is to fill the knapsack in such a way that we can get the maximum profit. Return the maximum profit.
       
       Note: Each item can be taken any number of times.

    Example 1:
        Input: val = [1, 1], wt = [2, 1], capacity = 3
        Output: 3
        Explanation: The optimal choice is to pick the 2nd element 3 times.

    Example 2:
        Input: val[] = [6, 1, 7, 7], wt[] = [1, 3, 4, 5], capacity = 8
        Output: 48
        Explanation: The optimal choice is to pick the 1st element 8 times.
    
    Example 3:
        Input: val[] = [6, 8, 7, 100], wt[] = [2, 3, 4, 5], capacity = 1
        Output: 0
        Explanation: We can't pick any element .hence, total profit is 0.
*/

#include <bits/stdc++.h>

using namespace std;

int solve(int i, int cap, int n, vector<int> &val, vector<int> &wt, vector<vector<int>> &dp) {
    if(cap == 0) return 0;
    
    if(i >= n) return 0;
    
    if(dp[i][cap] != -1) return dp[i][cap];
    
    
    int consider = INT_MIN, no_consider = INT_MIN;
    
    // don't consider the current weight
    no_consider = solve(i+1, cap, n, val, wt, dp);
    
    // consider the current weight
    if(wt[i] <= cap)
    consider = val[i] + solve(i, cap-wt[i], n, val, wt, dp);
    
    
    return dp[i][cap] = max(consider, no_consider);
}


int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight){
    vector<vector<int>> dp(n, vector<int>(w+1, -1));

    return solve(0, w, n, profit, weight, dp);
}

int main() {
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;
    
    vetor<int> weights(n), profits(n);

    cout << "Enter the weight and it's corresponding profit inorder : ";
    for(int i=0; i<n; i++) {
        cin >> weights[i];
        cin >> profits[i];
    }

    int weight;
    cout << "Enter the target weight : ";
    cin >> weight;

    int maxProfit = unboundedKnapsack(n, weight, profits, weights);

    cout << "Maximum profit we can acheive is : " << maxProfit << endl;

    return 0;
}


// Recursion time complexity - O(2^n)
// Recursion space complexity - O(2^n)

// DP time complexity - O(n^2)
// DP space complexity - O(n^2)
