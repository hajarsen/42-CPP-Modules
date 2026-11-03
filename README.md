*This project has been created as part of the 42 curriculum by hsennane.*

# CPP Module 07 — Templates

## Description

This module introduces **function templates** and **class templates**, allowing reusable logic to work with different types while preserving compile-time type checking.

The exercises are independent programs and are stored in `ex00`, `ex01`, and `ex02`.

## Instructions

### Building the Project

The exercise Makefiles use **C++98** with `-Wall -Wextra -Werror`. You need a C++ compiler and `make`.

```bash
git clone https://github.com/hajarsen/CPP07.git
cd CPP07
cd ex00
make
./whatever
```

To try another exercise, change into its directory, run `make`, and check its Makefile for the executable name. The common targets are `make`, `make clean`, `make fclean`, and `make re`.

### Exercises

| Exercise | Project | Purpose |
|---|---|---|
| `ex00` | **Whatever** | Implement generic swap, minimum, and maximum functions. |
| `ex01` | **Iter** | Apply a function to each element of an array. |
| `ex02` | **Array** | Implement a templated dynamic array class with indexed access. |

### Suggested Tests

Try swapping integers and strings, calling `iter` on arrays of several element types, copying an Array, and accessing indexes at and outside its bounds.

These are **suggested manual tests**; they have not been executed as part of this documentation update.

## Resources

The following sections explain the core concepts with simplified examples and diagrams, following the style of the NetPractice README.

---

### 🧩 Function Templates

A template describes an algorithm in terms of a type parameter. The compiler produces a suitable instantiation for the types used.

### 🔁 Iterating Over Arrays

A generic `iter` function accepts an array, its length, and a callable to apply to the elements.

### 📦 Class Templates

A templated Array class manages a dynamically allocated sequence of values; testing should include copies and out-of-range access.


### Concept Diagram

```text
    template <typename T>
              │
     ┌────────┼────────┐
     ▼        ▼        ▼
   int      double   string
     └────────┼────────┘
              ▼
        same generic
          algorithm
```

---

## 🎯 Learning and Evaluation Tips

1. Explain the purpose of each class, header and source file.
2. Compile with `-std=c++98 -Wall -Wextra -Werror`.
3. Try invalid inputs and boundary cases, not just the happy path.
4. Check that copies, exceptions, containers, and resource lifetimes behave as expected.
5. Consult the 42 subject provided for your module for evaluation requirements.

### Useful Links

- [C++ reference](https://en.cppreference.com/w/cpp)
- [C++ templates](https://en.cppreference.com/w/cpp/language/templates)
- [Function templates](https://en.cppreference.com/w/cpp/language/function_template)
- [GNU Make manual](https://www.gnu.org/software/make/manual/)

### AI Usage

AI assistance was used to **organize this README, clarify the C++ concepts, and create educational diagrams**. No C++ implementation files were changed by this documentation update.
