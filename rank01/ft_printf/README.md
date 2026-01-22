*This project has been created as part of the 42 curriculum by bwilson.*

# ft_printf

## Description

The **ft_printf** project consists of recreating a simplified version of the standard C library function `printf`.
The goal is to understand how formatted output works internally, including parsing format strings, handling
variadic arguments, and converting different data types into their textual representation.

This project strengthens knowledge of:
- variadic functions (`va_list`)
- number base conversions
- memory and type handling in C
- low-level output using `write()`

The implementation avoids using the original `printf` and relies only on allowed standard functions.

---

## Instructions

### Compilation

To compile the project, run:

```bash
make
```

This will generate the static library:

```
libftprintf.a
```

### Usage

Include the header in your project:

```c
#include "ft_printf.h"
```

Compile with your program:

```bash
cc main.c libftprintf.a
```

Example usage:

```c
ft_printf("Hello %s, number: %d, hex: %x\n", "world", 42, 42);
```

### Supported Conversions

- `%c` — character
- `%s` — string
- `%d` / `%i` — signed decimal integer
- `%u` — unsigned decimal integer
- `%x` — hexadecimal (lowercase)
- `%X` — hexadecimal (uppercase)
- `%p` — pointer address
- `%%` — percent sign

---

## Algorithm & Data Structures

### Format Parsing

The format string is processed character by character.
When a `%` is encountered, the following character determines the conversion type.
A dispatcher function maps each specifier to its corresponding handler.

### Variadic Arguments

The project uses `va_list`, `va_start`, `va_arg`, and `va_end` to retrieve arguments
based on the detected format specifier.

### Number Conversion

All number printing is implemented manually without using standard formatting functions.

- **Decimal (`%d`, `%i`, `%u`)**  
  Numbers are converted using recursive division by 10 to print digits in the correct order.

- **Hexadecimal (`%x`, `%X`, `%p`)**  
  Numbers are converted using base-16 division with lookup tables:
  - `"0123456789abcdef"`
  - `"0123456789ABCDEF"`

- **Pointers (`%p`)**  
  Pointer values are cast to `uintptr_t` to ensure correct behavior on 64-bit systems,
  then printed in hexadecimal with a `0x` prefix.

### Data Structures

No complex data structures are used.
The implementation relies on:
- primitive types
- recursion
- constant lookup strings for base conversion

This keeps the project simple, efficient, and norm-compliant.

---

## Resources

### Documentation & References

- `man 3 printf`
- `man 3 stdarg`
- GNU C Library Documentation
- The C Programming Language — Kernighan & Ritchie

### Use of AI

AI tools were used as a **learning and support resource** to:
- clarify concepts related to variadic functions
- understand number base conversions
- review edge cases (e.g. INT_MIN handling)
- improve explanations and documentation clarity

All code was written, tested, and validated by the student.
