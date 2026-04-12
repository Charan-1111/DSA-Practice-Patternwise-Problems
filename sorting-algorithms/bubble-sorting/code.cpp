#include <bits/stdc++.h>

using namespace std;

vector<int> bubbleSort(vector<int> &arr, int n) {
    for(int i=0; i<n; i++) {
        bool swapped = false;
        for(int j=0; j<n-1; j++) {
            if(arr[j] > arr[j+1]){
                swap(arr[j], arr[j+1]);
                swapped = true;
            }
        }
        
        if(!swapped)
        break;
    }
    
    return arr;
}

int main() {
    int n;
    cout << "Enter the number of elements in the array : ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter the elements of the array : ";
    for(int i=0; i<n; i++)
    cin >> arr[i];
    
    vector<int> sortedArr = bubbleSort(arr, n);
    
    return 0;
}
