/*
	Q. You are given an array greed[], where greed[i] represents the minimum size of cookie required to satisfy the i-th child, and an array cookie[], where cookie[j] represents the size of the j-th cookie. Each child can receive at most one cookie. A child i will be satisfied if they receive a cookie j such that cookie[j] >= greed[i]. Your task is to determine the maximum number of children that can be satisfied.


	Example 1:
		Input : greed[] = [1, 10, 3], cookie = [1, 2, 3]
		Output: 2
		Explanation: We can only assign cookie to the first and third child.

	Example 2:
		Input : greed[] = [10, 100], cookie = [1, 2]
		Output: 0
		Explanation: We can not assign cookies to any child.
*/

#include <bits/stdc++.h>

using namespace std;

int binSearch(vector<int> &cookie, int val) {
    int l = 0, r = cookie.size()-1;
    
    int res = -1;
    
    while(l <= r) {
        int mid = l + (r-l)/2;
        
        if(cookie[mid] >= val) {
            res = mid;
            r = mid-1;
        } else {
            l = mid+1;
        }
    }
    
    
    return res;
}


int assignCookie(vector<int> &greed, vector<int> &cookie) {
	sort(greed.begin(), greed.end());
        
    sort(cookie.begin(), cookie.end());
    
    int res = 0;
    
    for(int i=0; i<greed.size(); i++) {
        int idx = binSearch(cookie, greed[i]);
        
        if(idx != -1) {
            res++;
            cookie[idx] = 0;
        }
    }
    
    return res;
}


int main() {
	int n, m;
	cout << "Enter the no of children : ";
	cin >> n;

	vector<int> greed(n);
	cout << "Enter the greed value of each children in order : ";
	for(int i=0; i<n; i++)
	cin >> greed[i];


	cout << "Enter the number of cookies : ";
	cin >> m;

	vector<int> cookies(m);
	cout << "Enter the value of the cookies in order : ";
	for(int i=0; i<m; i++)
	cin >> cookies[i];


	int result = assignCookie(greed, cookies);

	cout << "Maximum number of children that can get satisfied is : " << result << endl;

	return 0;
}


// Time complexity - O(nlogm)
// Space complexity - O(1)
