*This project has been created as part of the 42 curriculum by hsennane.*

# CPP03 — Inheritance and Class Hierarchies

## Description

CPP03 introduces inheritance through game-style characters that can attack, take damage, and repair themselves. Derived classes specialize the state and behavior of a common base.

Each exercise builds on the previous concepts. The sections below describe the implementation, underlying C++ concepts, and expected behavior.

## Building

Each `exXX` folder has its own **C++98 Makefile**. Run `make` inside the exercise folder, then launch its executable (see that folder's Makefile for its name). Use `make fclean` to clean generated files.

### Exercises

| Folder | Topic | Purpose |
|---|---|---|
| `ex00` | **ClapTrap** | Manage hit points, energy points, and attacks. |
| `ex01` | **ScavTrap** | Derive from ClapTrap and add gate-keeper behavior. |
| `ex02` | **FragTrap** | Add another specialized derived class. |

## Technical Overview

### 1. Base and derived classes

`ClapTrap` defines shared data and actions; `ScavTrap` and `FragTrap` extend that base type. Inheritance is useful when classes share a common interface and behavior but need different defaults or specialized methods.

### 2. Object construction order

When a `ScavTrap` is created, its `ClapTrap` base part is initialized first. When it is destroyed, the derived destructor runs before the base destructor. Reading printed constructor/destructor messages helps trace this sequence.

### 3. State transitions

The ex00 `ClapTrap` begins with 10 hit points, 10 energy points and 0 attack damage. Attacking or repairing uses an energy point and checks whether it is dead or out of energy. `takeDamage()` reduces hit points without allowing negative health. `ScavTrap` sets its own initial values in its constructors.

### Implementation Details

| Component | Implementation |
|---|---|
| **Base class** | `ClapTrap` stores name, hit points, energy points, and attack damage. |
| **Derived classes** | `ScavTrap` and `FragTrap` inherit common behavior and define their own initialization and special methods. |
| **Attack and repair** | Check health and available energy before acting; successful actions consume energy. |
| **Damage handling** | Reduces hit points, stopping at zero if incoming damage is greater than or equal to remaining health. |
| **Object lifecycle** | Initializes the base-class subobject before the derived class and destroys them in reverse order. |

## Validation Cases

Trace constructor order in ex01/ex02. Try an attack with no energy, repair after reaching zero health, and repeated damage. Compare default health/energy values and specialized methods across classes.

**Implementation notes:** Health and energy counters are ordinary state variables; they are not an entire game engine. The example methods report actions through terminal output.

The suggestions above are for your own testing; no automated results are claimed here.

## References

- [C++ language reference](https://en.cppreference.com/w/cpp)
- [C++98 classes and language basics](https://en.cppreference.com/w/cpp/language)
- [GNU Make manual](https://www.gnu.org/software/make/manual/)

### AI Usage

AI assistance was used to organize the documentation, clarify concepts and prepare examples. **Source code was not changed** by this README update.
