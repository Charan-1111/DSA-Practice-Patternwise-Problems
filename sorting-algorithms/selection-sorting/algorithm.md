# Selection Sort Algorithm
- Simple comparision based algorithm.
- Repeatedly selects the smallest ( or largest ) element from unsorted array and place it at correct position.

## Algorithm
1. Start from the first element
2. Find the smallest element in the entire array.
3. Swap it with the first element.
4. Move to next position
5. Repeat until the array is sorted.

## Pseudo Code
```
for i = 0 to n-1:
	min_index = i
	for j = i+1 to n:
		if arr[j] < arr[min_index]:
			min_index = j
	swap arr[i] and arr[min_index]
```

## Example
Let's consider the unsorted array : [ 64, 25, 12, 22, 11 ]

Step 1 :- Find the smallest -> 11, swap with 64
				=> [ 11, 25, 12, 22, 64 ]
Step 2 :- Find the smallest -> 12, swap with 25
				=> [ 11, 12, 25, 22, 64 ]
Step 3 :- Find the smallest -> 22, swap with 25
				=> [ 11, 12, 22, 25, 64 ]

## Complexities
- ### Time Complexities
	- **Best Case** :- O(n^2)
	- **Average Case** :- O(n^2)
	- **Worst Case** :- O(n^2)

- ### Space Complexity
	- O(1)

- [CPP CODE](code.cpp)
