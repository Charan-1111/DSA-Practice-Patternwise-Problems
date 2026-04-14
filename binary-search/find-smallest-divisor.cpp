/*
    You are given an array of integers 'arr' and an integer 'limit'.

    Your task is to find the smallest positive integer divisor, such that upon dividing all the elements of the given array by it, the sum of the division's result is less than or equal to the given integer's limit.

    Note:
    Each result of the division is rounded to the nearest integer greater than or equal to that element. For Example, 7/3 = 3.
    
    Sample Input 1 :
    5
    1 2 3 4 5
    8  
    Sample Output 1 :
    3
    Explanation for Sample Input 1 :
    We can get a sum of 15(1 + 2 + 3 + 4 + 5) if we choose 1 as a divisor. 
    The sum is 9(1 + 1 + 2 + 2 + 3)  if we choose 2 as a divisor, and the sum is 7(1 + 1 + 1 + 2 + 2) if we choose 3 as a divisor, which is less than the 'limit'.
    Hence we return 3.
    Sample Input 2 :
    4
    8 4 2 3 
    10
    Sample Output 2 :
    2
    Explanation for Sample Input 2:
    We can get a sum of 17(8 + 4 + 2 + 3) if we choose 1 as a divisor. 
    The sum is 9(4 + 2 + 1 + 2) if we choose 2 as a divisor, which is less than the 'limit'.
    Hence, we return 2.
    Sample Input 3:
    5
    2 3 5 7 11
    11
    Sample Output 3 :
    3
*/


#include <bits/stdc++.h>

using namespace std;

int checkSum(vector<int>&arr, int div, int limit) {
	int sum = 0;

	for(int elem : arr) {
		sum = sum + (elem / div);

		if(elem % div != 0) {
			sum += 1;
		}
	}

	return sum <= limit;
}

int smallestDivisor(vector<int>& arr, int limit){
	int left = 1;
	int right = *max_element(arr.begin(), arr.end());

	int res;

	while(left <= right) {
		int mid = left + ((right - left)>>1);

		bool check = checkSum(arr, mid, limit);

		if(check) {
			res = mid;
			right = mid - 1;
		} else {
			left = mid + 1;
		}
	}

	return res;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array : ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter the elements of the array : ";
    for(int i=0; i<n; i++)
    cin >> arr[i];
    
    int limit;
    cout << "Enter the limit : ";
    cin >> limit;
    
    int res = roseGarden(arr, limit);
    cout << res << endl;
    
    return 0;
}

/*
    Time Complexity - O(nlog(max(arr)))
    Space Complexity - O(1)
*/
