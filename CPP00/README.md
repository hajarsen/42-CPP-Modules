*This project has been created as part of the 42 curriculum by hsennane.*

# CPP00 — Introduction to C++ and Classes

## Description

CPP00 introduces C++98 syntax, standard input/output, and object-oriented design through a megaphone and an interactive phone book.

## Building

Each `exXX` folder has its own **C++98 Makefile**. Run `make` inside the exercise folder, then launch its executable (see that folder's Makefile for its name). Use `make fclean` to clean generated files.

### Exercises

| Folder | Topic | Purpose |
|---|---|---|
| `ex00` | **Megaphone** | Convert command-line text to uppercase. |
| `ex01` | **PhoneBook** | Store and search up to eight contacts using two classes. |

## Technical Overview

### 1. Streams and arguments

`std::cout` prints to the terminal and `std::getline(std::cin, text)` reads an entire line. `argc` counts arguments including the executable; `argv[1]` is the first user argument. In `megaphone.cpp`, nested loops visit each argument and character, then convert the character with `std::toupper`.

### 2. Classes and encapsulation

`Contact` stores one person's fields. `PhoneBook` stores eight `Contact` objects plus counters. `private` keeps internal data hidden, while public `addContact()` and `searchContacts()` provide controlled interaction. A constructor initializes an object; its destructor runs at the end of its lifetime.

### 3. Circular storage and formatted output

After successfully adding a contact, the source calculates `(lastContactIndex + 1) % 8`. This wraps the next insertion position back to zero, overwriting an older contact once all eight slots are used. `std::setw(10)` formats a table column; long fields are shortened to nine characters plus a dot.

### Implementation Highlights

The Megaphone program writes each argument directly to the output stream without inserting separators; whitespace is preserved only when it is part of an argument. PhoneBook uses **physical array indices** for search results, so after eight insertions the displayed order does not necessarily match insertion chronology. Contacts are held in memory and are not persisted.

## Validation Cases

Run `./megaphone hello world` (notice how separate arguments are concatenated) and `./megaphone 'hello world'` (the space is preserved). In PhoneBook try `SEARCH` before `ADD`, create nine contacts, enter a non-numeric phone number, and select an invalid index.

**Implementation notes:** PhoneBook data exists only during the current run; it is not saved to disk. The source validates fields as printable text and requires digits for phone numbers.

The suggestions above are for your own testing; no automated results are claimed here.

## References

- [C++ language reference](https://en.cppreference.com/w/cpp)
- [C++98 classes and language basics](https://en.cppreference.com/w/cpp/language)
- [GNU Make manual](https://www.gnu.org/software/make/manual/)

