# Quick Sort Algorithm
- Most commonly used sorting algorithm.
- It follows divide-and-conquer approach and works by selecting pivot element and parititioning the array around it.

## Algorithm
1. Choose a pivot element.
2. Rearrange the array so that
	- Elements smaller than pivot -> left side.
	- Elements greater than pivot -> right side.
3. Recursively apply then same process to left and right subarrays.

## Partitioning Logic ( Core Idea )
- Pick pivot ( usually last element )
- Place pivot at correct position
- Move smaller elements before it.

## Pseudo Code
```
quickSort(arr, left, right):
	if left < right:
		pi = partition(arr, left, right)
		
		quickSort(arr, left, pi-1)
		quickSort(arr, pi, right)
```

## Complexities
- ### Time Complexities
	- **Best Case** :- O(nlogn)
	- **Average Case** :- O(nlogn)
	- **Worst Case** :- O(n^2) ( when pivot is smallest/largest repeatedly )
- ### Space Complexity - O(logn) ( recursion stack )

## Example
Consider the unsorted array :- [ 10, 7, 8, 9, 1, 5 ]
Step 1 :- Choose pivot -> 5
Rearrage :- [ 1, 5, 10, 7, 8, 9 ]

Step 2 :- Choose pivot -> 9
Rearrange :- [ 1, 5, 7, 8, 9, 10 ]

Repeat :- Final -> [ 1, 5, 7, 8, 9, 10 ]

- [CPP CODE](code.cpp)
