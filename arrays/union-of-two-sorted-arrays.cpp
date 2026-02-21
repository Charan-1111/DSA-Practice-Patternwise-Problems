/*
    Q. Given two sorted arrays a[] and b[], where each array may contain duplicate elements , the task is to return the elements in the union of the two arrays in sorted order.
    Union of two arrays can be defined as the set containing     distinct common elements that are present in either of the arrays.

    Examples:

Input: a[] = [1, 2, 3, 4, 5], b[] = [1, 2, 3, 6, 7]
Output: [1, 2, 3, 4, 5, 6, 7]
Explanation: Distinct elements including both the arrays are: 1 2 3 4 5 6 7.
Input: a[] = [2, 2, 3, 4, 5], b[] = [1, 1, 2, 3, 4]
Output: [1, 2, 3, 4, 5]
Explanation: Distinct elements including both the arrays are: 1 2 3 4 5.
Input: a[] = [1, 1, 1, 1, 1], b[] = [2, 2, 2, 2, 2]
Output: [1, 2]
Explanation: Distinct elements including both the arrays are: 1 2.
*/

#include <bits/stdc++.h>

using namespace std;

vector<int> findUnion(vector<int> &a, vector<int> &b) {
    vector<int> res;
    
    int i = 0, j = 0;
    int n = a.size(), m = b.size();
    
    int lastElem = -1;
    
    while(i < n && j < m) {
        int val = -1;
        if(a[i] <= b[j]) {
            val = a[i];
            i++;
        } else {
            val = b[j];
            j++;
        }
        
        if(lastElem != val){
            res.push_back(val);
            lastElem = val;
        }
    }
    
    while(i < n) {
        if(lastElem != a[i]) {
            res.push_back(a[i]);
            lastElem = a[i];
        }
        i++;
    }
    
    while(j < m) {
        if(lastElem != b[j]) {
            res.push_back(b[j]);
            lastElem = b[j];
        }
        j++;
    }
    
    return res;
}

int main() {
    int n, m;
    cout << "Enter the number of elements in the both arrays : ";
    cin >> n >> m;
    
    vector<int> a(n);
    cout << "Enter the elements of the first array in sorted order : ";
    for(int i=0; i<n; i++)
    cin >> a[i];
    cout << endl;
    
    vector<int> b(m);
    cout << "Enter the elements of the second array in sorted order : ";
    for(int i=0; i<m; i++)
    cin >> b[i];
    cout << endl;
    
    vector<int> res = findUnion(a, b);
    cout << "The union of two sorted arrays : ";
    for(int elem : res)
    cout << elem << " ";
    cout << endl;
    return 0;
}

/*
    Time Complexity - O(n+m)
    Space Complexity - O(n+m)
*/
