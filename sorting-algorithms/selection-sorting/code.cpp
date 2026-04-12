#include <bits/stdc++.h>

using namespace std;

vector<int> selectionSort(vector<int> &arr, int n) {
    for(int i=0; i<n; i++){
        int min_idx = i;
        for(int j=i+1; j<n; j++) {
            if(arr[j] < arr[min_idx])
            min_idx = j;
        }
        
        swap(arr[i], arr[min_idx]);
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
    
    vector<int> sortedArr = selectionSort(arr, n);
    
    return 0;
}
