/*
    Q. Given an array arr[]. Rotate the array to the left (counter-clockwise direction) by d steps, where d is a positive 
       integer. Do the mentioned change in the array in place.
       
       Note: Consider the array as circular.

    
    Example 1:
        Input: arr[] = [1, 2, 3, 4, 5], d = 2
        Output: [3, 4, 5, 1, 2]
        Explanation: when rotated by 2 elements, it becomes 3 4 5 1 2.

    Example 2:
        Input: arr[] = [2, 4, 6, 8, 10, 12, 14, 16, 18, 20], d = 3
        Output: [8, 10, 12, 14, 16, 18, 20, 2, 4, 6]
        Explanation: when rotated by 3 elements, it becomes 8 10 12 14 16 18 20 2 4 6.

    Example 3:
        Input: arr[] = [7, 3, 9, 1], d = 9
        Output: [3, 9, 1, 7]
        Explanation: when we rotate 9 times, we'll get 3 9 1 7 as resultant array.
*/

#include <bits/stdc++.h>

using namespace std;

void rotate(vector<int> &arr, int n, int d) {
    reverse(arr.begin(), arr.begin()+d);
    reverse(arr.begin()+d, arr.end());
    reverse(arr.begin(), arr.end());
}

int main() {
    int n;
    cout << "Enter the number of elements in the array : ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array in order : ";
    for(int i=0; i<n; i++)
    cin >> arr[i];

    int d;
    cout << "Enter the number of steps to rotate : ";
    cin >> d;

    rotate(arr, n, d);

    return 0;
}

// Time complexity - O(n)
// Space complexity - O(1)
