/*
	Q. Given an array of positive integers arr and a value sum, determine if there is a subset of arr with sum equal to given sum

	Example 1:
		Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 9
		Output: true 
		Explanation: Here there exists a subset with target sum = 9, 4+3+2 = 9.

	Example 2:
		Input: arr[] = [3, 34, 4, 12, 5, 2], sum = 30
		Output: false
		Explanation: There is no subset with target sum 30.

	Example 3:
		Input: arr[] = [1, 2, 3], sum = 6
		Output: true
*/

// here the question is referencing the subset, means each element can be repeated only once

#include <bits/stdc++.h>

using namespace std;

bool solve(int i, int n, vector<int> &arr, int target, vector<vector<int>> &dp) {
	if(target == 0) return true;

	if(i >= n) {
		return target == 0;
	}

	if(dp[i][target] != -1) return dp[i][target];
 
	bool no_take = false, take = false;

	// don't consider the current element into the subset
	no_take = solve(i+1, n, arr, target, dp);

	// consider the current element into the subset
	if(arr[i] <= target)
		take = solve(i+1, n, arr, target-arr[i], dp);

	return dp[i][target] = take || no_take;
} 

bool isSubSetSum(vector<int> &arr, int n, int target) {
	vector<vector<int>> dp(n+1, vector<int>(target+1, -1));
	return solve(0, n, arr, target, dp);
}

int main() {
	int n;
	cout << "Enter the size of the array : ";
	cin >> n;

	vector<int> arr(n);
	cout << "Enter the elements of the array : ";
	for(int i=0; i<n; i++)
		cin >> arr[i];


	int target;
	cout << "Enter the target sum : ";
	cin >> target;

	bool isPresent = isSubSetSum(arr, n, target);

	cout << "Subset sum solution : " << isPresent << endl;

	return 0;
}


// Time complexity - O(n^2)
// Space complexity - O(n^2)