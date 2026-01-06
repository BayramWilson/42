# get_next_line — Plan (step-by-step)

> Use this checklist in order. Don’t code until Phase 7.

---

## Phase 1 — Understand the input (read) (20–30 min)

**Goal:** Stop expecting lines from `read()`.

### TODO 1.1 — Tiny test program

Write a tiny test program that:

* opens a file
* calls `read(fd, buf, BUFFER_SIZE)`
* prints what was read **without assumptions**

Test with:

* `BUFFER_SIZE = 1`
* `BUFFER_SIZE = 5`
* `BUFFER_SIZE = 100`
* `BUFFER_SIZE=1032`

**Suggested compile/run loop**

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=1   test_read.c -o test_read && ./test_read ./input.txt
cc -Wall -Wextra -Werror -D BUFFER_SIZE=5   test_read.c -o test_read && ./test_read ./input.txt
cc -Wall -Wextra -Werror -D BUFFER_SIZE=100 test_read.c -o test_read && ./test_read ./input.txt
```

### TODO 1.2 — Answer (must be crystal clear)

* Can `read()` stop in the middle of a line?
* Can one `read()` contain multiple lines?
* What does `read()` return at EOF?

> If these answers aren’t crystal clear, don’t move on.

---

## Phase 2 — Define the “stash” concept (no code yet)

**Goal:** Understand state across calls.

### TODO 2.1 — Define `stash` on paper

Define a variable called `stash`:

* What does it store?
    - stash stores all unread data that has been read from the file but not yet returned as part of a line.
    - it is a growing string
* When does it change?
    - stash changes when: 
        - new data from read() is appended to it
        - a line is extracted and the used part is removed from it
        - split it into *line returned* and *remaining*
* When must it persist?
    - stash must persist between calls to *get_next_line*, because a call may end without finding *\n* and the next call must continue using the leftover data
    - persistence is about incomplete lines

### TODO 2.2 — Simulate by hand (this is where it clicks)

File:

```
Hello\nWorld\n
```

`BUFFER_SIZE = 4`

Write a table:

| Call | `read()` gives | `stash` before | `stash` after | returned |
| ---- | -------------- | -------------- | ------------- | -------- |
|   1  |    Hell        |                |    Hell       |          |
|      |                |                |               |          |
|   2  |    o\nWo       |   Hell         |   Hello\nWo   |  Hello\n |

    3       rld\n            Wo               World\n       World\n

    4       EOF              -                  -           NULL   

> Do not skip this.

---

## Phase 3 — Line extraction logic (thinking only)

**Goal:** Separate responsibilities.

### TODO 3.1 — Define the extractor (in words)

Define (in words) a function that:

* takes a string
* returns everything up to and including `\n`

Answer:

* What if there is no `\n`?
* What happens to the remaining part?

### TODO 3.2 — Decide extraction timing

Decide:

* Do you extract the line **before** or **after** reading more?
* Why?

> There is a right answer here logically, not stylistically.

---

## Phase 4 — Control flow of `get_next_line`

**Goal:** Understand the loop, not the code.

### TODO 4.1 — Describe the flow in bullet points

Example (not code):

* If `stash` has a newline → extract and return
* Else → read more
* Append read data to `stash`
* Repeat
* Handle EOF

> If you can’t explain this without code, don’t write code yet.

---

## Phase 5 — Memory ownership rules (very important)

**Goal:** Avoid leaks and double frees.

### TODO 5.1 — For each allocation, answer

* Who owns it?
* Who frees it?
* When is it no longer needed?

Typical question to answer:

* After returning a line, which memory still must exist?

> If you guess here, you’ll leak or segfault.

---

## Phase 6 — Edge cases checklist

**Goal:** Be evaluator-proof.

### TODO 6.1 — Think through expected behavior

* Empty file
* File without final `\n`
* Single-character file
* `BUFFER_SIZE = 1`
* Very large `BUFFER_SIZE`
* `read()` returns `-1`

Write expected behavior for each.

---

## Phase 7 — Only now: start coding

**Rule:** If you can’t explain what the next line of code does before writing it, stop.

Suggested order:

1. utils for string handling
2. stash append logic
3. line extraction
4. main loop

---

## Phase 8 — Self-evaluation prep (important for defense)

### TODO 8.1 — Prepare answers to

* Why `static`?
* Why not read the whole file?
* What breaks if `BUFFER_SIZE = 1`?
* What happens at EOF exactly?

> If you can explain these calmly, you’re ready.
