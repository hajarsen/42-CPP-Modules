*This project has been created as part of the 42 curriculum by hsennane.*

# CPP04 — Polymorphism and Abstract Classes

## Description

CPP04 demonstrates dynamic dispatch through virtual functions, resource ownership through deep copying, and interfaces defined by abstract base classes.

Each exercise builds on the previous concepts. This guide explains **what the code does, why the concepts matter, and how to explore them**.

## Instructions

### Build and run

These exercises use **C++98**, with `-Wall -Wextra -Werror -std=c++98` in their Makefiles. They are independent executables compiled in their respective folders.

```bash
git clone https://github.com/hajarsen/CPP04.git
cd CPP04
cd ex00
make
./ex00
cd ../ex01
make
./ex01
```

Inside each exercise, use `make` to compile, `make clean` to remove objects, `make fclean` to remove the executable, or `make re` to rebuild. Check each Makefile for its executable name.

### Exercises

| Folder | Topic | Purpose |
|---|---|---|
| `ex00` | **Animals** | Compare virtual calls with intentionally nonvirtual WrongAnimal/WrongCat behavior. |
| `ex01` | **Brains** | Give animals an owned `Brain` and verify independent copies. |
| `ex02` | **Abstract Animal** | Use an abstract `AAnimal` base with concrete derived types. |

## Resources — Understand the Concepts

### 1. Virtual methods and dispatch

Calling a virtual method through an `Animal*` or `Animal&` selects the method of the actual derived object. The WrongAnimal example intentionally illustrates what can happen without virtual dispatch.

### 2. Deep copies and ownership

The `Brain` class stores 100 ideas. Its copy constructor and assignment copy all ideas. When an animal owns a heap-allocated Brain, creating an independent copy matters: two animals should not accidentally point to the same mutable Brain or both delete it.

### 3. Abstract classes and destructors

`AAnimal` declares `virtual void makeSound() const = 0;`, making it abstract. You cannot construct `AAnimal` itself, but `Dog` and `Cat` can implement the interface. A virtual base destructor allows safe destruction through base pointers.

### How it works

```text
Animal* base_ptr
       │ virtual makeSound()
       ├────────► Dog::makeSound()
       └────────► Cat::makeSound()

Dog A → [Brain A] (independent)
Dog B → [Brain B] (deep copy)
```

## Practice and Testing

Compare output from Animal and WrongAnimal through base pointers. Copy a Dog or Cat, modify one Brain and verify the other is unchanged. Explain why `new AAnimal` would fail to compile.

**What to watch for:** `Brain` is an educational example of owned state, not a general-purpose data structure. Tests should distinguish copying an object from copying a pointer.

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
