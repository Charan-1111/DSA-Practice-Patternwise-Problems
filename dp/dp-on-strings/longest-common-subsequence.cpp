/*
    Q. Given two strings s1 and s2, return the length of their longest common subsequence (LCS). 
       If there is no common subsequence, return 0.

       A subsequence is a sequence that can be derived from the given string by deleting some or no elements 
       without changing the order of the remaining elements. For example, "ABE" is a subsequence of "ABCDE".


    Example 1:
        Input: s1 = "ABCDGH", s2 = "AEDFHR"
        Output: 3
        Explanation: The longest common subsequence of "ABCDGH" and "AEDFHR" is "ADH", which has a length of 3.

    Example 2:
        Input: s1 = "ABC", s2 = "AC"
        Output: 2
        Explanation: The longest common subsequence of "ABC" and "AC" is "AC", which has a length of 2.

    Example 3:
        Input: s1 = "XYZW", s2 = "XYWZ"
        Output: 3
        Explanation: The longest common subsequences of "XYZW" and "XYWZ" are "XYZ" and "XYW", both of length 3.
*/


#include <bits/stdc++.h>

using namespace std;

int solve(int i, int j, string &s1, string &s2, vector<vector<int>> &dp) {
    if(i < 0 || j < 0) return 0;
    
    if(dp[i][j] != -1) return dp[i][j];
    
    if(s1[i] == s2[j]) return 1 + solve(i-1, j-1, s1, s2, dp);
    
    int left = solve(i-1, j, s1, s2, dp);
    
    int right = solve(i, j-1, s1, s2, dp);
    
    return dp[i][j] = max(left, right);
}

int lcs(string &s1, string &s2) {
    int n = s1.length();
    int m = s2.length();
    
    vector<vector<int>> dp(n, vector<int>(m, -1));
    
    return solve(n-1, m-1, s1, s2, dp);
}

int main() {
    string s1, s2;

    cout << "Enter the strings in order : ";
    cin >> s1;
    cin >> s2;

    int result = lcs(s1, s2);

    return 0;
}


// Recursion time complexity - O(2^(m+n))
// Recursion space complexity - O(n+m)

// DP time complexity - O(n*m)
// DP space complexity - O(n+m)
