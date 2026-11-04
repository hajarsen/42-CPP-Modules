*This project has been created as part of the 42 curriculum by hsennane.*

# CPP06 — C++ Casting and Type Identification

## Description

CPP06 explores explicit conversions between C++ types: numeric literals, pointer/integer round trips, and runtime identification of polymorphic objects.

The sections below describe the exercise implementations and their underlying C++ concepts.

## Building

Each `exXX` folder has its own **C++98 Makefile**. Run `make` inside the exercise folder, then launch its executable (see that folder's Makefile for its name). Use `make fclean` to clean generated files.

### Exercises

| Folder | Topic | Purpose |
|---|---|---|
| `ex00` | **ScalarConverter** | Convert input text into char, int, float and double outputs. |
| `ex01` | **Serializer** | Convert a `Data*` to `uintptr_t` and back. |
| `ex02` | **Identify** | Recognize A, B or C objects through a Base pointer/reference. |

## Technical Overview

### 1. Scalar conversions are not always possible

`ScalarConverter` detects whether a literal is a character, integer, float or double, then prints its representations in all four forms. A value may be out of range for `char` or `int`, and special values like `nan` or `+inf` are not normal integers. The implementation checks printability and limits.

### 2. reinterpret_cast and pointer serialization

`Serializer::serialize()` converts a pointer to `uintptr_t`; `deserialize()` converts the integer representation back. This is an **address round trip**, not saving object contents to a file. The example compares the restored pointer with the original; the object must still be alive.

### 3. Runtime identification with dynamic_cast

`generate()` creates an A, B or C through a Base pointer. A `dynamic_cast` on a pointer returns null if the cast fails; a failing reference cast throws `std::bad_cast`. The exercise demonstrates both ways of identifying the dynamic type.

### Implementation Diagram

```text
Text '42.5f' ─► scalar conversion ─► char/int/float/double

Data* ─► uintptr_t ─► Data* (same address)

Base* ─► dynamic_cast ─► A? B? C?
```

## Validation Cases

Run `./convert a`, `./convert 42`, `./convert 42.5f`, `./convert nan`, `./convert +inf`, and an invalid string. For the other exercises check pointer equality and which derived class gets identified.

**Important:** A cast cannot make an expired pointer valid. Conversions of large floating-point values can lose precision, so check outputs rather than assuming exact values.

These checks are suggestions; the documentation update does not imply they were run.

## References

- [C++ reference](https://en.cppreference.com/w/cpp)
- [C++ language guide](https://en.cppreference.com/w/cpp/language)
- [GNU Make](https://www.gnu.org/software/make/manual/)

### AI Usage

AI assistance was used to organize the documentation, clarify concepts and prepare examples. **No source code was changed.**
