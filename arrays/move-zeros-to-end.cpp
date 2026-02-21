/*
    Q. Given an unsorted array of integers, you have to move the array elements in a way such that all the zeroes are transferred to the end, and all the non-zero elements are moved to the front. The non-zero elements must be ordered in their order of appearance.

    For example, if the input array is: [0, 1, -2, 3, 4, 0, 5, -27, 9, 0], then the output array must be:
    
    [1, -2, 3, 4, 5, -27, 9, 0, 0, 0].
    
    Expected Complexity: Try doing it in O(n) time complexity and O(1) space complexity. Here, ‘n’ is the size of the array.
*/

#include <bits/stdc++.h>

using namespace std;

void pushZerosAtEnd(vector<int> &arr) {
	int idx = 0;

	for(int i=0; i<arr.size(); i++) {
		if(arr[i] != 0) {
			swap(arr[idx], arr[i]);
			idx++;
		}
	}
}

int main() {
    int n;
    cout << "Enter the number of elements in the array : ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter the elements of the array : ";
    for(int i=0; i<n; i++)
    cin >> arr[i];
    
    pushZerosAtEnd(arr);
    
    cout << "Array after modification : ";
    for(int elem : arr) 
    cout << elem << " ";
    
    cout << endl;
    return 0;
}

/*
    Time Complexity - O(n)
    Space Complexity - O(1)
*/
