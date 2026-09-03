# ft_printf

<p align="center">
  <b>A custom implementation of the C standard printf function</b>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Language-C-A8B9CC?style=for-the-badge&logo=c&logoColor=black" alt="C">
  <img src="https://img.shields.io/badge/42-Common%20Core-black?style=for-the-badge" alt="42">
  <img src="https://img.shields.io/badge/Makefile-Build-orange?style=for-the-badge" alt="Makefile">
  <img src="https://img.shields.io/badge/Library-Static-blue?style=for-the-badge" alt="Static Library">
</p>

---

## 📖 About

**ft_printf** is a custom implementation of the standard C `printf()` function, developed as part of the **42 Common Core**.

The objective of the project is to reproduce the core behavior of `printf()` while working with **variadic functions**, format strings and multiple data types.

Unlike simply calling the standard library function, this implementation handles the format string manually and dispatches each conversion to a dedicated function.

The project focuses on understanding how formatted output works at a lower level while developing skills in:

* Variadic functions
* Format-string parsing
* Function decomposition
* Pointers and pointer casting
* Integer and hexadecimal conversions
* Unsigned values
* Memory and data representation
* File descriptor output
* Static libraries
* Makefiles and compilation

---

# ✨ Features

The implementation supports the standard conversion specifiers required by the 42 `ft_printf` project:

| Specifier | Description                                         |
| :-------: | --------------------------------------------------- |
|    `%c`   | Prints a single character                           |
|    `%s`   | Prints a string                                     |
|    `%p`   | Prints a pointer address in hexadecimal             |
|    `%d`   | Prints a signed decimal integer                     |
|    `%i`   | Prints a signed integer                             |
|    `%u`   | Prints an unsigned decimal integer                  |
|    `%x`   | Prints an unsigned integer in lowercase hexadecimal |
|    `%X`   | Prints an unsigned integer in uppercase hexadecimal |
|    `%%`   | Prints a literal `%` character                      |

The main function follows the standard `printf` interface:

```c
int ft_printf(const char *format, ...);
```

It returns the **number of characters successfully written**.

---

# 🧠 How It Works

At a high level, `ft_printf` processes the format string sequentially.

```text
                     ft_printf()
                          │
                          ▼
                  Read format string
                          │
                ┌─────────┴─────────┐
                │                   │
          Regular character       '%'
                │                   │
                ▼                   ▼
          Print directly       Read conversion
                                    │
                    ┌───────────────┼───────────────┐
                    │       │       │       │       │
                    ▼       ▼       ▼       ▼       ▼
                   %c      %s      %p    %d/%i    %u
                                            │
                                  ┌─────────┴─────────┐
                                  ▼                   ▼
                                 %x                  %X
                                  │                   │
                                  └─────────┬─────────┘
                                            ▼
                                      Print result
```

The implementation separates the different output types into dedicated functions instead of putting all conversion logic inside a single function.

This keeps the code easier to understand, maintain and extend.

---

# 🔧 Implementation

The project is organized around a main dispatcher and specialized output functions.

### `ft_printf.c`

Contains the main `ft_printf()` function.

Its responsibilities include:

* Initializing the variadic argument list.
* Traversing the format string.
* Detecting `%` conversion sequences.
* Selecting the appropriate output function.
* Keeping track of the number of characters printed.
* Closing the variadic argument list.

The variadic arguments are handled using the `<stdarg.h>` interface:

```c
va_list
va_start
va_arg
va_end
```

---

### Character output — `ft_putchar.c`

Handles the `%c` conversion.

```text
%c → character → output
```

This provides the basic character-printing operation used by the formatter.

---

### String output — `ft_putstr.c`

Handles `%s`.

```text
%s → char * → string output
```

The implementation traverses the string and writes its contents while accounting for the number of characters printed.

---

### Signed integers — `ft_putnbr.c`

Handles:

```text
%d
%i
```

The implementation converts signed decimal integers into their textual representation.

This requires handling:

* Positive numbers
* Negative numbers
* Zero
* Multiple digits
* The limits of the `int` type

---

### Unsigned integers — `ft_print_unsigned.c`

Handles:

```text
%u
```

Unlike signed decimal output, unsigned values must be interpreted using the full range of the `unsigned int` type.

---

### Hexadecimal output — `ft_print_hex.c`

Handles:

```text
%x
%X
```

The same numerical value can be represented using two different hexadecimal alphabets:

```text
%x → 0 1 2 3 4 5 6 7 8 9 a b c d e f

%X → 0 1 2 3 4 5 6 7 8 9 A B C D E F
```

The implementation therefore performs base-16 conversion while selecting the appropriate character set depending on the conversion specifier.

---

### Pointer output — `ft_print_ptr.c`

Handles:

```text
%p
```

Pointer values are represented as hexadecimal addresses.

This requires working with pointer types and converting the address into a printable hexadecimal representation.

---

# 📂 Project Structure

```text
Printf/
│
├── Makefile
├── ft_printf.h
│
├── ft_printf.c
├── ft_putchar.c
├── ft_putstr.c
├── ft_putnbr.c
├── ft_print_unsigned.c
├── ft_print_hex.c
└── ft_print_ptr.c
```

### File responsibilities

