/*
    You are given a strictly increasing array 'vec' and a positive integer 'k'.
    
    Find the 'kth' positive integer missing from 'vec'.
    
    
    Example :
    Input: vec = [2,4,5,7] , k = 3
    
    Output: 6
    
    Explanation : 
    In the given example, first missing positive integer is 1 second missing positive integer is 3, and the third missing positive integer is 6.
    Hence the answer is 6. 
*/


#include <bits/stdc++.h>

using namespace std;

int missingK(vector < int > vec, int n, int k) {
    int left = 0;
    int right = n-1;

    while(left <= right) {
        int mid = left + ((right - left) >> 1);

        int miss = vec[mid] - mid - 1;

        if(k > miss) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    return k + right + 1;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array : ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter the elements of the array : ";
    for(int i=0; i<n; i++)
    cin >> arr[i];
    
    int k;
    cout << "Enter a number to find the missing number : ";
    cin >> k;
    
    int missingNumber = missingK(arr, n, k);
    
    cout << "missing number : " << missingNumber << endl;
    
    return 0;
}

/*
    Time Complexity - O(nlogn)
    Space Complexity - O(1)
*/
