/*
    Q. You're given a sorted array 'a' of 'n' integers and an integer 'x'.
       Find the floor and ceiling of 'x' in 'a[0..n-1]'.


       Note:
       Floor of 'x' is the largest element in the array which is smaller than or equal to 'x'.
       Ceiling of 'x' is the smallest element in the array greater than or equal to 'x'.

    
    Example 1 :
        Input:
            6 8
            3 4 4 7 8 10

        Output : 8 8

        Explanation of sample input 1 :
        Since x = 8 is present in the array, it will be both floor and ceiling.

    Example 2:
        Input:
            6 2
            3 4 4 7 8 10


        Output: -1 3

        Explanation of sample input 2 :
        Since no number is less than or equal to x = 2 in the array, its floor does not exist. The ceiling will be 3.
*/


#include <bits/stdc++.h>

using namespace std;

int findFloor(vector<int> &arr, int n, int x){
    int l = 0, r = n-1;
    int res = -1;
    
    while(l <= r){
        int mid = l + (r-l)/2;
        
        if(arr[mid] > x){
            r = mid-1;
        } else {
            res = mid;
            l = mid + 1;
        }
    }
    
    if(res == -1)
    return -1;
    
    return arr[res];
}

int findCeil(vector<int> &arr, int n, int x) {
    int l = 0, r = n-1;
    int res = -1;
    
    while(l <= r){
        int mid = l + (r-l)/2;
        
        if(arr[mid] < x){
            l = mid + 1;
        } else {
            res = mid;
            r = mid -1;
        }
    }
    
    if(res == -1)
    return -1;
    
    return arr[res];
}



pair<int, int> getFloorAndCeil(vector<int> &arr, int n, int x) {
	// Write your code here.
    int floor = findFloor(arr, n, x);
    int ceil = findCeil(arr, n, x);
    
    return {floor, ceil};
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
    cout << "Enter the target to find the floor and ceil for : ";
    cin >> target;

    pair<int, int> result = getFloorAndCeil(arr, n, target);

    cout << "floor : " << result.first << " , " << "ceil : " << result.second << endl;
    return 0;
}

// Time complexity - O(logn)
// Space complexity - O(1)
