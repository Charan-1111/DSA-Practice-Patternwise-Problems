/*
    Q. Given an array of Intervals arr[][], where arr[i] = [starti, endi]. The task is to merge all of the overlapping Intervals.
    
    Example 1:
        Input: arr[][] = [[1, 3], [2, 4], [6, 8], [9, 10]]
        Output: [[1, 4], [6, 8], [9, 10]]
        Explanation: In the given intervals we have only two overlapping intervals here, [1, 3] and [2, 4] which on merging will become [1, 4]. Therefore we will return [[1, 4], [6, 8], [9, 10]].
        
    Example 2:
        Input: arr[][] = [[6, 8], [1, 9], [2, 4], [4, 7]]
        Output: [[1, 9]]
        Explanation: In the given intervals all the intervals overlap with the interval [1, 9]. Therefore we will return [1, 9].
*/

#include <bits/stdc++.h>

using namespace std;

vector<vector<int>> mergeOverlappingIntervals(vector<vector<int>> &arr){
	vector<vector<int>> res;

	int start = arr[0][0];
	int end = arr[0][1];

	for(int i=1; i<arr.size(); i++) {
		if(arr[i][0] <= end) {
			end = max(end, arr[i][1]);
		} else {
			res.push_back({start, end});
			start = arr[i][0];
			end = arr[i][1];
		}
	}

	res.push_back({start, end});
	return res;
}

int main() {
    int n;
    cout << "Enter the number of intervals : ";
    cin >> n;
    
    vector<vector<int>> intervals(n, vector<int>(2));
    cout << "Enter the start and end time of the each interval : ";
    for(int i=0; i<n; i++) {
        cin >> arr[i][0] >> arr[i][1];
    }
    
    vector<vector<int>> mergedIntervals = mergeOverlappingIntervals(intervals);
    
    return 0;
}

// Time complexity - O(n)
// Space complexity - O(n)
