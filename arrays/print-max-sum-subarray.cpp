/*
    Q. Given an array arr[], the task is to print the subarray having maximum sum.
    
    Example 1:
        Input : 2, 3, -8, 7, -1, 2, 3
        Output : 7, -1, 2, 3
*/


#include <bits/stdc++.h>

using namespace std;

vector<int> maximumsumSubarray(vector<int> &arr)
{
    int sum = 0;
    int maxSum = INT_MIN;

    vector<int> res;
    vector<int> temp;

    for(int elem : arr) {
        sum += elem;

        if(sum > maxSum) {
            maxSum = sum;
            temp.push_back(elem);
            res = temp;
        } else {
            temp = {};
        }

        if(sum < 0) {
            sum = 0;
            temp = {};
        }
    }

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
    
    vector<int> res = maximumsumSubarray(arr);
    
    for(int elem : res) {
        cout << elem << " ";
    }
    cout << endl;
    return 0;
}

// Time complexity - O(n)
// Space complexity - O(1)
