/*
    Q. Given an array arr[] of integers and another integer target. Determine if there exist two distinct indices such that 
       the sum of their elements is equal to the target.

    Example 1:
        Input: arr[] = [0, -1, 2, -3, 1], target = -2
        Output: true
        Explanation: arr[3] + arr[4] = -3 + 1 = -2

    Example 2:
        Input: arr[] = [1, -2, 1, 0, 5], target = 0
        Output: false
        Explanation: None of the pair makes a sum of 0

    Example 3:
        Input: arr[] = [11], target = 11
        Output: false
        Explanation: No pair is possible as only one element is present in arr[]
*/

#include <bits/stdc++.h>

using namespace std;

bool twoSum(vector<int>& arr, int target) {
    sort(arr.begin(), arr.end());
    int l = 0, r = arr.size()-1;
    
    while(l <= r) {
        int sum = arr[l] + arr[r];
        
        if(sum == target && l != r) {
            return true;
        } else if(sum < target) {
            l++;
        } else {
            r--;
        }
    }
    
    return false;
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
    cout << "Enter the target to find : ";
    cin >> target;

    bool result = twoSum(arr, target);

    cout << "result : " << result << endl;
    return 0;
}

// Time complexity - O(nlogn + n)
// Space complexity - O(1)
