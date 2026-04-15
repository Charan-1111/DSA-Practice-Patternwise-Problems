#include <bits/stdc++.h>

using namespace std;

int partition(vector<int> &arr, int low, int high) {
    int pivot = arr[high];  // choose last element as pivot
    int i = low - 1;

    for (int j = low; j < high; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[i + 1], arr[high]);
    return i + 1;
}

void quickSort(vector<int> &arr, int left, int right) {
    if(left < right) {
        int pi = partition(arr, left, right);
        
        quickSort(arr, left, pi-1);
        quickSort(arr, pi, right);
    }
}

int main() {
    int n;
    cout << "Enter the number of elements in the array : ";
    cin >> n;
    
    vector<int> arr(n);
    cout << "Enter the elements of the array : ";
    for(int i=0; i<n; i++)
    cin >> arr[i];
    
    
    quickSort(arr, 0, n-1);
    
    
    cout << "Sorted array : ";
    for(int elem : arr)
    cout << elem << " ";
    cout << endl;
    
    return 0;
}
