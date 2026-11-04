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

## Repository Structure

The repository brings together **CPP00–CPP09** in a single, organized collection. Each module retains its independent exercises, source files, and dedicated README, making it easy to explore individual implementations or follow the progression across the series.

## Build

All exercises target **C++98** and are compiled independently using their own Makefiles. Standard targets include `make`, `make clean`, `make fclean`, and `make re`. There is no repository-wide executable.

## Technical Highlights

The modules cover object-oriented design, memory and resource management, inheritance, polymorphism, exception handling, templates, and the Standard Template Library. The series concludes with practical applications of **ordered maps**, **stack-based expression evaluation**, and **merge-insertion sorting**, including a comparison of `std::vector` and `std::deque`.

Detailed implementation notes and validation cases are available in each module's README.
