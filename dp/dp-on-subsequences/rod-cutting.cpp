/*
    Q. Given a rod of length n inches and an array price[], where price[i] denotes the value of a piece of length i. 
       Your task is to determine the maximum value obtainable by cutting up the rod and selling the pieces.

       Note: n = size of price, and price[] is 1-indexed array.


    Example 1:
        Input: price[] = [1, 5, 8, 9, 10, 17, 17, 20]
        Output: 22
        Explanation: The maximum obtainable value is 22 by cutting in two pieces of lengths 2 and 6, i.e., 5 + 17 = 22.

    Example 2:
        Input: price[] = [3, 5, 8, 9, 10, 17, 17, 20]
        Output: 24
        Explanation: The maximum obtainable value is 24 by cutting the rod into 8 pieces of length 1, i.e, 8*price[1] = 8*3 = 24.

    Example 3:
        Input: price[] = [3]
        Output: 3
        Explanation: There is only 1 way to pick a piece of length 1.
*/


#include <bits/stdc++.h>

using namespace std;

int solve(int i, int tot, int n, vector<int> &arr, vector<vector<int>> &dp) {
	if(tot == 0 || i >= n) return 0;
	
	if(dp[i][tot] != -1) return dp[i][tot];
	
	int consider = INT_MIN, no_consider = INT_MIN;
	
	// don't consider the current element
	no_consider = solve(i+1, tot, n, arr, dp);
	
	// consider the current element
	if(i+1 <= tot)
	consider = arr[i] + solve(i, tot-i-1, n, arr, dp);
	
	return dp[i][tot] = max(consider, no_consider);
}

int cutRod(vector<int> &price, int n){
	vector<vector<int>> dp(n, vector<int>(n+1, -1));
	
	return solve(0, n, n, price, dp);
}

int main() {
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;


    vector<int> arr(n);
    cout << "Enter the profits in order : ";
    for(int i=0; i<n; i++)
    cin >> arr[i];

    int result = cutRod(arr, n);

    cout << "Maximum profit we can achieve : " << result << endl;

    return 0;
}


// Recursion time complexity - O(2^n)
// Recursion space complexity - O(2^n)

// DP time complexity - O(n^2)
// DP space complexity - O(n^2)
