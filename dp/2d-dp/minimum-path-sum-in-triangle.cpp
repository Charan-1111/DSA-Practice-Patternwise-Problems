/*
	Q. Given a triangle array, return the minimum path sum to reach from top to bottom.
	   For each step, you may move to an adjacent number of the row below. More formally, 
	   if you are on index i on the current row, you may move to either index i or index i + 1 on the next row.


	Example 1:

		Input: triangle = [[2],[3,4],[6,5,7],[4,1,8,3]]
		Output: 11
		Explanation:
		     2
		   3 4
		  6 5 7
		 4 1 8 3
		The minimum path sum from top to bottom is 2 + 3 + 5 + 1 = 11.


	Example 2:

		Input: triangle = [[10]]
		Output: 10
*/


#include <bits/stdc++.h>

using namespace std;

int solve(int i, int j, int n, vector<vector<int>> &grid, vector<vector<int>> &dp) {
	if(i >= n || j >= n) return INT_MAX;

	if(i == n-1) return grid[i][j];

	if(dp[i][j] != -1) return dp[i][j];

	int down = INT_MAX, right = INT_MAX;

	// down movement (i, j) => (i+1, j)
	if(i+1 < n)
	down = solve(i+1, j, n, grid, dp);

	// right movement (i, j) => (i+1, j+1)
	if(i+1 < n && j+1 < n)
	right = solve(i+1, j+1, n, grid, dp);


	return dp[i][j] = grid[i][j] + min(right, down);
}

int minimumPathSum(vector<vector<int>>& grid, int n){
	vector<vector<int>> dp(n, vector<int>(n, -1));
	return solve(0, 0, n, grid, dp);
}

int main() {
	int n;
	cout << "Enter the number of rows and columns of the grid : ";
	cin >> n >> m;

	vector<vector<int>> grid(n, vector<int>(n));
	cout << "Enter the value of the triangle grid in order : ";
	for(int i=0; i<n; i++) {
		for(int j=0; j<i+1; j++)
			cin >> grid[i][j];
	}

	int result = minimumPathSum(grid, n);

	cout << "Minimum path sum in the triangle is : " << result << endl;
	return 0;
}


// Recursion time complexity - O(2^n)
// Recursion space complexity - O(2^n)

// DP time complexity - O(n^2)
// DP space complexity - O(n^2) 
