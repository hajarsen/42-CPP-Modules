*This project has been created as part of the 42 curriculum by hsennane.*

# CPP Module 06 — C++ Casts

## Description

This module practices different forms of C++ type conversion: **scalar conversions**, pointer serialization, and **runtime identification** of derived objects.

The exercises are independent programs and are stored in `ex00`, `ex01`, and `ex02`.

## Instructions

### Building the Project

The exercise Makefiles use **C++98** with `-Wall -Wextra -Werror`. You need a C++ compiler and `make`.

```bash
git clone https://github.com/hajarsen/CPP06.git
cd CPP06
cd ex00
make
./convert 42
./convert 42.0f
```

To try another exercise, change into its directory, run `make`, and check its Makefile for the executable name. The common targets are `make`, `make clean`, `make fclean`, and `make re`.

### Exercises

| Exercise | Project | Purpose |
|---|---|---|
| `ex00` | **ScalarConverter** | Convert input literals to character, integer, float, and double representations. |
| `ex01` | **Serializer** | Convert a data pointer into an integer representation and back. |
| `ex02` | **Runtime type identification** | Identify derived class instances using pointer and reference casts. |

### Suggested Tests

For ScalarConverter, try `a`, `42`, `-42`, `42.0f`, `nan`, `inf`, and invalid strings. For Serializer, verify a round-trip preserves the original pointer. For type identification, test generated A/B/C instances.

These are **suggested manual tests**; they have not been executed as part of this documentation update.

## Resources

The following sections explain the core concepts with simplified examples and diagrams, following the style of the NetPractice README.

---

### 🔄 Scalar Conversion

Different C++ scalar types have different valid ranges and representations. A conversion may succeed, lose precision, or be impossible.

### 📍 Pointer Serialization

A pointer can be converted to an integer type capable of holding it, then converted back. This demonstrates the relationship between object addresses and integer representations.

### 🔍 Runtime Type Identification

Polymorphic base-class pointers and references can be dynamically checked against derived types using `dynamic_cast`.


### Concept Diagram

```text
         Input literal
              │
              ▼
      ScalarConverter
       /    |    |    \
      ▼     ▼    ▼     ▼
     char  int float double

Data* ─► uintptr_t ─► Data*
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
- [C++ casts](https://en.cppreference.com/w/cpp/language/explicit_cast)
- [dynamic_cast](https://en.cppreference.com/w/cpp/language/dynamic_cast)
- [GNU Make manual](https://www.gnu.org/software/make/manual/)

### AI Usage

AI assistance was used to **organize this README, clarify the C++ concepts, and create educational diagrams**. No C++ implementation files were changed by this documentation update.
