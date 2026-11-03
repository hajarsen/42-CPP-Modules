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

## Resources — Learn the Ideas Step by Step

This section is meant to help you **understand, explain, and test** the exercises instead of simply running them. Read the concepts, trace the diagrams, run the examples, and answer the questions at the end.

---

## 🖥️ 1. From C to C++

C++ retains many C concepts, but introduces useful abstractions such as **classes**, **encapsulation**, and the `std::string` and stream libraries.

| C-style idea | C++98 idea | Why it matters |
|---|---|---|
| `printf` | `std::cout` | Stream-based output |
| `scanf` / manual input | `std::getline(std::cin, line)` | Read a complete line, including spaces |
| `char*` buffers | `std::string` | Text with managed storage and useful methods |
| Struct + helper functions | Class with methods | Keep related behavior and data together |

### Example: output streams

```cpp
#include <iostream>
#include <string>

int main()
{
    std::string name = "Alice";
    std::cout << "Hello " << name << std::endl;
}
```

`std::endl` writes a newline and **flushes** the stream; `'\n'` writes a newline without necessarily flushing. Understanding the difference can help when working with interactive prompts.

---

## 🔊 2. Exercise 00: Megaphone

The first exercise uses **`argc`**, **`argv`**, character conversion, and nested loops. There is no class yet: the goal is to become comfortable with C++ streams.

### How command-line arguments are represented

```text
./megaphone "hello world" 42
      │         │        │
 argv[0]     argv[1]   argv[2]

argc = 3 (program name included)
```

The source walks through every character in each supplied argument and calls `std::toupper` after converting the byte to `unsigned char`. That conversion avoids undefined behavior with negative signed `char` values (except EOF semantics).

```text
            each argument
                  │
                  ▼
          read each character
                  │
                  ▼
              toupper()
                  │
                  ▼
            std::cout
```

### Try these commands

```bash
cd ex00
make
./megaphone "hello c++"
./megaphone hello world
./megaphone
```

The source concatenates argument text **without inserting spaces** between separate arguments: `hello world` is printed as `HELLOWORLD`. If you want a visible space, include it inside a quoted argument.

When called without arguments, the program prints the prescribed loud feedback message.

---

## 📇 3. Exercise 01: Designing a PhoneBook

The second exercise introduces two classes:

- `Contact` holds the data for one person.
- `PhoneBook` manages an array of contacts and user interactions.

### Encapsulation

`private` means code outside a class cannot directly access its internal members. `public` methods provide controlled operations.

```text
              PhoneBook
 ┌─────────────────────────────────┐
 │ private:                        │
 │  Contact contacts[8]            │
 │  nbrOfContacts                  │
 │  lastContactIndex               │
 │                                 │
 │ public:                         │
 │  addContact()                   │
 │  searchContacts()               │
 └─────────────────────────────────┘
          │            │
          ▼            ▼
       Contact      Terminal
       objects      I/O
```

Why not store everything in global variables? Because the class keeps **state** and its operations together, making data access clearer and easier to test.

### 4. Fixed-size storage and circular replacement

The source uses a **fixed array of eight contacts**. There is no dynamic array allocation for these contact records.

When the book fills up, adding another contact overwrites the oldest slot according to a rotating index:

```cpp
lastContactIndex = (lastContactIndex + 1) % maxContacts;
```

Follow the index for ten successful insertions:

| Inserted contact | Slot used | Next insertion slot |
|---|---:|---:|
| 1 | 0 | 1 |
| 2 | 1 | 2 |
| 7 | 6 | 7 |
| 8 | 7 | 0 |
| 9 | 0 (overwrites first) | 1 |
| 10 | 1 (overwrites second) | 2 |

```text
   ┌────┬────┬────┬────┬────┬────┬────┬────┐
   │ 0  │ 1  │ 2  │ 3  │ 4  │ 5  │ 6  │ 7  │
   └────┴────┴────┴────┴────┴────┴────┴────┘
     ▲                                   │
     └──────────── wrap with % 8 ────────┘
```

**Important detail:** This is a circular *slot replacement* policy; the display uses slot indices and is not necessarily sorted by chronological insertion order after wrapping.

### 5. Building an interactive terminal loop

`main.cpp` reads commands with `std::getline`:

```text
             Read one line
                   │
                   ▼
           ┌───────────────┐
           │ ADD / SEARCH? │
           └───────┬───────┘
             /     │      \
           ADD   SEARCH   EXIT
            │      │       │
       Ask fields  List    Stop
            │    contacts  loop
            └──────┬───────┘
                   ▼
             Read next line
```

`ADD` asks for first name, last name, nickname, phone number, and darkest secret. The program rejects blank and non-printable entries; the **phone number must consist of digits**. End-of-file during input is handled.

`SEARCH` displays a table and asks for a valid index. For readability, values longer than ten characters are shortened to **nine characters followed by a dot**.

### 6. Formatting with iomanip

`std::setw(10)` defines a **minimum field width** for the next formatted output operation. A field such as `Alexanderson` is therefore truncated manually first to fit the ten-character display.

```text
Original:  "Alexanderson"
Truncated: "Alexander."
Column:     [Alexander.]
              10 chars
```

The actual full data remains stored in the Contact and can be viewed when selecting its index.

---

## 🧪 7. Suggested Tests

From the `ex01` directory:

```bash
make
./PhoneBook
```

| Test | Steps | What to check |
|---|---|---|
| Empty book | Start, type `SEARCH` | "No contacts" |
| One contact | `ADD`, enter five fields, then `SEARCH` | Contact visible |
| Bad phone | Enter letters as phone number | Rejected and asked again |
| Invalid index | `SEARCH`, choose out-of-range number | Rejected |
| Long name | Add name longer than 10 characters | Table truncates |
| Capacity | Add nine contacts | Slot 0 is replaced |
| Exit | Type `EXIT` | Loop ends |

**These tests are examples to try; they were not executed for this README update.**

### Debugging questions

1. Why does `argv[0]` not represent the first user argument?
2. What happens if `std::getline` reaches EOF?
3. Why use `% maxContacts` after inserting a contact?
4. What is the difference between hiding a field with `private` and validating it in a public method?

<details>
<summary><strong>Answers</strong></summary>

1. `argv[0]` is the command name/path; the first additional argument is `argv[1]`.
2. Input fails, so the program can stop rather than loop indefinitely.
3. The modulo wraps the next insertion index from 7 back to 0.
4. Access control limits who can manipulate fields; validation checks whether a proposed value is acceptable.

</details>

## 🎯 What to Be Able to Explain in an Evaluation

- The roles of `argc` and `argv` and why loops have two levels in Megaphone.
- The difference between a **class definition** and an **object instance**.
- Constructors, destructors, member functions, `const` methods, and access modifiers.
- The PhoneBook insertion index and its wraparound behavior.
- Why input is read with `std::getline` instead of mixing token and line input.

### Further Reading

- [Classes — cppreference](https://en.cppreference.com/w/cpp/language/classes)
- [std::string](https://en.cppreference.com/w/cpp/string/basic_string)
- [std::getline](https://en.cppreference.com/w/cpp/string/basic_string/getline)
- [Formatted input/output](https://en.cppreference.com/w/cpp/io)

### AI Usage

AI assistance was used to **explain the code, prepare diagrams, and propose exercises and test cases**. No C++ source code was changed, and the test results were not independently verified.
