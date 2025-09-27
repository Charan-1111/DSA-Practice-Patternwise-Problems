/*
    Q. Given a sequence of numbers. Find all leaders in sequence. An element is a leader if it is strictly greater than all the elements on its right side.

        Note:
        1. Rightmost element is always a leader.
        2. The order of elements in the return sequence must be the same as the given sequence
        
        
    Example 1:
        Input : 6 7 4 2 5 3
        Output : 7 5 3
        
    Example 2:
        Input : 11 10 9 8
        Output : 11 10 9 8
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> findLeaders(vector<int> &elements, int n) {
    vector<int> res;
    int maxVal = elements[n-1];

    res.push_back(maxVal);

    for(int i=n-2; i>=0; i--) {
        if(elements[i] > maxVal) {
            maxVal = elements[i];
            res.push_back(maxVal);
        }
    }

    reverse(res.begin(), res.end());

    return res;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array : ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter the elements of the array in order : ";
    for(int i=0; i<n; i++)
    cin >> arr[i];
    
    vector<int> res = findLeaders(arr, n);
    
    cout << "Leaders are : ";
    for(int elem : res)
    cout << elem << " ";
    cout << endl;
    
    return 0;
}

// Time complexity - O(n)
// Space complexity - O(n)
