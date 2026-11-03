*This project has been created as part of the 42 curriculum by hsennane.*

# CPP Module 09 — STL Containers and Algorithms

## Description

This module applies C++98 STL containers and algorithms to three practical problems: historical Bitcoin rates, **reverse Polish notation (RPN)**, and the **Ford–Johnson merge-insertion sorting approach**.

The exercises are independent programs and are stored in `ex00`, `ex01`, and `ex02`.

## Instructions

### Building the Project

The exercise Makefiles use **C++98** with `-Wall -Wextra -Werror`. You need a C++ compiler and `make`.

```bash
git clone https://github.com/hajarsen/CPP09.git
cd CPP09
cd ex01
make
./RPN '8 9 * 9 - 9 - 9 - 4 - 1 +'
```

To try another exercise, change into its directory, run `make`, and check its Makefile for the executable name. The common targets are `make`, `make clean`, `make fclean`, and `make re`.

### Exercises

| Exercise | Project | Purpose |
|---|---|---|
| `ex00` | **Bitcoin Exchange** | Read dated values, look up historical exchange rates, and calculate results. |
| `ex01` | **RPN** | Evaluate postfix expressions using a stack. |
| `ex02` | **PmergeMe** | Sort integers using a pair-based merge-insertion approach with vector and deque containers. |

### Suggested Tests

For RPN, try `3 4 +`, `8 2 /`, `3 0 /` (error), and incomplete expressions. For PmergeMe, try sorted, reversed, small and odd-length input and duplicates. For Bitcoin Exchange, test valid dates, invalid dates, negative inputs, and values missing from the rate history.

These are **suggested manual tests**; they have not been executed as part of this documentation update.

## Resources

The following sections explain the core concepts with simplified examples and diagrams, following the style of the NetPractice README.

---

### 🗓️ Historical Lookup

Bitcoin Exchange reads date/value input and uses historical exchange data; dates, file format, and rate lookup are important validation points.

### 🧮 RPN and Stacks

In postfix notation, operators consume preceding operands. A stack stores intermediate values until the final result remains.

### ⚡ Merge-Insertion Sorting

The PmergeMe implementation groups values into pairs, recursively sorts the larger elements, then inserts remaining values using an order influenced by Jacobsthal numbers. It implements vector and deque versions.


### Concept Diagram

```text
      RPN: 3 4 + 2 *
       │  │  │ │ │
       ▼  ▼  ▼ ▼ ▼
       3  4  + 2 *
           │     │
         3+4=7   │
               7*2=14

     result = 14
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
- [C++ STL containers](https://en.cppreference.com/w/cpp/container)
- [std::stack](https://en.cppreference.com/w/cpp/container/stack)
- [std::lower_bound](https://en.cppreference.com/w/cpp/algorithm/lower_bound)
- [GNU Make manual](https://www.gnu.org/software/make/manual/)

### AI Usage

AI assistance was used to **organize this README, clarify the C++ concepts, and create educational diagrams**. No C++ implementation files were changed by this documentation update.
