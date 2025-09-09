/*
	Q. Given a string containing digits from 2-9 inclusive, return all possible letter combinations that the number could represent. Return the answer in any order.
       A mapping of digits to letters (just like on the telephone buttons) is given below. Note that 1 does not map to any letters.

    Example 1:
		Input: digits = "23"
		Output: ["ad","ae","af","bd","be","bf","cd","ce","cf"]

	Example 2:
		Input: digits = ""
		Output: []

	Example 3:
		Input: digits = "2"
		Output: ["a","b","c"]
*/

#include <bits/stdc++.h>

using namespace std;

void solve(int i, int n, string s, unordered_map<char, string> &mp, string &str, vector<string> &res) {
	if(i >= n){
		res.push_back(s);
		return;
	}

	for(int idx=0; idx < mp[str[i]].length(); idx++) {
		// consider this char into the string
		solve(i+1, n, s+mp[str[i]][idx], mp, str, res);	
	}
}

vector<string> findAllPossibleCombinations(string str) {
	unordered_map<char, string> mp;
	mp['2'] = "abc";
	mp['3'] = "def";
	mp['4'] = "ghi";
	mp['5'] = "jkl";
	mp['6'] = "mno";
	mp['7'] = "pqrs";
	mp['8'] = "tuv";
	mp['9'] = "wxyz";

	vector<string> res;
	string s = "";

	solve(0, str.length(), s, mp, str, res);

	return res;
}

int main() {

	string str;
	cout << "Enter the string : ";
	cin >> str;

	vector<string> possibleList = findAllPossibleCombinations(str);

	for(string s : possibleList) {
		cout << s << " ";
	}
	cout << endl;

	return 0;
}


// Time complexity - O(n⋅4^n)
// Space complexity - O(n⋅4^n)