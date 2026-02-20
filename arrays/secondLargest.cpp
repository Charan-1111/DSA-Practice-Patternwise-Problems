/*
    Q. Given an array of positive integers arr[], return the second largest element from the array. If the second largest element doesn't exist then return -1.

    Note: The second largest element should not be equal to the largest element.
    
    Examples:

    Input: arr[] = [12, 35, 1, 10, 34, 1]
    Output: 34
    Explanation: The largest element of the array is 35 and the second largest element is 34.
    
    Input: arr[] = [10, 5, 10]
    Output: 5
    Explanation: The largest element of the array is 10 and the second largest element is 5.
    
    Input: arr[] = [10, 10, 10]
    Output: -1
    Explanation: The largest element of the array is 10 and the second largest element does not exist.
*/

#include <bits/stdc++.h>

using namespace std;

int getSecondLargest(vector<int> &arr){
    int large = -1, secondLarge = -1;
    
    for(int elem : arr) {
        if(elem > large) {
            secondLarge = max(secondLarge, large);
            large = elem;
        } else {
            secondLarge = max(secondLarge, elem);
        }
    }
    
    return secondLarge;
}

int main() {
    int n;
    cout << "Enter the number of elements of the array : ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter the elements of the array : ";
    for(int i=0; i<n; i++)
    cin >> arr[i];
    
    int secondLarge = getSecondLargest(arr);
    
    cout << "Second largest element of the array is : " << secondLarge << endl;
    
    return 0;
}

/*
    Time Complexity - O(n)
    Space Complexity - O(1)
*/
