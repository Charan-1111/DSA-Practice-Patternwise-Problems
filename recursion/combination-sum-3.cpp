/*
	Q. Find all valid combinations of k numbers that sum up to n such that the following conditions are true:
		  . Only numbers 1 through 9 are used.
		  . Each number is used at most once.
	   Return a list of all possible valid combinations. The list must not contain the same combination twice, and the combinations may be returned in any order.
*/

#include <bits/stdc++.h>

using namespace std;

void solve(int i, int k, int sum, vector<int> temp, vector<vector<int>> &res) {
	if(sum == 0) {
		if(temp.size() == k){
			res.push_back(temp);
		}

		return;
	}

	if(i >= 10) {
		if(sum == 0 && temp.size() == k) {
			res.push_back(temp);
		} 

		return;
	}

	// consider the current element into the subset
	if(i <= sum) {
		temp.push_back(i);
		solve(i+1, k, sum-i, temp, res);
		temp.pop_back();
	}

	// don't consider the current element into the subset
	solve(i+1, k, sum, temp, res);
}

vector<vector<int>> combinationSum3(int k, int n) {
	vector<vector<int>> res;

	vector<int> temp;
	solve(1, k, n, temp, res);

	return res;
}

int main() {
	int k, n;
	cin >> k >> n;

	vector<vector<int>> res = combinationSum3(k, n);

	return 0;
}

// Time complexity - O(2^9)
// Space complexity - O(2^9)