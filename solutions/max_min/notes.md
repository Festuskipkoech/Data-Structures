# Challenge 2 — Find the Maximum and Minimum

## Problem Statement

Given an unsorted array of integers, find both the maximum and minimum values
in a **single pass** through the array.

```
Input:  [3, 1, 7, 2, 9, 4]
Output: max = 9, min = 1
```

**Target complexity:** O(n) time, O(1) space


---

## How to Think About It

The naive instinct is to make two separate loops — one hunting the max,
one hunting the min. That works, but it costs you two passes and misses
the point of the problem entirely.

The insight: **both searches follow the exact same logic**. On every element
you ask two questions simultaneously:

- Is this larger than what I currently think is the max?
- Is this smaller than what I currently think is the min?

You carry two running answers through the loop — `max` and `min` — and update
each independently. One loop, two comparisons, done.


---

## The Mental Model

Imagine you are watching numbers appear on a screen one at a time. Before any
number appears, you have no answer yet — so you set both `max` and `min` to the
very first number. That first element is simultaneously the largest and smallest
thing you have seen so far, which is correct.

Then for every subsequent element:

```
if element > max  ->  max = element
if element < min  ->  min = element
```

Both conditions are checked on every iteration. They are independent — an
element could update max, update min, update both (impossible), or update
neither.


---

## Step-by-Step Trace

Array: `[3, 1, 7, 2, 9, 4]`

```
Start:       max = 3,  min = 3   (seeded with first element)

i=1  val=1:  1 > 3? No           max stays 3
             1 < 3? Yes          min = 1

i=2  val=7:  7 > 3? Yes          max = 7
             7 < 1? No           min stays 1

i=3  val=2:  2 > 7? No           max stays 7
             2 < 1? No           min stays 1

i=4  val=9:  9 > 7? Yes          max = 9
             9 < 1? No           min stays 1

i=5  val=4:  4 > 9? No           max stays 9
             4 < 1? No           min stays 1

Result: max = 9, min = 1
```


---

## Why This Is O(n) Time, O(1) Space

**Time:** You visit every element exactly once. No nested loops, no sorting,
no second pass. The number of comparisons scales linearly with input size.

**Space:** You only ever hold two extra variables — `max` and `min`. No
auxiliary array, no hash map. Memory usage does not grow with input size.


---

## Edge Cases You Must Handle

| Situation | What to do |
|---|---|
| Empty array | Return early — there is no max or min to find |
| Single element | Max and min are the same value — handled automatically by seeding |
| All identical elements | Max equals min — handled automatically |
| Negative numbers | Comparison operators work correctly, no special handling needed |
| Already sorted | Algorithm is correct, just happens to update on every element (ascending) or only the first (descending) |


---

## Common Mistakes

**Initializing max to 0 and min to 0**

This breaks on arrays of all negative numbers. `min = 0` would never update
because every element is less than zero... wait, actually it would. But `max`
would be wrong for an array like `[-5, -3, -8]` where the true max is `-3`
but initialized `max = 0` would never get updated.

The safe initialization is always the **first element of the array**.

**Using a separate loop for each**

Correct, but you are visiting n elements twice — O(2n) which simplifies to
O(n) but wastes work and violates the problem's single-pass constraint.

**Forgetting to check if the array is empty before accessing index 0**

Accessing `arr[0]` on an empty array is undefined behavior in C. Always guard
against this.


---

## The Pattern to Remember

> Carry running answers through a single loop.
> Seed them with the first element.
> Update independently on each iteration.

This same pattern appears in: finding the second maximum, tracking max
and index together, finding the range (max - min), and many other
"single pass statistics" problems.
