/*
    You are given an array 'arr' of size 'n' having unique elements that has been sorted in ascending order and rotated between 1 and 'n' times which is unknown.

    The rotation involves shifting every element to the right, with the last element moving to the first position. For example, if 'arr' = [1, 2, 3, 4] was rotated one time, it would become [4, 1, 2, 3].
    
    Your task is to find the minimum number in this array.
    
    Note :
    All the elements in the array are distinct. 
    
    Example :
    Input: arr = [3,4,5,1,2]
    
    Output: 1
    
    Explanation: The original array was [1,2,3,4,5] and it was rotated 3 times.
*/


#include <bits/stdc++.h>

using namespace std;

int findMin(vector<int>& arr){
	int l = 0;
	int r = arr.size() - 1;

	int res = INT_MAX;

	while(l <= r) {
		int mid = l + ((r-l)>>1);

		if(arr[l] <= arr[mid]) {
			// left half is sorted
			res = min(res, arr[l]);
			l = mid + 1;
		} else {
			res = min(res, arr[mid]);
			r = mid - 1;
		}
	}

	return res;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array : ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter the elements of the array : ";
    for(int i=0; i<n; i++)
    cin >> arr[i];
    
    int minimumElem = findMin(arr);
    
    return 0;
}

/*
    Time Complexity - O(logn)
    Space Complexity - O(1)
*/
