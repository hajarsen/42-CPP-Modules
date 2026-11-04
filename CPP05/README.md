*This project has been created as part of the 42 curriculum by hsennane.*

# CPP05 — Exceptions, Bureaucracy and Forms

## Description

CPP05 introduces robust class invariants, exceptions, and abstract classes through a bureaucracy simulation. Bureaucrats have grades and may sign or execute forms only when they satisfy each form's requirements.

The sections below describe the exercise implementations and their underlying C++ concepts.

## Building

Each `exXX` folder has its own **C++98 Makefile**. Run `make` inside the exercise folder, then launch its executable (see that folder's Makefile for its name). Use `make fclean` to clean generated files.

### Exercises

| Folder | Topic | Purpose |
|---|---|---|
| `ex00` | **Bureaucrat** | Construct objects with valid grades; reject invalid grades. |
| `ex01` | **Form** | Introduce signing requirements and signed state. |
| `ex02` | **AForm** | Introduce abstract forms and different executable actions. |
| `ex03` | **Intern** | Choose a concrete form by name with a factory-like helper. |

## Technical Overview

### 1. Grades are invariants

A Bureaucrat's grade lies in the interval 1–150, where **1 is the highest rank**. Code that constructs a grade outside this range raises an exception. A form specifies separate grades to sign and execute it, so the caller must satisfy the relevant limit.

### 2. Exception handling

Instead of silently creating an invalid object or allowing an illegal operation, a function can `throw` an exception. The caller can `catch` the error and report it. The source defines exceptions for grades and unsigned forms, providing meaningful error messages through `what()`.

### 3. Abstract forms and polymorphism

`AForm` defines common checks and calls a derived `executeAction()` for the specific task. ShrubberyCreationForm, RobotomyRequestForm and PresidentialPardonForm represent distinct actions. The base form can be used through a pointer without needing to know which concrete form it is.

### 4. Factory pattern with Intern

`Intern::makeForm(name, target)` matches a string against three supported names and calls the corresponding creation method using an array of member-function pointers. Unknown names raise `FormNotFoundException`. This isolates the choice of class from the caller.

### Implementation Highlights

**Execution control** is centralized in `AForm`: a form must be signed, and the executing bureaucrat must meet the required grade before the derived `executeAction()` runs. `Intern::makeForm()` uses member-function pointers to create the requested concrete form and returns an owning `AForm*`, leaving the caller responsible for its deletion.

## Validation Cases

Create a Bureaucrat with grades 1, 150, 0 and 151. Try signing a form with too-low authority, executing before signing, and asking the Intern for an unknown form. Compare the errors you receive.

**Important:** `AForm::execute()` verifies both the signed state and the executor's grade before calling the concrete action. A successful sign does not automatically mean execution is authorized.

These checks are suggestions; the documentation update does not imply they were run.

## References

- [C++ reference](https://en.cppreference.com/w/cpp)
- [C++ language guide](https://en.cppreference.com/w/cpp/language)
- [GNU Make](https://www.gnu.org/software/make/manual/)

