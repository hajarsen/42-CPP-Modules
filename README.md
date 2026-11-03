*This project has been created as part of the 42 curriculum by hsennane.*

# CPP Module 08 — Templated Containers and Iterators

## Description

This module introduces the **Standard Template Library (STL)**, iterators, algorithms, and containers. The exercises implement an element search, a span calculator, and an iterable stack.

The exercises are independent programs and are stored in `ex00`, `ex01`, and `ex02`.

## Instructions

### Building the Project

The exercise Makefiles use **C++98** with `-Wall -Wextra -Werror`. You need a C++ compiler and `make`.

```bash
git clone https://github.com/hajarsen/CPP08.git
cd CPP08
cd ex00
make
./easyfind
```

To try another exercise, change into its directory, run `make`, and check its Makefile for the executable name. The common targets are `make`, `make clean`, `make fclean`, and `make re`.

### Exercises

| Exercise | Project | Purpose |
|---|---|---|
| `ex00` | **Easyfind** | Search for an integer in a container using iterators and standard algorithms. |
| `ex01` | **Span** | Store integers and compute shortest and longest spans. |
| `ex02` | **MutantStack** | Extend a stack with iterator access to its underlying container. |

### Suggested Tests

Try searching for present and missing values, spans containing fewer than two numbers, duplicate numbers, large ranges, and iterating through a MutantStack after push/pop operations.

These are **suggested manual tests**; they have not been executed as part of this documentation update.

## Resources

The following sections explain the core concepts with simplified examples and diagrams, following the style of the NetPractice README.

---

### 🔎 Algorithms and Iterators

Standard algorithms work with iterator ranges rather than directly depending on one container type.

### 📏 Span Calculations

For a sequence of numbers, shortest span is the minimum difference between adjacent values after sorting; longest span is max minus min.

### 📚 Iterable Stacks

A regular stack exposes push/pop/top, while a MutantStack adds begin/end iterators to traverse its underlying container.


### Concept Diagram

```text
       STL container
      [3, 7, 10, 14]
            │
       begin() → end()
            │
      iterator traversal
            │
          std::find
            │
      value or not found
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
- [C++ algorithms](https://en.cppreference.com/w/cpp/algorithm)
- [C++ iterators](https://en.cppreference.com/w/cpp/iterator)
- [std::stack](https://en.cppreference.com/w/cpp/container/stack)
- [GNU Make manual](https://www.gnu.org/software/make/manual/)

### AI Usage

AI assistance was used to **organize this README, clarify the C++ concepts, and create educational diagrams**. No C++ implementation files were changed by this documentation update.
