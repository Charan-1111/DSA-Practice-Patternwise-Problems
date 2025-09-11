/*
	Q. Consider a rat placed at position (0, 0) in an n x n square matrix mat[][]. The rat's goal is to reach the destination at position (n-1, n-1). The rat can move in four possible directions: 'U'(up), 'D'(down), 'L' (left), 'R' (right).

		The matrix contains only two possible values:

			. 0: A blocked cell through which the rat cannot travel.
			. 1: A free cell that the rat can pass through.

		Your task is to find all possible paths the rat can take to reach the destination, starting from (0, 0) and ending at (n-1, n-1), under the condition that the rat cannot revisit any cell along the same path. Furthermore, the rat can only move to adjacent cells that are within the bounds of the matrix and not blocked.
		If no path exists, return an empty list.

		Note: Return the final result vector in lexicographically smallest order.


		Examples:
			Input: mat[][] = [[1, 0, 0, 0], [1, 1, 0, 1], [1, 1, 0, 0], [0, 1, 1, 1]]
			Output: ["DDRDRR", "DRDDRR"]
			Explanation: The rat can reach the destination at (3, 3) from (0, 0) by two paths - DRDDRR and DDRDRR, when printed in sorted order we get DDRDRR DRDDRR.

		Example 2:
			Input: mat[][] = [[1, 0], [1, 0]]
			Output: []
			Explanation: No path exists as the destination cell is blocked.

		Example 3:
			Input: mat = [[1, 1, 1], [1, 0, 1], [1, 1, 1]]
			Output: ["DDRR", "RRDD"]
			Explanation: The rat has two possible paths to reach the destination: 1. "DDRR" 2. "RRDD", These are returned in lexicographically sorted order.
*/

#include <bits/stdc++.h>

using namespace std;

void solve(int i, int j, int n, vector<vector<int>> &mat, string s, vector<string> &res) {
    if(i == n-1 && j == n-1) {
        res.push_back(s);
        return;
    }

    // Up
    if(i-1 >= 0 && mat[i-1][j] == 1) {
        mat[i-1][j] = 0;
        solve(i-1, j, n, mat, s+"U", res);
        mat[i-1][j] = 1;
    }

    // Down
    if(i+1 < n && mat[i+1][j] == 1) {
        mat[i+1][j] = 0;
        solve(i+1, j, n, mat, s+"D", res);
        mat[i+1][j] = 1;
    }

    // Left
    if(j-1 >= 0 && mat[i][j-1] == 1) {
        mat[i][j-1] = 0;
        solve(i, j-1, n, mat, s+"L", res);
        mat[i][j-1] = 1;
    }

    // Right
    if(j+1 < n && mat[i][j+1] == 1) {
        mat[i][j+1] = 0;
        solve(i, j+1, n, mat, s+"R", res);
        mat[i][j+1] = 1;
    }
}

vector < string > searchMaze(vector < vector < int >> & mat, int n) {
    if(mat[0][0] == 0 || mat[n-1][n-1] == 0) return {};
    // Write your code here.
    vector<string> result;
    string s = "";

    mat[0][0] = 0;
    solve(0, 0, n, mat, s, result);
    mat[0][0] = 1;

    return result;
}


int main() {
	int n;
	cout << "Enter the size of the square matrix : ";
	cin >> n;


	vector<vector<int>> mat(n, vector<int>(n));

	cout << "Enter the elements of the matrix in order :";
	for(int i=0; i<n; i++) {
		for(int j=0; j<n; j++) {
			cin >> mat[i][j];
		}
	}


	vector<string> result = searchMaze(mat, n);

	sort(result.begin(), result.end());

	for(string s : result) {
		cout << s << " ";
	}

	cout << endl;

	return 0;

}