/*
    Q. Given an array ‘arr’ of size ‘n’ find the largest element in the array.
    
    Example:

    Input: 'n' = 5, 'arr' = [1, 2, 3, 4, 5]
    
    Output: 5
    
    Explanation: From the array {1, 2, 3, 4, 5}, the largest element is 5.
*/

#include <bits/stdc++.h>

using namespace std;

int findLargest(vector<int> &arr) {
    int res = INT_MIN;
    
    for(int elem : arr) {
        res = max(res, elem);
    }
    
    return res;
}

int main() {
    int n;
    cout << "Enter the length of the array : ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter the elements : ";
    for(int i=0; i<n; i++)
    cin >> arr[i];
    
    int largest = findLargest(arr);
    
    cout << "Largest among them : " << largest << endl;
    return 0;
}

/*
    Time Complexity :- O(n)
    Space Complexity - O(1)
*/
