# Insertion Sort Algorithm
- It builds the sorted array one element at a time by inserting each element into its correct position.

## Algorithm
1. Assume the first element is already sorted.
2. Pick the next element.
3. Compare it with elements in the sorted part ( left side ).
4. Shift larger elements one position to the right.
5. Insert the element at the current position.
6. Repeat for all elements

## Pseudo Code
```
for i = 1 to n-1:
	key = arr[i]
	j = i - 1
	while j >= 0 and arr[j] > key:
		arr[j+1] = arr[j]
		j = j - 1
	arr[j+1] = key
```

## Example
Let's consider the unsorted array :- [ 5, 3, 8, 4, 2 ]
**Step-by-step:**

-   Start: `[5] | [3, 8, 4, 2]`
-   Insert `3` → `[3, 5] | [8, 4, 2]`
-   Insert `8` → `[3, 5, 8] | [4, 2]`
-   Insert `4` → `[3, 4, 5, 8] | [2]`
-   Insert `2` → `[2, 3, 4, 5, 8]`

## Complexities
- ### Time Complexities
	- **Best Case** :- O(n) ( already sorted )
	- **Average Case** :- O(n^2)
	- **Worst Case** :- O(n^2)

- ### Space Complexity :- O(1)

- [CPP CODE](code.cpp)
