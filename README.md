*This project has been created as part of the 42 curriculum by hsennane.*

# CPP Module 00

## Description

**CPP Module 00** focuses on **Namespaces, classes, member functions, std::iostream and basic encapsulation**.

This first C++ module introduces object-oriented programming through text processing and a small interactive contact manager. The repository contains two exercises.

## Instructions

### Building and Running

Requires a C++ compiler and GNU Make. Exercise Makefiles use **C++98** with `-Wall -Wextra -Werror`.

```bash
git clone https://github.com/hajarsen/CPP00.git
cd CPP00/ex00
make
./megaphone "hello, c++!"
```

Run `make clean`, `make fclean` or `make re` inside an exercise directory. Exercises are separate programs, so compile them individually rather than expecting one executable at the repository root.

### Exercises

| Directory | Objective |
|---|---|
| `ex00` | **Megaphone:** Read command-line arguments and display their uppercase form. |
| `ex01` | **PhoneBook:** Create Contact and PhoneBook classes, store entries, and interact through a command-line menu. |

### Suggested Tests

Try no arguments, several words, and punctuation with Megaphone. In PhoneBook, add several contacts, search for an existing or missing index, and test the behavior when its capacity is reached.

These are suggested manual checks, **not verified automated test results**.

## Resources

Below are the key ideas with simplified diagrams, following the educational structure of the NetPractice README.

---

### Encapsulation

A class groups data and operations. Access modifiers (`private` and `public`) separate internal state from the interface used by other code.

### Input and Output

`std::cout` writes output, `std::cin` reads input, and string operations process text without manual C-style buffer management.


### Concept Diagram

```text
Input:  hello, c++!
          │
          ▼
     Character conversion
          │
          ▼
Output: HELLO, C++!
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
