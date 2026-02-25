/*
    Q. You are given an array 'a' of size 'n' and an integer 'k'.
       Find the length of the longest subarray of 'a' whose sum is equal to 'k'.



    Example :
    Input: ‘n’ = 7 ‘k’ = 3
    ‘a’ = [1, 2, 3, 1, 1, 1, 1]
    
    Output: 3
    
    Explanation: Subarrays whose sum = ‘3’ are:
    
    [1, 2], [3], [1, 1, 1] and [1, 1, 1]
    
    Here, the length of the longest subarray is 3, which is our final answer.
*/

#include <bits/stdc++.h>

using namespace std

int longestSubarrayWithSumK(vector<int> a, long long k) {
    unordered_map<int, int> mp;

    mp[0] = -1;

    int sum = 0, len = 0;

    for(int i=0; i<a.size(); i++) {
        sum = sum + a[i];

        if(mp.find(sum-k) != mp.end()) {
            len = max(len, i-mp[sum-k]);
        }

        if(mp.find(sum) == mp.end()) {
            mp[sum] = i;
        }
    }

    return len;
}

int main() {
    int n;
    cout << "Enter the length of the array : ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter the numbers : ";
    for(int i=0; i<n; i++)
    cin >> arr[i];
    
    int k;
    cout << "Enter the sum : ";
    cin >> k;
    
    int maxLen = longestSubarrayWithSumK(arr, k);
    
    
    cout << "Maximum length subarray with given sum : " << maxLen << endl;
    
    return 0;
}

/*
    Time Complexity - O(n)
    Space Complexity - O(n)
*/
