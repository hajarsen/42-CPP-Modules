*This project has been created as part of the 42 curriculum by hsennane.*

# CPP Module 09 — Containers, Algorithms & Complexity

## Description

**CPP09** is a set of three independent exercises combining **C++98 STL containers**, parsing, algorithm design, and performance measurement. Think of this README as a **study guide**: it explains the ideas, walks through examples, describes the actual implementation, and provides exercises to check your understanding.

| Exercise | Program | Main questions |
|---|---|---|
| **ex00 — Bitcoin Exchange** | `btc` | How can a sorted map retrieve the most recent available value for a date? |
| **ex01 — RPN** | `RPN` | How can a stack evaluate an expression without parentheses? |
| **ex02 — PmergeMe** | `PmergeMe` | How does a merge-insertion approach sort values, and why do Jacobsthal numbers appear? |

All three exercises have their own Makefile. The code uses **C++98**, rather than modern C++ features.

## Instructions

### Build and run

Requirements: `c++` and `make`. All exercises compile with `-Wall -Wextra -Werror -std=c++98`.

```bash
git clone https://github.com/hajarsen/CPP09.git
cd CPP09

cd ex00 && make && cd ..
cd ex01 && make && cd ..
cd ex02 && make && cd ..
```

Each directory also supports `make clean`, `make fclean` and `make re`.

### Quick commands

```bash
# ex00: requires an input file and a database named data.csv
cd ex00
./btc input.txt

# ex01: expression is a single quoted shell argument
cd ../ex01
./RPN "3 4 + 2 *"

# ex02: pass positive integers as separate arguments
cd ../ex02
./PmergeMe 8 3 5 1 9 4 7 2
```

**Important for ex00:** The current repository does **not** contain `ex00/data.csv`. The program calls `loadDatabase("data.csv")`, so it cannot perform exchange calculations until you supply a correctly formatted CSV file in the working directory. The small example below uses **artificial rates only for testing**.

---

## 📈 Exercise 00 — Bitcoin Exchange

### 1. The problem

You have two sources of information:

- A **historical database**: date and exchange rate.
- An **input file**: date and amount to convert.

For each input date, the program should choose the rate on that date, or if that date has no rate, the **most recent earlier date**. It then computes:

```text
result = input value × selected historical exchange rate
```

This is a **predecessor lookup** problem over ordered keys.

### 2. Why std::map?

In `BitcoinExchange.hpp`, the rate collection is represented as a sorted mapping of dates to rates. A `std::map` maintains its keys in order and offers logarithmic lookup operations.

The code stores dates as **YYYY-MM-DD** strings. For valid, zero-padded ISO-style dates, lexicographic order matches chronological order:

```text
2011-01-01 < 2011-01-03 < 2011-01-10
        keys sorted automatically by std::map
```

The key lookup in the source is:

```cpp
it = _rates.upper_bound(date);
if (it == _rates.begin())
{
    // No rate exists on or before date.
}
else
{
    --it; // Largest key <= requested date.
}
```

**Why upper_bound instead of find?** `find` works only for an exact key. `upper_bound(d)` returns the first key **strictly greater than** `d`. Stepping one element back selects the greatest key not exceeding `d`.

### 3. Walkthrough with a tiny reproducible database

In the `ex00` directory, create this test-only `data.csv`:

```csv
date,exchange_rate
2011-01-01,2
2011-01-03,4
2011-01-10,8
```

Then create `input.txt`:

```text
date | value
2011-01-01 | 3
2011-01-05 | 3
2011-01-10 | 0.5
2010-12-31 | 1
```

Run `./btc input.txt`. These are the **intended calculations from the code**, not historical Bitcoin prices:

| Requested date | Rate date chosen | Calculation | Expected result |
|---|---|---|---|
| 2011-01-01 | 2011-01-01 | 3 × 2 | 6 |
| 2011-01-05 | 2011-01-03 | 3 × 4 | 12 |
| 2011-01-10 | 2011-01-10 | 0.5 × 8 | 4 |
| 2010-12-31 | None | Earlier than first database date | Error |

