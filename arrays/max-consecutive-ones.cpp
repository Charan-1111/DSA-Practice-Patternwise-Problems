/*
    Q. You are given an array ‘ARR’ of length ‘N’ consisting of only ‘0’s and ‘1’s. Your task is to determine the maximum 
       length of the consecutive number of 1’s.

    Example 1:
        Input : 0 1 1 0 0 1 1 1
        Output : 3

    Example 2:
        Input : 0 1 1 0
        Output : 2
*/

#include <bits/stdc++.h>

using namespace std;

int consecutiveOnes(vector<int>& arr){
    int cnt = 0;

    int maxCnt = 0;

    for(int elem : arr) {
        if(elem == 1) {
            cnt++;
            maxCnt = max(maxCnt, cnt);
        } else {
            cnt = 0;
        }
    }
    maxCnt = max(maxCnt, cnt);

    return maxCnt;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array : ";
    cin >> n;

    vector<int> arr(n);
    cout << "Enter the elements of the array in order : ";
    for(int i=0; i<n; i++)
    cin >> arr[i];

    int result = consecutiveOnes(arr);

    cout << "Maximum consecutive 1's : " << result << endl;

    return 0;
}

// Time complexity - O(n)
// Space complexity - O(1)
