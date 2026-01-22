*This project has been created as part of the 42 curriculum by bwilson.*

---

## Description
This project is a reimplementation of a subset of the standard C library (commonly
referred to as "libft") created as part of the 42 curriculum. The goal is to
reproduce several common libc functions (string handling, memory operations,
character checks/conversions, and simple helpers) in order to learn C, pointers,
memory management, and to practise the project's coding and style rules.

---

## Instructions
Build the static library using the provided `Makefile` from the project root:

```bash
cd /home/rammo/42/libft
make
```

Available `make` targets:
- `make` / `make all` - compile object files and create `libft.a`
- `make clean` - remove object files (`*.o`)
- `make fclean` - remove object files and the library (`libft.a`)
- `make re` - `fclean` then `all`

To compile a test program against the library:

```bash
gcc -I. main.c libft.a -o myprog
# or explicitly link object files
gcc -I. main.c -L. -lft -o myprog
```

If you prefer not to use the `Makefile`, you can build manually:

```bash
gcc -Wall -Wextra -Werror -c *.c
ar rcs libft.a *.o
rm -f *.o
```
---

## Resources
- The C standard library documentation and `man` pages (e.g. `man memcpy`, `man strchr`).
- 42 subject / project instructions and recommended reading from the 42 intranet.
- Common references and tutorials about pointers, memory and strings in C (e.g. "The C Programming Language" by Kernighan & Ritchie).

---

### AI usage disclosure
AI-assisted tooling was used during development for non-authoritative tasks only:
- Generated an initial `Makefile` template and suggested improvements to it.
- Generated an initial `libft.h` header template with function prototypes.
- Suggested fixes to several implementation prototypes and helper guidance.

All source code was written or reviewed by the author (`bwilson`). AI outputs were inspected and edited by the author before being added to the repository.

---

## License / Notes
This repository is an educational project created for the 42 curriculum. Follow
the 42 subject instructions and local rules when submitting.
