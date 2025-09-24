/*
    Q. Given a sorted array, arr[] and a number target, you need to find the number of occurrences of target in arr[]. 

    Example 1:
        Input: arr[] = [1, 1, 2, 2, 2, 2, 3], target = 2
        Output: 4
        Explanation: target = 2 occurs 4 times in the given array so the output is 4.

    Example 2:
        Input: arr[] = [1, 1, 2, 2, 2, 2, 3], target = 4
        Output: 0
        Explanation: target = 4 is not present in the given array so the output is 0.

    Example 3:
        Input: arr[] = [8, 9, 10, 12, 12, 12], target = 12
        Output: 3
        Explanation: target = 12 occurs 3 times in the given array so the output is 3.
*/

#include <bits/stdc++h>

using namespace std;

int findFirstOccuracne(int l, int r, int target, vector<int> &arr) {
	int ans = -1;

	while(l <= r) {
		int mid = l + ((r-l)>>1);

		if(arr[mid] == target) {
			ans = mid;
			r = mid - 1;
		} else if(arr[mid] < target) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}

	return ans;
}

int findLastOccurance(int l, int r, int target, vector<int> &arr) {
	int ans = -1;

	while(l <= r) {
		int mid = l + ((r-l)>>1);

		if(arr[mid] == target) {
			ans = mid;
			l = mid + 1;
		} else if(arr[mid] < target) {
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}

	return ans;
}

int count(vector<int>& arr, int n, int x) {
	int l = 0, r = n-1;
	int firstOccurance = findFirstOccuracne(l, r, x, arr);
	int lastOccurance = findLastOccurance(l, r, x, arr);



	return firstOccurance == -1 && lastOccurance == -1 ? 0 : lastOccurance - firstOccurance + 1;
}


int main() {
    int n;
    cout << "Enter the number of elements in the array : ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array in order : ";
    for(int i=0; i<n; i++)
    cin >> arr[i];

    int target;
    cout << "Enter the target to find the number of occurances : ";
    cin >> target;

    int result = count(arr, n, target);

    cout << "Number of occurances of the given target is : " << result << endl;

    return 0;
}

// Time complexity - O(logn)
// Space complexity - O(1)
