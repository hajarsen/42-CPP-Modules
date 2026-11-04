*This project has been created as part of the 42 curriculum by hsennane.*

# CPP01 — Memory, Pointers and References

## Description

CPP01 explores object lifetime, dynamic arrays, references, file streams, and dispatching member functions. Its exercises build intuition about resource ownership and C++ object behavior.

## Building

Each `exXX` folder has its own **C++98 Makefile**. Run `make` inside the exercise folder, then launch its executable (see that folder's Makefile for its name). Use `make fclean` to clean generated files.

### Exercises

| Folder | Topic | Purpose |
|---|---|---|
| `ex00` | **Zombie** | Compare a local zombie with one created using `new`. |
| `ex01` | **Zombie Horde** | Allocate and clean up an array of objects. |
| `ex02` | **Brain** | Compare a string, its pointer, and its reference. |
| `ex03` | **Weapon** | Understand object relationships using `HumanA` and `HumanB`. |
| `ex04` | **File replacement** | Replace text in a file without modifying the input. |
| `ex05` | **Harl** | Select a class method from a message level. |

## Technical Overview

### 1. Automatic vs dynamic lifetime

Local objects are destroyed automatically when their scope ends; `new` returns a pointer to a dynamically allocated object that must be paired with `delete`. For arrays, use matching `new[]` and `delete[]`. `ex00` demonstrates heap and stack zombies; `ex01` creates a horde.

### 2. Pointers vs references

A pointer stores an address and can be reassigned or null; a reference names an existing object and must be initialized. `HumanA` stores a `Weapon&`, while `HumanB` stores a `Weapon*` initialized to null. This lets `HumanB` exist without a weapon until `setWeapon()` is called.

### 3. Files and member-function pointers

`ex04/main.cpp` uses `std::ifstream` and `std::ofstream` to create an output file with `.replace` appended. `ex05` stores pointers to `Harl` member functions and dispatches one through `(this->*pointer)()` based on the requested level.

### Implementation Highlights

**Ownership is explicit:** the caller is responsible for deleting zombies created with `newZombie()`, while the `Weapon` used by `HumanA` or `HumanB` is a non-owning dependency. These relationships illustrate why an object holding a pointer is not necessarily responsible for destroying the pointed-to resource.

## Validation Cases

Check zombie constructor/destructor output, pointer/reference addresses in ex02, and `HumanB` before and after `setWeapon()`. In ex04, test missing files, replacing repeated words, and an empty search string.

**Implementation notes:** The ex04 executable is named `readFile` in its Makefile. An empty search string is rejected. Memory ownership is especially important when using `new` and `new[]`.

The suggestions above are for your own testing; no automated results are claimed here.

## References

- [C++ language reference](https://en.cppreference.com/w/cpp)
- [C++98 classes and language basics](https://en.cppreference.com/w/cpp/language)
- [GNU Make manual](https://www.gnu.org/software/make/manual/)

### AI Usage

AI assistance was used to organize the documentation, clarify concepts and prepare examples. **Source code was not changed** by this README update.
