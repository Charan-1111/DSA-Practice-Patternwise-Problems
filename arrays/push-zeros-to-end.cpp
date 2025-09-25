/*
    Q. Given an unsorted array of integers, you have to move the array elements in a way such that all the zeroes are transferred to the end, 
       and all the non-zero elements are moved to the front. The non-zero elements must be ordered in their order of appearance.

       For example, if the input array is: [0, 1, -2, 3, 4, 0, 5, -27, 9, 0], then the output array must be: [1, -2, 3, 4, 5, -27, 9, 0, 0, 0].

       Expected Complexity: Try doing it in O(n) time complexity and O(1) space complexity. Here, ‘n’ is the size of the array.


    Example 1:
        Input : 2 0 4 1 3 0 28
        Output : 2 4 1 3 28 0 0

    Example 2:
        Input : 0 0 0 0 1
        Example :  1 0 0 0 0
*/

#include <bits/stdc++.h>

using namespace std;

void pushZerosAtEnd(vector<int> &arr) {
	int idx = 0;

	for(int i=0; i<arr.size(); i++) {
		if(arr[i] != 0) {
			swap(arr[i], arr[idx]);
			idx++;
		}
	}
}

int main() {
    int n;
    cout << "Enter the number of elements in the array : ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array in order : ";
    for(int i=0; i<n; i++)
    cin >> arr[i];

    pushZerosAtEnd(arr);

    return 0;
}


// Time complexity - O(n)
// Space complexity - O(1)
