*This project has been created as part of the 42 curriculum by hsennane.*

# CPP Module 01

## Description

This module introduces **C++ object lifetime**, **dynamic allocation**, **pointers and references**, and **file streams**. Each exercise is a small independent program that explores one part of memory and object management.

## Instructions

### Build and run

Use a C++98 compiler and `make`. For example:

```bash
git clone https://github.com/hajarsen/CPP01.git
cd CPP01/ex00
make
./Zombie
```

Compile the other exercises inside their respective directories. Standard Makefile targets include `make`, `make clean`, `make fclean`, and `make re`.

### Exercises

| Directory | Topic | Objective |
|---|---|---|
| `ex00` | Zombie | Create objects on the stack and heap |
| `ex01` | Zombie Horde | Create and manage an array of objects |
| `ex02` | Brain | Understand references, pointers, and addresses |
| `ex03` | Weapon | Compare composition using references and pointers |
| `ex04` | File replacement | Read a text file and write a `.replace` file |
| `ex05` | Harl | Call class member functions to emit different messages |

### Example — File replacement

From `ex04`, once built:

```bash
printf 'hello world\n' > sample.txt
./replace sample.txt hello hi
cat sample.txt.replace
```

Check the actual executable name in `ex04/Makefile` if it differs.

### Suggested tests

Test successful file replacements and missing files, empty search strings, the creation/destruction order of zombie objects, and behavior of references when an existing Weapon changes. These are **manual test suggestions**, not claims of passing tests.

## Resources

---

## 🧠 Stack vs Heap

```text
   Automatic allocation          Dynamic allocation
   ┌─────────────────┐            ┌──────────────────────┐
   │ Zombie local;   │            │ Zombie* p = new ... │
   │ lifetime: scope │            │ lifetime: until     │
   │                 │            │ delete p;           │
   └─────────────────┘            └──────────────────────┘
```

### Pointer vs Reference

A **pointer** stores an address and can be reassigned. A **reference** is another name for an already existing object.

```text
          Weapon object
           ▲        ▲
           │        │
    Weapon* ptr    Weapon& ref
```

### Object Lifetime

C++ constructors initialize objects and destructors release resources during destruction. A zombie horde demonstrates initializing arrays of objects and cleaning them up correctly.

---

## 🎯 Learning Checklist

- Explain the difference between `new`, `delete`, and local objects.
- Identify which object owns allocated resources.
- Demonstrate the difference between pointers and references.
- Test file reading and writing without changing the input file unexpectedly.

### Useful Links

- [C++ new expression](https://en.cppreference.com/w/cpp/language/new)
- [C++ references](https://en.cppreference.com/w/cpp/language/reference)
- [C++ file streams](https://en.cppreference.com/w/cpp/io/basic_fstream)

### AI Usage

AI assistance was used to structure the README and explain concepts. Application source files were not modified.
