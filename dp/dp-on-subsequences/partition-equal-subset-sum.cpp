/*
	Q. Given an array arr[], determine if it can be partitioned into two subsets such that the sum of elements in both parts is the same.
		Note: Each element must be in exactly one subset.


	Example 1:
		Input: arr = [1, 5, 11, 5]
		Output: true
		Explanation: The two parts are [1, 5, 5] and [11].

	Example 2:
		Input: arr = [1, 3, 5]
		Output: false
		Explanation: This array can never be partitioned into two such parts.
*/

#include <bits/stdc++.h>

using namespace std;

bool solve(int i, int sum, int n, vector<int> &arr, vector<vector<int>> &dp) {
	if(sum == 0) return true;

	if(i >= n) return sum == 0;

	if(dp[i][sum] != -1) return dp[i][sum];


	bool left = false, right = false;

	// don't consider the current element
	left = solve(i+1, sum, n, arr, dp);

	// consider the current element
	if(arr[i] <= sum)
	right = solve(i+1, sum-arr[i], n, arr, dp);

	return dp[i][sum] = left || right;
} 

bool canPartition(vector<int> &arr, int n)
{
	int sum = accumulate(arr.begin(), arr.end(), 0);

	if(sum & 1) return false;


	sum = sum / 2;

	vector<vector<int>> dp(n, vector<int>(sum+1, -1));

	return solve(0, sum, n, arr, dp);
}

int main() {
	int n;
	cout << "Enter the size of the array : ";
	cin >> n;

	vector<int> arr(n);
	cout << "Enter the elements of the array in order : ";
	for(int i=0; i<n; i++)
		cin >> arr[i];

	int result = canPartition(arr, n);

	cout << "can the array partitioned : " << result << endl;
	return 0;
}


// Recursion time complexity - O(2^n)
// Recursion space complexity - O(2^n)

// DP time complexity - O(n^2)
// DP space complexity - O(n^2)
