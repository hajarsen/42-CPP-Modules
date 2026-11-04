*This project has been created as part of the 42 curriculum by hsennane.*

# CPP02 — Fixed-Point Numbers and Operator Overloading

## Description

CPP02 builds a `Fixed` number class step by step: canonical object construction, integer and float conversions, arithmetic operators, comparisons, and increments.

Each exercise builds on the previous concepts. This guide explains **what the code does, why the concepts matter, and how to explore them**.

## Building

Each `exXX` folder has its own **C++98 Makefile**. Run `make` inside the exercise folder, then launch its executable (see that folder's Makefile for its name). Use `make fclean` to clean generated files.

### Exercises

| Folder | Topic | Purpose |
|---|---|---|
| `ex00` | **Canonical form** | Implement constructors, assignment, destructor and raw-value access. |
| `ex01` | **Numeric conversion** | Convert integers and floats to and from fixed-point. |
| `ex02` | **Operators** | Overload arithmetic, comparison, increment/decrement, min and max. |

## Resources — Understand the Concepts

### 1. What fixed-point means

Instead of storing a fractional value directly, the class stores a scaled integer `value`. The header declares `fractionalBits = 8`, so the scale factor is `2^8 = 256`. For example, 1.5 corresponds to the raw integer 384. `toFloat()` divides by 256.

### 2. Canonical form and copying

The default constructor initializes the raw number to zero. A copy constructor builds a new object from an existing object; assignment updates an already-existing object. The destructor finishes the object's lifetime. Keeping these operations consistent avoids surprising object behavior.

### 3. Operator overloading and precision

Comparison operators compare stored raw integers. `+`, `-`, `*`, and `/` in the current ex02 implementation convert operands to floating point, calculate, then construct a `Fixed` result. Prefix `++a` returns the updated object; postfix `a++` returns a copy of the previous value. Each increment changes the raw value by 1—that is, 1/256 of a unit.

### How it works

```text
Float 1.5  ─×256─► Raw 384 ─÷256─► Float 1.5

++a : increment raw value, return current object
 a++: save old copy, increment, return old copy
```

## Practice and Testing

Test `Fixed(1.5f).getRawBits()` (expected raw 384), comparisons, copies, and prefix versus postfix increments. Try values that require rounding and observe the limited fractional precision.

**What to watch for:** These are fixed-point approximations, not arbitrary-precision numbers. The current division operator has no explicit guard against dividing by zero, so do not assume safe behavior for that case.

The suggestions above are for your own testing; no automated results are claimed here.

### Questions to consider

- What does this exercise add compared with the previous one?
- Which parts of the code manage data, and which perform operations?
- How do errors and boundary cases affect the results?
- Could you explain the diagram and the output in a 42 evaluation?

## Useful Resources

- [C++ language reference](https://en.cppreference.com/w/cpp)
- [C++98 classes and language basics](https://en.cppreference.com/w/cpp/language)
- [GNU Make manual](https://www.gnu.org/software/make/manual/)

### AI Usage

AI assistance was used to organize the documentation, clarify concepts and prepare examples. **Source code was not changed** by this README update.
