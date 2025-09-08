/*
	Q. Given an array arr[] and a target, your task is to find all unique combinations in the array where the sum is equal to target. 
	The same number may be chosen from the array any number of times to make target.
	You can return your answer in any order.


	Example 1 :
		Input: arr[] = [2, 4, 6, 8], target = 8
		Output: [[2 2 2 2] [2 2 4] [2 6] [4 4] [8]]
		Explanation: Total number of possible combinations are 5.

	Example 2:
		Input: arr[] = [2, 7, 6, 5], target = 16
		Output: [[2 2 2 2 2 2 2 2] [2 2 2 2 2 6] [2 2 2 5 5] [2 2 5 7] [2 2 6 6] [2 7 7] [5 5 6]]
		Explanation: Total number of possible combinations are 7.

	Example 3:
		Input: arr[] = [6, 5, 7], target = 8
		Output: []
		Explanation: There are no possible combinantions such that target sum is 8.
*/

#include <bits/stdc++.h>

using namespace std;

void solve(int i, int n, int target, vector<int> &arr, vector<int> v, set<vector<int>> &s) {
	if(i >= n) {
		if(target == 0) {
			s.insert(v);
		}

		return;
	}

	// consider the current element into the set;
	if(arr[i] <= target) {
		v.push_back(arr[i]);
		solve(i, n, target-arr[i], arr, v, s);
		v.pop_back();
	}


	// don't consider the current element into the set
	solve(i+1, n, target, arr, v, s);
}

vector<vector<int>> findAllUniqueSubsequences(vector<int> &arr, int n, int target) {
	set<vector<int>> s;

	vector<int>v;

	solve(0, n, target, arr, v, s);

	vector<vector<int>> res;
	for(vector<int> t : s)
		res.push_back(t);

	return res;
}

int main() {
	int n;
	cout << "Enter the size of the array : ";
	cin >> n;

	vector<int> arr(n);
	cout << "Enter the elements of the array : ";
	for(int i=0; i<n; i++)
		cin >> arr[i];


	int target;
	cout << "Enter the target sum : ";
	cin >> target;

	vector<vector<int>> res = findAllUniqueSubsequences(arr, n, target);

	return 0;
}