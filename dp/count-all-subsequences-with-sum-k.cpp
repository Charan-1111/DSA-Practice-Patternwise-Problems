/*
	Q. Given an array nums and an integer k. Return the number of non-empty subsquences of nums such that sum of all the elements in the subsequence is equal to k.

	Example 1.

	Input : nums = [4, 9, 2, 5, 1] , k = 10
	Output : 2
	Explanation : The possible subsets with sum k are [9, 1] , [4, 5, 1].


	Example 2.
	Input : nums = [4, 2, 10, 5, 1, 3] , k = 5
	Output : 3
	Explanation : The possible subsets with sum k are [4, 1] , [2, 3] , [5].
*/

// recursive approach


#include <bits/stdc++.h>

using namespace std;

int solve(int i, int n, vector<int> &arr, int k, vector<vector<int>> &dp) {
	if(k == 0) return 1;

	if(i >= n) {
		return k==0;
	}

	if(dp[i][k] != -1) return dp[i][k];


	int no_take = 0, take = 0;

	// don't consider the current element into the subset;
	no_take = solve(i+1, n, arr, k, dp);

	// consider the current element into the subset
	if(arr[i] <= k) 
		take = solve(i+1, n, arr, k-arr[i], dp);


	return dp[i][k] = take + no_take;
}

int countSubSequencesWithSumK(vector<int> &arr, int n, int k) {
	vector<vector<int>> dp(n+1, vector<int>(k+1, -1));
	return solve(0, n, arr, k, dp);
}

int main() {
	int n;
	cout << "Enter the size of the array : ";
	cin >> n;

	cout << "Enter the elements of the array : ";
	vector<int> v(n);
	for(int i=0; i<n; i++) {
		cin >> v[i];
	}

	int k;
	cout << "Enter the sum : ";
	cin >> k;


	int cnt = countSubSequencesWithSumK(v, n, k);

	cout << "Count : " << cnt << endl;
	return 0;
}



// Time Complexity - O(n^2)
// Space Complexity - O(n^2)