| File                  | Responsibility                                 |
| --------------------- | ---------------------------------------------- |
| `ft_printf.c`         | Main formatting engine and conversion dispatch |
| `ft_printf.h`         | Function prototypes and declarations           |
| `ft_putchar.c`        | Character output                               |
| `ft_putstr.c`         | String output                                  |
| `ft_putnbr.c`         | Signed decimal output                          |
| `ft_print_unsigned.c` | Unsigned decimal output                        |
| `ft_print_hex.c`      | Hexadecimal output                             |
| `ft_print_ptr.c`      | Pointer address output                         |
| `Makefile`            | Compilation and static library generation      |

---

# 🛠️ Technologies & Concepts

### Programming language

**C**

The project is implemented entirely in C and follows the constraints of the 42 curriculum.

### Core concepts

* Variadic functions
* `va_list`
* `va_start`
* `va_arg`
* `va_end`
* Pointers
* Pointer casting
* Integer representation
* Base conversion
* String manipulation
* Format-string parsing
* Function decomposition
* File descriptors
* `write()`

### Build system

**Make**

The project uses a Makefile to automate compilation and generate the static library.

---

# 📦 Compilation

Clone the repository:

```bash
git clone https://github.com/sorayaafdz/Printf.git
cd Printf
```

Compile the library:

```bash
make
```

This generates:

```text
libftprintf.a
```

---

## Makefile commands

### Compile

```bash
make
```

### Remove object files

```bash
make clean
```

### Remove object files and the compiled library

```bash
make fclean
```

### Recompile the project

```bash
make re
```

---

# 🚀 Using ft_printf

Once `libftprintf.a` has been generated, the library can be linked to another C project.

Include the header:

```c
#include "ft_printf.h"
```

Example:

```c
#include "ft_printf.h"

int main(void)
{
    char    *name;
    int     age;

    name = "Soraya";
    age = 26;

    ft_printf("Name: %s\n", name);
    ft_printf("Age: %d\n", age);
    ft_printf("Hexadecimal: %x\n", 42);
    ft_printf("Pointer: %p\n", name);

    return (0);
}
```

Compile:

```bash
cc main.c -L. -lftprintf -I. -o program
```

Run:

```bash
./program
```

---

# 🔍 Example Output

```text
Name: Soraya
Age: 26
Hexadecimal: 2a
Pointer: 0x7ffee4...
```

The exact pointer value will depend on the execution environment.

---

# 🧩 Why Variadic Functions?

One of the main objectives of this project is understanding **variadic functions**.

The standard `printf()` function accepts a variable number of arguments:

```c
printf("Name: %s | Age: %d\n", name, age);
```

The number and types of arguments are not known at compile time by the function itself.

`ft_printf` therefore uses the facilities provided by `<stdarg.h>`.

The typical workflow is:

```c
va_list args;

va_start(args, format);

value = va_arg(args, type);

va_end(args);
```

This project provides practical experience working with arguments whose number and type depend on the format string.

---

# 🧮 Number Base Conversion

A significant part of the implementation involves converting numerical values into different textual representations.

For example:

```text
Decimal
  42
   │
   ├── %d / %i
   │       ↓
   │      "42"
   │
   ├── %x
   │       ↓
   │      "2a"
   │
   └── %X
           ↓
          "2A"
```

This requires understanding how numbers can be represented in different bases and how to generate their corresponding character representation.

---

# 🧠 Key Learning Outcomes

This project strengthened several fundamental C programming skills.

### 1. Variadic functions

Understanding how functions such as `printf()` can receive an arbitrary number of arguments.

### 2. Format parsing

Learning to interpret a format string and determine what operation needs to be performed.

### 3. Type handling

Working with different argument types:

```text
char
char *
int
unsigned int
void *
```

### 4. Pointers

Using pointers for:

* Strings
* Memory addresses
* Generic data
* Pointer conversions

### 5. Number systems

Implementing decimal and hexadecimal representations without relying on the original `printf()` implementation.

### 6. Modular design

Separating each conversion into its own implementation rather than creating one large function.

### 7. Static libraries

Understanding how multiple object files can be compiled and packaged into a reusable `.a` library.

### 8. Build automation

Using Makefiles to automate compilation and dependency management.

---

# 🧪 Testing

Testing a `printf` implementation requires checking not only the visible output but also the **return value**.

A useful comparison is:

```c
printf(...)
ft_printf(...)
```

Both should produce equivalent output for the supported conversions and return the corresponding number of characters written.

Typical test cases include:

* Empty strings
* Empty format strings
* Multiple conversions
* Positive integers
* Negative integers
* Zero
* Large unsigned values
* Hexadecimal values
* Uppercase hexadecimal values
* Pointer addresses
* Multiple arguments
* Consecutive conversions
* Literal `%` characters
* Strings containing spaces and special characters

---

# 📈 Skills Demonstrated

```text
C PROGRAMMING
│
├── Variadic Functions
├── Pointers
├── String Handling
├── Integer Conversion
├── Hexadecimal Conversion
├── Type Handling
└── File Descriptors
        │
        ▼
SOFTWARE ENGINEERING
│
├── Modular Design
├── Code Organization
├── Error Handling
├── Makefiles
└── Static Libraries
```

---

# 🎓 42 Common Core

**ft_printf** is one of the foundational projects of the **42 Common Core**.

It builds on the low-level C knowledge developed during `Libft` and provides concepts that are useful throughout later projects involving:

* Systems programming
* Unix
* Parsing
* Memory management
* Processes
* Networking
* C++
* Software architecture

This project was completed as part of my **42 Madrid Common Core**.

---

# 👩‍💻 Author

**Soraya Fernández**

Software Developer · 42 Madrid Common Core

GitHub: **[@sorayaafdz](https://github.com/sorayaafdz)**
