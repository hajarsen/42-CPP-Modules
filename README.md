*This project has been created as part of the 42 curriculum by hsennane.*

# CPP00 — Introduction to C++ and Classes

## Description

CPP00 introduces C++98 syntax, standard input/output, and object-oriented design through a megaphone and an interactive phone book.

Each exercise builds on the previous concepts. This guide explains **what the code does, why the concepts matter, and how to explore them**.

## Instructions

### Build and run

These exercises use **C++98**, with `-Wall -Wextra -Werror -std=c++98` in their Makefiles. They are independent executables compiled in their respective folders.

```bash
git clone https://github.com/hajarsen/CPP00.git
cd CPP00
cd ex00
make
./megaphone 'hello world'
cd ../ex01
make
./PhoneBook
```

Inside each exercise, use `make` to compile, `make clean` to remove objects, `make fclean` to remove the executable, or `make re` to rebuild. Check each Makefile for its executable name.

### Exercises

| Folder | Topic | Purpose |
|---|---|---|
| `ex00` | **Megaphone** | Convert command-line text to uppercase. |
| `ex01` | **PhoneBook** | Store and search up to eight contacts using two classes. |

## Resources — Understand the Concepts

### 1. Streams and arguments

`std::cout` prints to the terminal and `std::getline(std::cin, text)` reads an entire line. `argc` counts arguments including the executable; `argv[1]` is the first user argument. In `megaphone.cpp`, nested loops visit each argument and character, then convert the character with `std::toupper`.

### 2. Classes and encapsulation

`Contact` stores one person's fields. `PhoneBook` stores eight `Contact` objects plus counters. `private` keeps internal data hidden, while public `addContact()` and `searchContacts()` provide controlled interaction. A constructor initializes an object; its destructor runs at the end of its lifetime.

### 3. Circular storage and formatted output

After successfully adding a contact, the source calculates `(lastContactIndex + 1) % 8`. This wraps the next insertion position back to zero, overwriting an older contact once all eight slots are used. `std::setw(10)` formats a table column; long fields are shortened to nine characters plus a dot.

### How it works

```text
PhoneBook
┌──────────────────────────────────────┐
│ Contact slots: [0][1][2][3][4][5][6][7] │
│                 ↑                    │
│       next = (next + 1) % 8         │
└──────────────────────────────────────┘
```

## Practice and Testing

Run `./megaphone hello world` (notice how separate arguments are concatenated) and `./megaphone 'hello world'` (the space is preserved). In PhoneBook try `SEARCH` before `ADD`, create nine contacts, enter a non-numeric phone number, and select an invalid index.

**What to watch for:** PhoneBook data exists only during the current run; it is not saved to disk. The source validates fields as printable text and requires digits for phone numbers.

The suggestions above are for your own testing; no automated results are claimed here.

### Questions to consider

- What does this exercise add compared with the previous one?
- Which parts of the code manage data, and which perform operations?
- How do errors and boundary cases affect the results?
- Could you explain the diagram and the output in a 42 evaluation?

## Useful Resources

- [C++ language reference](https://en.cppreference.com/w/cpp)
- [C++98 classes and language basics](https://en.cppreference.com/w/cpp/language)
- [GNU Make manual](https://www.gnu.org/software/make/manual/)

### AI Usage

AI assistance was used to organize the documentation, clarify concepts and prepare examples. **Source code was not changed** by this README update.
