/*
	Q. Given an array arr of non-negative integers and an integer target, the task is to count all subsets of the array whose sum is equal to the given target.

	Example 1:
		Input: arr[] = [5, 2, 3, 10, 6, 8], target = 10
		Output: 3
		Explanation: The subsets {5, 2, 3}, {2, 8}, and {10} sum up to the target 10.

	Example 2:
		Input: arr[] = [2, 5, 1, 4, 3], target = 10
		Output: 3
		Explanation: The subsets {2, 1, 4, 3}, {5, 1, 4}, and {2, 5, 3} sum up to the target 10.

	Example 3:
		Input: arr[] = [5, 7, 8], target = 3
		Output: 0
		Explanation: There are no subsets of the array that sum up to the target 3.

	Example 4:
		Input: arr[] = [35, 2, 8, 22], target = 0
		Output: 1
		Explanation: The empty subset is the only subset with a sum of 0.
*/

#include <bits/stdc++.h>

using namespace std;

int solve(int i, int target, int n, vector<int> &arr, int mod, vector<vector<int>> &dp) {
	if(target == 0) return 1;

	if(i >= n) return target == 0;

	if(dp[i][target] != -1) return dp[i][target];


	int left = 0, right = 0;

	// don't consider the current element
	left = solve(i+1, target, n, arr, mod, dp);

	// consider the current element
	if(arr[i] <= target)
	right = solve(i+1, target-arr[i], n, arr, mod, dp);


	return dp[i][target] = (left + right) % mod;
}

int findWays(vector<int>& arr, int k){
	int n = arr.size();

	int mod = 1000000007;

	vector<vector<int>> dp(n+1, vector<int>(k+1, -1));

	int res = solve(0, k, n, arr, mod, dp);

	// cout << "ress : " << dp[0][k] << endl;
	return res != 0 ? res : 0;
}

int main() {
	int n;
	cout << "Enter the size of the array : ";
	cin >> n;

	vector<int> arr(n);

	cout << "Enter the elements of the arrray in order : ";
	for(int i=0; i<n; i++)
	cin >> arr[i];


	int target;
	cout << "Enter the target sum : ";
	cin >> target;

	int result = findWays(arr, target);

	return 0;
}


// Recursion time complexity - O(2^n)
// Recursion space complexity - O(2^n)

// DP time complexity - O(n^2)
// DP space complexity - O(n^2)
