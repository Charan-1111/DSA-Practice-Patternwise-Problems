/*
    Q. Given a string s, the task is to arrange the string according to the frequency of each character, in ascending order. If two elements have the same frequency, then they are sorted in lexicographical order.
    
    Example 1:
        Input : geeksforgeeks
        Output : geeksforgeeks
        
    Example 2:
        Input : abc
        Output : abc
*/

#include <bits/stdc++.h>

using namespace std;

string frequencySort(string &s) {
    unordered_map<char, int> mp;
    for(char ch : s) {
     mp[ch]++;   
    }
    
    priority_queue<pair<int, char>, vector<pair<int, char>>, greater<pair<int, char>>> pq;
    
    for(auto x : mp) {
        pq.push({x.second, x.first});
    }
    
    string res;
    res.reserve(s.length());
    
    while(!pq.empty()) {
        pair<int, char> p = pq.top();
        pq.pop();
        
        while(p.first--) {
            res.push_back(p.second);
        }
    }
    
    return res;
}

int main() {
    string s;
    cout << "Enter the string : ";
    cin >> s;
    
    string res = frequencySort(s);
    return 0;
}

// Time complexity - O(nlogn)
// Space complexity - O(n)
