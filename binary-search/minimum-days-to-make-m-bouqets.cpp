/*
    You are given 'n' roses and you are also given an array 'arr' where 'arr[i]' denotes that the 'ith' rose will bloom on the 'arr[i]th' day.

    You can only pick already bloomed roses that are adjacent to make a bouquet. You are also told that you require exactly 'k' adjacent bloomed roses to make a single bouquet.
    
    Find the minimum number of days required to make at least 'm' bouquets each containing 'k' roses. Return -1 if it is not possible.
    
    Example :
    Input: n = 9,  arr = [ 1, 2, 1, 2, 7, 2, 2, 3, 1 ], k = 3, m = 2
    
    Output: 3. 
    
    Explanation: This is because on the 3rd day: all the roses with 'arr[i]' less than equal to 3 have already bloomed, this means every rose except the 5th rose has bloomed. Now we can form the first bouquet from the first three roses and the second bouquet from the last three roses.
*/


#include <bits/stdc++.h>

using namespace std;

bool canMake(vector<int> &arr, int days, int k, int m) {
    int noBou = 0;
    int noFlo = 0;

    for(int i=0; i<arr.size(); i++) {
        if(arr[i] <= days) {
            noFlo++;
        } else {
            noBou = noBou + (noFlo / k);
            noFlo = 0;
        }
    }
    
    if(noFlo != 0) {
        noBou = noBou + (noFlo/k);
    }

    return noBou >= m;
}

int roseGarden(vector<int> arr, int k, int m){
    int left = *min_element(arr.begin(), arr.end());
    int right = *max_element(arr.begin(), arr.end());

    int res = -1;

    while(left <= right) {
        int mid = left + ((right-left)>>1);
        
        cout << mid << endl;

        bool check = canMake(arr, mid, k, m);

        if(check) {
            res = mid;
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return res;
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
    cout << "Enter the number of flowers required to make boquet : ";
    cin >> k;
    
    int m;
    cout << "Enter the minimum number of boquets required : ";
    cin >> m;
    int res = roseGarden(arr, k, m);
    cout << res << endl;
    
    return 0;
}

/*
    Time Complexity - O(nlog(max(arr) - min(arr)))
    Space Complexity - O(1)
*/
