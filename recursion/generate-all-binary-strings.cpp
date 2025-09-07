/*
	Q . Given an integer n. Generte and print all the binary strings of length n that does not contains consecutive 1's
	A binary string is that which contains only 1's and 0's

	Example 1:

	Input:
	n = 3
	Output:
	000 , 001 , 010 , 100 , 101
	Explanation:
	None of the above strings contain consecutive 1s. "110" is not an answer as it has '1's occuring consecutively. 
*/

#include <bits/stdc++.h>

using namespace std;

void solve(int i, int n, string s, vector<string> &res) {
	if(i >= n) {
		res.push_back(s);
		return;
	}

	// include 0 in the current string;
	solve(i+1, n, s+"0", res);

	// include 1 in the current string, but before including the 1 we need to check if the previous character should not be 1
	if(s.back() != '1')
		solve(i+1, n, s+"1", res);
}

vector<string> genearateStrings(int n) {
	if(n == 0) return {};

	string s = "";
	vector<string> res;


	solve(0, n, s, res);

	return res;
}

int main() {
	int n;
	cout << "Enter the length of the binary strings : ";
	cin >> n;

	vector<string> binaryStrings = genearateStrings(n);

	for(string s : binaryStrings) {
		cout << s << " ";
	}

	cout << endl;

	return 0;
}


// Time complexity - O(2^n) where n is the length of the string
// space complexity - O(n) as we are using extra space to store the result strings
