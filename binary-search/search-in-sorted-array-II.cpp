/*
    You are given a rotated sorted array 'a' of length 'n' and a 'key'. You need to determine if the 'key' exists in the array 'a'.

    The given sorted array is rotated from an unknown index 'x'. Such that after rotation the array became [a[x], a[x+1]...., a[n-1], a[1]..., a[x-1]], (0-based indexing). For example, if the array is [1, 2, 3, 4, 5] and x = 2 then the rotated array will be [3, 4, 5, 1, 2, 3].
    
    Return True if the 'key' is found in 'a'. Otherwise, return False.

    Note: Array ‘a’ may contain duplicate elements.
  
    Example:
    
    Input: a = [6, 10, 1, 3, 5], key = 3
    
    Output: True
    
    Explanation: The array 'a' contains the 'key' = 3, so we return True.
*/

#include <bits/stdc++.h>

using namespace std;

bool searchInARotatedSortedArrayII(vector<int>&arr, int key) {
    int l = 0, r = arr.size()-1;

    while(l <= r) {
        int mid = l + ((r-l)>>1);

        if(arr[mid] == key) return true;

        if(arr[l] == arr[mid] && arr[mid] == arr[r]) {
            l++;
            r--;
        } else if(arr[l] <= arr[mid]) {
            if(arr[l] <= key && key <= arr[mid]) {
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        } else {
            if(arr[mid] <= key && key <= arr[r]) {
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
    }

    return false;
}


int main() {
    int n;
    cout << "Enter the number of elements in the array : ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter the elements of the array : ";
    for(int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    int key;
    cout << "Enter the key to check : ";
    cin >> key;
    
    cout << "Does key present in the given array : " << searchInARotatedSortedArrayII(arr, key) << endl;
    return 0;
}

/*
    Time Complexity - O(logn)
    Space Complexity - O(1)
*/
