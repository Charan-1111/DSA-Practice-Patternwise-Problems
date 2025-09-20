/*
	Q. You are given a matrix mat[][] of size n x m where each element is a positive integer. Starting from any cell in the first row, 
	   you are allowed to move to the next row, but with specific movement constraints. From any cell (r, c) in the current row, 
	   you can move to any of the three possible positions :

			. (r+1, c-1) — move diagonally to the left.
			. (r+1, c) — move directly down.
			. (r+1, c+1) — move diagonally to the right.
       Find the maximum sum of any path starting from any column in the first row and ending at any column in the last row, following the above movement constraints.


    Example 1:
		Input: mat[][] = [[3, 6, 1], [2, 3, 4], [5, 5, 1]]
		Output: 15
		Explaination: The best path is (0, 1) -> (1, 2) -> (2, 1). It gives the maximum sum as 15.


	Example 2:
		Input: mat[][] = [[2, 1, 1], [1, 2, 2]]
		Output: 4
		Explaination: The best path is (0, 0) -> (1, 1). It gives the maximum sum as 4.

	Example 3:
		Input: mat[][] = [[25]]
		Output: 25
		Explaination: (0, 0) is the only cell in mat[][], so maximum path sum will be 25.
*/


#include <bits/stdc++.h>

using namespace std;

int solve(int i, int j, int n, int m, vector<vector<int>> &arr, vector<vector<int>> &dp) {
	  if(i >= n || j >= m || j < 0) return INT_MIN;
	  
	  if(i == n-1) return arr[i][j];
	  
	  if(dp[i][j] != -1) return dp[i][j]; 
	  
	  
	  int left_col = INT_MIN, col = INT_MIN, right_col = INT_MIN;
	  
	  // down movement (i, j) => (i+1, j)
	  if(i+1 < n)
	  col = solve(i+1, j, n, m, arr, dp);
	  
	  // left column movement (i, j) => (i+1, j-1)
	  if(i+1 < n && j-1 >= 0)
	  left_col = solve(i+1, j-1, n, m, arr, dp);
	  
	  // right column movement (i, j) => (i+1, j+1)
	  if(i+1 < n && j+1 < m)
	  right_col = solve(i+1, j+1, n, m, arr, dp);
	  
	  return dp[i][j] = max(dp[i][j], arr[i][j] + max(col, max(left_col, right_col)));
}

int maximumPath(vector<vector<int>>& mat) {
    int n = mat.size();
    int m = mat[0].size();
    
    
    int res = INT_MIN;
    
    vector<vector<int>> dp(n, vector<int>(m, -1));
    
    for(int j = 0; j<m; j++) {
        res = max(res, solve(0, j, n, m, mat, dp));
    }
    
    return res;
}

int main() {
	int n, m;

	cout << "Enter the number of rows and columns in the matrix : ";
	cin >> n >> m;

	vector<vector<int>> mat(n, vector<int>(m));
	cout << "Enter the elements of the matrix in order : ";
	for(int i=0; i<n; i++){
		for(int j=0; j<m; j++)
			cin >> mat[i][j];
	}


	int result = maximumPath(mat);

	cout << "Maximum falling sum is : " << result << endl;

	return 0;
}

// Recursion time complexity -  O(3^n)
// Recursion space complexity - O(3^n)


// DP time complexity - O(n^2)
// DP space complexity - O(n^2)
