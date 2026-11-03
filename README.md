*This project has been created as part of the 42 curriculum by hsennane.*

# CPP Module 03

## Description

**CPP Module 03** focuses on **Inheritance, derived classes and construction order**.

This module builds a family of simple game-like classes to illustrate single inheritance, reused state, overridden behavior, and constructors/destructors across a class hierarchy.

## Instructions

### Building and Running

Requires a C++ compiler and GNU Make. Exercise Makefiles use **C++98** with `-Wall -Wextra -Werror`.

```bash
git clone https://github.com/hajarsen/CPP03.git
cd CPP03/ex00
make
./ClapTrap
```

Run `make clean`, `make fclean` or `make re` inside an exercise directory. Exercises are separate programs, so compile them individually rather than expecting one executable at the repository root.

### Exercises

| Directory | Objective |
|---|---|
| `ex00` | **ClapTrap:** Implement a base character with attack, damage, repair, and resource tracking. |
| `ex01` | **ScavTrap:** Derive ScavTrap from ClapTrap and add specialized behavior. |
| `ex02` | **FragTrap:** Introduce FragTrap and compare its behavior with the other classes. |

### Suggested Tests

Run each exercise and inspect constructor/destructor messages. Test attacks, taking damage, repairs, and operations after resources are exhausted.

These are suggested manual checks, **not verified automated test results**.

## Resources

Below are the key ideas with simplified diagrams, following the educational structure of the NetPractice README.

---

### Inheritance

A derived class can reuse fields and methods from a base class; the derived class can specialize behavior.

### Construction and Destruction

Base subobjects are initialized before the derived object. Destruction occurs in the opposite order.

### State Transitions

Attacking and repairing change energy or health state. Tests should cover exhausted energy, zero hit points, and repeated actions.


### Concept Diagram

```text
         ClapTrap
         /     \
        /       \
   ScavTrap   FragTrap

Base constructor → Derived constructor
Derived destructor → Base destructor
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
