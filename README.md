*This project has been created as part of the 42 curriculum by omatalla.*

# ft_printf

## Table of Contents

- [Description](#description)
- [Project Goals](#project-goals)
- [Skills Acquired](#skills-acquired)
- [Features](#features)
  - [Mandatory Conversions](#mandatory-conversions)
  - [Helper Functions](#helper-functions)
- [Project Structure](#project-structure)
- [Algorithm and Technical Design](#algorithm-and-technical-design)
  - [Overview](#overview)
  - [Variadic Arguments](#variadic-arguments)
  - [Number Conversion Strategy](#number-conversion-strategy)
    - [Decimal Conversion](#decimal-conversion)
    - [Unsigned Integer Conversion](#unsigned-integer-conversion)
    - [Hexadecimal Conversion](#hexadecimal-conversion)
    - [Pointer Conversion](#pointer-conversion)
  - [Return Value Tracking](#return-value-tracking)
- [Repository](#repository)
- [Instructions](#instructions)
  - [Build the Library](#build-the-library)
  - [Remove Object Files](#remove-object-files)
  - [Remove Object Files and Library](#remove-object-files-and-library)
  - [Rebuild Everything](#rebuild-everything)
- [Usage Example](#usage-example)
- [Testing](#testing)
  - [Custom Tests](#custom-tests)
  - [Community Testers](#community-testers)
- [Resources](#resources)
  - [Documentation](#documentation)
  - [Books](#books)
  - [Videos](#videos)
  - [Useful References](#useful-references)
- [AI Usage](#ai-usage)
- [Author](#author)

## Description

ft_printf is the second core project of the 42 Curriculum. Its objective is to recreate a simplified version of the standard C library function `printf()`.

The project introduces variadic functions and challenges students to reproduce the behavior of one of the most widely used functions in the C standard library while respecting strict implementation constraints.

The mandatory part of the project supports the following conversion specifiers:

* `%c` — Character
* `%s` — String
* `%p` — Pointer address
* `%d` — Signed decimal integer
* `%i` — Signed integer
* `%u` — Unsigned decimal integer
* `%x` — Unsigned hexadecimal integer (lowercase)
* `%X` — Unsigned hexadecimal integer (uppercase)
* `%%` — Percent sign

The function reproduces the behavior of `printf()` for the supported conversions and returns the number of characters printed.

## Project Goals

The purpose of ft_printf is to:

* Understand how variadic functions work in C.
* Learn how the standard `printf()` function processes variable-length argument lists.
* Practice recursive number conversion algorithms.
* Strengthen knowledge of pointers and type conversions.
* Develop reusable output functions that can be integrated into future projects.
* Improve debugging and testing skills through comparison with the original `printf()`.

## Skills Acquired

Through this project I practiced:

* Variadic functions (`stdarg.h`)
* Recursive algorithms
* Integer and base conversion
* Pointer manipulation
* Memory-safe string handling
* API design
* Software testing and validation
* Defensive programming
* Documentation and code organization

## Features

### Mandatory Conversions

| Specifier | Description                                                    |
| --------- | -------------------------------------------------------------- |
| `%c`      | Prints a single character                                      |
| `%s`      | Prints a string                                                |
| `%p`      | Prints a pointer address                                       |
| `%d`      | Prints a signed decimal integer                                |
| `%i`      | Prints a signed integer                                        |
| `%u`      | Prints an unsigned decimal integer                             |
| `%x`      | Prints an unsigned hexadecimal integer using lowercase letters |
| `%X`      | Prints an unsigned hexadecimal integer using uppercase letters |
| `%%`      | Prints a percent sign                                          |

### Helper Functions

The project is organized around several helper functions responsible for printing specific data types:

| Function                | Purpose                                               |
| ----------------------- | ----------------------------------------------------- |
| `ft_putchar`            | Prints a single character                             |
| `ft_putstr`             | Prints a string                                       |
| `ft_putnbr`             | Prints signed integers                                |
| `ft_putunsigned`        | Prints unsigned integers                              |
| `ft_puthexa`            | Prints hexadecimal numbers                            |
| `ft_putptr`             | Prints memory addresses                               |
| `ft_activate_specifier` | Dispatches conversions to the correct helper function |

## Project Structure

```text
ft_printf.c
├── ft_activate_specifier()
├── ft_putchar()
├── ft_putstr()
├── ft_putnbr()
├── ft_putunsigned()
├── ft_puthexa()
└── ft_putptr()
```

## Algorithm and Technical Design

### Overview

The implementation follows a dispatcher-based design.

The main `ft_printf()` function scans the format string character by character. Whenever a normal character is encountered, it is printed immediately.

When a percent sign (`%`) is found, the next character is interpreted as a conversion specifier and passed to a dedicated dispatcher function.

```text
Format String
      |
      v
Character Scan
      |
      +--> Regular Character --> Print
      |
      +--> '%' Found
                  |
                  v
          ft_activate_specifier()
                  |
                  +--> %c
                  +--> %s
                  +--> %p
                  +--> %d / %i
                  +--> %u
                  +--> %x
                  +--> %X
                  +--> %%
```

### Variadic Arguments

The project uses the standard variadic argument macros provided by `<stdarg.h>`:

```c
va_list
va_start
va_arg
va_end
```

These macros allow the function to retrieve an unknown number of arguments at runtime.

For example:

```c
ft_printf("%s %d", "Oscar", 42);
```

After detecting `%s`, the dispatcher retrieves a `char *` using `va_arg()`.

After detecting `%d`, it retrieves an `int`.

### Number Conversion Strategy

Instead of storing converted numbers in temporary buffers, the implementation prints numbers recursively.

#### Decimal Conversion

The signed integer printer divides the number by ten until only one digit remains.

Example:

```text
1234

1234 / 10 -> 123
123  / 10 -> 12
12   / 10 -> 1

Print order:
1 -> 2 -> 3 -> 4
```

This approach naturally prints digits in the correct order without requiring additional memory.

Special care is taken to correctly handle:

```text
INT_MIN = -2147483648
```

by converting the value to a `long` before negation.

#### Unsigned Integer Conversion

Unsigned integers are printed using the same recursive strategy but without sign handling.

Example:

```text
4294967295
```

The implementation correctly handles the full range of a 32-bit unsigned integer.

#### Hexadecimal Conversion

Hexadecimal numbers are printed recursively using base 16.

The implementation uses one of two lookup tables:

```c
"0123456789abcdef"
```

or

```c
"0123456789ABCDEF"
```

depending on whether `%x` or `%X` was requested.

Example:

```text
255

255 / 16 = 15
255 % 16 = 15

Output:
ff
```

#### Pointer Conversion

Pointers are first cast to:

```c
unsigned long
```

to ensure compatibility with 64-bit systems.

The address is then printed in hexadecimal format and prefixed with:

```text
0x
```

For null pointers:

```text
(nil)
```

is printed to match the behavior of the GNU implementation of `printf()` used at 42.

### Return Value Tracking

Each helper function returns the number of characters it printed.

The main function accumulates these values to reproduce the behavior of the standard `printf()`, which returns the total number of printed characters.

## Repository

Clone the repository using:

```bash
git clone https://github.com/oscarmatallana/ft_printf.git
cd ft_printf
```

## Instructions

### Build the library

Compile the project:

```bash
make
```

This generates:

```text
libftprintf.a
```

### Remove object files

```bash
make clean
```

### Remove object files and library

```bash
make fclean
```

### Rebuild everything

```bash
make re
```

## Usage Example

Include the header file:

```c
#include "ft_printf.h"
```

Compile your program together with the library:

```bash
cc main.c libftprintf.a
```

Example:

```c
#include "ft_printf.h"

int	main(void)
{
	ft_printf("Hello %s!\n", "World");
	ft_printf("Value: %d\n", 42);
	return (0);
}
```

Expected output:

```text
Hello World!
Value: 42
```

## Testing

The project was tested using:

### Custom Tests

* Comparison against the system `printf()`
* Edge case testing
* Return value verification
* NULL pointer and NULL string testing
* Integer boundary testing
* Unsigned integer boundary testing

### Community Testers

* printfTester
  https://github.com/Tripouille/printfTester

* UnitTester ft_printf
  https://github.com/MagicHatJo/-UT-ft_printf

* ft_printf_tester
  https://github.com/romslf/ft_printf_tester

## Resources

### Documentation

* Linux Manual Pages (`man 3 printf`)
* Linux Manual Pages (`man stdarg`)
* GNU C Library Documentation
* ISO C Standard Library Documentation

### Books

* The C Programming Language — Brian Kernighan & Dennis Ritchie
* C Programming For Dummies — Dan Gookin

### Videos

* "All You Need to Know About Variadic Functions" — Oceano
* "Let's Build a Mini printf Function" — Oceano

### Useful References

* https://en.cppreference.com/w/c/io/fprintf
* https://en.cppreference.com/w/c/variadic
* https://pythontutor.com

## AI Usage

AI tools were used as supplementary learning resources during the development of this project.

The AI was primarily used for:

* Visualizing the behavior of variadic functions.
* Clarifying pointer conversions and integer representations.
* Exploring recursive number-printing algorithms.
* Discussing edge cases such as `INT_MIN`, `NULL` pointers and large unsigned integers.
* Reviewing testing strategies.
* Improving project documentation and explanations.
* Running preliminary conceptual tests before validation with community testers.

All source code, implementation decisions, debugging, compilation, testing, and final validation were completed and verified by the author.

## Author

**Oscar Matallana**

42 Berlin — `omatalla`

Email: [omatalla@student.42berlin.de](mailto:omatalla@student.42berlin.de)

GitHub: https://github.com/oscarmatallana

