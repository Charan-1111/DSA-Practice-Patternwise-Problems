# Merge Sort Algorithm
- Divide-and-Conquer sorting algorithm.
- It recursively splits the array into smaller parts, sort them and then merges them back together.

## Algorithm
1. Divide the array into two halves.
2. Recursively sort both halves
3. Merge the sorted halves into one sorted array.

## Pseudo Code
```
mergeSort(arr, left, right):
	if left < right:
		mid = (left + right)/2
		mergeSort(arr, left, mid)
		mergeSort(arr, mid+1, right)
```

## Complexities
- ### Time Complexities
	- Best Case :- O(nlogn)
	- Average Case :- O(nlogn)
	- Worst Case :- O(nlogn)
- ### Space Complexity :- O(n)

## Example
- Unsorted Array :- [ 38, 27, 43, 3, 9, 82, 10 ]
- Step1 :- Divide
	- [ 38, 27, 43, 3, 9, 82, 10 ]
	- [ 38, 27, 43 ]  [ 3, 9, 82, 10 ]
	- [ 38 ] [ 27, 43 ] [ 3, 9 ] [ 82, 10 ]
	- [ 38 ] [ 27 ] [ 43 ] [ 3 ] [ 9 ] [ 82 ] [ 10 ]
- Step2 :- Merge
	- [ 27, 43 ] -> Merge with [ 38 ] => [ 27, 38, 43 ]
	- [ 3, 9 ] and [ 82, 10 ] => [ 3, 9, 10, 82 ]
	- Final :- [ 3, 9, 10, 27, 38, 43, 82 ]
