/*
    Q. You are given an array ‘ARR’ consisting of ‘N’ strings. Your task is to find the longest common prefix among all these strings. If there is no common prefix, you have to return an empty string.

        A prefix of a string can be defined as a substring obtained after removing some or all characters from the end of the string.
        
    Example 1:
        Input : coding codezen codingninja coder
        Output : cod
        
    Example 2:
        Input : night ninja nil
        Output : ni
*/

#include <bits/stdc++.h>

using namespace std;

string findPrefix(string prefix, string str) {
    string pref = "";

    int i=0, j=0;
    while(i < prefix.length() && j < str.length()) {
        if(prefix[i] == str[j]) {
            pref = pref + prefix[i];
            i++;
            j++;
        } else {
            break;
        }
    }

    return pref;
}

string longestCommonPrefix(vector<string> &arr, int n)
{
    if(arr.size() == 0) return "";

    if(arr.size() == 1) return arr[0];

    sort(arr.begin(), arr.end());

    string prefix = findPrefix(arr[0], arr[1]);

    for(int i=2; i<arr.size(); i++) {
        prefix = findPrefix(prefix, arr[i]);
    }

    return prefix;
}

int main() {
    int n;
    cout << "Enter the number of strings : ";
    cin >> n;
    
    vector<string> v;
    cout << "Enter the string in order : ";
    for(int i=0; i<n; i++)
    cin >> v[i];
    
    string prefix = longestCommonPrefix(v, n);
    
    return 0;
}

// Time complexity - O(n⋅m⋅logn)
// Space complexity - O(n)
