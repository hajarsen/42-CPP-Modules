*This project has been created as part of the 42 curriculum by hsennane.*

# CPP08 — STL Containers, Algorithms and Iterators

## Description

CPP08 makes practical use of the C++ Standard Template Library (STL): searching ranges, calculating numerical spans, and making a stack iterable.

This README explains **what each exercise demonstrates**, the key ideas behind the code, and ways to explore them yourself.

## Building

Each `exXX` folder has its own **C++98 Makefile**. Run `make` inside the exercise folder, then launch its executable (see that folder's Makefile for its name). Use `make fclean` to clean generated files.

### Exercises

| Folder | Topic | What it does |
|---|---|---|
| `ex00` | **Easyfind** | Search for an integer using a standard algorithm. |
| `ex01` | **Span** | Track numbers and compute minimum and maximum distances. |
| `ex02` | **MutantStack** | Extend a stack adaptor with iteration support. |

## Resources — Key Concepts

### 1. Containers and iterators

Containers own elements; iterators identify positions in a range, commonly `[begin(), end())`. Algorithms such as `std::find` operate on these iterator ranges, allowing similar code to work with different containers.

### 2. How Span works

`Span` stores values in a vector with a maximum capacity. To calculate the shortest span, it copies and sorts the values, then compares neighboring differences. The longest span is simply max minus min. Both calculations require at least two values.

### 3. Why sorting helps the shortest span

For sorted values `[2, 6, 9, 20]`, the adjacent gaps are 4, 3 and 11, so the shortest span is **3**; the longest span is **18**. You do not need to compare every pair once values are in sorted order.

### 4. Why MutantStack?

`std::stack` is an adaptor exposing `push`, `pop`, and `top`, but no public iterators. The `MutantStack` class derives from `std::stack` and exposes `begin()` and `end()` using the protected underlying container `c`.

### Visual summary

```text
Span values: 20 2 9 6
     │ sort copy
     ▼
     2 --4-- 6 --3-- 9 --11-- 20
     shortest = 3 / longest = 18

MutantStack ─► underlying deque ─► iterators
```

## Tests to Try

Search for a present and missing value in easyfind. For Span, try zero/one item, full capacity, duplicate values and a very large number range. For MutantStack, compare normal stack access with an iterator loop.

**Important:** Shortest span and longest span report differences between stored values, not the number of elements between positions. The Span class throws an exception when the collection is too small.

These checks are suggestions; the documentation update does not imply they were run.

## Further Reading

- [C++ reference](https://en.cppreference.com/w/cpp)
- [C++ language guide](https://en.cppreference.com/w/cpp/language)
- [GNU Make](https://www.gnu.org/software/make/manual/)

### AI Usage

AI assistance was used to organize the documentation, clarify concepts and prepare examples. **No source code was changed.**
