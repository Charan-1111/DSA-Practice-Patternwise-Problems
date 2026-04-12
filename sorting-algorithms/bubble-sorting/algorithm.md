# Bubble Sort Algorithm
- Repeatedly compares adjacent elements and swap them if they are in wrong order.

## Algorithm
1. Start from first element.
2. Compare it with next element.
3. Swap if the current element is greater than next.
4. Continue this process for entire array.
5. Repeat the steps for remaining elements ( excluding already sorted ones at the end ).

## Pseudo Code
```
for i = 0 to n-1:
	swapped = false
	for j = 0 to n-2:
		if(arr[j] > arr[j+1]):
			swap(arr[j], arr[j+1])
			swapped = true
	if swapped == false:
		break
```

## Example
Let's consider unsorted array : [ 5, 3, 8, 4, 2 ]
**Pass 1:**
-   (5,3) → swap → `[3,5,8,4,2]`
-   (5,8) → no swap
-   (8,4) → swap → `[3,5,4,8,2]`
-   (8,2) → swap → `[3,5,4,2,8]`

**Pass 2:**
-   (3,5) → no swap
-   (5,4) → swap → `[3,4,5,2,8]`
-   (5,2) → swap → `[3,4,2,5,8]`

**Pass 3:**
-   (3,4) → no swap
-   (4,2) → swap → `[3,2,4,5,8]`

**Pass 4:**
-   (3,2) → swap → `[2,3,4,5,8]`

**Sorted array**:  
`[2, 3, 4, 5, 8]`


## Complexities
- ### Time Complexities
	- **Best Case** :- O(n) ( already sorted )
	- **Average Case** :- O(n^2)
	- **Worst Case** :- O(n^2)

- ### Space Complexity
	- O(1)
