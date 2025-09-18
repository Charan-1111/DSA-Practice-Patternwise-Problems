/*
    Q. Ninja is planing this ‘N’ days-long training schedule. Each day, he can perform any one of these three activities. 
       (Running, Fighting Practice or Learning New Moves). Each activity has some merit points on each day. 
       As Ninja has to improve all his skills, he can’t do the same activity in two consecutive days. 
       Can you help Ninja find out the maximum merit points Ninja can earn?
       You are given a 2D array of size N*3 ‘POINTS’ with the points corresponding to each day and activity. 
       Your task is to calculate the maximum number of merit points that Ninja can earn.


    Example 1:
        Input: arr[]= [[1, 2, 5], [3, 1, 1], [3, 3, 3]]
        Output: 11
        Explanation: Geek will learn a new move and earn 5 point 
                     then on second day he will do running and earn 3 point and 
                     on third day he will do fighting and earn 3 points so, maximum merit point will be 11.
    
    Example 2:
        Input: arr[]= [[1, 1, 1], [2, 2, 2], [3, 3, 3]]
        Output: 6
        Explanation: Geek can perform any activity each day while adhering to the constraints, 
                     in order to maximize his total merit points as 6.
    
    Example 3:
        Input: arr[]= [[4, 2, 6]]
        Output: 6
        Explanation: Geek will learn a new move to make his merit points as 6.
*/


#include <bits/stdc++.h>

using namespace std;

int solve(int idx, int last, int n, vector<vector<int>> &arr, vector<vector<int>> &dp) {
    if(idx >= n) return 0;
    
    if(dp[idx][last+1] != -1) return dp[idx][last+1];
    
    int val = INT_MIN;
    for(int j=0; j<3; j++) {
        if(j != last)
        val = max(val, arr[idx][j] + solve(idx+1, j, n, arr, dp));
    }
    
    return dp[idx][last+1] = val;
}


int ninjaTraining(int n, vector<vector<int>> &points)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));

    int res = solve(0, -1, n, points, dp);

    return dp[0][0];
}

int main() {
    int n;
    cout << "Enter the number of days : ";
    cin >> n;

    vector<vector<int>> arr(n, vector<int>(3));
    cout << "Enter the activity points in order : ";
    for(int i=0; i<n; i++){
        for(int j=0; j<3; j++) {
            cin >> arr[i][j];
        }
    }

    int res = ninjaTraining(n, arr);
    cout << "Maximum points can gain : " << res;

    return 0;
}


// Recursion time complexity - O(3^n)
// Recursion space complexity - O(1)

// DP time complexity - O(n^2)
// Dp space complexity - O(n^2)
