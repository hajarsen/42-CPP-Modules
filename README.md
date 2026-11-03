*This project has been created as part of the 42 curriculum by hsennane.*

# CPP09 — STL Containers and Algorithms

## Description

**CPP Module 09** applies C++98 containers to three problems: finding historical exchange rates, evaluating postfix expressions, and sorting numbers using a **Ford–Johnson-inspired merge-insertion approach**.

The aim of this README is to help visitors understand both **what the programs do** and **how their algorithms work**.

| Exercise | Program | Main concept |
|---|---|---|
| `ex00` | `btc` | `std::map` and ordered lookups |
| `ex01` | `RPN` | `std::stack` and postfix evaluation |
| `ex02` | `PmergeMe` | `std::vector`, `std::deque` and sorting |

## Instructions

### Build

Each exercise has its own Makefile. Use a C++ compiler and `make`; the projects use `-std=c++98 -Wall -Wextra -Werror`.

```bash
git clone https://github.com/hajarsen/CPP09.git
cd CPP09

cd ex00 && make && cd ..
cd ex01 && make && cd ..
cd ex02 && make && cd ..
```

Inside an exercise folder: `make clean` removes object files; `make fclean` removes objects and the executable; `make re` rebuilds.

---

## 📈 Exercise 00 — Bitcoin Exchange

### The problem

Given an input date and Bitcoin amount, multiply the amount by the **exchange rate on that date**. If the date has no entry, use the most recent **earlier** rate.

The program reads a comma-separated database and a separate input file:

```text
data.csv                input.txt
date,exchange_rate      date | value
2011-01-01,2            2011-01-05 | 3
2011-01-03,4
2011-01-10,8
```

**These rates are invented for demonstration, not historical market data.**

For the input `2011-01-05 | 3`, the program uses the rate for **2011-01-03** (4), so the result is **3 × 4 = 12**.

### Why std::map?

`std::map<std::string, double>` keeps date keys sorted. With dates written as `YYYY-MM-DD`, their string order agrees with chronological order for valid dates.

The source uses `upper_bound(date)` and steps back one iterator:

```text
Stored dates:  Jan 01 ── Jan 03 ───── Jan 10
Query:                          Jan 05
upper_bound(Jan 05) ────────────────► Jan 10
Previous entry     ◄─────────────── Jan 03
Chosen rate: Jan 03
```

`upper_bound` returns the first key **greater than** the query; the previous key is the latest available date **not later than** the query. If the query precedes every key, no earlier rate exists.

### Running ex00

The repository currently does **not include a `data.csv` database**. Supply one in `ex00/` before running the program.

```bash
cd ex00
make
# Place your own data.csv and input.txt here.
./btc input.txt
```

The code checks date formats and calendar validity, rejects negative values and values above 1000, and reports malformed lines. It uses a map lookup per input line. For `n` rates, the lookup is **O(log n)**.

**Implementation note:** The source checks whether the rate map is empty inside its database-reading loop, so an invalid first data row may cause an early error even if later rows would be valid.

---

## 🧮 Exercise 01 — Reverse Polish Notation

### How postfix notation works

An ordinary mathematical expression is written with operators between numbers:

```text
(3 + 4) × 2
```

In **Reverse Polish Notation (RPN)**, the operators follow the numbers:

```text
3 4 + 2 *
```

The program uses `std::stack<int>`. Numbers are pushed; operators pop the top two numbers, calculate a result, then push it back.

### Worked example

```text
Token       Stack (bottom → top)
  3         [3]
  4         [3, 4]
  +         [7]          (3 + 4)
  2         [7, 2]
  *         [14]         (7 × 2)

Result: 14
```

For subtraction and division, **operand order matters**. The first popped value is the right operand; the second popped value is the left operand.

### Try it

```bash
cd ex01
make
./RPN "3 4 + 2 *"  # 14
./RPN "8 2 /"      # 4
./RPN "3 0 /"      # Error: division by zero
```

The implementation accepts **single-digit operands (0–9)** and operators `+`, `-`, `*`, `/`. It rejects invalid tokens, insufficient operands, and expressions that do not leave exactly one stack value. For `t` tokens, evaluation takes **O(t) time** and at most **O(t) auxiliary space**.

---

## ⚙️ Exercise 02 — PmergeMe

### What is PmergeMe?

`PmergeMe` sorts positive integers using two STL containers:

- **`std::vector`:** contiguous memory, fast random access.
- **`std::deque`:** segmented storage, also supporting fast random access.

