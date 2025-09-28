/*
    Q. You are given a rectangular matrix mat[][] of size n x m, and your task is to return an array while traversing the matrix in spiral form.
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> spiralPathMatrix(vector<vector<int>> matrix, int n, int m) 
{
    vector<int> res;

    int t = 0, b = n-1, l = 0, r = m-1;

    int dir = 0;

    while(t <= b && l <= r) {
        switch (dir) {
            case 0:
            for(int j=l; j<=r; j++){
                res.push_back(matrix[t][j]);
            }
            t++;
            break;
            case 1:
            for(int i=t; i<=b; i++){
                res.push_back(matrix[i][r]);
            }
            r--;
            break;
            case 2:
            for(int j=r; j>=l; j--){
                res.push_back(matrix[b][j]);
            }
            b--;
            break;
            default:
            for(int i=b; i>=t; i--){
                res.push_back(matrix[i][l]);
            }
            l++;
            break;
        }
        dir = (dir+1)%4;
    }

    return res;
}

int main() {
    int n, m;
    cout << "Enter the number of rows and columns that matrix contains : ";
    cin >> n >> m;
    
    vector<vector<int>> mat(n, vector<int>(m));
    cout << "Enter the elements of the matrix in order : ";
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++)
        cin >> mat[i][j];
    }
    
    vector<int> res = spiralPathMatrix(mat, n, m);
    
    cout << "Spiral order for the given matrix is : ";
    for(int elem : res) 
    cout << elem << " ";
    
    cout << endl;
    return 0;
}

// Time complexity - O(n*m)
// Space complexity - O(n+m)
