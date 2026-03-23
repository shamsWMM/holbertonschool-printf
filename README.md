# \_printf

A simplified version of the C standard library `printf` function.

## Description

`_printf` is a variadic function that produces formatted output to the standard output stream (`stdout`). It processes a format string containing zero or more directives and conversion specifiers, writing the resulting output character by character.

This project was built as part of the **Holberton School** curriculum to gain a deeper understanding of variadic functions, format parsing, and low-level output handling in C.

---

## Prototype

```c
int _printf(const char *format, ...);
```

## Return Value

- On success: the total number of characters printed (excluding the null terminator `\0).`
- On failure: `-1` if `format` is `NULL` or if an error occurs.

---

## Supported Conversion Specifiers

| Specifier | Description                                      | Example Input          | Example Output  |
|-----------|--------------------------------------------------|------------------------|-----------------|
| `%c`      | Prints a single character                        | `_printf("%c", 'H');`  | `H`             |
| `%s`      | Prints a string of characters                    | `_printf("%s", "Hi");` | `Hi`            |
| `%%`      | Prints a literal percent sign                    | `_printf("%%");`       | `%`             |
| `%d`      | Prints a signed decimal integer                  | `_printf("%d", 42);`   | `42`            |
| `%i`      | Prints a signed integer (identical to `%d`)      | `_printf("%i", -7);`   | `-7`            |

---

## Limitations

This implementation does **not** handle the following:

- Buffer handling (as in the C library `printf`)
- Flag characters (`-`, `+`, ` `, `#`, `0`)
- Field width
- Precision
- Length modifiers (`l`, `h`)

---

## File Structure

| File                | Description                                              |
|---------------------|----------------------------------------------------------|
| `_printf.c`         | Core `_printf` function — parses format string and dispatches to handlers |
| `print_helpers.c` | Handler functions for each conversion specifier (`%c`, `%s`, `%d`, `%i`, `%%`) |
| `main.h`            | Header file containing prototypes and struct definitions |
| `man_3_printf`      | Manual page for the `_printf` function                   |
| `main.c`            | Test file (optional/example usage)                       |

---

## Compilation

All files are compiled on **Ubuntu 20.04 LTS** using:

```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 -Wno-format *.c -o printf
```

---

## Usage

### Example

```c
#include "main.h"

int main(void)
{
    int len;

    len = _printf("Hello, %s! You are number %d.\n", "world", 1);
    _printf("Characters printed: %d\n", len);

    _printf("Single char: %c\n", 'A');
    _printf("Negative number: %i\n", -98);
    _printf("Percent sign: %%\n");

    return (0);
}
```

### Expected Output

```
Hello, world! You are number 1.
Characters printed: 31
Single char: A
Negative number: -98
Percent sign: %
```

---

## Man Page

A custom man page is provided. To view it locally:

```bash
man ./man_3_printf
```

---

## Flowchart

```
         START
           |
           v
   Is format NULL?
      /         \
    YES          NO
     |            |
     v            v
  return -1   Loop through format string
                  |
                  v
           Is current char '%' ?
              /        \
            NO          YES
            |            |
            v            v
       Write char   Read next char (specifier)
       to stdout         |
            |            v
            |     Match specifier?
            |      /    |    |    \     \
            |    'c'   's'  'd'  'i'   '%'   (unknown)
            |     |     |    |    |     |        |
            |     v     v    v    v     v        v
            |  print  print print print print  write '%'
            |  char   str   int   int   '%'   then char
            |     \     |    /    /     /        |
            |      \    |   /    /     /         |
            |       v   v  v    v     v          |
            +-----> Add to total count <---------+
                        |
                        v
                 End of format string?
                   /          \
                 NO           YES
                  |             |
                  v             v
           Continue loop   return total count
                              |
                              v
                            END
```

---

## Testing
A test file is provided in the `test/` directory.
Compile and run it:
```bash
gcc -Wall -Werror -Wextra -pedantic -std=gnu89 _printf.c print_helpers.c test/main.c -o test_printf
./test_printf
```
---

# Branching Strategy

## Branch Types
- **main**
- **feature/\***
- **bugfix/\***

## Workflow
1. Create a branch: `git checkout -b feature/<feature-name>`
2. Push to remote: `git push -u origin feature/<feature-name>`
3. Open a Pull Request on GitHub
4. Code review with teammate
5. Merge when approved

---

## Authors
- **Shams Watha** — [shamsWMM](https://github.com/shamsWMM)
- **Venghour Heng** — [hengvenghour7](https://github.com/hengvenghour7)

