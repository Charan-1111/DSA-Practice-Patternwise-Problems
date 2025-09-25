/*
    Q. You are given a sorted integer array 'arr' of size 'n'.
       You need to remove the duplicates from the array such that each element appears only once.
       Return the length of this new array.
       
       Note: Do not allocate extra space for another array. You need to do this by modifying the given input array 
       in place with O(1) extra memory. 


    Example 1:
        Input : 1 2 2 3 3 3 4 4 5 5 
        Output : 5

    Example 2:
        Input :  1 1 2 3 3 4 5 5 5 
        Output : 5
*/

#include <bits/stdc++.h>

using namespace std;

int removeDuplicates(vector<int> &arr, int n) {
	int idx = 1;
	int last_elem = arr[0];

	for(int i=1; i<n; i++){
		if(arr[i] != last_elem) {
			last_elem = arr[i];
			swap(arr[idx], arr[i]);
			idx++;
		}
	}
	return idx;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array : ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements in the array in order : ";
    for(int i=0; i<n; i++)
    cin >> arr[i];

    int result = removeDuplicates(arr, n);

    cout << "Final length of the array after removal : " << result << endl;

    return 0;
}
