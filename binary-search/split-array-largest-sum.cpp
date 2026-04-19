/*
    You’re given an array 'arr' of size 'n' and an integer 'k'.

    Your task is to split 'arr' into 'k' sub-arrays such that the maximum sum achieved from the 'k' subarrays formed must be the minimum possible.
    
    A subarray is a contiguous part of the array.
    
    Return the minimum possible value of the maximum sum obtained after splitting the array into 'k' partitions.
    
    
    
    Example:
    Input: ‘arr’ = [1, 1, 2] and ‘k’ = 2 
    
    Output: 2
    
    Explanation: If we want to make two subarrays, there are two possibilities: [[1], [1, 2]] and [[1, 1], [2]]. We can see that the maximum sum of any subarray is minimized in the second case. Hence, the answer is 2, which is the maximum sum of any subarray in [[1, 1], [2]].
*/

#include <bits/stdc++.h>

using namespace std;

int split(vector<int> &arr, int val) {
    int noOfSubArrays = 1;
    int sum = 0;

    for(int elem : arr) {
        if(sum + elem > val) {
            noOfSubArrays++;
            sum = elem;
        } else {
            sum += elem;
        }
    }

    return noOfSubArrays;
}

int splitArray(vector<int> &arr, int k) {
    int left = *max_element(arr.begin(), arr.end());
    int right = accumulate(arr.begin(), arr.end(), 0);

    int res;
    while(left <= right) {
        int mid = left + ((right - left) >> 1);

        int noOfSubArrays = split(arr, mid);

        if(noOfSubArrays == k) {
            res = mid;
            right = mid - 1;
        } else if(noOfSubArrays < k) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return left;
}

int main() {
    int n;
    cout << "Enter the number of element of the array : ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter the elements of the array : ";
    for(int i=0; i<n; i++)
    cin >> arr[i];
    
    int m;
    cout << "Enter the number of sub arrays : ";
    cin >> m;
    
    int res = splitArray(arr, m);
    
    cout << "res : " << res << endl;
    return 0;
}

/*
    Time Complexity - O(logn)
    Space Complexity -O(1)
*/
