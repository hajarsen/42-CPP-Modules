*This project has been created as part of the 42 curriculum by hsennane.*

# CPP Module 04

## Description

**CPP Module 04** focuses on **Runtime polymorphism, abstract classes, virtual destructors and deep copying**.

This module demonstrates how base-class pointers interact with derived classes, why virtual methods matter, and how to manage copied owned data safely.

## Instructions

### Building and Running

Requires a C++ compiler and GNU Make. Exercise Makefiles use **C++98** with `-Wall -Wextra -Werror`.

```bash
git clone https://github.com/hajarsen/CPP04.git
cd CPP04/ex00
make
./ex00
```

Run `make clean`, `make fclean` or `make re` inside an exercise directory. Exercises are separate programs, so compile them individually rather than expecting one executable at the repository root.

### Exercises

| Directory | Objective |
|---|---|
| `ex00` | **Animals:** Compare virtual Animal behavior with intentionally non-virtual WrongAnimal/WrongCat behavior. |
| `ex01` | **Brain:** Use Brain objects and test deep-copy behavior for Dog and Cat. |
| `ex02` | **Abstract Animal:** Use an abstract animal base type and concrete derived types. |

### Suggested Tests

Compare sounds through base pointers, check correct destruction through a base-class pointer, and verify that changing one copied Brain does not change another.

These are suggested manual checks, **not verified automated test results**.

## Resources

Below are the key ideas with simplified diagrams, following the educational structure of the NetPractice README.

---

### Virtual Functions

A virtual method dispatches according to the dynamic object type, rather than only the pointer's static type.

### Deep vs Shallow Copy

When objects own heap resources, copying only a pointer can cause accidental sharing and double deletion. A deep copy creates independent owned state.

### Abstract Base Classes

A pure virtual function makes a class abstract: it defines an interface but cannot be directly instantiated.


### Concept Diagram

```text
       Animal* pointer
              │
         virtual call
              │
       ┌──────┴──────┐
       ▼             ▼
      Dog           Cat
   makeSound()   makeSound()
```

---

## 🎯 Learning Checklist

- Explain the purpose of every source file and the classes/functions defined in it.
- Compile with the project's C++98 warning flags.
- Test normal input, empty or invalid input, and boundary cases.
- Check resource cleanup, copying, and object lifetime where applicable.

### Useful Links

- [C++ language reference](https://en.cppreference.com/w/cpp)
- [C++ classes and objects](https://en.cppreference.com/w/cpp/language/classes)
- [GNU Make manual](https://www.gnu.org/software/make/manual/)

### AI Usage

AI assistance was used to **organize this README, explain C++ concepts, and prepare educational diagrams**. The original C++ source code was not changed as part of this documentation update.
