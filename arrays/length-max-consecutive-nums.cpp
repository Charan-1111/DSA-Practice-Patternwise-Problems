/*
    Q. Given an array arr[] of non-negative integers. Find the length of the longest sub-sequence such that elements in the subsequence are consecutive integers, the consecutive numbers can be in any order.
    
    Example 1:
        Input : 2 6 1 9 4 5 3
        Output : 6
        
    Example 2:
        Input : 1 9 3 10 4 20 3
        Output : 4
*/

#include <bits/stdc++.h>

using namespace std;

int longestConsecutive(vector<int>& arr) {
    set<int> s{arr.begin(), arr.end()};
      
    int cnt = 0;
    int prev_val = -1;
    
    int max_cnt = INT_MIN;
    
    for(auto x : s){
        if(prev_val == -1){
            cnt = 1;
            prev_val = x;
        }
        
        
        else{
            if(x - prev_val == 1){
                cnt++;
                prev_val = x;
            }
            else{
                max_cnt = max(max_cnt, cnt);
                cnt = 1;
                prev_val = x;
            }
        }
    }
    
    
    max_cnt = max(max_cnt, cnt);
    
    return max_cnt;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array : ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter the elements of the array in order : ";
    for(int i=0; i<n; i++)
    cin >> arr[i];
    
    int result = longestConsecutive(arr);
    
    cout << "Maximum length of consecutive numbers in the array : " << result << endl;
    return 0;
}

// Time complexity - O(n)
// Space complexity - O(n)
