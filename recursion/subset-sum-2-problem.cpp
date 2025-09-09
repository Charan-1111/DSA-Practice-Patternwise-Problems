/*
	Q. Given an array arr of size n that may contain duplicates. Your task is to return all possible subsets. Return only unique subsets and they can be in any order

	   Note : The individual subsets should be sorted.


	Example:
		Input: 
		nums = [1,2,2] 
		Output: 
		[[],[1],[1,2],[1,2,2],[2],[2,2]]
		Explanation: 
		We can have subsets ranging from length 0 to 3. which are listed above. Also the subset [1,2] appears twice but is printed only once as we require only unique subsets.
*/

// Note : an empty subset is always a subset 

#include <bits/stdc++.h>

using namespace std;

void solve(int i, int n, vector<int> &arr, vector<int> temp, set<vector<int>> &s) {
	if(i >= n) {
		s.insert(temp);
		return;
	}


	// consider the current element into the set
	temp.push_back(arr[i]);
	solve(i+1, n, arr, temp, s);
	temp.pop_back();

	// don't consider the current element into the set

	solve(i+1, n, arr, temp, s);
}

vector<vector<int>> findAllUniqueSubsets(vector<int> &arr, int n) {
	// sorting the array, as we want the individual subsets to be in sorted order
	sort(arr.begin(), arr.end()); // this take O(nlogn) time complexity


	set<vector<int>> s;
	vector<int> temp;

	solve(0, n, arr, temp, s);

	vector<vector<int>> res;
	for(vector<int> x : s) {
		res.push_back(x);
	}

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

	vector<vector<int>> subsets = findAllUniqueSubsets(arr, n);
	return 0;
}

// Time complexity - O(nlogn + 2^n)
// Space comlexity - O(2^n + n^2)