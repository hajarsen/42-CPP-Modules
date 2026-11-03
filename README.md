*This project has been created as part of the 42 curriculum by hsennane.*

# CPP Module 02

## Description

**CPP Module 02** explores **fixed-point numbers**, the **Orthodox Canonical Form**, conversion between numeric representations, and **operator overloading**.

The source files are located under `cpp02/ex00`, `cpp02/ex01` and `cpp02/ex02`.

## Instructions

### Building and Running

```bash
git clone https://github.com/hajarsen/CPP02.git
cd CPP02/cpp02/ex00
make
./fixed_point
```

Compile each exercise separately using its Makefile (`-Wall -Wextra -Werror -std=c++98`).

### Exercises

| Directory | Subject |
|---|---|
| `cpp02/ex00` | Introduce a Fixed class with canonical constructors, assignment, and a destructor |
| `cpp02/ex01` | Convert fixed-point values to and from integer and floating-point representations |
| `cpp02/ex02` | Add arithmetic, comparisons, increments, and helper operations |

### Suggested tests

Try zero, positive and negative numbers, fractional values, copy construction, assignment, comparisons, and arithmetic operations. Compare conversions to expected values while accounting for fixed-point rounding.

## Resources

---

## 🧮 Fixed-Point Representation

A fixed-point number stores an integer scaled by a fixed power of two.

```text
      Decimal value
            │
   scale by 2^fractional_bits
            ▼
     Stored integer bits
            │
   divide by 2^fractional_bits
            ▼
     Decimal approximation
```

For illustration, with 8 fractional bits:

```text
1.5 × 256 = 384
384 / 256 = 1.5
```

### Why Fixed-Point?

Fixed-point representation is useful when you want predictable scaling or learn how integers can represent fractional quantities.

---

## 🔁 Orthodox Canonical Form

A typical C++98 value type provides:

```text
Fixed()                 Default constructor
Fixed(const Fixed&)     Copy constructor
operator=(...)          Copy assignment
~Fixed()                Destructor
```

This makes object copying and lifetime behavior explicit.

---

## ➕ Operator Overloading

```text
Fixed a, b
    │
    ├── a + b  → arithmetic operator
    ├── a < b  → comparison operator
    ├── ++a    → prefix increment
    └── a++    → postfix increment
```

Operators should reflect the intended meaning of the value type and should be implemented with careful attention to references and `const` methods.

## 🎯 Learning Checklist

- Explain the raw stored value and its scaling factor.
- Distinguish copy construction from assignment.
- Check rounding and numeric precision.
- Verify operators using simple numeric examples.

### Useful Links

- [C++ operator overloading](https://en.cppreference.com/w/cpp/language/operators)
- [C++ constructors](https://en.cppreference.com/w/cpp/language/constructor)

### AI Usage

AI assistance was used to structure the README and add illustrative explanations. C++ source files were not modified.