```text
Database keys:
[01 Jan]──[03 Jan]────────────[10 Jan]
             ▲
             │ lookup 05 Jan
             │ upper_bound = 10 Jan
             └─ step back: 03 Jan
```

### 4. Parsing and input validation

The implementation checks:

- Dates with the `YYYY-MM-DD` layout and a valid month/day, including leap-year February.
- Amounts that parse as numbers.
- Amounts from **0 to 1000 inclusive** (negative amounts and values above 1000 are rejected).
- Missing input/database files and dates before the first available rate.

An exact subtlety of the current code: `loadDatabase` checks whether the map is empty **inside its CSV-reading loop**. If the first data row is invalid, it can report an empty database before reaching a later valid row. This is a useful robustness test.

### 5. Complexity

For `n` stored rates, an individual `upper_bound` query takes **O(log n)** comparisons in a balanced tree. Parsing `m` input lines therefore needs approximately **O(m log n)** lookup work, in addition to input parsing. Loading a series of rates with map insertion costs approximately **O(n log n)** in the ordinary worst case.

---

## 🧮 Exercise 01 — Reverse Polish Notation (RPN)

### 1. Infix vs postfix

In ordinary **infix** notation, operators appear between their operands:

```text
(3 + 4) × 2
```

In **postfix** (Reverse Polish) notation, the operator comes after the values it consumes:

```text
3 4 + 2 *
```

No parentheses are required because evaluation order is encoded directly in token order.

### 2. A stack is Last-In, First-Out

`std::stack<int>` is the natural data structure:

- Number: **push** it onto the stack.
- Operator: **pop** the right operand, then the left operand; compute and **push** the result.
- End: exactly **one** value must remain.

```text
Expression: 3 4 + 2 *

Token     Stack (bottom → top)       Operation
─────     ────────────────────       ─────────
3         [3]                        push 3
4         [3, 4]                     push 4
+         [7]                        3 + 4
2         [7, 2]                     push 2
*         [14]                       7 × 2

Final result: 14
```

### 3. Operand order matters

For subtraction and division:

```cpp
int right = values.top(); values.pop();
int left  = values.top(); values.pop();
```

Then calculate `left - right` or `left / right`. Mixing this order changes the result.

For example, `8 2 /` means **8 ÷ 2**, not 2 ÷ 8.

### 4. What the code accepts

The source currently accepts only **single-digit operands** `0`–`9` and these binary operators:

| Token | Operation | Example | Result |
|---|---|---|---|
| `+` | Addition | `3 4 +` | 7 |
| `-` | Subtraction | `9 4 -` | 5 |
| `*` | Multiplication | `3 4 *` | 12 |
| `/` | Integer division | `8 2 /` | 4 |

Examples of expected errors: an unsupported token, insufficient operands, more than one value remaining, or division by zero.

The code does not explicitly guard **signed integer overflow**; don't assume arbitrary-size arithmetic.

### 5. Complexity

If an expression has `t` tokens, each is processed once. Stack push/pop operations are constant-time, so evaluation takes **O(t) time** and **O(t) auxiliary space** in the worst case.

---

## ⚙️ Exercise 02 — PmergeMe and Ford–Johnson Sorting

### 1. What is the goal?

This exercise accepts a list of **positive integers**, orders them, and reports the processing time for **two different STL containers**:

- `std::vector<int>` — contiguous storage.
- `std::deque<int>` — segmented, double-ended sequence storage.

The code calls two related functions: `fordJohnsonVector` and `fordJohnsonDeque`. Both implement a **pair-based recursive merge-insertion approach** influenced by the Ford–Johnson algorithm.

**Theoretical idea:** Minimize the number of comparisons needed to sort.  
**Engineering question:** How many actual operations, memory moves, and container accesses are performed by this particular implementation?

