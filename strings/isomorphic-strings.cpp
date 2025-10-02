/*
    Q. You have been given two strings, 'str1' and 'str2'.
       Your task is to return true if the given two strings are isomorphic to each other, else return false.
       
    Note :
        Two strings are isomorphic if a one-to-one mapping is possible for every character of the first string ‘str1’ to every character of the second string ‘str2’ while preserving the order of the characters.
        
        All occurrences of every character in the first string ‘str1’ should map to the same character in the second string, ‘str2’.
        
    
    Example 1:
        Input : aab, xxy
        Output : true
        
    Example 2:
        Input : aab, xyz
        Output : false
*/

#include <bits/stdc++.h>

using namespace std;

bool areIsomorphic(string &str1, string &str2) {
    if (str1.length() != str2.length()) return false;

    // ASCII size (256) or could use 128 for standard chars
    vector<int> map1(256, -1);
    vector<int> map2(256, -1);

    for (int i = 0; i < str1.length(); i++) {
        char c1 = str1[i];
        char c2 = str2[i];

        if (map1[c1] == -1 && map2[c2] == -1) {
            // first time mapping
            map1[c1] = c2;
            map2[c2] = c1;
        } else {
            // must match previous mapping
            if (map1[c1] != c2 || map2[c2] != c1)
                return false;
        }
    }
    return true;
}

int main() {
    string str1, str2;
    cout << "Enter the two strings to compare : ";
    cin  >> str1 >> str2;
    
    bool result = areIsomorphic(str1, str2);
    
    cout << "Is the two strings are isomorphic : " << result << endl;
    
    return 0;
}

// Time complexity - O(n)
// Space complexity - O(1)
