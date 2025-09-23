/*
    Q. Given a sorted array arr[] and a number target, the task is to find the upper bound of the target in this given array.
       The upper bound of a number is defined as the smallest index in the sorted array where the element is greater than the 
       given number.

       Note: If all the elements in the given array are smaller than or equal to the target, the upper bound will be the 
       length of the array.

    
    Example 1:
        Input: arr[] = [2, 3, 7, 10, 11, 11, 25], target = 9
        Output: 3
        Explanation: 3 is the smallest index in arr[], at which element (arr[3] = 10) is larger than 9.

    Example 2:
        Input: arr[] = [2, 3, 7, 10, 11, 11, 25], target = 11
        Output: 6
        Explanation: 6 is the smallest index in arr[], at which element (arr[6] = 25) is larger than 11.

    Example 3:
        Input: arr[] = [2, 3, 7, 10, 11, 11, 25], target = 100
        Output: 7
        Explanation: As no element in arr[] is greater than 100, return the length of array.
*/

#include <bits/stdc++.h>

using namespace std;

int upperBound(vector<int> &arr, int x, int n){
	int l = 0;
	int r = n-1;

	int ans = -1;

	while(l <= r) {
		int mid = l + ((r-l)>>1);

		if(arr[mid] > x) {
			ans = mid;
			r = mid - 1;
		} else {
			l = mid + 1;
		}
	}

	return ans != -1 ? ans : n;
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
    cout << "Enter the target for which we need to find the upper bound : ";
    cin >> target;

    int result = upperBound(arr, target, n);

    cout << "Upper bound of the given element is : " << result << endl;

    return 0;
}

// Time complexity - O(logn)
// Space complexity - O(1)
