/*
    A monkey is given ‘n’ piles of bananas, where the 'ith' pile has ‘a[i]’ bananas. An integer ‘h’ is also given, which denotes the time (in hours) in which all the bananas should be eaten.

    Each hour, the monkey chooses a non-empty pile of bananas and eats ‘m’ bananas. If the pile contains less than ‘m’ bananas, then the monkey consumes all the bananas and won’t eat any more bananas in that hour.
    
    Find the minimum number of bananas ‘m’ to eat per hour so that the monkey can eat all the bananas within ‘h’ hours.
    
    Example:
    
    Input: ‘n’ = 4, ‘a’ =  [3, 6, 2, 8] , ‘h’ = 7
    
    Output: 3
    
    Explanation: If ‘m’ = 3, then 
    The time taken to empty the 1st pile is 1 hour.
    The time taken to empty the 2nd pile is 2 hour.
    The time taken to empty the 3rd pile is 1 hour.
    The time taken to empty the 4th pile is 3 hour.
    Therefore a total of 7 hours is taken. It can be shown that if the rate of eating bananas is reduced, they can’t be eaten in 7 hours.
*/



#include <bits/stdc++.h>

using namespace std;

long long int calculateTime(vector<int> &arr, int m) {
    long long int timeTaken = 0;

    for(int val : arr) {
        timeTaken = timeTaken + (val / m);

        if(val%m != 0) {
            timeTaken += 1;
        }
    }

    return timeTaken;
}

int minimumRateToEatBananas(vector<int> v, int h) {
    long long int total = *max_element(v.begin(), v.end());

    int l = 1, r = total;

    int res;

    while(l <= r) {
        long long int mid = l + ((r-l)>>1);

        long long int timeTaken = calculateTime(v, mid);

        if(timeTaken <= h) {
            res = mid;
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }

    return res;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array : ";
    cin >> n;
    
    vector<int> bananas(n);
    cout << "Enter the entries of the array : ";
    for(int i=0; i<n; i++)
    cin >> bananas[i];
    
    int h;
    cout << "Enter the hours : ";
    cin >> h;
    
    int m = minimumRateToEatBananas(bananas, h);
    
    cout << m << endl;
    
    return 0;
}

/*
    Time Complexity - O(nlogM) ( M - maximum element of the array )
    Space Complexity - O(1)
*/
