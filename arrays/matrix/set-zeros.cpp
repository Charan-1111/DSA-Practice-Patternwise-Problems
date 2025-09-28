/*
    Q. You are given a 2D matrix mat[][] of size n x m. The task is to modify the matrix such that if mat[i][j] is 0, all the elements in the i-th row and j-th column are set to 0.
    
    
*/

#include <bits/stdc++.h>

using namespace std;

void setMatrixZeroes(vector<vector<int>> &mat) {
    vector<pair<int, int>> v;
    
    int n = mat.size();
    int m = mat[0].size();
    
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++){
            if(mat[i][j] == 0) {
                v.push_back({i, j});
            }
        }
    }
    
    for(pair<int, int> t : v) {
        int i = t.first;
        int j = t.second;
        
        for(int idx=0; idx<m; idx++)
        mat[i][idx] = 0;
        
        for(int idx = 0; idx < n; idx++)
        mat[idx][j] = 0;
    }
}

int main() {
    int n, m;
    cout << "Enter the number of rows and columns that matrix consists : ";
    cin >> n >> m;
    
    vector<vector<int>> mat(n, vector<int>(m));
    
    cout << "Enter the values of the matrix in order : ";
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++)
        cin >> mat[i][j];
    }
    
    setMatrixZeroes(mat);
    
    return 0;
}

// Time complexity - O(n*m)
// Space complexity - O(n)
