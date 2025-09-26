/*
    Q. Given an array arr[]. Find the majority element in the array. If no majority element exists, return -1.
       Note: A majority element in an array is an element that appears strictly more than arr.size()/2 times in the array.

    Example 1:
        Input: arr[] = [1, 1, 2, 1, 3, 5, 1]
        Output: 1
        Explanation: Since, 1 is present more than 7/2 times, so it is the majority element.

    Example 2:
        Input: arr[] = [7]
        Output: 7
        Explanation: Since, 7 is single element and present more than 1/2 times, so it is the majority element.

    Example 3:
        Input: arr[] = [2, 13]
        Output: -1
        Explanation: Since, no element is present more than 2/2 times, so there is no majority element.
*/

#include <bits/stdc++.h>

using namespace std;

int findMajorityElement(int arr[], int n) {
	int cnt = 1;
	int elem = arr[0];

	for(int i=1; i<n; i++) {
		if(arr[i] != elem) {
			cnt--;
			if(cnt == 0) {
				elem = arr[i];
			}
		}
		cnt++;
	}

	int tot = 0;
	for(int i=0; i<n; i++) {
		if(arr[i] == elem) tot++;
	}

	return tot > (n>>1) ? elem : -1; 
}

int main() {
    int n;
    cout << "Enter the number of elements in the array : ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array in order : " ;
    for(int i=0; i<n; i++)
    cin >> arr[i];

    int result = findMajorityElement(arr, n);

    cout << "Majority element in the array : " << result << endl;

    return 0;
}

// Time complexity - O(n)
// Space complexity - O(1)
