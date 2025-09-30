/*
    Q. You are given a string 'str' of length 'N'.
       Your task is to reverse the original string word by word.
    
    There can be multiple spaces between two words and there can be leading or trailing spaces but in the output reversed string you need to put a single space between two words, and your reversed string should not contain leading or trailing spaces.
    
    Example 1:
        Input : Welcome to Coding Ninjas
        Output : Ninjas Coding to Welcome
*/

#include <bits/stdc++.h>

using namespace std;

string reverseString(string &str){
	stack<string> st;

	string word = "";

	for(int i=0; i<str.size(); i++) {
		if(str[i] != ' ') {
			word = word + str[i];
		} else {
			if(word != "") {
				st.push(word);
			}
			word = "";
		}
	}

	if(word != "")
	st.push(word);

	string res = "";

	while(!st.empty()) {
		res = res + st.top() + " ";
		st.pop();
	}
	return res;
}

int main() {
    string s;
    cout << "Enter the string : ";
    cin >> s;
    
    string res = reverseString(s);
    
    cout << "Reversed string is : " << res << endl;
    
    return 0;
}

// Time complexity - O(n)
// Space complexity - O(n)
