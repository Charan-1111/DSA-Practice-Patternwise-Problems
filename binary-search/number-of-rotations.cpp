/*
    You are given an array 'arr' having 'n' distinct integers sorted in ascending order. The array is right rotated 'r' times

    Find the minimum value of 'r'.
    
    Right rotating an array means shifting the element at 'ith' index to (‘i+1') mod 'n' index, for all 'i' from 0 to ‘n-1'.
    
    Example:
    Input: 'n' = 5 , ‘arr’ = [3, 4, 5, 1, 2]
    
    Output: 3 
    
    Explanation:
    If we rotate the array [1 ,2, 3, 4, 5] right '3' times then we will get the 'arr'. Thus 'r' = 3.
*/


#include <bits/stdc++.h>

using namespace std;

int findKRotation(vector<int> &arr){
    int l = 0;
    int r = arr.size() - 1;

    int res = INT_MAX;
    int idx = -1;

    while(l <= r) {
        int mid = l + ((r-l)>>1);

        if(arr[l] <= arr[mid]) {
            // left half is sorted
            if(arr[l] <= res) {
                res = arr[l];
                idx = l;
            }
            l = mid + 1;
        } else {
            if(arr[mid] <= res) {
                res = arr[mid];
                idx = mid;
            }
            r = mid - 1;
        }
    }

    return idx;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array : ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter the elements of the array : ";
    for(int i=0; i<n; i++)
    cin >> arr[i];
    
    int numRotations = findKRotation(arr);
    
    return 0;
}

/*
    Time Complexity - O(logn)
    Space Complexity - O(1)
*/
