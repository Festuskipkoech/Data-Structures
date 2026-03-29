# DSA Complete Summary
> A personal revision sheet covering all core Data Structures and Algorithms concepts.

---

## Table of Contents
1. [Big O Notation](#big-o-notation)
2. [Arrays](#arrays)
3. [Linked Lists](#linked-lists)
4. [Stacks](#stacks)
5. [Queues](#queues)
6. [Hash Maps](#hash-maps)
7. [Trees](#trees)
8. [Heaps](#heaps)
9. [Graphs](#graphs)
10. [Recursion](#recursion)
11. [Binary Search](#binary-search)
12. [Sorting Algorithms](#sorting-algorithms)
13. [Two Pointers](#two-pointers)
14. [Sliding Window](#sliding-window)
15. [Dynamic Programming](#dynamic-programming)
16. [Tries](#tries)
17. [Big O Cheat Sheet](#big-o-cheat-sheet)

---

## Big O Notation

Big O describes how an algorithm **scales** as input grows. It is about the shape of growth, not exact speed.

### Complexity Classes (fastest to slowest)

| Notation | Name | Example |
|---|---|---|
| O(1) | Constant | Array index access |
| O(log n) | Logarithmic | Binary search |
| O(n) | Linear | Loop through array |
| O(n log n) | Linearithmic | Merge sort, quick sort |
| O(n²) | Quadratic | Nested loops |
| O(2ⁿ) | Exponential | Naive recursion |
| O(n!) | Factorial | Brute force permutations |

### Rules
- **Drop constants** — O(2n) is O(n)
- **Drop lower order terms** — O(n² + n) is O(n²)
- **Worst case by default** unless stated otherwise
- Big O applies to both **time** and **space** independently

### O(n log n) Explained
Every step cuts the problem in half AND you still process all elements at each level.
- For n = 1000: log₂(1000) ≈ 10 levels, n = 1000 work per level → 10,000 operations total
- This is why efficient sorting is O(n log n) — the best achievable for general sorting

---

## Arrays

A **contiguous block of memory**. Every element sits adjacent to the previous one. This layout drives all its properties.

### Key Operations

| Operation | Big O | Why |
|---|---|---|
| Access by index | O(1) | Direct address calculation |
| Search unsorted | O(n) | Must check every element |
| Search sorted | O(log n) | Binary search possible |
| Insert/delete at end | O(1) | No shifting needed |
| Insert/delete in middle | O(n) | Must shift elements |

### Important Notes
- **Search unsorted is O(n)** because there is no pattern to exploit — you scan from index 0 checking every element until found or exhausted
- **Insert/delete in middle is O(n)** because contiguous memory forces shifting of all elements after the target position to fill gaps or make room
- Fast access, slow modification in the middle

---

## Linked Lists

Nodes scattered anywhere in memory, each holding a **value** and a **pointer** to the next node. No contiguous layout, no index.

### Key Operations

| Operation | Big O | Why |
|---|---|---|
| Access by index | O(n) | Must traverse from head |
| Search | O(n) | No direct address calculation |
| Insert/delete at head | O(1) | Just rewire one pointer |
| Insert/delete in middle | O(n) to find + O(1) to do | Traversal to position, then rewire |

### Types
- **Singly Linked** — each node points to next only
- **Doubly Linked** — each node points to both next and previous

### Core Tradeoff

```
Arrays       — fast access O(1), slow insert/delete in middle O(n)
Linked Lists — slow access O(n), fast insert/delete once positioned O(1)
```

Choose based on which operations your problem performs most frequently.

---

## Stacks

**Last In First Out (LIFO)**. Think of a stack of plates — you add and remove from the top only.

### Core Operations

| Operation | Big O | Description |
|---|---|---|
| Push | O(1) | Add to top |
| Pop | O(1) | Remove from top |
| Peek | O(1) | View top without removing |

### Real World Uses
- Undo functionality in editors
- Browser back button history
- Balancing parentheses
- Function call stack in programming

### Key Point
All operations are O(1) because you only ever work at one end — the top.

---

## Queues

**First In First Out (FIFO)**. Think of a supermarket line — first person in is first served.

### Core Operations

| Operation | Big O | Description |
|---|---|---|
| Enqueue | O(1) | Add to back |
| Dequeue | O(1) | Remove from front |

### Real World Uses
- Print job scheduling
- BFS graph traversal
- Request handling in servers

### Stack vs Queue

```
Stack — insert and remove from the SAME end (top)
Queue — insert at back, remove from front
```

---

## Hash Maps

Stores **key-value pairs**. Uses a hash function to convert a key into an array index for direct access.

### How it Works
1. Hash function converts key to a number — e.g. sum ASCII values of characters
2. Modulo maps that number into a valid array index — e.g. 417 % 10 = 7
3. Value stored at that index
4. Same process on retrieval — same key always produces same index

### Key Operations

| Operation | Average | Worst Case | Why Worst Case |
|---|---|---|---|
| Insert | O(1) | O(n) | Collisions |
| Lookup | O(1) | O(n) | Collisions |
| Delete | O(1) | O(n) | Collisions |

### Collisions
When two keys hash to the same index:
- **Chaining** — each slot holds a linked list, new entry appended to the list
- **Open Addressing** — probe forward to find next available empty slot

### Why Hash Maps Are Powerful in Interviews
Many O(n²) brute force problems reduce to O(n) using a hash map to remember what you have already seen. Trading **space for time** is the core pattern.

---

## Trees

A **hierarchical data structure** of nodes connected by edges. Unlike linear structures, trees branch out.

### Vocabulary

| Term | Meaning |
|---|---|
| Root | Topmost node, no parent |
| Node | Any single element |
| Edge | Connection between nodes |
| Leaf | Node with no children |
| Height | Edges from root to deepest leaf |
| Depth | Edges from root to specific node |
| Subtree | Any node and everything below it |

### Binary Tree
Every node has **at most two children** — left and right.

### Binary Search Tree (BST)
Binary tree with ordering rule:
- Everything in left subtree is **less than** current node
- Everything in right subtree is **greater than** current node
- Rule applies to every node

### BST Operations

| Operation | Balanced BST | Unbalanced BST |
|---|---|---|
| Search | O(log n) | O(n) |
| Insert | O(log n) | O(n) |
| Delete | O(log n) | O(n) |
| Traversal | O(n) | O(n) |

### Tree Traversals

| Traversal | Order | Use Case |
|---|---|---|
| In-order | Left, Root, Right | Sorted output from BST |
| Pre-order | Root, Left, Right | Copy or serialize tree |
| Post-order | Left, Right, Root | Delete tree safely |

### Why Trees Are Recursive
Every subtree is itself a valid tree. This self-similar structure makes recursion the natural tool — define behavior at one node, let recursion handle the rest.

---

## Heaps

A **complete binary tree** satisfying the heap property. Stored as an array using index arithmetic.

### Types
- **Max Heap** — every parent is greater than or equal to its children. Root holds maximum.
- **Min Heap** — every parent is less than or equal to its children. Root holds minimum.

### Index Arithmetic (array storage)
For node at index i:
```
Parent      — (i - 1) // 2
Left child  — 2i + 1
Right child — 2i + 2
```

### Key Operations

| Operation | Big O | Notes |
|---|---|---|
| Peek min/max | O(1) | Always at index 0 |
| Insert | O(log n) | Add at end, bubble up |
| Extract min/max | O(log n) | Remove root, replace with last, bubble down |
| Search | O(n) | No shortcut available |
| Build heap | O(n) | From existing array |

### Priority Queue
A heap is the standard implementation of a priority queue — elements served by priority, not arrival order.

### When to Use a Heap
Whenever you need **repeated access to the minimum or maximum** of a changing dataset. Sorting costs O(n log n) upfront. A heap gives O(log n) per operation.

### Common Interview Patterns
- K most frequent elements
- Merge K sorted lists
- Find median from data stream
- Kth largest element

---

## Graphs

A collection of **nodes (vertices)** connected by **edges**. The most general relationship structure. Trees are a special case of graphs.

### Types

| Type | Description | Example |
|---|---|---|
| Undirected | Edges have no direction | Facebook friendships |
| Directed | Edges have direction | Twitter followers |
| Weighted | Edges carry a cost/value | Google Maps distances |
| Unweighted | All edges equal | Basic connectivity |

### Representation

**Adjacency List** — each node stores list of neighbors
```
graph = {
    'A': ['B', 'C'],
    'B': ['A', 'D'],
}
```
Space: O(V + E). Best for sparse graphs.

**Adjacency Matrix** — 2D array where matrix[i][j] = 1 means edge exists
Space: O(V²). Best for dense graphs.

### Traversal Algorithms

#### DFS — Depth First Search
Go as deep as possible before backtracking. Uses a stack (or recursion).

| Property | Value |
|---|---|
| Time | O(V + E) |
| Space | O(V) |
| Use for | Cycle detection, path existence, topological sort |

#### BFS — Breadth First Search
Visit all neighbors at current level before going deeper. Uses a queue.

| Property | Value |
|---|---|
| Time | O(V + E) |
| Space | O(V) |
| Use for | Shortest path, level order traversal, nearest neighbor |

### Critical Rule
Always maintain a **visited set** to prevent infinite loops in graphs with cycles.

### DFS vs BFS

```
DFS — go deep first, uses stack, finds if path exists
BFS — go wide first, uses queue, finds shortest path
```

---

## Recursion

A function that **calls itself** to solve a smaller version of the same problem.

### Two Required Parts
- **Base case** — condition that stops recursion. Missing this causes stack overflow.
- **Recursive case** — function calls itself with smaller input, moving toward base case.

### The Call Stack
Every recursive call is pushed onto the call stack and waits for the call below it to return. This is why missing a base case causes a stack overflow — the stack grows until memory runs out.

### Big O of Recursion
Depends on branching and depth:
- One call per level, depth n → O(n) time, O(n) space
- Two calls per level → O(2ⁿ) exponential

### Good vs Bad Recursion

| Type | Technique | Time | Space |
|---|---|---|---|
| Bad — naive | Recalculate everything | O(2ⁿ) | O(n) |
| Good — memoized | Cache results, reuse | O(n) | O(n) |

### Memoization
Store results of subproblems in a hash map. When the same subproblem appears again, return the cached result instead of recalculating.

### When to Use Recursion
When the problem contains smaller versions of itself — trees, graphs, divide and conquer. Convert to iterative when input is massive and stack depth becomes a concern.

---

## Binary Search

An algorithm for finding a target in a **sorted** array by repeatedly halving the search space.

### How it Works
1. Set left pointer at index 0, right pointer at last index
2. Calculate midpoint
3. If mid equals target — found it
4. If mid is less than target — target is in right half, move left up
5. If mid is greater than target — target is in left half, move right down
6. If left crosses right — target does not exist

### Big O

| Case | Time | Space |
|---|---|---|
| Best | O(1) | O(1) iterative |
| Average | O(log n) | O(1) iterative |
| Worst | O(log n) | O(log n) recursive |

### Critical Requirement
Array **must be sorted**. Binary search is invalid on unsorted data — the decision to go left or right depends entirely on sorted order.

### Connection to BST
Binary search on a sorted array and searching a BST are the same algorithm expressed differently. In an array you use index arithmetic to find the midpoint. In a BST the midpoint is the current node and the halves are the left and right subtrees.

---

## Sorting Algorithms

### Merge Sort

**Divide and conquer**. Split array in half recursively until single elements, then merge sorted halves back up.

| Case | Time | Space |
|---|---|---|
| Best | O(n log n) | O(n) |
| Average | O(n log n) | O(n) |
| Worst | O(n log n) | O(n) |

- Guaranteed O(n log n) in all cases — its biggest strength
- Requires extra space for merging
- Stable sort — equal elements maintain original relative order

### Quick Sort

**Divide and conquer**. Pick a pivot, partition array so everything less than pivot is left, everything greater is right. Pivot is now in final position. Recurse on both sides.

| Case | Time | Space |
|---|---|---|
| Best | O(n log n) | O(log n) |
| Average | O(n log n) | O(log n) |
| Worst | O(n²) | O(log n) |

- Worst case when pivot is always smallest or largest — use random pivot to avoid
- In-place — does not need extra array
- Faster than merge sort in practice on average

### Merge Sort vs Quick Sort

| Property | Merge Sort | Quick Sort |
|---|---|---|
| Worst case time | O(n log n) | O(n²) |
| Space | O(n) | O(log n) |
| Stable | Yes | No |
| In-place | No | Yes |
| Interview choice | Safer, predictable | Faster in practice |

---

## Two Pointers

A **technique** using two index variables that move through data simultaneously to eliminate nested loops and reduce O(n²) to O(n).

### Two Variations

**Opposite Ends** — one pointer at start, one at end, move toward each other
- Use for: pairs in sorted arrays, reversing in place, palindrome checking

**Same Direction** — both start at beginning, move at different speeds
- Use for: cycle detection in linked lists, removing duplicates

### Big O

| | Value |
|---|---|
| Time | O(n) |
| Space | O(1) |

### When to Reach for Two Pointers
- Finding a pair in a sorted array
- Comparing elements from both ends
- Removing duplicates in place
- Reversing something in place
- Checking symmetry like palindromes

---

## Sliding Window

An extension of two pointers. Maintains a **contiguous window** between two pointers and slides it across data, expanding and contracting based on conditions.

### Two Variations

**Fixed Size Window** — window size K is given, never changes
- Calculate first window, then slide by adding new element and removing old one
- Never recalculate entire window — just adjust by what entered and left

**Variable Size Window** — window expands and contracts based on a condition
- Expand right pointer to grow
- When condition violated, shrink from left until valid again
- Track best result seen

### General Template
```
expand right pointer    — grow the window
check condition         — is window still valid?
shrink left pointer     — contract until valid again
update answer           — track best result seen
```

### Big O

| | Value |
|---|---|
| Time | O(n) — right moves forward n times, left moves forward at most n times total |
| Space | O(k) — size of window or character set tracked in hash map |

### When to Reach for Sliding Window
- Longest or shortest subarray satisfying a condition
- Maximum or minimum sum of fixed size subarray
- Any problem about contiguous elements with some property

### Connection to Hash Maps
Most variable size sliding window problems use a hash map to track window contents in O(1), bringing overall complexity to O(n).

---

## Dynamic Programming

Solving problems by breaking into subproblems, solving each **once**, storing results, and reusing them. Recursion plus memoization taken to its full potential.

### Two Required Conditions
- **Optimal Substructure** — optimal solution built from optimal subproblem solutions
- **Overlapping Subproblems** — same subproblems appear multiple times

### Two Approaches

| Approach | Method | Notes |
|---|---|---|
| Top Down (Memoization) | Recursive with cache | Natural, only solves needed subproblems |
| Bottom Up (Tabulation) | Iterative, fill table | No recursion overhead, no stack overflow risk |

### The Framework for Any DP Problem
1. **Define the subproblem** — what does dp[i] represent?
2. **Find the recurrence relation** — how does dp[i] relate to previous values?
3. **Identify base cases** — smallest subproblems answered directly
4. **Determine fill order** — ensure dependencies are computed before they are needed

### Common Patterns

| Pattern | Description | Example Problems |
|---|---|---|
| Linear DP | dp[i] depends on dp[i-1] or dp[i-2] | Fibonacci, climbing stairs, house robber |
| 2D DP | dp[i][j] depends on neighbors | Knapsack, unique paths |
| String DP | Comparing two strings | Longest common subsequence, edit distance |
| Interval DP | Solving ranges | Matrix chain multiplication |

### Big O
Depends on number of subproblems and work per subproblem:
- Fibonacci: O(n) time, O(1) space optimized
- Knapsack: O(n × W) time and space

### The Honest Truth
The hard part is not the code — it is recognizing that DP applies and defining what dp[i] means. That insight comes from solving many problems until patterns become instinctive.

---

## Tries

A tree-like structure for storing and searching **strings**. Each node stores a single character. Words are formed by following paths from root to a marked endpoint.

### Node Structure
Each node contains:
- A dictionary of children — one entry per character that follows
- A boolean `is_end_of_word` flag

### Key Operations

| Operation | Big O | Notes |
|---|---|---|
| Insert | O(m) | m is word length |
| Search exact | O(m) | Check is_end_of_word at last node |
| Prefix search | O(m) | Do not check is_end_of_word |

### Trie vs Hash Map for Strings

| Operation | Hash Map | Trie |
|---|---|---|
| Exact search | O(m) | O(m) |
| Prefix search | O(n × m) | O(m) |
| Autocomplete | O(n × m) | O(m + results) |

Trie wins decisively on anything **prefix related**. Hash map cannot efficiently answer prefix queries.

### Real World Uses
- Autocomplete in search bars
- Spell checkers
- IP routing
- Word games

### Space Tradeoff
Tries can use significant memory. The dictionary children approach only allocates used slots, which is more efficient than an array of 26 slots per node.

---

## Big O Cheat Sheet

### Data Structures

| Structure | Access | Search | Insert | Delete | Space |
|---|---|---|---|---|---|
| Array | O(1) | O(n) | O(n) | O(n) | O(n) |
| Linked List | O(n) | O(n) | O(1) head | O(1) head | O(n) |
| Stack | O(n) | O(n) | O(1) | O(1) | O(n) |
| Queue | O(n) | O(n) | O(1) | O(1) | O(n) |
| Hash Map | N/A | O(1) avg | O(1) avg | O(1) avg | O(n) |
| BST balanced | O(log n) | O(log n) | O(log n) | O(log n) | O(n) |
| Heap | O(1) top | O(n) | O(log n) | O(log n) | O(n) |
| Trie | O(m) | O(m) | O(m) | O(m) | O(n×m) |

### Algorithms

| Algorithm | Best | Average | Worst | Space |
|---|---|---|---|---|
| Binary Search | O(1) | O(log n) | O(log n) | O(1) |
| Merge Sort | O(n log n) | O(n log n) | O(n log n) | O(n) |
| Quick Sort | O(n log n) | O(n log n) | O(n²) | O(log n) |
| DFS | O(V+E) | O(V+E) | O(V+E) | O(V) |
| BFS | O(V+E) | O(V+E) | O(V+E) | O(V) |
| Two Pointers | O(n) | O(n) | O(n) | O(1) |
| Sliding Window | O(n) | O(n) | O(n) | O(k) |

---

*Built from first principles. Every concept here connects to the others — master the fundamentals and the advanced topics follow naturally.*