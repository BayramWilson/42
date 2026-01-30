*This project has been created as part of the 42 curriculum by bwilson*

# Push Swap

## Description

**Push Swap** is a sorting algorithm project where the goal is to sort a stack of integers using a limited set of operations, with the minimum number of moves possible.

The project consists of two stacks:
- **Stack A**: Contains the initial unsorted integers
- **Stack B**: An empty auxiliary stack used during sorting

The challenge is to sort Stack A in ascending order using only the following operations:
- `sa`, `sb`, `ss` — Swap the first two elements
- `pa`, `pb` — Push top element between stacks
- `ra`, `rb`, `rr` — Rotate (first becomes last)
- `rra`, `rrb`, `rrr` — Reverse rotate (last becomes first)

This implementation uses:
- **Sort 3**: Hardcoded optimal sorting for 3 elements
- **Sort 5**: Optimized sorting for 4-5 elements
- **Turk Algorithm**: Cost-based sorting for 6+ elements

## Instructions

### Compilation

```bash
make        # Compile the project
make clean  # Remove object files
make fclean # Remove object files and executable
make re     # Recompile from scratch
```

### Usage

```bash
./push_swap <numbers>
```

**Examples:**
```bash
# Sort 5 numbers
./push_swap 4 67 3 87 23

# Sort numbers passed as a string
./push_swap "4 67 3 87 23"

# Count operations
ARG="4 67 3 87 23"; ./push_swap $ARG | wc -l

# Verify with checker (if available)
ARG="4 67 3 87 23"; ./push_swap $ARG | ./checker_linux $ARG
```

```bash
ARG=$(shuf -i 1-500 -n 500 | tr '\n' ' ')
OPS=$(./push_swap $ARG)

echo "$OPS" | ./checker_linux $ARG
echo "instructions: $(echo "$OPS" | wc -l)"
```

### Testing with Random Numbers

```bash
# Test with 100 random numbers
ARG=$(shuf -i 1-100 -n 100 | tr '\n' ' '); ./push_swap $ARG | wc -l

# Test with 500 random numbers
ARG=$(shuf -i 1-500 -n 500 | tr '\n' ' '); ./push_swap $ARG | wc -l
```

### Expected Performance

| Input Size | Target Operations |
|------------|-------------------|
| 3 numbers  | ≤ 3 operations    |
| 5 numbers  | ≤ 12 operations   |
| 100 numbers| < 700 operations  |
| 500 numbers| < 5500 operations |

## Resources

