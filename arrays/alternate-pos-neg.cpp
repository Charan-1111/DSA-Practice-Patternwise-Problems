/*
    Q. You are given an array ‘arr’ that contains an equal number of positive and negative elements. Rearrange the given array such that positive and negative numbers are arranged alternatively. Also, the respective relative order of positive and negative should be maintained.
    
    Example 1:
        Input : 1 2 3 -1 -2 -3
        Output : 1 -1 2 -2 3 -3 
        
    Example 2:
        Input : 1 -10 5 -1 2 -3 0 -2
        Output : 1 -10 5 -1 2 -3 0 -2
*/

#include <bits/stdc++.h>

using namespace std;

void posAndNeg(vector<int> &arr)
{
    vector<int> pos, neg;

    for(int elem : arr){
        if(elem >= 0) {
            pos.push_back(elem);
        } else {
            neg.push_back(elem);
        }
    }

    int i=0;
    int n_idx = 0, p_idx = 0;

    while(i < arr.size()) {
        if(i & 1) {
            arr[i] = neg[n_idx];
            n_idx++;
        } else {
            arr[i] = pos[p_idx];
            p_idx++;
        }

        i++;
    }
    
}

int main() {
    int n;
    cout << "Enter the number of elements in the array : ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter the elements of the array in order : ";
    for(int i=0; i<n; i++)
    cin >> arr[i];
    
    posAndNeg(arr);
    
    return 0;
}

// Time complexity - O(n + n)
// Space complexity - O(n)
