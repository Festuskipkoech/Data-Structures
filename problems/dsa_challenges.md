# DSA Challenges
> Practice problems for every core DSA topic. Solve in C or Python — your choice.
> Aim for correctness first, then optimize for time and space complexity.
> Always test edge cases: empty input, single element, duplicates, large input.

---

## Table of Contents
1. [Arrays](#arrays)
2. [Linked Lists](#linked-lists)
3. [Stacks](#stacks)
4. [Queues](#queues)
5. [Hash Maps](#hash-maps)
6. [Trees](#trees)
7. [Heaps](#heaps)
8. [Graphs](#graphs)
9. [Recursion](#recursion)
10. [Binary Search](#binary-search)
11. [Sorting](#sorting)
12. [Two Pointers](#two-pointers)
13. [Sliding Window](#sliding-window)
14. [Dynamic Programming](#dynamic-programming)
15. [Tries](#tries)

---

## Arrays

### Challenge 1 — Reverse an Array In-Place
**Difficulty:** Easy

Reverse the given array in-place. Do not create a new array.

```
Input:  [1, 2, 3, 4, 5]
Output: [5, 4, 3, 2, 1]
```

**Constraints:** 0 ≤ len(A) ≤ 10⁵

**Edge cases to test:**
- Empty array
- Single element
- Even vs odd length

**Target complexity:** O(n) time, O(1) space

---

### Challenge 2 — Find the Maximum and Minimum
**Difficulty:** Easy

Given an unsorted array of integers, find both the maximum and minimum values in a single pass.

```
Input:  [3, 1, 7, 2, 9, 4]
Output: max = 9, min = 1
```

**Constraints:** 1 ≤ len(A) ≤ 10⁵

**Target complexity:** O(n) time, O(1) space

---

### Challenge 3 — Rotate Array
**Difficulty:** Medium

Rotate array A to the right by K positions.

```
Input:  A = [3, 8, 9, 7, 6], K = 3
Output: [9, 7, 6, 3, 8]
```

**Constraints:** 0 ≤ N ≤ 10⁵, 0 ≤ K ≤ 10⁹

**Hint:** K can be larger than the array length. What operation handles that?

**Target complexity:** O(n) time, O(1) space

---

### Challenge 4 — Two Sum
**Difficulty:** Medium

Given an array of integers and a target, return the indices of the two numbers that add up to the target. Each input has exactly one solution.

```
Input:  nums = [2, 7, 11, 15], target = 9
Output: [0, 1]
```

**Constraints:** 2 ≤ len(nums) ≤ 10⁴

**Hint:** Brute force is O(n²). Can you do O(n) using a hash map?

**Target complexity:** O(n) time, O(n) space

---

### Challenge 5 — Missing Number
**Difficulty:** Medium

Given an array containing n distinct numbers in the range [0, n], return the one missing number.

```
Input:  [3, 0, 1]
Output: 2
```

**Constraints:** 1 ≤ n ≤ 10⁴

**Hint:** Think about the sum of first n natural numbers.

**Target complexity:** O(n) time, O(1) space

---

### Challenge 6 — Count Non-Divisible (Hard)
**Difficulty:** Hard

Given array A of N integers, for each A[i] count how many elements in A are not divisors of A[i]. Return an array of those counts.

```
Input:  [3, 1, 2, 3, 6]
Output: [2, 4, 3, 2, 0]
```

**Constraints:** 1 ≤ N ≤ 5×10⁴, 1 ≤ A[i] ≤ 10⁶

**Hint:** Brute force O(n²) will time out. Precompute frequencies and use divisor counting.

**Target complexity:** O(N × sqrt(maxA))

---

## Linked Lists

### Challenge 7 — Reverse a Linked List
**Difficulty:** Easy

Reverse a singly linked list in-place.

```
Input:  1 → 2 → 3 → 4 → 5 → None
Output: 5 → 4 → 3 → 2 → 1 → None
```

**Target complexity:** O(n) time, O(1) space

---

### Challenge 8 — Detect a Cycle
**Difficulty:** Medium

Given the head of a linked list, determine if the list contains a cycle.

```
Input:  1 → 2 → 3 → 4 → 2 (cycle back to node 2)
Output: true
```

**Hint:** Use fast and slow pointers. No extra data structures needed.

**Target complexity:** O(n) time, O(1) space

---

### Challenge 9 — Find the Middle Node
**Difficulty:** Easy

Given the head of a linked list, return the middle node. If there are two middle nodes return the second.

```
Input:  1 → 2 → 3 → 4 → 5
Output: node with value 3

Input:  1 → 2 → 3 → 4
Output: node with value 3
```

**Hint:** Fast and slow pointer again. When fast reaches the end where is slow?

**Target complexity:** O(n) time, O(1) space

---

### Challenge 10 — Merge Two Sorted Lists
**Difficulty:** Medium

Merge two sorted linked lists and return the merged list sorted.

```
Input:  1 → 2 → 4   and   1 → 3 → 4
Output: 1 → 1 → 2 → 3 → 4 → 4
```

**Target complexity:** O(n + m) time, O(1) space

---

## Stacks

### Challenge 11 — Valid Parentheses
**Difficulty:** Easy

Given a string containing only '(', ')', '{', '}', '[', ']', determine if the input string is valid. Brackets must close in the correct order.

```
Input:  "()[]{}"
Output: true

Input:  "([)]"
Output: false
```

**Hint:** Push opening brackets onto a stack. When you see a closing bracket check the top.

**Target complexity:** O(n) time, O(n) space

---

### Challenge 12 — Implement a Stack Using an Array
**Difficulty:** Easy

Implement a stack class with push, pop, peek, and is_empty operations using only an array as the underlying structure.

**Operations to implement:**
- `push(value)` — add to top
- `pop()` — remove and return top, raise error if empty
- `peek()` — return top without removing, raise error if empty
- `is_empty()` — return true if stack has no elements

---

### Challenge 13 — Minimum Stack
**Difficulty:** Medium

Design a stack that supports push, pop, peek and retrieving the minimum element in O(1) time.

```
push(5), push(3), push(7), push(2)
get_min() → 2
pop()
get_min() → 3
```

**Hint:** Use a second stack to track minimums.

**Target complexity:** O(1) for all operations

---

## Queues

### Challenge 14 — Implement a Queue Using Two Stacks
**Difficulty:** Medium

Implement a queue (FIFO) using only two stacks.

**Operations to implement:**
- `enqueue(value)` — add to back
- `dequeue()` — remove from front
- `peek()` — view front without removing
- `is_empty()`

**Hint:** One stack for input, one for output. Transfer when output is empty.

---

### Challenge 15 — Recent Counter
**Difficulty:** Easy

Implement a class that counts the number of recent requests within the past 3000 milliseconds.

```
ping(1)    → 1
ping(100)  → 2
ping(3001) → 3
ping(3002) → 3
```

**Hint:** A queue where you remove timestamps that are no longer within range.

**Target complexity:** O(1) amortized per ping

---

## Hash Maps

### Challenge 16 — Two Sum with Hash Map
**Difficulty:** Easy

Same as Challenge 4 but you must implement it using a hash map explicitly. Show the O(n) approach clearly.

---

### Challenge 17 — First Non-Repeating Character
**Difficulty:** Easy

Given a string, find the first character that appears exactly once.

```
Input:  "leetcode"
Output: "l"

Input:  "aabb"
Output: "" (none found)
```

**Target complexity:** O(n) time, O(1) space (alphabet is fixed size)

---

### Challenge 18 — Group Anagrams
**Difficulty:** Medium

Given an array of strings, group the anagrams together.

```
Input:  ["eat","tea","tan","ate","nat","bat"]
Output: [["bat"],["nat","tan"],["ate","eat","tea"]]
```

**Hint:** What do all anagrams of a word have in common when sorted?

**Target complexity:** O(n × m log m) where m is max string length

---

### Challenge 19 — Longest Consecutive Sequence
**Difficulty:** Hard

Given an unsorted array of integers, return the length of the longest consecutive sequence.

```
Input:  [100, 4, 200, 1, 3, 2]
Output: 4  (sequence 1, 2, 3, 4)
```

**Hint:** Put everything in a hash set. For each number check if it is the start of a sequence.

**Target complexity:** O(n) time

---

## Trees

### Challenge 20 — Maximum Depth of Binary Tree
**Difficulty:** Easy

Given the root of a binary tree return its maximum depth — the number of nodes along the longest path from root to a leaf.

```
Input:
        3
       / \
      9  20
        /  \
       15   7

Output: 3
```

**Hint:** Recursion. Depth of a node is 1 + max(depth of left, depth of right).

**Target complexity:** O(n) time, O(h) space where h is tree height

---

### Challenge 21 — Invert a Binary Tree
**Difficulty:** Easy

Given the root of a binary tree, invert it — mirror the tree by swapping every left and right child.

```
Input:
        4
       / \
      2   7
     / \ / \
    1  3 6  9

Output:
        4
       / \
      7   2
     / \ / \
    9  6 3  1
```

**Target complexity:** O(n) time

---

### Challenge 22 — Validate a Binary Search Tree
**Difficulty:** Medium

Given the root of a binary tree, determine if it is a valid BST.

```
Input:
      5
     / \
    1   4
       / \
      3   6

Output: false  (4 is in right subtree of 5 but 4 < 5)
```

**Hint:** Track valid min and max range for each node.

**Target complexity:** O(n) time

---

### Challenge 23 — Lowest Common Ancestor
**Difficulty:** Medium

Given a BST and two nodes p and q, find their lowest common ancestor — the deepest node that has both p and q as descendants.

```
Input: BST root, p = 2, q = 8
Output: node 6 (root)
```

**Hint:** Use the BST property. If both values are less than current go left. If both greater go right. Otherwise current is the LCA.

**Target complexity:** O(h) time where h is tree height

---

## Heaps

### Challenge 24 — Kth Largest Element
**Difficulty:** Medium

Find the kth largest element in an unsorted array.

```
Input:  nums = [3, 2, 1, 5, 6, 4], k = 2
Output: 5
```

**Hint:** Maintain a min heap of size k. The root is always the kth largest.

**Target complexity:** O(n log k) time

---

### Challenge 25 — Top K Frequent Elements
**Difficulty:** Medium

Given an integer array, return the k most frequent elements.

```
Input:  nums = [1, 1, 1, 2, 2, 3], k = 2
Output: [1, 2]
```

**Target complexity:** O(n log k) time

---

### Challenge 26 — Merge K Sorted Lists
**Difficulty:** Hard

Merge k sorted linked lists and return one sorted list.

```
Input:  [1→4→5, 1→3→4, 2→6]
Output: 1→1→2→3→4→4→5→6
```

**Hint:** Use a min heap. Push the head of each list. Pop minimum, push its next node.

**Target complexity:** O(n log k) where n is total nodes, k is number of lists

---

## Graphs

### Challenge 27 — Number of Islands
**Difficulty:** Medium

Given a 2D grid of '1' (land) and '0' (water), count the number of islands. An island is surrounded by water and formed by connecting adjacent land cells horizontally or vertically.

```
Input:
11110
11010
11000
00000

Output: 1
```

**Hint:** DFS from each unvisited land cell, marking visited cells as you go.

**Target complexity:** O(m × n) time

---

### Challenge 28 — Clone a Graph
**Difficulty:** Medium

Given a reference to a node in a connected undirected graph, return a deep copy of the graph.

**Hint:** DFS with a hash map from original node to its clone.

**Target complexity:** O(V + E) time

---

### Challenge 29 — Course Schedule (Cycle Detection)
**Difficulty:** Medium

There are n courses. Some courses have prerequisites. Given a list of prerequisite pairs, determine if it is possible to finish all courses.

```
Input:  n = 2, prerequisites = [[1,0]]
Output: true  (take course 0 then course 1)

Input:  n = 2, prerequisites = [[1,0],[0,1]]
Output: false  (cycle — each requires the other)
```

**Hint:** Build a directed graph and detect a cycle using DFS.

**Target complexity:** O(V + E) time

---

### Challenge 30 — Shortest Path in Binary Matrix
**Difficulty:** Medium

Given an n × n binary matrix, return the length of the shortest clear path from top-left to bottom-right. A clear path only goes through cells with value 0, moving in 8 directions.

```
Input:
[[0,1],
 [1,0]]

Output: 2
```

**Hint:** BFS guarantees shortest path. DFS does not.

**Target complexity:** O(n²) time

---

## Recursion

### Challenge 31 — Fibonacci with Memoization
**Difficulty:** Easy

Implement Fibonacci using top-down memoization. Ensure no subproblem is computed twice.

```
Input:  n = 10
Output: 55
```

**Target complexity:** O(n) time, O(n) space

---

### Challenge 32 — Power Function
**Difficulty:** Medium

Implement pow(x, n) — raise x to the power n. Handle negative exponents.

```
Input:  x = 2.0, n = 10
Output: 1024.0

Input:  x = 2.0, n = -2
Output: 0.25
```

**Hint:** Recursive — pow(x, n) = pow(x, n//2) × pow(x, n//2). This gives O(log n) not O(n).

**Target complexity:** O(log n) time

---

### Challenge 33 — Generate All Subsets
**Difficulty:** Medium

Given an integer array of unique elements, return all possible subsets.

```
Input:  [1, 2, 3]
Output: [[], [1], [2], [3], [1,2], [1,3], [2,3], [1,2,3]]
```

**Hint:** For each element you make a binary choice — include it or not. Recursion handles this naturally.

**Target complexity:** O(2ⁿ) — unavoidable, there are 2ⁿ subsets

---

### Challenge 34 — Flatten Nested List
**Difficulty:** Medium

Given a nested list where each element is either an integer or a list of integers (recursively), flatten it into a single list.

```
Input:  [1, [2, [3, 4], 5], 6]
Output: [1, 2, 3, 4, 5, 6]
```

**Target complexity:** O(n) time where n is total number of integers

---

## Binary Search

### Challenge 35 — Classic Binary Search
**Difficulty:** Easy

Implement binary search. Given a sorted array and a target, return the index of target or -1 if not found.

```
Input:  nums = [-1, 0, 3, 5, 9, 12], target = 9
Output: 4
```

**Target complexity:** O(log n) time, O(1) space

---

### Challenge 36 — Search in Rotated Sorted Array
**Difficulty:** Medium

A sorted array was rotated at some unknown pivot. Search for a target value.

```
Input:  nums = [4, 5, 6, 7, 0, 1, 2], target = 0
Output: 4
```

**Hint:** Modified binary search. At each step one half is always sorted — use that to decide which half to search.

**Target complexity:** O(log n) time

---

### Challenge 37 — Find First and Last Position
**Difficulty:** Medium

Given a sorted array that may contain duplicates and a target, find the first and last position of the target.

```
Input:  nums = [5, 7, 7, 8, 8, 10], target = 8
Output: [3, 4]
```

**Hint:** Two separate binary searches — one for leftmost, one for rightmost.

**Target complexity:** O(log n) time

---

### Challenge 38 — Frog Jump
**Difficulty:** Easy

A frog starts at position X and wants to reach position Y. Each jump covers exactly D distance. Find the minimum number of jumps needed.

```
Input:  X = 10, Y = 85, D = 30
Output: 3
```

**Target complexity:** O(1) — pure math

---

## Sorting

### Challenge 39 — Implement Merge Sort
**Difficulty:** Medium

Implement merge sort from scratch. Return the sorted array.

```
Input:  [38, 27, 43, 3, 9, 82, 10]
Output: [3, 9, 10, 27, 38, 43, 82]
```

**Target complexity:** O(n log n) time, O(n) space

---

### Challenge 40 — Implement Quick Sort
**Difficulty:** Medium

Implement quick sort from scratch using last element as pivot.

```
Input:  [10, 7, 8, 9, 1, 5]
Output: [1, 5, 7, 8, 9, 10]
```

**Target complexity:** O(n log n) average, O(n²) worst case

---

### Challenge 41 — Sort Colors (Dutch National Flag)
**Difficulty:** Medium

Given an array with only 0s, 1s, and 2s, sort them in-place in a single pass without using a sorting function.

```
Input:  [2, 0, 2, 1, 1, 0]
Output: [0, 0, 1, 1, 2, 2]
```

**Hint:** Three pointers — low, mid, high.

**Target complexity:** O(n) time, O(1) space

---

## Two Pointers

### Challenge 42 — Valid Palindrome
**Difficulty:** Easy

Given a string, determine if it is a palindrome considering only alphanumeric characters and ignoring case.

```
Input:  "A man, a plan, a canal: Panama"
Output: true

Input:  "race a car"
Output: false
```

**Target complexity:** O(n) time, O(1) space

---

### Challenge 43 — Container With Most Water
**Difficulty:** Medium

Given n vertical lines where line i has height h[i], find two lines that together with the x-axis forms a container that holds the most water.

```
Input:  [1, 8, 6, 2, 5, 4, 8, 3, 7]
Output: 49
```

**Hint:** Start with widest container. Move the shorter line inward — why is this always safe?

**Target complexity:** O(n) time, O(1) space

---

### Challenge 44 — Three Sum
**Difficulty:** Medium

Given an integer array, return all triplets that sum to zero. No duplicate triplets.

```
Input:  [-1, 0, 1, 2, -1, -4]
Output: [[-1, -1, 2], [-1, 0, 1]]
```

**Hint:** Sort first. Fix one element, then use two pointers on the rest.

**Target complexity:** O(n²) time

---

### Challenge 45 — Remove Duplicates from Sorted Array
**Difficulty:** Easy

Given a sorted array, remove duplicates in-place. Return the new length.

```
Input:  [1, 1, 2, 3, 3, 4]
Output: 4  (array becomes [1, 2, 3, 4, ...])
```

**Target complexity:** O(n) time, O(1) space

---

## Sliding Window

### Challenge 46 — Longest Substring Without Repeating Characters
**Difficulty:** Medium

Given a string, find the length of the longest substring without repeating characters.

```
Input:  "abcabcbb"
Output: 3  (substring "abc")
```

**Hint:** Sliding window with a hash map tracking last seen index of each character.

**Target complexity:** O(n) time, O(min(n, alphabet)) space

---

### Challenge 47 — Maximum Sum Subarray of Size K
**Difficulty:** Easy

Given an array and integer K, find the maximum sum of any contiguous subarray of size K.

```
Input:  arr = [2, 1, 5, 1, 3, 2], K = 3
Output: 9  (subarray [5, 1, 3])
```

**Hint:** Calculate first window then slide — add new element, subtract removed element.

**Target complexity:** O(n) time, O(1) space

---

### Challenge 48 — Minimum Window Substring
**Difficulty:** Hard

Given strings s and t, return the minimum window substring of s that contains all characters of t.

```
Input:  s = "ADOBECODEBANC", t = "ABC"
Output: "BANC"
```

**Hint:** Variable sliding window with two hash maps tracking character counts.

**Target complexity:** O(n) time

---

### Challenge 49 — Longest Repeating Character Replacement
**Difficulty:** Medium

Given a string and integer K, find the length of the longest substring containing the same letter after replacing at most K characters.

```
Input:  s = "AABABBA", k = 1
Output: 4
```

**Hint:** Sliding window. Window is valid if (window size - count of most frequent char) ≤ K.

**Target complexity:** O(n) time

---

## Dynamic Programming

### Challenge 50 — Climbing Stairs
**Difficulty:** Easy

You can climb 1 or 2 steps at a time. How many distinct ways can you reach the nth step?

```
Input:  n = 4
Output: 5
```

**Target complexity:** O(n) time, O(1) space optimized

---

### Challenge 51 — House Robber
**Difficulty:** Medium

Given an array of non-negative integers representing house values, find the maximum amount you can rob without robbing two adjacent houses.

```
Input:  [2, 7, 9, 3, 1]
Output: 12  (rob houses 0, 2, 4 → 2 + 9 + 1)
```

**Hint:** dp[i] = max(dp[i-1], dp[i-2] + nums[i])

**Target complexity:** O(n) time, O(1) space optimized

---

### Challenge 52 — 0/1 Knapsack
**Difficulty:** Medium

Given items with weights and values and a bag of capacity W, maximize total value without exceeding capacity. Each item used at most once.

```
Input:
  capacity = 6
  weights  = [2, 2, 3]
  values   = [6, 10, 12]
Output: 22  (items 2 and 3, weight 5, value 22)
```

**Target complexity:** O(n × W) time and space

---

### Challenge 53 — Longest Common Subsequence
**Difficulty:** Medium

Given two strings, return the length of their longest common subsequence.

```
Input:  text1 = "abcde", text2 = "ace"
Output: 3  (subsequence "ace")
```

**Hint:** 2D DP table. dp[i][j] = LCS of first i chars of text1 and first j chars of text2.

**Target complexity:** O(m × n) time and space

---

### Challenge 54 — Coin Change
**Difficulty:** Medium

Given coin denominations and a target amount, find the minimum number of coins needed to make that amount. You have unlimited coins of each denomination.

```
Input:  coins = [1, 5, 10, 25], amount = 36
Output: 3  (25 + 10 + 1)
```

**Hint:** dp[i] = minimum coins needed to make amount i

**Target complexity:** O(amount × number of coins) time

---

### Challenge 55 — Word Break
**Difficulty:** Medium

Given a string s and a dictionary of words, determine if s can be segmented into a sequence of dictionary words.

```
Input:  s = "leetcode", wordDict = ["leet","code"]
Output: true
```

**Target complexity:** O(n²) time

---

## Tries

### Challenge 56 — Implement a Trie
**Difficulty:** Medium

Implement a Trie with insert, search, and starts_with operations.

```
trie.insert("apple")
trie.search("apple")    → true
trie.search("app")      → false
trie.starts_with("app") → true
trie.insert("app")
trie.search("app")      → true
```

**Target complexity:** O(m) per operation where m is key length

---

### Challenge 57 — Word Search II
**Difficulty:** Hard

Given a 2D board of characters and a list of words, find all words that exist in the board. Words can be constructed from adjacent cells horizontally or vertically.

```
Input:
board = [["o","a","a","n"],
         ["e","t","a","e"],
         ["i","h","k","r"],
         ["i","f","l","v"]]
words = ["oath","pea","eat","rain"]

Output: ["eat","oath"]
```

**Hint:** Build a Trie from the words, then DFS on the board pruning with the Trie.

**Target complexity:** O(m × n × 4^L) where L is max word length

---

### Challenge 58 — Shorten a Message
**Difficulty:** Medium

Given a string message and integer K, shorten the message to at most K characters by removing whole words from the end. Add "..." only if words were removed.

```
Input:  message = "This is a long message for testing", K = 20
Output: "This is a long..."
```

**Constraints:** 1 ≤ len(message) ≤ 10⁴, 1 ≤ K ≤ 100

**Edge cases:** K smaller than first word, exact fit, all words fit

---

## General Challenges (Mixed Topics)

### Challenge 59 — LRU Cache
**Difficulty:** Hard

Design a data structure that follows the Least Recently Used cache eviction policy. Implement get and put in O(1).

```
cache = LRUCache(2)
cache.put(1, 1)
cache.put(2, 2)
cache.get(1)    → 1
cache.put(3, 3) → evicts key 2
cache.get(2)    → -1 (not found)
```

**Hint:** Combine a hash map with a doubly linked list.

**Target complexity:** O(1) for both get and put

---

### Challenge 60 — Odd Occurrences in Array
**Difficulty:** Easy

Given an array where every element appears an even number of times except one, find that unpaired element.

```
Input:  [9, 3, 9, 3, 9, 7, 9]
Output: 7
```

**Hint:** XOR trick. x XOR x = 0. x XOR 0 = x. XOR all elements together.

**Target complexity:** O(n) time, O(1) space

---

*Work through these systematically. Start easy within each topic, push to hard. Time yourself — 20 to 45 minutes per problem. Always ask: is there a better time complexity? Is there a better space complexity? Can I handle all edge cases cleanly?*
