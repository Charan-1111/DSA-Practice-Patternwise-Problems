/*
    Q. The problem is to find the rightmost bit of a non-negative number 'N' that is currently unset (i.e., has a value of 0) in its binary representation and set it to 1.

        Return the number after setting the rightmost unset bit of 'N'. If there are no unset bits in N's binary representation, then the number should remain unchanged.
        
    Example 1:
        Input : 10
        Output : 11
        
    Example 2:
        Input : 7
        Output : 7
*/

#include <bits/stdc++.h>

using namespace std;

int setBits(int n){
    if(((n+1) & n) == 0) return n;

    int cnt= 0;

    while(n&1 != 0) {
        n = n >> 1;
        cnt++;
    }

    n = n | 1;

    while(cnt != 0) {
        n = n << 1;
        n = n | 1;
        cnt--;
    }

    return n;
}

int main() {
    int n;
    cout << "Enter the number : ";
    cin >> n;
    
    int res = setBits(n);
    
    cout << "Result after setting the rightmost unset bit to set : " << res << endl;
    return 0;
}

// Time complexity - O(k) // k = no.of consectutive trailing 1's
// Space complexity - O(1)
