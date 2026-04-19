/*
    Given an array ‘arr’ of integer numbers, ‘arr[i]’ represents the number of pages in the ‘i-th’ book.

    There are ‘m’ number of students, and the task is to allocate all the books to the students.
    
    Allocate books in such a way that:
    
    1. Each student gets at least one book.
    2. Each book should be allocated to only one student.
    3. Book allocation should be in a contiguous manner.
    
    
    You have to allocate the book to ‘m’ students such that the maximum number of pages assigned to a student is minimum.
    
    If the allocation of books is not possible, return -1.
    
    Example:
    Input: ‘n’ = 4 ‘m’ = 2 
    ‘arr’ = [12, 34, 67, 90]
    
    Output: 113
    
    Explanation: All possible ways to allocate the ‘4’ books to '2' students are:
    
    12 | 34, 67, 90 - the sum of all the pages of books allocated to student 1 is ‘12’, and student two is ‘34+ 67+ 90 = 191’, so the maximum is ‘max(12, 191)= 191’.
    
    12, 34 | 67, 90 - the sum of all the pages of books allocated to student 1 is ‘12+ 34 = 46’, and student two is ‘67+ 90 = 157’, so the maximum is ‘max(46, 157)= 157’.
    
    12, 34, 67 | 90 - the sum of all the pages of books allocated to student 1 is ‘12+ 34 +67 = 113’, and student two is ‘90’, so the maximum is ‘max(113, 90)= 113’.
*/

#include <bits/stdc++.h>

using namespace std;

int canAllocate(vector<int> &arr, int maxVal, int m) {
    int noOfStudents = 1;

    int pagesTotal = 0;

    for(int elem : arr) {
        if(pagesTotal + elem > maxVal) {
            noOfStudents++;
            pagesTotal = elem;
        } else {
            pagesTotal += elem;
        }
    }


    return noOfStudents;
}

int findPages(vector<int>& arr, int n, int m) {
    if(arr.size() < m) return -1;

    int left = *max_element(arr.begin(), arr.end());

    int right = accumulate(arr.begin(), arr.end(), 0);

    int res = -1;

    while(left <= right) {
        int mid = left + ((right - left) >> 1);

        int noOfStudents = canAllocate(arr, mid, m);

        if(noOfStudents <= m) {
            right = mid - 1;
        } else {
            left = mid + 1;
        }
    }

    return left;
} 

int main() {
    int n;
    cout << "Enter the number of element of the array : ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter the elements of the array : ";
    for(int i=0; i<n; i++)
    cin >> arr[i];
    
    int m;
    cout << "Enter the number of students : ";
    cin >> m;
    
    int res = findPages(arr, n, m);
    
    cout << "res : " << res << endl;
    return 0;
}

/*
    Time Complexity - O(logn)
    Space Complexity -O(1)
*/
