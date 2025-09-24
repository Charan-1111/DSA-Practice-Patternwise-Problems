/*
    Q. Given a sorted array arr[] (0-index based) of distinct integers and an integer k, find the index of k if it is present in the arr[]. 
    If not, return the index where k should be inserted to maintain the sorted order.


    Example 1:
        Input: arr[] = [1, 3, 5, 6], k = 5
        Output: 2
        Explanation: Since 5 is found at index 2 as arr[2] = 5, the output is 2.

    Example 2:
        Input: arr[] = [1, 3, 5, 6], k = 2
        Output: 1
        Explanation: The element 2 is not present in the array, but inserting it at index 1 will maintain the sorted order.

    Example 3:
        Input: arr[] = [2, 6, 7, 10, 14], k = 15
        Output: 5
        Explanation: The element 15 is not present in the array, but inserting it after index 4 will maintain the sorted order.
*/

#include <bits/stdc++.h>

using namespace std;

int searchInsert(vector<int>& arr, int m)
{
	int l = 0;
	int r = arr.size()-1;

	int ans = -1;

	while(l <= r) {
		int mid = l + ((r-l)>>1);

		if(arr[mid] == m) {
			return mid;
		} else if(arr[mid] < m) {
			ans = mid;
			l = mid + 1;
		} else {
			r = mid - 1;
		}
	}

	return ans + 1;
}

int main() {
    int n;
    cout << "Enter the size of the array : ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array in order : ";
    for(int i=0; i<n; i++)
    cin >> arr[i];

    int target;
    cout << "Enter the target to find the insertion position : ";
    cin >> target;

    int result = searchInsert(arr, target);

    cout << "Insertion position is : " << result << endl;

    return 0;
}
