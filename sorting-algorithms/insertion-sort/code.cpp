#include <bits/stdc++.h>

using namespace std;

vector<int> insertionSort(vector<int> &arr, int n) {
    for(int i=1; i<n; i++) {
        int key = arr[i];
        int j = i-1;
        
        while(j > 0 && arr[j] > key) {
            arr[j+1] = arr[j];
            j = j - 1;
        }
        
        arr[j+1] = key
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
    
    vector<int> sortedArr = insertionSort(arr, n);
    
    return 0;
}
