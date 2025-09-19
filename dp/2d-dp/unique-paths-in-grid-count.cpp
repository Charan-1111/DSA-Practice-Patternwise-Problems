/*
    Q. You are given a 2d list grid[][] of size n x m consisting of values 0 and 1.
       A value of 0 means that you can enter that cell and 1 implies that entry to that cell is not allowed.
       You start at the upper-left corner of the grid (1, 1) and you have to reach the bottom-right corner 
       (n, m) such that you can only move in the right or down direction from every cell.
       Your task is to calculate the total number of ways of reaching the target.

       Note: The first (1, 1) and last (n, m) cell of the grid can also be 1.
       It is guaranteed that the total number of ways will fit within a 32-bit integer.


    Example 1:
        Input: n = 3, m = 3,
        grid[][] = [[0, 0, 0], [0, 1, 0], [0, 0, 0]]
        Output: 2
        Explanation: There are two ways to reach the bottom-right corner:
        1. Right -> Right -> Down -> Down
        2. Down -> Down -> Right -> Right

    Example 2:
        Input: n = 1, m = 3,
        grid[][] = [[1, 0, 1]]
        Output: 0
        Explanation: There is no possible path to reach the end.
*/

#include <bits/stdc++.h>

using namespace std;


int solve(int i, int j, int n, int m, vector<vector<int>> &arr, vector<vector<int>> &dp) {
    if(i >= n || j >= m) return 0;
    
    if(i == n-1 && j == m-1) return 1;
    
    if(dp[i][j] != -1) return dp[i][j];
    
    int right = 0, down = 0;
    // right movement;
    if(j+1 < m && arr[i][j+1] != 1)
    right = solve(i, j+1, n, m, arr, dp);
    
    // down movement
    if(i+1 < n && arr[i+1][j] != 1)
    down = solve(i+1, j, n, m, arr, dp);
    
    return dp[i][j] = right + down;
}


int uniquePaths(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();
    
    if(grid[0][0] == 1 || grid[n-1][m-1] == 1) return 0;
    vector<vector<int>> dp(n, vector<int>(m, -1));
    
    return solve(0, 0, n, m, grid, dp);
}


int main() {
    int n, m;
    cout << "Enter the number of rows and columns in the grid : ";
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    cout << "Enter the values in the grid : ";
    for(int i=0; i<n; i++){
        for(int j=0; j<m; j++)
        cin >> grid[i][j];
    }

    int result = uniquePaths(grid);

    cout << "Total number of ways we can reach is : " << result << endl;

    return 0;
}

// Recursion time complexity - O(2^(n+m))
// Recursion space complexity - O(n+m)

// DP time complexity - O(n*m)
// DP space complexity - O(n*m) (dp + recursion stack)
