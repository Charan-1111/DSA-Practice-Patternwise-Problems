/*
    Q. You are given an array of integers 'ARR' of length 'N' and an integer Target. Your task is to return all pairs of elements such that they add up to Target.

    Note:
    
    We cannot use the element at a given index twice.
    Follow Up:
    
    Try to do this problem in O(N) time complexity.
    
    Sample Input 1 :
    2
    4 9
    2 7 11 13
    5 1
    1 -1 -1 2 2
    Sample Output 1:
    2 7
    -1 2
    -1 2
    Explanation for Sample 1:
    For the first test case, we can see that the sum of  2 and 7 is equal to 9 and it is the only valid pair.
    
    For the second test case, there are two valid pairs (-1,2) and (-1,2), which add up to 1.
*/

#include <bits/stdc++.h>

using namespace std;

vector<pair<int,int>> twoSum(vector<int>& arr, int target, int n){
	vector<pair<int, int>> res;

	unordered_map<int, int> mp;

	for(int i=0; i<n; i++) {
		int val = target-arr[i];

		if(mp[val] > 0) {
			res.push_back({val, arr[i]});
			mp[val]--;
		} else {
			mp[arr[i]]++;
		}
	}

	if(res.size() == 0) return {{-1, -1}};

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
    
    int target;
    cout << "Enter the target sum : ";
    cin >> target;
    
    vector<pair<int, int>> res = twoSum(arr, target, n);
    
    cout << "Pairs with the given sum are " << endl;
    for(pair<int, int> p : res) {
        cout << p.first << " " << p.second << endl;
    }
    
    return 0;
}

/*
    Time Complexity - O(n)
    Space Complexity - O(n)
*/

