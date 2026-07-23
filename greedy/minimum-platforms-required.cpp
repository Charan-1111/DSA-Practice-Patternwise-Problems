j/*
  Q. You have been given two arrays, 'AT' and 'DT', representing the arrival and departure times of all trains that reach a railway station.

    Your task is to find the minimum number of platforms required for the railway station so that no train needs to wait.
    
    Note :
    1. Every train will depart on the same day and the departure time will always be greater than the arrival time. For example, A train with arrival time 2240 and departure time 1930 is not possible.
    
    2. Time will be given in 24H format and colons will be omitted for convenience. For example, 9:05AM will be given as "905", or 9:10PM will be given as "2110".
    
    3. Also, there will be no leading zeroes in the given times. For example, 12:10AM will be given as “10” and not as “0010”. 
    
    Examples:
    Sample Input 1:
    2
    6
    900 940 950 1100 1500 1800
    910 1200 1120 1130 1900 2000
    4
    100 200 300 400
    200 300 400 500
    Sample Output 1:
    3
    2
    
    
    Sample Input 2:
    2
    2
    900 1000
    999 1100
    3
    1200 1300 1450
    1310 1440 1600    
    Sample Output 2:
    1
    2
*/

#include <bits/stdc++.h>

using namespace std;

int calculateMinPatforms(vector<int> &at, vector<int> &dt) {
    int n = at.size();
    
    int cnt = 0;
    int res = 0;

    sort(at, at+n);
    sort(dt, dt+n);

    int i=0, j=0;

    while(i < n && j < n) {
        if(at[i] <= dt[j]) {
            cnt++;
            i++;
        } else if(dt[j] < at[i]) {
            cnt--;
            j++;
        }

        res = max(res, cnt);
    }

    return res;
}

int main() {
    int n;
    cout << "Enter number of trains : ";
    cin >> n;
    
    vector<int> arrivals(n);
    vector<int> departures(n);
    
    cout << "Enter the arrival and departure times of each train : ";
    for(int i=0; i<n; i++) {
        int arrival, departure;
        cin >> arrival >> departure;
        
        arrivals[i] = arrival;
        departures[i] = departure;
    }
    
    int minimumTracks = calculateMinPatforms(arrivals, departures);
    
    cout << "Minimum tracks required are : " << minimumTracks << endl;
    
    return 0;
}

/*
    Time Complexity - O(n + nlogn)
    Space Complexity - O(1)
*/







