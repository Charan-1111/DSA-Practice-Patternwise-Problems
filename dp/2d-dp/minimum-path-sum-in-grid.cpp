/*
    Q. Ninjaland is a country in the shape of a 2-Dimensional grid 'GRID', with 'N' rows and 'M' columns. Each point in the grid has some cost associated with it.
       Find a path from top left i.e. (0, 0) to the bottom right i.e. ('N' - 1, 'M' - 1) which minimizes the sum of the cost of all the numbers along the path. You need to tell the minimum sum of that path.


    Example 1:

        Input : n = 2, m = 3
        grid = 5 9 6
               11 5 2

        Output : 21

    Example 2:

        Input : n = 1, m = 1
        grid :  5

        Output : 5
*/

#include <bits/stdc++.h>

using namespace std;


int solve(int i, int j, vector<vector<int>> &grid, vector<vector<int>> &dp) {
    if(i == 0 && j == 0)
    return grid[i][j];

    if(dp[i][j] != -1)
    return dp[i][j];


    int left = INT_MAX, up = INT_MAX;

    // left
    if(j > 0)
    left =  solve(i, j-1, grid, dp);

    // up
    if(i > 0)
    up =  solve(i-1, j, grid, dp);

    return dp[i][j] = grid[i][j] + min(left, up);
} 
int minSumPath(vector<vector<int>> &grid) {
    int n = grid.size();
    int m = grid[0].size();

    vector<vector<int>> dp(n, vector<int>(m, -1));
    int res = solve(n-1, m-1, grid, dp);

    return res;
}


int main() {
    int n, m;
    cout << "Enter the number of rows and columns of the grid : ";
    cin >> n >> m;

    vector<vector<int>> grid(n, vector<int>(m));
    cout << "Enter the elements of the grid in order : ";
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++){
            cin >> grid[i][j];
        }
    }

    int result = minSumPath(grid);

    cout << "Minimum path sum in the grid is : " << result << endl;

    return 0;
}


// Recursion time complexity - O(2^n)
// Recursion space complexity - O(2^n)


// DP time complexity - O(n^2)
// DP space complexity - O(n^2)
