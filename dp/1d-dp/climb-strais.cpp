/*
	Q. There are n stairs, a person standing at the bottom wants to reach the top. The person can climb either 1 stair or 2 stairs at a time. 
	   Your task is to count the number of ways, the person can reach the top (order does matter).


	Example 1:
		Input: n = 1
		Output: 1
		Explanation: There is only one way to climb 1 stair.

	Example 2: 
		Input: n = 2
		Output: 2
		Explanation: There are 2 ways to reach 2th stair: {1, 1} and {2}.  

	Example 3:
		Input: n = 4
		Output: 5
		Explanation: There are five ways to reach 4th stair: {1, 1, 1, 1}, {1, 1, 2}, {2, 1, 1}, {1, 2, 1} and {2, 2}.
*/


#include <bits/stdc++.h>

using namespace std;

int solve(int n, vector<int> &dp) {
    if(n < 0) return 0;

    if(n == 0) return 1;

    if(dp[n] != -1) return dp[n];

    return dp[n] = solve(n-1, dp) + solve(n-2, dp);
}

int countDistinctWays(int n) {
    //  Write your code here.
    vector<int> dp(n+1, -1);
    return solve(n, dp); 
}

int main() {
	int n;
	cout << "Enter the number of stairs : ";
	cin >> n;

	int result = countDistinctWays(n);

	cout << "Number of distinct ways to reach the last stair is : " << result << endl;

	return 0;
}


// Time complexity without memoization - O(2^n) - because we are calling branches in 2 at every step
// Time complexity - O(n)
// Explination - Each n is computed once and stored in the dp[n], and for each n we do O(1) work => overall complexity reduces to O(n)

// Space complexity - O(n + n) // one n for the dp memory that we are using and another for the recursive stack