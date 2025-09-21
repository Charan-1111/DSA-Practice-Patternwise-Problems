/*
	Q. Given an array of positive integers arr[] and a value sum, determine if there is a subset of arr[] with sum equal to given sum. 

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
		Explanation: The entire array can be taken as a subset, giving 1 + 2 + 3 = 6.
*/


#include <bits/stdc++.h>

using namespace std;

bool solve(int i, int target, int n, vector<int> &arr, vector<vector<int>> &dp){
  if(target == 0) return true;

  if(i >= n) {
    return target == 0;
  }

  if(dp[i][target] != -1) return dp[i][target];


  bool left = false, right = false;
  
  // don't consider the current element
  left = solve(i+1, target, n, arr, dp);

  // consider the current element
  if(arr[i] <= target)
  right = solve(i+1, target-arr[i], n, arr, dp);

  return dp[i][target] = left || right;
}


bool subsetSumToK(int n, int k, vector<int> &arr) {
    vector<vector<int>> dp(n+1, vector<int>(k+1, -1));

    return solve(0, k, n, arr, dp);
}


int main() {
	int n;
	cout << "Enter the size of the array : ";
	cin >> n;

	vector<int> arr(n);
	cout << "Enter the elements of the array in order : ";
	for(int i=0; i<n; i++)
		cin >> arr[i];


	int target;
	cout << "Enter the target sum : ";
	cin >> target;

	int result = subsetSumToK(n, target, arr);

	cout << "result : " << result;

	return 0;
}


// Recursion time complexity - O(2^n)
// Recursion space complexity - O(2^n)


// DP time complexity - O(n^2)
// DP space complexity - O(n^2)
