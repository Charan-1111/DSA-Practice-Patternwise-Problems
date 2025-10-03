/*
    Q. Given two non-empty strings s1 and s2, consisting only of lowercase English letters, determine whether they are anagrams of each other or not.
        Two strings are considered anagrams if they contain the same characters with exactly the same frequencies, regardless of their order.
        
    Example 1:
        Input : s1 = "geeks" s2 = "kseeg"
        Output : true
        
    Example 2:
        Input : s1 = "allergy", s2 = "allergyy" 
        Output : false
        
    Example 3:
        Input : s1 = "listen", s2 = "lists"
        Output : false
*/

#include <bits/stdc++.h>

using namespace std;

bool areAnagrams(string& s1, string& s2) {
    unordered_map<char, int> mp;
    for(char ch : s1) {
        mp[ch]++;
    }
    
    for(char ch : s2) {
        if(mp.find(ch) == mp.end() || mp[ch] == 0) return false;
        
        mp[ch]--;
    }
    
    return true;
}

int main() {
    string s1, s2;
    cout << "Enter the strings : ";
    cin >> s1 >> s2;
    
    bool res = areAnagrams(s1, s2);
    
    cout << "Is the strings are anagram : " << res << endl;
    
    return 0;
}

// Time complexity - O(n)
// Space complexity - O(1)
