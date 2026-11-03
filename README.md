*This project has been created as part of the 42 curriculum by hsennane.*

# CPP Module 05 — Repetition and Exceptions

## Description

This module models a small bureaucracy with constrained grades, forms, and actions. Its exercises focus on class invariants, **exceptions**, inheritance, abstract classes, and object creation through an Intern.

The exercises are independent programs and are stored in `ex00`, `ex01`, `ex02`, and `ex03`.

## Instructions

### Building the Project

The exercise Makefiles use **C++98** with `-Wall -Wextra -Werror`. You need a C++ compiler and `make`.

```bash
git clone https://github.com/hajarsen/CPP05.git
cd CPP05
cd ex00
make
./bureaucrat
```

To try another exercise, change into its directory, run `make`, and check its Makefile for the executable name. The common targets are `make`, `make clean`, `make fclean`, and `make re`.

### Exercises

| Exercise | Project | Purpose |
|---|---|---|
| `ex00` | **Bureaucrat** | Construct a Bureaucrat and handle invalid grades. |
| `ex01` | **Form** | Add forms with signing requirements and signed state. |
| `ex02` | **AForm** | Use an abstract form type and concrete forms with execution behavior. |
| `ex03` | **Intern** | Create forms from a requested name using an Intern. |

### Suggested Tests

Try grades just inside and outside the allowed range, signing with insufficient grade, executing an unsigned form, and requesting an unknown form from the Intern.

These are **suggested manual tests**; they have not been executed as part of this documentation update.

## Resources

The following sections explain the core concepts with simplified examples and diagrams, following the style of the NetPractice README.

---

### ⚖️ Invariants and Exceptions

A grade must stay in its permitted interval. Constructors and member functions can throw exceptions when an operation violates the class rules.

### 🧬 Polymorphic Forms

Derived forms represent distinct actions but share a common base interface. This allows a Bureaucrat to operate on different form types.

### 🏭 Intern and Factory Logic

An Intern selects a concrete form type from an input name, demonstrating object creation without hard-coding a concrete type in the caller.


### Concept Diagram

```text
          Bureaucrat
         grade (1..150)
               │
               ▼
       sign / execute
               │
               ▼
             AForm
       ┌───────┼──────────┐
       ▼       ▼          ▼
  Shrubbery Robotomy Presidential
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
- [C++ exceptions](https://en.cppreference.com/w/cpp/language/throw)
- [Virtual functions](https://en.cppreference.com/w/cpp/language/virtual)
- [GNU Make manual](https://www.gnu.org/software/make/manual/)

### AI Usage

AI assistance was used to **organize this README, clarify the C++ concepts, and create educational diagrams**. No C++ implementation files were changed by this documentation update.
