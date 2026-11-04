*This project has been created as part of the 42 curriculum by hsennane.*

# CPP07 — Function and Class Templates

## Description

CPP07 introduces C++ templates, which let you write reusable algorithms and containers without duplicating logic for every type.

This README explains **what each exercise demonstrates**, the key ideas behind the code, and ways to explore them yourself.

## Building

Each `exXX` folder has its own **C++98 Makefile**. Run `make` inside the exercise folder, then launch its executable (see that folder's Makefile for its name). Use `make fclean` to clean generated files.

### Exercises

| Folder | Topic | What it does |
|---|---|---|
| `ex00` | **Whatever** | Write generic `swap`, `min`, and `max` functions. |
| `ex01` | **Iter** | Apply a function to every element of an array. |
| `ex02` | **Array** | Implement a templated, dynamically allocated array with bounds checks. |

## Resources — Key Concepts

### 1. Function templates

A template uses a type placeholder such as `template <typename T>`. Calling `swap` with integers or strings lets the compiler instantiate suitable functions. Types still need to support the operations required by the template.

### 2. Generic array traversal

The `iter` exercise accepts a pointer to an array, the number of elements, and a function to apply. It makes the traversal logic independent of whether elements are integers, characters or another compatible type.

### 3. Class templates and memory

`Array<T>` in ex02 owns a dynamically allocated `T[]`. Its size is stored separately and `operator[]` throws an `OutOfBoundsException` for an invalid index. The copy constructor allocates new storage and copies values to avoid pointer aliasing. The destructor releases the array.

### 4. Copy-assignment caution

In the current code, `Array::operator=` deletes its existing storage before allocating the replacement. If allocation fails, that operation does not provide a strong exception-safety guarantee. This is a useful discussion point about safe resource management.

### Visual summary

```text
Template swap<T>(a, b)
      ├── T = int ──► swap integers
      └── T = string ──► swap strings

Array<T> : owns T[] + size + checked [] access
```

## Tests to Try

Try `swap` on both integers and strings, call `iter` on an array, copy a nonempty Array, modify only the copy, and access an out-of-range index. Confirm the exception is handled.

**Important:** Templates generally need their definitions available at the point of instantiation. An `Array<T>` copy is independent, unlike simply copying a `T*` pointer.

These checks are suggestions; the documentation update does not imply they were run.

## Further Reading

- [C++ reference](https://en.cppreference.com/w/cpp)
- [C++ language guide](https://en.cppreference.com/w/cpp/language)
- [GNU Make](https://www.gnu.org/software/make/manual/)

### AI Usage

AI assistance was used to organize the documentation, clarify concepts and prepare examples. **No source code was changed.**
