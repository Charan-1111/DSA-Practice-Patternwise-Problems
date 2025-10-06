/*
    Q. Given a number ‘N’ and a number ‘K’. Return true if ‘K’th bit of number is set, else return false.
    
    Example 1:
        Input 1: 3 2
        Output 1: Yes
*/

#include <bits/stdc++.h>

using namespace std;

bool isKthBitSet(int n, int k) {
    while(k != 1) {
        n = n>>1;

        k--;
    }

    return n&1;
}

int main() {
    int n, m;
    cout << "Enter the number and position bit: ";
    cin >> n >> m;
    
    bool res = isKthBitSet(n, m);
    
    cout << "is the bit is set : " << res << endl;
    
    return 0;
}

// Time complexity - O(n)
// Space complexity - O(1)
