/*
    You are the owner of a Shipment company. You use conveyor belts to ship packages from one port to another. The packages must be shipped within 'd' days.

    The weights of the packages are given in an array 'weights'. The packages are loaded on the conveyor belts every day in the same order as they appear in the array. The loaded weights must not exceed the maximum weight capacity of the ship.
    
    Find out the least-weight capacity so that you can ship all the packages within 'd' days.
    
    Sample Input 1:
        8 5
        5 4 5 2 3 4 5 6
    Sample Output 1:
        9
        Explanation for Sample Input 1:
        In the test case, the given weights are [5,4,5,2,3,4,5,6] and these are needed to be shipped in 5 days. We can divide these weights in the following manner:
        Day         Weights            Total
        1        -   5, 4          -    9
        2        -   5, 2          -    7
        3        -   3, 4          -    7
        4        -   5             -    5
        5        -   6             -    6
        The least weight capacity needed is 9, which is the total amount of weight that needs to be taken on Day 1.
    Sample Input 2:
        10 1
        1 2 3 4 5 6 7 8 9 10
    Sample Output 2:
        55
*/


#include <bits/stdc++.h>

using namespace std;

bool canLoad(vector<int> &arr, int weight, int d) {
    int days = 0;

    int totalWeight = 0;

    for(int elem : arr) {
        if(totalWeight + elem > weight) {
            days++;
            totalWeight = elem;
        } else {
            totalWeight += elem;
        }
    }

    if(totalWeight <= weight)
    days++;

    return days <= d;
}

int leastWeightCapacity(vector<int> &weights, int d){
    int left = *max_element(weights.begin(), weights.end());
    int right = accumulate(weights.begin(), weights.end(), 0);

    int res;

    while(left <= right) {
        int mid = left + ((right - left) >> 1);

        bool check = canLoad(weights, mid, d);

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
    cout << "Enter the weights : ";
    for(int i=0; i<n; i++)
    cin >> arr[i];
    
    int limit;
    cout << "Enter the days : ";
    cin >> limit;
    
    int res = roseGarden(arr, limit);
    cout << res << endl;
    
    return 0;
}

/*
    Time Complexity - O(nlog(max(arr)))
    Space Complexity - O(1)
*/
