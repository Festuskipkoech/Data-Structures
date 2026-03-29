# Challenge 1 — Reverse an Array In-Place
> DSA breakdown: memory model, algorithm mechanics, complexity analysis, edge cases.

---

## The Problem

Reverse a given array in-place. No new array allowed.

```
Input:  [1, 2, 3, 4, 5]
Output: [5, 4, 3, 2, 1]
```

Constraints: 0 ≤ len(A) ≤ 10⁵ — Target: O(n) time, O(1) space.

---

## 1. Memory Model — Why "In-Place" Matters

An array in C is a **contiguous block of memory**. Every element sits at a fixed, predictable address calculated from the base pointer and the element size.

```
Index:   0      1      2      3      4
Value:   1      2      3      4      5
Addr:  0x100  0x104  0x108  0x10C  0x110   (assuming 4-byte int)
```

Because of this layout, index access is O(1) — the CPU computes the address directly:

```
address of arr[i] = base_address + (i × sizeof(int))
```

**In-place** means we operate directly on this memory block. We do not allocate a second array and copy into it. The only extra memory allowed is a small constant — in our case, three integer variables (`left`, `right`, `temp`).

This is what O(1) space means — the memory used does not grow as the array grows.

---

## 2. The Naive Approach (and Why We Reject It)

The obvious first instinct: allocate a new array, fill it backwards, copy it back.

```c
int reversed[n];
for (int i = 0; i < n; i++) {
    reversed[i] = arr[n - 1 - i];
}
for (int i = 0; i < n; i++) {
    arr[i] = reversed[i];
}
```

This works but violates the constraint. It uses O(n) extra space for `reversed[]`. As n grows to 10⁵ integers, that is 400KB of unnecessary allocation. The in-place approach uses 12 bytes regardless of input size.

---

## 3. The Two-Pointer Technique

This is the core DSA technique at play here. Two index variables — `left` and `right` — start at opposite ends of the array and move toward each other, swapping elements as they go.

### How It Works

```
Initial state:
left = 0, right = 4
[1, 2, 3, 4, 5]
 ^           ^

Step 1: swap arr[0] and arr[4]
[5, 2, 3, 4, 1]
    ^       ^
left = 1, right = 3

Step 2: swap arr[1] and arr[3]
[5, 4, 3, 2, 1]
       ^
left = 2, right = 2

Step 3: left >= right — stop. Middle element (arr[2] = 3) needs no swap.
```

### The Loop Condition

```c
while (left < right)
```

This is the key guard. When `left == right`, both pointers are on the same element — swapping it with itself changes nothing. When `left > right`, the pointers have crossed and we have processed every pair. Either way, we are done.

For an array of length n:
- Odd length — pointers meet at the middle index, which is never swapped
- Even length — pointers cross without meeting, every element is swapped exactly once

### The Swap

```c
int temp   = arr[left];
arr[left]  = arr[right];
arr[right] = temp;
```

A three-line swap is standard. You cannot do `arr[left] = arr[right]; arr[right] = arr[left];` — by the time line 2 executes, `arr[left]` already holds the wrong value. The `temp` variable captures the original before it is overwritten.

---

## 4. Complexity Analysis

### Time — O(n)

Each iteration moves `left` forward by 1 and `right` backward by 1. The loop runs exactly `n / 2` times (integer division). For n = 100,000 that is 50,000 swaps.

Big O drops the constant factor (1/2), so the time complexity is O(n). The algorithm scales linearly with input size.

### Space — O(1)

Three variables are allocated regardless of input size: `left`, `right`, `temp`. These are fixed-size integers on the stack. Memory usage does not scale with n. This satisfies the O(1) space constraint.

No recursion is used, so there is no hidden call stack growth.

---

## 5. Edge Cases

These are explicitly required by the problem statement.

### Empty Array (len = 0)

```c
if (len <= 1) return;
```

The guard at the top handles this. An empty array is already reversed — there is nothing to do. Without the guard, the loop would calculate `right = -1` and the `left < right` condition (0 < -1) would be false anyway, but explicit handling communicates intent clearly and avoids potential undefined behaviour with pointer arithmetic.

### Single Element (len = 1)

Same guard. A single-element array is its own reverse. Attempting to swap index 0 with index 0 is pointless and the guard skips it entirely.

### Even vs Odd Length

The loop condition `left < right` handles both:

- **Odd length** (e.g. 5 elements): pointers meet at index 2. `left == right`, condition is false, loop ends. The middle element is never touched, which is correct.
- **Even length** (e.g. 4 elements): pointers cross. After processing the innermost pair (indices 1 and 2), `left` becomes 2 and `right` becomes 1. `2 < 1` is false, loop ends. All pairs processed.

No special casing needed — the single loop condition handles both.

---

## 6. Why Two Pointers Is the Right Tool Here

The two-pointer technique reduces a class of problems from O(n²) or O(n) extra space to O(n) time and O(1) space by recognising that you can process two elements simultaneously from opposite or same-direction positions.

For reversal specifically:
- Element at index `i` from the left needs to swap with element at index `i` from the right
- These two positions move symmetrically toward the centre
- The pattern terminates naturally when they meet

This same technique appears in palindrome checking, container with most water, three sum, and removing duplicates from sorted arrays. Recognising it here builds the instinct for those harder problems.

---

## 7. The Code

```c
void reverse_array(int *arr, int len) {
    if (len <= 1) return;

    int left  = 0;
    int right = len - 1;

    while (left < right) {
        int temp     = arr[left];
        arr[left]    = arr[right];
        arr[right]   = temp;

        left++;
        right--;
    }
}
```

Clean, no edge case special casing inside the loop, handles all constraints. Every line has a direct reason to exist.

---

## 8. Quick Reference

| Property | Value |
|---|---|
| Technique | Two pointers — opposite ends |
| Time complexity | O(n) |
| Space complexity | O(1) |
| Iterations | n / 2 |
| Handles empty | Yes — early return |
| Handles single | Yes — early return |
| Handles even/odd | Yes — loop condition |

---

*The simplicity of this solution is intentional. Elegant DSA solutions do exactly what the problem requires — no more, no less.*