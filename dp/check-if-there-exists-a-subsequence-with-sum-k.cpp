/*
	Q. Given an array arr of size n and sum k, check whether there exists a subsequence such that the sum of all elements in the subsequence equals the given target sum k

	Example 1:

	Input:  arr = [10,1,2,7,6,1,5], k = 8.
	Output:  Yes
	Explanation:  Subsequences like [2, 6], [1, 7] sum upto 8

	Example 2 :

	Input:  arr = [2,3,5,7,9], k = 100. 
	Output:  No
	Explanation:  No subsequence can sum upto 100
*/

#include <bits/stdc++.h>

using namespace std;

bool solve(int i, int n, vector<int> &arr, int k, vector<vector<int>> &dp) {
	if(k == 0) return true;

	if(i >= n) {
		return k == 0;
	}


	if(dp[i][k] != -1) return dp[i][k];


	bool no_take = false, take = false;

	// don't consider the current element in to the subset;
	no_take = solve(i+1, n, arr, k, dp);


	// consider the current element into the subset

	if(arr[i] <= k) 
		take = solve(i+1, n, arr, k-arr[i], dp);


	return dp[i][k] = take || no_take;
}


bool checkIfSubsequecnceExists(vector<int> &arr, int n, int k) {
	vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
	return solve(0, n, arr, k, dp);
}

int main() {
	int n;
	cout << "Enter the size of the array : ";
	cin >> n;

	cout << "Enter the elements of the array : ";
	vector<int> arr(n);
	for(int i=0; i<n; i++)
		cin >> arr[i];

	int k;
	cout << "Enter the sum : ";
	cin >> k;

	return checkIfSubsequecnceExists(arr, n, k);
}

// Recursion time complexity - O(2^n)
// Recursion space complexity - O(2^n)

// DP Time Complexity - O(n^2)
// DP Space complexity - O(n^2)
