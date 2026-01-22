*This project has been created as part of the 42 curriculum by bwilson.*

# get_next_line

## Description

The **get_next_line** project is a core systems-programming exercise from the 42
curriculum. Its goal is to implement a function, `get_next_line(int fd)`, that reads
and returns a file **one line at a time**, handling arbitrary buffer sizes and
preserving state between function calls.

The main challenge of the project is not reading from a file itself, but correctly
managing **partial reads**, **memory ownership**, and **state persistence** across
multiple calls, while respecting strict coding standards (Norminette).

This project deepens the understanding of:
- low-level I/O with `read()`
- dynamic memory management
- static variables and state
- robust control flow and edge-case handling

---

## Instructions

### Compilation

The project is compiled together with a user-defined `BUFFER_SIZE`:

```bash
cc -Wall -Wextra -Werror -D BUFFER_SIZE=42 get_next_line.c get_next_line_utils.c
```

### Usage

```c
int fd = open("file.txt", O_RDONLY);
char *line;

while ((line = get_next_line(fd)) != NULL)
{
    printf("%s", line);
    free(line);
}
close(fd);
```

Rules:
- The caller **must free** each returned line.
- `get_next_line` returns `NULL` on EOF or error.

---

## Algorithm & Data Structure Explanation

### Core idea: the stash

The algorithm revolves around a static variable commonly called **stash**.

**Stash definition:**
- A dynamically allocated string
- Stores data read from the file but not yet returned
- Persists between calls to `get_next_line`

### High-level algorithm

1. **Check stash**
   - If stash already contains a newline (`\n`), extract and return the next line.

2. **Read from file**
   - Call `read(fd, buffer, BUFFER_SIZE)` only when needed.
   - Append the read bytes to stash.

3. **Repeat**
   - Continue until a newline is found or EOF/error occurs.

4. **EOF handling**
   - If `read()` returns `0` and stash still contains data, return it as the last line.
   - Otherwise, return `NULL`.

5. **Error handling**
   - On `read()` returning `-1`, free owned memory and return `NULL`.

### Why this works

- `read()` may stop in the middle of a line or return multiple lines at once.
- The stash ensures no data is lost between calls.
- Each call returns **exactly one line**, preserving correct order.

### Data structures used

- **char \*** for stash (dynamic string)
- **static storage duration** for persistence
- No complex structures — simplicity and correctness are key

---

## Edge Cases Handled

- Empty files
- Files without a trailing newline
- `BUFFER_SIZE = 1`
- Very large `BUFFER_SIZE`
- Read errors (`read() == -1`)
- Multiple lines returned in a single read

---

## Resources

### Technical references
- `man 2 read`
- `man 3 malloc`
- The Linux Programming Interface — Michael Kerrisk
- POSIX standard documentation

### How AI was used

AI (ChatGPT) was used **as a learning assistant**, not as a code generator.

Specifically:
- Breaking down the problem into conceptual phases
- Verifying algorithm logic and edge cases
- Explaining memory ownership and control flow
- Reviewing code against Norminette rules

All code was written, tested, and debugged manually by the author.
AI was not used to bypass learning objectives.

---

## Project Planning & Learning Process

Below is the structured plan followed during development, used to ensure correctness
before writing code.

---

## get_next_line — Plan (step-by-step)

### Phase 1 — Understand `read()`
- `read()` can stop mid-line
- One read can contain multiple lines
- Returns `0` at EOF, `-1` on error

### Phase 2 — Define stash
- Stores unread data
- Grows with each read
- Shrinks when a line is extracted
- Persists across calls

### Phase 3 — Line extraction
- Extract up to and including `\n`
- Remaining data stays in stash
- At EOF, remaining stash is returned once

### Phase 4 — Control flow
- Check stash before reading
- Read only when necessary
- Handle EOF and errors explicitly

### Phase 5 — Memory ownership
- Returned line → owned by caller
- Stash → owned and managed internally
- Temporary buffer → freed every call

### Phase 6 — Edge cases
- Empty file → `NULL`
- No trailing newline → last line returned
- BUFFER_SIZE = 1 → still works

### Phase 7 — Coding
- Utilities first
- Extraction logic
- Main loop assembly

### Phase 8 — Memory audit
- Every malloc has exactly one free
- No leaks, no double frees

### Phase 9 — Defense preparation
- Why `static` is required
- Why not read the whole file
- EOF behavior
- BUFFER_SIZE stress cases

---

## Author

**Bayram Wilson**  
42 Berlin — `bwilson`
