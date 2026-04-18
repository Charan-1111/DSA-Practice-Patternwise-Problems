/*
    You are given an array 'arr' consisting of 'n' integers which denote the position of a stall.

    You are also given an integer 'k' which denotes the number of aggressive cows.
    
    You are given the task of assigning stalls to 'k' cows such that the minimum distance between any two of them is the maximum possible.
    
    Print the maximum possible minimum distance.
    
    Example:
    Input: 'n' = 3, 'k' = 2 and 'arr' = {1, 2, 3}
    
    Output: 2
    
    Explanation: The maximum possible minimum distance will be 2 when 2 cows are placed at positions {1, 3}. Here distance between cows is 2.
*/

#include<bits/stdc++.h>

using namespace std;

bool isPossible(vector<int> &arr, int k, int minDist) {
    int cowCnt = 1;

    int idx = 0;

    for(int i=1; i<arr.size(); i++) {
        if(arr[i] - arr[idx] >= minDist) {
            cowCnt++;
            idx = i;
        }
    }

    return cowCnt >= k;
}


int aggressiveCows(vector<int> &stalls, int k){
    sort(stalls.begin(), stalls.end());

    int left = INT_MAX;
    for(int i=1; i<stalls.size(); i++) {
        left = min(left, stalls[i]-stalls[i-1]);
    }

    int right = stalls[stalls.size()-1] - stalls[0];


    int res;


    while(left <= right) {
        int mid = left + ((right - left) >> 1);

        bool check = isPossible(stalls, k, mid);

        if(check) {
            res = mid;
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return res;
}


int main() {
    int n;
    cout << "Enter the number of stalls : ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter the stalls : ";
    for(int i=0; i<n; i++)
    cin >> arr[i];
    
    int k;
    cout << "Enter the number of cows : ";
    cin >> k;
    
    int minDist = aggressiveCows(arr, k);
    
    cout << "Maximum possible minimum distance : " << minDist << endl;
    
    return 0;
}

/*
    Time Complexity - O(nlogn + nlogn)
    Space Complexity - O(1)
*/
