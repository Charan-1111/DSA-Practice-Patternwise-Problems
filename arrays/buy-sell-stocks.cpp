/*
    Q. You are given an array/list 'prices' where the elements of the array represent the prices of the stock as they were yesterday and indices of the array represent minutes. Your task is to find and return the maximum profit you can make by buying and selling the stock. You can buy and sell the stock only once.

        Note: You can’t sell without buying first.
        
    Example 1:
        Input : 17 20 11 9 12 6
        Output : 3
        
    Example 2:
        Input : 98 101 66 72
        Output : 6
*/

#include <bits/stdc++.h>

using namespace std;

int maximumProfit(vector<int> &prices){
    int minVal = prices[0];
    int maxProfit = 0;

    for(int i=1; i<prices.size(); i++) {
        if(prices[i] < minVal) {
            minVal = prices[i];
        } else {
            maxProfit = max(maxProfit, prices[i]-minVal);
        }
    }

    return maxProfit;
}

int main() {
    int n;
    cout << "Enter the number of days for the stock : ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter the stock values for each day in order : ";
    for(int i=0; i<n; i++)
    cin >> arr[i];
    
    int maxProfit = maximumProfit(arr);
    
    cout << "Maximum profit we can achieve is : " << maxProfit << endl;
    return 0;
}

// Time complexity - O(n)
// Space complexity - O(1)