Those are not the same metric.

### 2. Pair the numbers

Take the input:

```text
8  3  5  1  9  4  7  2
```

The program pairs adjacent elements and orders each pair internally:

```text
Unordered pairs      Ordered (small, large)
(8, 3)                (3, 8)
(5, 1)                (1, 5)
(9, 4)                (4, 9)
(7, 2)                (2, 7)

Larger values: [8, 5, 9, 7]
```

The **larger elements** form a smaller sorting problem.

### 3. Recursively sort the large elements

```text
[8, 5, 9, 7]
       │
       ▼
recursive ordering
       │
       ▼
[5, 7, 8, 9]
```

Now reorder each pair to match its large partner:

```text
(1,5)  (2,7)  (3,8)  (4,9)
```

The invariant is that the **small member of each pair is ≤ its large partner**. This matters because it limits where the small member needs to be inserted.

### 4. Build the main chain

The source starts with the small member of the first pair, then appends the sorted large members:

```text
Initial main chain:
[1, 5, 7, 8, 9]

Remaining small values waiting to be inserted:
[2, 3, 4]
```

The main chain is already sorted. Each pending small value is inserted with `std::lower_bound` into a restricted prefix **before its matching large partner**.

### 5. Why Jacobsthal numbers?

The Jacobsthal sequence satisfies:

```text
J(0) = 0, J(1) = 1
J(n) = J(n-1) + 2 × J(n-2)

0, 1, 1, 3, 5, 11, 21, 43, 85, ...
```

Ford–Johnson sorting uses a carefully chosen insertion order related to these numbers to keep binary-search comparison ranges favorable. The current source starts its group boundaries at **1 and 3**, then calculates:

```cpp
nextJacobsthal = jacobsthal + 2 * previousJacobsthal;
```

That generates boundaries **3, 5, 11, 21, ...**. Within each group, insertion positions are visited in reverse order.

For the eight-number example, the code inserts:

```text
Initial: [1, 5, 7, 8, 9]

Insert 3 (before partner 8)
      → [1, 3, 5, 7, 8, 9]

Insert 2 (before partner 7)
      → [1, 2, 3, 5, 7, 8, 9]

Insert 4 (before partner 9)
      → [1, 2, 3, 4, 5, 7, 8, 9]
```

**Why not simply insert from left to right?** The Jacobsthal grouping tries to maintain favorable search-range sizes for the later binary insertions. This is about the **number of comparisons**, not automatically about minimum elapsed time.

### 6. Binary insertion and the partner bound

This line is central to understanding the source:

```cpp
std::vector<int>::iterator partner =
    std::find(chain.begin(), chain.end(), orderedPairs[index].second);
std::vector<int>::iterator insertionPosition =
    std::lower_bound(chain.begin(), partner, orderedPairs[index].first);
chain.insert(insertionPosition, orderedPairs[index].first);
```

- `std::find` locates the large partner.
- `lower_bound` searches the sorted range **before that partner**.
- `insert` places the small value into the chain.

The deque version follows the same strategy with deque iterators.

### 7. What if the input count is odd?

The code saves the unpaired last value as `odd`, sorts the complete pairs, and inserts the remaining value later using `lower_bound`.

```text
Input:  8 3 | 5 1 | 9
Pairs: (3,8), (1,5)
Odd:   9  ← inserted into the sorted chain later
```

### 8. Vector vs deque

| Feature | `std::vector` | `std::deque` |
|---|---|---|
| Storage | Contiguous | Segmented |
| Random access | O(1) | O(1) |
| Middle insertion | O(n) due to shifting | O(n) in general |
| Memory locality | Typically strong | Often less contiguous |
| Used here | `fordJohnsonVector` | `fordJohnsonDeque` |

Both implementations use **binary search to locate insertion positions**, but inserting into the middle of either container still costs work.

### 9. Complexity: theory vs this implementation

