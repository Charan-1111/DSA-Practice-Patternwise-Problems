/*
    Q. You are given a sorted array 'arr' of positive integers of size 'n'.
    
    It contains each number exactly twice except for one number, which occurs exactly once.

    Find the number that occurs exactly once.

    Example :
    Input: ‘arr’ = {1, 1, 2, 3, 3, 4, 4}.
    
    Output: 2
    
    Explanation: 1, 3, and 4 occur exactly twice. 2 occurs exactly once. Hence the answer is 2.
*/

#include <bits/stdc++.h>

using namespace std;

int getSingleElement(vector<int> &arr){
	int val = 0;
	for(int elem : arr){
		val = val ^ elem;
	}
	return val;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array : ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter the elements of the array : ";
    for(int i=0; i<n; i++)
    cin >> arr[i];
    
    int singleElem = getSingleElement(arr);
    cout << "Single Element is : " << singleElem << endl;
    return 0;
}

/*
    Time Complexity - O(n)
    Space Complexity - O(1)
*/
