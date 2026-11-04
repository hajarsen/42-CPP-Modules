*This project has been created as part of the 42 curriculum by hsennane.*

# CPP08 — STL Containers, Algorithms and Iterators

## Description

CPP08 makes practical use of the C++ Standard Template Library (STL): searching ranges, calculating numerical spans, and making a stack iterable.

The sections below describe the exercise implementations and their underlying C++ concepts.

## Building

Each `exXX` folder has its own **C++98 Makefile**. Run `make` inside the exercise folder, then launch its executable (see that folder's Makefile for its name). Use `make fclean` to clean generated files.

### Exercises

| Folder | Topic | Purpose |
|---|---|---|
| `ex00` | **Easyfind** | Search for an integer using a standard algorithm. |
| `ex01` | **Span** | Track numbers and compute minimum and maximum distances. |
| `ex02` | **MutantStack** | Extend a stack adaptor with iteration support. |

## Technical Overview

### 1. Containers and iterators

Containers own elements; iterators identify positions in a range, commonly `[begin(), end())`. Algorithms such as `std::find` operate on these iterator ranges, allowing similar code to work with different containers.

### 2. How Span works

`Span` stores values in a vector with a maximum capacity. To calculate the shortest span, it copies and sorts the values, then compares neighboring differences. The longest span is simply max minus min. Both calculations require at least two values.

### 3. Shortest span calculation

For sorted values `[2, 6, 9, 20]`, the adjacent gaps are 4, 3 and 11, so the shortest span is **3**; the longest span is **18**. You do not need to compare every pair once values are in sorted order.

### 4. Iterable stack adaptor

`std::stack` is an adaptor exposing `push`, `pop`, and `top`, but no public iterators. The `MutantStack` class derives from `std::stack` and exposes `begin()` and `end()` using the protected underlying container `c`.

### Implementation Highlights

**Span calculations use different strategies:** the shortest span sorts a copy of the stored numbers before comparing adjacent differences, while the longest span can be determined directly from the minimum and maximum. `MutantStack` exposes iterators through the underlying container while retaining the standard stack operations.

## Validation Cases

Search for a present and missing value in easyfind. For Span, try zero/one item, full capacity, duplicate values and a very large number range. For MutantStack, compare normal stack access with an iterator loop.

**Important:** Shortest span and longest span report differences between stored values, not the number of elements between positions. The Span class throws an exception when the collection is too small.

These checks are suggestions; the documentation update does not imply they were run.

## References

- [C++ reference](https://en.cppreference.com/w/cpp)
- [C++ language guide](https://en.cppreference.com/w/cpp/language)
- [GNU Make](https://www.gnu.org/software/make/manual/)