Both versions follow a **pair-based merge-insertion strategy** inspired by **Ford–Johnson sorting**. The algorithm aims to make good choices about the *number of comparisons*, not necessarily the fastest elapsed runtime.

### Step 1 — Form pairs

Take the example:

```text
Input:      8  3  5  1  9  4  7  2

Pairs:     (8,3) (5,1) (9,4) (7,2)
Ordered:   (3,8) (1,5) (4,9) (2,7)
Large values: [8, 5, 9, 7]
```

### Step 2 — Sort the larger values recursively

```text
[8, 5, 9, 7]
     │ recursive sort
     ▼
[5, 7, 8, 9]

Corresponding ordered pairs:
(1,5) (2,7) (3,8) (4,9)
```

The main chain begins with the first smaller element and the sorted larger elements:

```text
Main chain:   [1, 5, 7, 8, 9]
Still pending: 2, 3, 4
```

### Step 3 — Insert pending values

The code locates each pending value's **larger partner** using `std::find`. It then uses `std::lower_bound` to find an insertion point **before that partner**.

That boundary is useful because each smaller value is known to be ≤ its own partner.

```text
[1, 5, 7, 8, 9]
      │ insert 3 before 8
      ▼
[1, 3, 5, 7, 8, 9]
      │ insert 2 before 7
      ▼
[1, 2, 3, 5, 7, 8, 9]
      │ insert 4 before 9
      ▼
[1, 2, 3, 4, 5, 7, 8, 9]
```

Odd-length inputs have one unpaired value; the code inserts it into the chain later.

### Why Jacobsthal numbers?

The **Jacobsthal sequence** begins:

```text
0, 1, 1, 3, 5, 11, 21, 43, ...

J(n) = J(n−1) + 2 × J(n−2)
```

The source uses boundaries starting at **1 and 3**, then follows this recurrence to determine groups of pending elements. It processes each group in reverse position order.

This ordering is inspired by Ford–Johnson's approach to keeping binary-insertion search ranges efficient in **comparison count**.

### Vector vs deque — what does this code measure?

`main.cpp` reads the same input into a vector and deque, sorts each separately, and prints CPU time from `clock()` in microseconds.

| Aspect | `std::vector` | `std::deque` |
|---|---|---|
| Storage | Contiguous | Segmented |
| Random access | O(1) | O(1) |
| Middle insertion | Generally O(n) | Generally O(n) |
| Algorithm implemented | Recursive pair/insertion | Same strategy |

**Complexity matters:** Classical Ford–Johnson is comparison-efficient (O(n log n) comparisons). But this particular implementation uses repeated linear `std::find` operations and middle insertions, so its **overall running work can be O(n²)**. Do not describe its runtime as O(n log n) just because it uses `lower_bound`.

Timing on one run is not a reliable benchmark; larger inputs, repeated trials, and the same data are needed for a meaningful comparison.

### Run ex02

```bash
cd ex02
make
./PmergeMe 8 3 5 1 9 4 7 2
./PmergeMe 3 2 1
./PmergeMe 1 2 3 4 5
./PmergeMe 5 5 2 2 1
```

The parser rejects empty input, zero, negative values and invalid integer arguments. Check that the `After:` output is sorted; the new README has not been used as an automated test of the program.

---

## 🎯 Things to Remember

1. **Bitcoin Exchange:** ordered maps support efficient lookup of the latest rate not after a date.
2. **RPN:** a stack matches postfix evaluation because operators use the last two pending values.
3. **PmergeMe:** pair sorting, recursion, bounded insertion and Jacobsthal-guided ordering form the core idea.
4. **Performance:** comparison counts, asymptotic running time, and measured CPU time are different quantities.

### Useful Links

- [C++ containers](https://en.cppreference.com/w/cpp/container)
- [std::map::upper_bound](https://en.cppreference.com/w/cpp/container/map/upper_bound)
- [std::stack](https://en.cppreference.com/w/cpp/container/stack)
- [std::lower_bound](https://en.cppreference.com/w/cpp/algorithm/lower_bound)
- [Merge-insertion sort](https://en.wikipedia.org/wiki/Merge-insertion_sort)
- [Jacobsthal sequence](https://oeis.org/A001045)

### AI Usage

AI assistance was used to explain the existing implementation, prepare diagrams and suggest tests. The program source files were not modified, and no new runtime benchmark results are claimed.
