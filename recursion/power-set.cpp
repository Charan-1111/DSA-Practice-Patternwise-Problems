/*
	Q. Given a string s of length n, find all the possible non-empty subsequences of the string s in lexicographically-sorted order.

	Example 1:

	Input : 
	s = "abc"
	Output: 
	a ab abc ac b bc c
	Explanation : 
	There are a total 7 number of subsequences possible for the given string, and they are mentioned above in lexicographically sorted order.
*/


#include <bits/stdc++.h>

using namespace std;

void solve(int i, int n, string s, string st, set<string> &res) {
	if(i >= n) {
		if(s != ""){
			res.insert(s);
		}
		return;
	}


	// include the current character in the string
	solve(i+1, n, s+st[i], st, res);


	// don't include the current character in the string
	solve(i+1, n, s, st, res);
}

vector<string> generateAllStrings(string s) {
	if(s == "") return {};
	int n = s.length();

	set<string> st;

	string temp = "";
	solve(0, n, temp, s, st);

	vector<string> res;
	for(string x : st) {
		res.push_back(x);
	}

	return res;
}

int main() {
	string s;
	cout << "Enter the string: ";
	cin >> s;

	vector<string> res = generateAllStrings(s);

	for(string s : res) {
		cout << s << " ";
	}
	cout << endl;
	
	return 0;
}

// Time complexity - O(2^n) as for every recursive call we are checking for 2 cases
// Space complexity - O(n) as we are using extra space to store the result