/*
    Q. Given a sorted array arr[] and a number target, the task is to find the lower bound of the target in this given array. 
       The lower bound of a number is defined as the smallest index in the sorted array where the element is greater than or 
       equal to the given number.

       Note: If all the elements in the given array are smaller than the target, the lower bound will be the length of the 
       array. 


    Example 1:
        Input:  arr[] = [2, 3, 7, 10, 11, 11, 25], target = 9
        Output: 3
        Explanation: 3 is the smallest index in arr[] where element (arr[3] = 10) is greater than or equal to 9.

    Example 2:
        Input: arr[] = [2, 3, 7, 10, 11, 11, 25], target = 11
        Output: 4
        Explanation: 4 is the smallest index in arr[] where element (arr[4] = 11) is greater than or equal to 11.

    Example 3:
        Input: arr[] = [2, 3, 7, 10, 11, 11, 25], target = 100
        Output: 7
        Explanation: As no element in arr[] is greater than 100, return the length of array.
*/

#include <bits/stdc++.h>

using namespace std;

int lowerBound(vector<int> arr, int n, int x) {
	int l = 0;
	int r = n-1;

	int ans = -1;

	while(l <= r) {
		int mid = l + ((r-l)>>1);

		if(arr[mid] >= x) {
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
    cout << "Enter the target for which we need to find the lower bound : ";
    cin >> target;
    
    int result = lowerBound(arr, n, target);

    cout << "Lower bound index : " << result << endl;
    
    return 0;
}

// Time complexity - O(logn)
// Space complexity - O(1)
