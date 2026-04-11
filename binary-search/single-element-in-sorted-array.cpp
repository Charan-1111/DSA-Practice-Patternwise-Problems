/*
    You are given a sorted array ‘arr’ of ‘n’ numbers such that every number occurred twice in the array except one, which appears only once.

    Return the number that appears once.
    
    Example:
    Input: 'arr' = [1,1,2,2,4,5,5]
    
    Output: 4 
    
    Explanation: 
    Number 4 only appears once the array.
    
    Note :
    Exactly one number in the array 'arr' appears once.
*/

#include <bits/stdc++.h>

using namespace std;

int singleNonDuplicate(vector<int>& arr){
	int l = 0, r = arr.size()-1;
    int n = arr.size();

    int res = -1;

    while(l <= r) {
        int mid = l + ((r-l)>>1);

        res = mid;

        if(arr[mid] != arr[mid-1] && arr[mid] != arr[mid+1]) return arr[mid];

        if(mid & 1) {
            // odd index
            if(arr[mid] == arr[mid + 1] && mid < n) {
                r = mid - 1;
            } else if (arr[mid] == arr[mid - 1] && mid > 0) {
                l = mid + 1;
            }
        } else {
            if(arr[mid] == arr[mid + 1] && mid < n) {
                l = mid + 2;
            } else if (arr[mid] == arr[mid - 1] && mid > 0) {
                r = mid - 2;
            }
        }
    }

    return arr[res];
}

int main() {
    int n;
    cout << "Enter the number of entries in the sorted array : ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter the elements of the sorted array : ";
    for(int i=0; i<n; i++)
    cin >> arr[i];
    
    int singleElement = singleNonDuplicate(arr);
    
    cout << "Single Element is : " << singleElement << endl;
    
    return 0;
}

/*
    Time Complexity - O(logn)
    Space Complexity - O(1)
*/