In the **comparison model**, Ford–Johnson merge-insertion sorting is a comparison-efficient **O(n log n)** sorting method.

However, this repository's code also:

1. Searches linearly for a matching pair for each sorted larger value.
2. Calls `std::find` to locate partners in the growing chain.
3. Performs middle insertions in vector or deque.
4. Makes recursive copies/temporary containers.

These operations can create **O(n²) work** in the current implementation even though `lower_bound` itself needs O(log n) comparisons per insertion. Therefore, **do not claim the implementation runs in O(n log n) time solely because it is Ford–Johnson-inspired**.

A comparison-count optimization claim would also require instrumenting the code and comparing measured comparisons against a known bound.

### 10. Timing results and benchmarking limitations

`main.cpp` uses `clock()` and reports elapsed **CPU clock ticks converted to microseconds**:

```text
Time to process a range of N elements with std::vector : ... us
Time to process a range of N elements with std::deque  : ... us
```

This is not a universal speed ranking. Small inputs can show noisy results; compiler, machine, input distribution, and container allocation all matter.

For fair comparisons, use the **same input values**, repeat runs, use multiple input sizes, and report a distribution such as the median. The code currently measures each container once per invocation.

### 11. Commands and test cases

```bash
cd ex02
make

./PmergeMe 3 2 1
./PmergeMe 8 3 5 1 9 4 7 2
./PmergeMe 1 2 3 4 5 6
./PmergeMe 9 8 7 6 5 4 3 2 1
./PmergeMe 5 5 2 2 1
```

The input parser rejects zero, negative numbers, non-numeric strings, numbers outside the positive signed-int range, and an empty argument list.

**Validation strategy:** Extract the line beginning with `After:` and compare against a trustworthy reference sort (e.g. `std::sort` in a separate test program). Include both **odd** and **even** sizes and duplicate values when testing the actual implementation. No benchmark or correctness suite has been run as part of this README update.

---

## 🧪 Practical Exercises and Self-Assessment

Try these before reading the answers.

**Q1.** For the database keys 2011-01-01, 2011-01-03, and 2011-01-10, which rate date is used for 2011-01-08?

**Q2.** What does `6 2 - 3 *` evaluate to, and why?

**Q3.** In PmergeMe, why can a small pair member search only the range before its large partner?

**Q4.** Does using `std::lower_bound` make the whole PmergeMe program O(n log n)?

**Q5.** Why might `std::vector` and `std::deque` differ in runtime even when both produce the same sorted output?

<details>
<summary><strong>Answers — click to reveal</strong></summary>

1. 2011-01-03: it is the latest date no later than 2011-01-08.
2. 12: first 6 − 2 = 4, then 4 × 3 = 12.
3. The smaller member is known to be ≤ its partner, and the main chain is sorted.
4. No. Searching and middle insertion can be linear for each element; the concrete implementation has potentially quadratic work.
5. They have different memory layouts and movement/iterator behavior, so constant factors and insertion costs differ.

</details>

## 📚 Useful References

- [C++ containers — cppreference](https://en.cppreference.com/w/cpp/container)
- [std::map::upper_bound — cppreference](https://en.cppreference.com/w/cpp/container/map/upper_bound)
- [std::stack — cppreference](https://en.cppreference.com/w/cpp/container/stack)
- [std::lower_bound — cppreference](https://en.cppreference.com/w/cpp/algorithm/lower_bound)
- [Merge-insertion sort — Wikipedia](https://en.wikipedia.org/wiki/Merge-insertion_sort)
- [Jacobsthal numbers — OEIS A001045](https://oeis.org/A001045)
- [GNU Make manual](https://www.gnu.org/software/make/manual/)

### AI Usage

AI assistance was used to **inspect the source, explain the data structures and algorithms, write educational diagrams, and propose test cases**. This change only modifies the README. Explanatory examples and benchmark discussion are not claims that the programs or test cases were executed.