### Documentation & References
- [Push Swap Tutorial - Medium](https://medium.com/@jamierobertdawson/push-swap-the-least-amount-of-moves-with-two-stacks-d1e76a71789a)
- [Visualizer for Push Swap](https://github.com/o-reo/push_swap_visualizer)

### AI Usage Disclosure

AI assistance (Claude) was used in this project for:
- **Algorithm explanation**: Understanding the Turk algorithm concepts and cost-based sorting
- **Code structure**: Organizing helper functions and splitting code for norminette compliance
- **Debugging**: Identifying issues like missing function declarations and logic errors
- **Documentation**: Generating this README and the detailed algorithm guide below

All code was reviewed, understood, and adapted by the student. The core algorithm logic and implementation decisions were made by the student with AI serving as a learning and debugging tool.

---

# Sorting Algorithms - Detailed Guide

## Table of Contents
1. [Basic Operations](#basic-operations)
2. [Helper Functions](#helper-functions)
3. [Sort 3 Algorithm](#sort-3-algorithm)
4. [Sort 5 Algorithm (4 elements)](#sort-5-algorithm-for-4-elements)
5. [Sort 5 Algorithm (5 elements)](#sort-5-algorithm-for-5-elements)
6. [Turk Algorithm (6+ elements)](#turk-algorithm-6-elements)

---

## Basic Operations

Before understanding the sorting algorithms, you need to know the basic operations available:

### Stack A and Stack B
- **Stack A**: The main stack we're sorting
- **Stack B**: A temporary stack used for sorting

### Operations

#### 1. **sa** - Swap A
Swaps the first two elements at the top of stack A.
```
Before:  A = [3, 1, 2]  (top is 3)
After:   A = [1, 3, 2]  (top is 1)
```

#### 2. **ra** - Rotate A
Shifts all elements of stack A up by 1. The first element becomes the last.
```
Before:  A = [3, 1, 2, 4]
After:   A = [1, 2, 4, 3]
```

#### 3. **rra** - Reverse Rotate A
Shifts all elements of stack A down by 1. The last element becomes the first.
```
Before:  A = [3, 1, 2, 4]
After:   A = [4, 3, 1, 2]
```

#### 4. **pb** - Push B
Takes the first element from stack A and pushes it to the top of stack B.
```
Before:  A = [3, 1, 2]    B = [5]
After:   A = [1, 2]       B = [3, 5]
```

#### 5. **pa** - Push A
Takes the first element from stack B and pushes it to the top of stack A.
```
Before:  A = [1, 2]       B = [3, 5]
After:   A = [3, 1, 2]    B = [5]
```

---

## Helper Functions

These functions help us understand and manipulate the stacks:

### 1. `get_stack_size(t_stack *stack)`
**Purpose**: Counts how many elements are in a stack.

**How it works**:
- Starts at 0
- Traverses through the stack, counting each node
- Returns the total count

**Example**:
```c
Stack A = [3, 1, 2, 4]
get_stack_size(A) returns 4
```

### 2. `find_min_value(t_stack *stack)`
**Purpose**: Finds the smallest value in the stack.

**How it works**:
- Starts with the first element's value as the minimum
- Compares each element with the current minimum
- Updates minimum if a smaller value is found
- Returns the smallest value

**Example**:
```c
Stack A = [5, 2, 8, 1, 3]
find_min_value(A) returns 1
```

### 3. `find_min_index(t_stack *stack)`
**Purpose**: Finds the position (index) of the smallest value in the stack.

**How it works**:
- Index 0 = top of stack (first element)
- Index 1 = second element
- Index 2 = third element, etc.
- Traverses the stack, tracking the index of the minimum value
- Returns the index where the minimum is located

**Example**:
```c
Stack A = [5, 2, 8, 1, 3]
         index: 0  1  2  3  4
Minimum value 1 is at index 3
find_min_index(A) returns 3
```

### 4. `is_sorted(t_stack *a)`
**Purpose**: Checks if a stack is already sorted in ascending order.

**How it works**:
- Traverses the stack
- Compares each element with the next one
- Returns 1 (true) if sorted, 0 (false) if not

**Example**:
```c
Stack A = [1, 2, 3, 4]  → is_sorted(A) returns 1 (sorted)
Stack A = [3, 1, 2, 4]  → is_sorted(A) returns 0 (not sorted)
```

---

## Sort 3 Algorithm

### Overview
The `sort_3` function sorts exactly 3 elements in stack A using only operations on stack A (no pushing to B needed).

### Strategy
We analyze all 6 possible arrangements of 3 numbers and apply the minimal operations needed to sort them.

### The 6 Cases

Let's call the three elements:
- **x** = first element (top of stack)
- **y** = second element
- **z** = third element (bottom of stack)

#### Case 1: Already Sorted ✅
```
Stack: [x, y, z] where x < y < z
Example: [1, 2, 3]
Action: Do nothing (return)
```

#### Case 2: Swap First Two
```
Stack: [x, y, z] where x > y < z && x < z
Example: [2, 1, 3]
Visual:  2 > 1 < 3, and 2 < 3
Action: sa (swap first two)
Result: [1, 2, 3]
```

#### Case 3: Swap Then Rotate
```
Stack: [x, y, z] where x < y > z && x < z
Example: [1, 3, 2]
Visual:  1 < 3 > 2, and 1 < 2
Action: sa, then ra
        sa → [3, 1, 2]
        ra → [1, 2, 3]
```

#### Case 4: Rotate Up
```
Stack: [x, y, z] where x > y < z && x > z
Example: [3, 1, 2]
Visual:  3 > 1 < 2, and 3 > 2
Action: ra (rotate up)
Result: [1, 2, 3]
```

#### Case 5: Reverse Rotate
```
Stack: [x, y, z] where x < y > z && x > z
Example: [2, 3, 1]
Visual:  2 < 3 > 1, and 2 > 1
Action: rra (reverse rotate)
Result: [1, 2, 3]
```

#### Case 6: Swap Then Reverse Rotate
```
Stack: [x, y, z] where x > y > z
Example: [3, 2, 1]
Visual:  3 > 2 > 1 (all descending)
Action: sa, then rra
        sa → [2, 3, 1]
        rra → [1, 2, 3]
```

### Complete Decision Tree
```
Is x < y < z? → YES → Already sorted, do nothing
              → NO  → Continue...

Is x > y < z && x < z? → YES → sa
                       → NO  → Continue...

Is x < y > z && x < z? → YES → sa, then ra
                       → NO  → Continue...

Is x > y < z && x > z? → YES → ra
                       → NO  → Continue...

Is x < y > z && x > z? → YES → rra
                       → NO  → Continue...

Otherwise (x > y > z) → sa, then rra
```

---

## Sort 5 Algorithm for 4 Elements

### Overview
When we have 4 elements, we reduce the problem to sorting 3 elements by:
1. Pushing the smallest element to stack B
2. Sorting the remaining 3 elements in A
3. Pushing the element back from B to A

### Step-by-Step Process

#### Step 1: Find and Push Minimum to B
We use the helper function `push_min_to_b()` which:
1. Finds the index of the minimum value using `find_min_index()`
2. Calculates the stack size using `get_stack_size()`
3. Decides whether to use `ra` or `rra` to bring minimum to top:
   - If minimum is in the first half: use `ra` (rotate up)
   - If minimum is in the second half: use `rra` (reverse rotate)
4. Pushes the minimum to stack B using `pb`

**Example**:
```
Initial: A = [4, 2, 1, 3]    B = []
         index: 0  1  2  3

Step 1.1: Find minimum
          Minimum value = 1
          Minimum index = 2

Step 1.2: Calculate rotations
          Size = 4
          Index 2 is in second half (2 > 4/2)
          Need: 4 - 2 = 2 reverse rotations

Step 1.3: Rotate to bring minimum to top
          rra → A = [3, 4, 2, 1]
          rra → A = [1, 3, 4, 2]

Step 1.4: Push to B
          pb → A = [3, 4, 2]    B = [1]
```

#### Step 2: Sort Remaining 3 Elements
Now stack A has exactly 3 elements, so we call `sort_3()`.

**Example**:
```
A = [3, 4, 2]    B = [1]
sort_3() sorts A → A = [2, 3, 4]
```

#### Step 3: Push Back from B
Push the element from B back to A. Since it's the smallest, it will be at the top.

**Example**:
```
A = [2, 3, 4]    B = [1]
pa → A = [1, 2, 3, 4]    B = []
Final result: Sorted! ✅
```

### Complete Example Walkthrough

```
Initial state:
A = [4, 2, 1, 3]    B = []

1. Find minimum (value 1 at index 2)
2. Rotate: rra, rra → A = [1, 3, 4, 2]
3. Push: pb → A = [3, 4, 2]    B = [1]
4. Sort 3: sort_3() → A = [2, 3, 4]    B = [1]
5. Push back: pa → A = [1, 2, 3, 4]    B = []

Total operations: 2 rotations + 1 push + sort_3 operations + 1 push
```

---

## Sort 5 Algorithm for 5 Elements

### Overview
When we have 5 elements, we reduce the problem to sorting 3 elements by:
1. Pushing the two smallest elements to stack B
2. Sorting the remaining 3 elements in A
3. Pushing both elements back from B to A in the correct order

### Step-by-Step Process

#### Step 1: Push First Minimum to B
Same as in the 4-element case, we find and push the smallest element.

**Example**:
```
Initial: A = [5, 2, 4, 1, 3]    B = []
         index: 0  1  2  3  4

Minimum value = 1 at index 3
Rotations needed: 5 - 3 = 2 reverse rotations
rra, rra → A = [1, 3, 5, 2, 4]
pb → A = [3, 5, 2, 4]    B = [1]
```

#### Step 2: Push Second Minimum to B
Now we find the minimum of the remaining elements in A and push it.

**Example**:
```
Current: A = [3, 5, 2, 4]    B = [1]
         index: 0  1  2  3

Minimum value = 2 at index 2
Rotations needed: 2 forward rotations (index 2 <= 4/2)
ra, ra → A = [2, 4, 3, 5]
pb → A = [4, 3, 5]    B = [2, 1]
Note: B now has [2, 1] where 2 is on top, 1 is below
```

#### Step 3: Sort Remaining 3 Elements
Stack A now has exactly 3 elements, so we call `sort_3()`.

**Example**:
```
A = [4, 3, 5]    B = [2, 1]
sort_3() sorts A → A = [3, 4, 5]    B = [2, 1]
```

#### Step 4: Push Back from B
Push both elements back from B to A. The order in B is important:
- After pushing two minimums, B has: `[second_smallest, smallest]`
- When we push back:
  - First `pa`: pushes second_smallest to A
  - Second `pa`: pushes smallest to A (on top of second_smallest)
- This gives us: `[smallest, second_smallest, ...]` which is correct!

**Example**:
```
A = [3, 4, 5]    B = [2, 1]
pa → A = [2, 3, 4, 5]    B = [1]
pa → A = [1, 2, 3, 4, 5]    B = []
Final result: Sorted! ✅
```

### Why the Order Works

When we push two minimums to B:
1. First push: smallest goes to B → `B = [smallest]`
2. Second push: second smallest goes to B → `B = [second_smallest, smallest]`

When pushing back:
1. First `pa`: second_smallest goes to A → `A = [second_smallest, ...]`
2. Second `pa`: smallest goes to A (on top) → `A = [smallest, second_smallest, ...]`

This automatically gives us the correct sorted order!

### Complete Example Walkthrough

```
Initial state:
A = [5, 2, 4, 1, 3]    B = []

Phase 1: Push first minimum
1. Find minimum: value 1 at index 3
2. Rotate: rra, rra → A = [1, 3, 5, 2, 4]
3. Push: pb → A = [3, 5, 2, 4]    B = [1]

Phase 2: Push second minimum
4. Find minimum: value 2 at index 2
5. Rotate: ra, ra → A = [2, 4, 3, 5]
6. Push: pb → A = [4, 3, 5]    B = [2, 1]

Phase 3: Sort remaining 3
7. sort_3() → A = [3, 4, 5]    B = [2, 1]

Phase 4: Push back
8. pa → A = [2, 3, 4, 5]    B = [1]
9. pa → A = [1, 2, 3, 4, 5]    B = []

Total operations: rotations + pushes + sort_3 operations + pushes
```

---

## Turk Algorithm (6+ Elements)

### Overview
For more than 5 elements, we use the **Turk Algorithm** (cost-based sorting). It finds the cheapest element to move and optimizes rotations.

### The 4 Phases

```
┌─────────────────────────────────────────────────────────────┐
│  PHASE 1: Push all but 3 elements to B                      │
│  A: [5,3,8,1,9,2,7,4,6] → A: [8,1,9]  B: [6,4,7,2,5,3]     │
├─────────────────────────────────────────────────────────────┤
│  PHASE 2: Sort the 3 remaining elements in A                │
│  A: [1,8,9]                                                 │
├─────────────────────────────────────────────────────────────┤
│  PHASE 3: Push back from B to A (cheapest first)            │
│  Calculate cost for each B element, move the cheapest       │
├─────────────────────────────────────────────────────────────┤
│  PHASE 4: Final rotation                                    │
│  Rotate A so smallest element is on top                     │
│  A: [1,2,3,4,5,6,7,8,9] ✓                                   │
└─────────────────────────────────────────────────────────────┘
```

### Key Concepts

#### 1. Index (Rank) Assignment
Before sorting, assign each element a rank (0 = smallest, n-1 = largest):
```
Values: [42, -5, 100, 3]
Ranks:  [2,   0,   3,  1]
```
This simplifies comparisons since we work with consecutive integers.

#### 2. Target Position
For each element in B, find where it should be inserted in A:
- Find the smallest element in A that is greater than the B element
- If none exists, target the position of the smallest element in A

#### 3. Cost Calculation
For each B element, calculate:
- **cost_b**: Rotations needed to bring it to top of B
- **cost_a**: Rotations needed to position A for insertion
- Positive cost = forward rotation (ra/rb)
- Negative cost = reverse rotation (rra/rrb)

#### 4. Finding the Cheapest
```
Total cost = |cost_a| + |cost_b|
```
Choose the element with the minimum total cost.

#### 5. Execute Move (Optimized)
```
If cost_a > 0 AND cost_b > 0 → Use rr (rotate both)
If cost_a < 0 AND cost_b < 0 → Use rrr (reverse rotate both)
Then handle remaining rotations individually
Finally: pa
```

### Turk Helper Functions

| Function | Purpose |
|----------|---------|
| `assign_index()` | Assigns rank 0 to n-1 based on value |
| `set_position()` | Updates current position (0 = top) |
| `get_target_pos()` | Finds insertion point in A for B element |
| `assign_target_pos()` | Sets target_pos for all B elements |
| `calculate_cost()` | Computes cost_a and cost_b for each B element |
| `find_cheapest()` | Returns B element with lowest total cost |
| `execute_move()` | Performs optimized rotations and push |
| `final_rotate()` | Rotates A until smallest is on top |

### Example Walkthrough

```
Initial: A = [3, 1, 4, 2, 5, 7, 6]    B = []

Phase 1: Push to B (keep 3 in A)
  pb, pb, pb, pb → A = [5, 7, 6]    B = [2, 4, 1, 3]

Phase 2: Sort 3
  sort_3() → A = [5, 6, 7]    B = [2, 4, 1, 3]

Phase 3: Push back cheapest first
  For each B element, calculate cost to insert into correct position in A
  
  Loop iteration 1:
  - Element 2: needs to go between nothing and 5, cost calculated
  - Element 4: needs to go between nothing and 5, cost calculated
  - Element 1: needs to go before 5 (smallest), cost calculated
  - Element 3: needs to go between nothing and 5, cost calculated
  - Find cheapest, execute move, pa
  
  Repeat until B is empty...

Phase 4: Final rotate
  Rotate A until smallest element (1) is on top
  Final: A = [1, 2, 3, 4, 5, 6, 7] ✓
```

### Why Turk is Efficient

1. **Cost optimization**: Always moves the cheapest element first
2. **Combined rotations**: Uses rr/rrr to rotate both stacks simultaneously
3. **Minimal operations**: Typically achieves:
   - < 700 operations for 100 numbers
   - < 5500 operations for 500 numbers

### Turk Algorithm Code Structure

```c
void turk_sort(t_stack **a, t_stack **b)
{
    t_stack *cheapest;

    // Phase 1: Push all but 3 to B
    while (get_stack_size(*a) > 3)
        pb(a, b);
    
    // Phase 2: Sort remaining 3
    sort_3(a);
    
    // Phase 3: Push back from B to A (cheapest first)
    while (*b)
    {
        set_position(*a);
        set_position(*b);
        assign_target_pos(*a, *b);
        calculate_cost(*a, *b);
        cheapest = find_cheapest(*b);
        execute_move(a, b, cheapest->cost_a, cheapest->cost_b);
    }
    
    // Phase 4: Final rotation
    set_position(*a);
    final_rotate(a);
}
```

---

## Key Helper Function: `push_min_to_b()`

This is a crucial helper function used in both 4 and 5 element sorting.

### How It Works

```c
static void push_min_to_b(t_stack **a, t_stack **b)
{
    int min_index;
    int size;
    int i;

    // Step 1: Get the size of stack A
    size = get_stack_size(*a);
    
    // Step 2: Find where the minimum value is located
    min_index = find_min_index(*a);
    
    // Step 3: Decide rotation direction
    if (min_index <= size / 2)
    {
        // Minimum is in the first half - use forward rotation
        i = 0;
        while (i < min_index)
        {
            ra(a);  // Rotate up
            i++;
        }
    }
    else
    {
        // Minimum is in the second half - use reverse rotation
        i = size - min_index;
        while (i > 0)
        {
            rra(a);  // Rotate down
            i--;
        }
    }
    
    // Step 4: Push the minimum to stack B
    pb(a, b);
}
```

### Why We Choose Rotation Direction

**Example with 5 elements**:
```
Stack A = [5, 2, 4, 1, 3]
         index: 0  1  2  3  4
         size = 5, midpoint = 2.5

If minimum is at index 0, 1, or 2:
  → Use ra (forward rotation) - fewer operations

If minimum is at index 3 or 4:
  → Use rra (reverse rotation) - fewer operations
```

This optimization minimizes the number of rotations needed!

---

## Summary

### Sort 3
- **Input**: 3 elements in stack A
- **Strategy**: Analyze all 6 possible arrangements and apply minimal operations
- **Operations used**: sa, ra, rra (only stack A operations)
- **No stack B needed**

### Sort 5 (4 elements)
- **Input**: 4 elements in stack A
- **Strategy**: Push 1 minimum → Sort 3 → Push back
- **Helper functions**: `get_stack_size()`, `find_min_index()`, `push_min_to_b()`
- **Operations used**: ra/rra, pb, sort_3 operations, pa

### Sort 5 (5 elements)
- **Input**: 5 elements in stack A
- **Strategy**: Push 2 minimums → Sort 3 → Push back
- **Helper functions**: `get_stack_size()`, `find_min_index()`, `push_min_to_b()`
- **Operations used**: ra/rra, pb (twice), sort_3 operations, pa (twice)

### Turk Algorithm (6+ elements)
- **Input**: 6 or more elements in stack A
- **Strategy**: Push all but 3 → Sort 3 → Push back cheapest first → Final rotate
- **Helper functions**: `assign_index()`, `set_position()`, `get_target_pos()`, `calculate_cost()`, `find_cheapest()`, `execute_move()`, `final_rotate()`
- **Operations used**: pb, sort_3 operations, rr/rrr (optimized), ra/rra, rb/rrb, pa

### Key Insight
Both 4 and 5 element sorting reduce the problem to sorting 3 elements, which we can solve optimally. The Turk algorithm extends this by using cost-based optimization to efficiently handle larger sets. This is a classic "divide and conquer" approach!


