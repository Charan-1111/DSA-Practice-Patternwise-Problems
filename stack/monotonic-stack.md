# Monotonic Stack & Monotonic Queue Handbook

## 1. What is a Monotonic Data Structure?

A monotonic data structure maintains its elements in either increasing
or decreasing order.

-   **Monotonic Increasing Stack**: top is the smallest among recent
    candidates.
-   **Monotonic Decreasing Stack**: top is the largest among recent
    candidates.
-   **Monotonic Deque**: supports both ends and is ideal for sliding
    window problems.

The key benefit is that every element is pushed once and popped at most
once, giving **O(n)** algorithms.

------------------------------------------------------------------------

# 2. When Should You Think of Monotonic Stack?

Look for: - Next Greater/Smaller Element - Previous Greater/Smaller
Element - Largest Rectangle in Histogram - Trapping Rain Water - Remove
K Digits - Stock Span - Sum of Subarray Minimums

Template:

``` cpp
stack<int> st;
for (int i = 0; i < n; i++) {
    while (!st.empty() && nums[st.top()] > nums[i]) {
        st.pop();
    }
    st.push(i);
}
```

------------------------------------------------------------------------

# 3. When Should You Think of Monotonic Deque?

Look for: - Sliding Window Maximum - Sliding Window Minimum - Jump Game
VI - Constrained Subsequence Sum

Template:

``` cpp
deque<int> dq;
for (int i = 0; i < n; i++) {
    while (!dq.empty() && dq.front() < i-k+1)
        dq.pop_front();

    while (!dq.empty() && nums[dq.back()] <= nums[i])
        dq.pop_back();

    dq.push_back(i);

    if (i >= k-1)
        answer.push_back(nums[dq.front()]);
}
```

------------------------------------------------------------------------

# 4. Why Does It Work?

Whenever a new element is "better" than an older one:

-   Larger for maximum queries
-   Smaller for minimum queries

the older candidate can never become useful again while both coexist, so
it is discarded immediately.

This is the greedy insight behind monotonic structures.

------------------------------------------------------------------------

# 5. Common Problems

  Problem                          Structure
  -------------------------------- ------------------
  Next Greater Element             Increasing Stack
  Daily Temperatures               Increasing Stack
  Stock Span                       Decreasing Stack
  Largest Rectangle in Histogram   Increasing Stack
  Trapping Rain Water              Increasing Stack
  Remove K Digits                  Increasing Stack
  Sliding Window Maximum           Decreasing Deque
  Sliding Window Minimum           Increasing Deque
  Jump Game VI                     Decreasing Deque

------------------------------------------------------------------------

# 6. Complexity

Every element is: - pushed once - popped at most once

Therefore:

-   Time: O(n)
-   Space: O(n) for stacks, O(k) for sliding window deque.

------------------------------------------------------------------------

# 7. Pattern Recognition Checklist

Use a **Monotonic Stack** if: - You need next/previous greater or
smaller values. - You want to remove useless candidates permanently.

Use a **Monotonic Deque** if: - The window moves continuously. -
Elements expire from the left. - You need the maximum/minimum for every
window.

------------------------------------------------------------------------

# 8. Common Mistakes

-   Using `if` instead of `while` when popping.
-   Storing values instead of indices when indices are required.
-   Forgetting to remove expired indices in sliding window problems.
-   Using `>=` instead of `>` (or vice versa) without considering
    duplicates.
-   Forgetting to process remaining stack elements when required.

------------------------------------------------------------------------

# 9. Mental Model

Ask yourself:

1.  Can an older element ever beat the current one in the future?
2.  If not, discard it immediately.
3.  Keep only candidates that may become answers later.

This mindset leads naturally to monotonic stack/deque solutions.
