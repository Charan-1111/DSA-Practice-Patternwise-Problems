/*
	Q. Given an infinite supply of each denomination of Indian currency { 1, 2, 5, 10 } and a target value n. Find the minimum number of coins and/or notes needed to
	   make the change for Rs n. 

	Example 1:
		Input: n = 39
		Output: 6
		Explaination: 39 can be formed using 3 coins of 10 rupees, 1 coin of 5 rupees and 2 coins of 2 rupees so minimum coins required are 6.

	Example 2:
		Input: n = 121
		Output: 13
		Explaination: 121 can be formed using 12 coins of 10 rupees and 1 coin of 1 rupees.
*/


#include <bits/stdc++.h>

using namespace std;

int findMin(int n) {
    vector<int> list = {1, 2, 5, 10};
    
    int tot = 0;
    
    for(int i=3; i>=0; i--) {
        int q = n/list[i];
        int rem = n%list[i];
        
        tot += q;
        n = rem;
    }
    
    return tot;
}

int main() {
	int n;
	cout << "Enter the amount to get the change : ";
	cin >> n;

	int totalCoins = findMin(n);

	cout << "Minimum number of coins required are : " << totalCoins << endl;

	return 0;
}

// Time complexity - O(n);
// Space complexity - O(1);
