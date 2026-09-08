*This project has been created as part of the 42 curriculum by dboldino.*

# ft_printf

## Description

`ft_printf` is a 42 school project that consists of recoding a simplified
version of the C standard library function `printf`. The goal is to
implement a variadic function, `ft_printf`, that parses a format string at
runtime and writes formatted output to the standard output, replicating (a
subset of) the behavior of the original `printf` from `<stdio.h>`.

Beyond simply reproducing a familiar function, the project is meant to teach:
- how to work with a variadic functions in C (`<stdarg.h>`);
- how to parse a format string character by character and dispatch behavior
  based on conversion specifiers;

The library currently supports the following conversion specifiers:

| Specifier | Meaning                              |
|-----------|---------------------------------------|
| `%c`      | Character                              |
| `%s`      | String                                 |
| `%d`      | Signed decimal integer                 |
| `%i`      | Signed decimal integer                 |
| `%u`      | Unsigned decimal integer               |
| `%x`      | Unsigned hexadecimal integer (lowercase)|
| `%X`      | Unsigned hexadecimal integer (uppercase)|
| `%p`      | Pointer address, in hexadecimal        |
| `%%`      | A literal percent sign                 |

`ft_printf` returns the number of characters written on success, and `-1`
if a `write` call fails.

## Instructions

### Compilation

The project is built with the provided `Makefile`, which compiles the
sources into a static library named `libftprintf.a`.

```bash
make        # compiles the sources and produces libftprintf.a
make clean  # removes the object files
make fclean # removes the object files and the library
make re     # fclean + all
```

### Using the library in your own project

1. Compile the library with `make` (or copy the `srcs`/`includes` folders
   into your own project and build it together with your sources).
2. Include the header in the files where you want to use `ft_printf`:

   ```c
   #include "ft_printf.h"
   ```

3. Compile your project and link against the library and the include path,
   for example:

   ```bash
   cc -Wall -Wextra -Werror your_file.c -Iincludes -L. -lftprintf -o your_program
   ```

### Example

```c
#include "ft_printf.h"

int main(void)
{
    ft_printf("Hello, %s! You have %d new message%c\n", "world", 3, 's');
    ft_printf("Pointer: %p, hex: %x / %X, char: %c, percent: %%\n",
               &main, 255, 255, 'A');
    return (0);
}
```

## Algorithm and data structures

`ft_printf` does not rely on any dynamic data structure (no linked list,
array, or heap allocation): the format string is scanned once, from left to
right, using a **single pointer walk** combined with the standard C
`va_list` mechanism (`<stdarg.h>`) to consume arguments on demand. This
choice keeps the function simple, predictable, and free of memory
management concerns, which matches the scope of the project (a
non-flag, non-width, non-precision subset of `printf`).

The implementation is split into two responsibilities:

- **Parsing / dispatch (`ft_printf.c`)** - `ft_printf` iterates over the
  format string one character at a time. Every time it encounters a `%`,
  it looks at the next character and delegates the actual conversion to
  `ft_arg_check`, a small dispatcher that maps a conversion specifier
  (`c`, `s`, `d`, `i`, `u`, `x`, `X`, `p`, `%`) to the matching printing
  function, pulling the correctly-typed argument out of the `va_list` with
  `va_arg`. This is effectively a **finite-state scan**: the only two
  states are "copying a literal character" and "handling a conversion",
  so no explicit state struct is needed - the position of the pointer in
  the string is the state.
- **Conversion / output (`ft_print_utils.c`)** - each conversion has its
  own small, focused function (`ft_putchar`, `ft_putstr`, `ft_putnbr`,
  `ft_putnbr_hexa`, `ft_putptr`), all built on top of `write(2)`. Numeric
  conversions (`ft_putnbr` for decimal, `ft_putnbr_hexa` for hexadecimal)
  are implemented **recursively**: the function first prints
  `nb / base` (everything but the last digit) before printing
  `nb % base` (the last digit). This is the natural way to print digits in
  the correct order without needing an intermediate buffer/array to store
  them in reverse and then re-walk it - the call stack itself acts as the
  temporary storage, unwinding from the most significant digit to the
  least significant one.

Every printing function returns the number of characters it wrote (or `-1`
on a `write` failure), and these counts are summed up as `ft_printf`
progresses. This makes error propagation straightforward: a single `-1`
anywhere in the chain short-circuits the whole call and is returned
immediately, mirroring the real `printf`'s return-value contract (number of
characters printed, or a negative value on error).

## Resources

### Classic references

- [C Standard, `printf` specification (ISO/IEC 9899, §7.21.6.1)](https://port70.net/~nsz/c/c11/n1570.html#7.21.6.1)
- [`man 3 printf`](https://man7.org/linux/man-pages/man3/printf.3.html) - the reference manual page for the standard library function this project reimplements.
- [`man 3 stdarg`](https://man7.org/linux/man-pages/man3/stdarg.3.html) - documentation on `va_list`, `va_start`, `va_arg`, `va_end`, used to handle the variadic arguments.
- [`man 2 write`](https://man7.org/linux/man-pages/man2/write.2.html) - the syscall used under the hood for all output.
- [42 Norm](https://github.com/42School/norminette) - the coding-style standard the project's source code follows.

### AI usage

AI was used as a development and documentation aid for this project. The source code itself remains the responsibility of the project author. AI was not used as a substitute for understanding the implementation or for validating the behaviour of the submitted code.
