/*
	Q. Given an array arr containing positive integers. Find the maximum sum of 
		 elements of any possible subsequence such that no two numbers 
		 in the subsequence should be adjacent in array arr[].
		 
		 
	 Example 1:
		Input: arr[] = [5, 5, 10, 100, 10, 5]
		Output: 110
		Explanation: If you take indices 0, 3 and 5, then = 5+100+5 = 110.
		
	 Example 2:
		Input: arr[] = [3, 2, 7, 10]
		Output: 13
		Explanation: 3 and 10 forms a non continuous subsequence with maximum sum.
	 
	 Example 3:
		Input: arr[] = [9, 1, 6, 10]
		Output: 19
		Explanation: 9 and 10 forms a non continuous subsequence with maximum sum.
*/


#include <bits/stdc++.h>

using namespace std;

int solve(int i, int n, vector<int> &arr, vector<int> &dp) {
    if(i >= n) return 0;

    if(dp[i] != -1) return dp[i];

    // don't select the current index
    int no_select = solve(i+1, n, arr, dp);

    // select the current index
    int select = arr[i] + solve(i+2, n, arr, dp);

    return dp[i] = max(select, no_select);
}

int maximumNonAdjacentSum(vector<int> &nums, int n){
    // Write your code here.
    vector<int> dp(n, -1);

    return solve(0, n, nums, dp);
}

int main() {
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;

    vector<int> arr(n);

    cout << "Enter the elements of the array in sequence : ";
    for(int i=0; i<n; i++)
    cin >> arr[i];

    int result = maximumNonAdjacentSum(arr, n);

    cout << "Maximum non adjacent sum is : " << result << endl;
    return 0;
}


// Recursion time complexity - O(2^n)
// Recursion space complexity - O(2^n)


// Dp time complexity - O(n)
// Dp space complexity - O(n)