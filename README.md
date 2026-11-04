# 42 C++ Modules

**C++98 · Object-Oriented Programming · Memory Management · Templates · STL · Algorithms**

A collection of my **42 C++ modules (CPP00–CPP09)**, organized in a single repository. Each module contains independent exercises and its own README documenting the core concepts, implementation choices, and validation cases.

## Modules

| Module | Focus | Key topics |
|:--|:--|:--|
| [CPP00](CPP00/README.md) | C++ foundations | Streams, classes, encapsulation, PhoneBook |
| [CPP01](CPP01/README.md) | Memory management | Object lifetime, pointers, references, file streams |
| [CPP02](CPP02/README.md) | Fixed-point arithmetic | Orthodox Canonical Form, conversions, operator overloading |
| [CPP03](CPP03/README.md) | Inheritance | Base and derived classes, object initialization |
| [CPP04](CPP04/README.md) | Polymorphism | Virtual functions, deep copying, abstract classes |
| [CPP05](CPP05/README.md) | Exceptions | Invariants, error handling, abstract forms |
| [CPP06](CPP06/README.md) | Type conversion | Scalar casts, pointer serialization, RTTI |
| [CPP07](CPP07/README.md) | Templates | Generic functions, array templates |
| [CPP08](CPP08/README.md) | STL | Iterators, containers, algorithms |
| [CPP09](CPP09/README.md) | Applied algorithms | Bitcoin Exchange, RPN, merge-insertion sorting |

## Organization

The modules are stored in folders named `CPP00` through `CPP09`. Each folder retains its original exercises (`ex00`, `ex01`, etc.) and a dedicated README. Exercises are **standalone programs**, not components of a single application.

## Building

The projects target **C++98**. Each exercise includes its own `Makefile`; run `make` from the exercise's directory to compile it. `make clean`, `make fclean`, and `make re` are available in the module Makefiles. Executable names vary by exercise.

## Technical Scope

The collection progresses from classes and memory management to inheritance, polymorphism, exception handling, generic programming, and STL algorithms. The final module includes historical-rate lookups with `std::map`, postfix evaluation with `std::stack`, and pair-based merge-insertion sorting with `std::vector` and `std::deque`.

The module READMEs contain additional implementation notes and validation cases. The original modules are retained as separate GitHub repositories, and their commit histories are imported into this repository through Git subtrees without squashing.
