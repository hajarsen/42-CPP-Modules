*This project has been created as part of the 42 curriculum by hsennane.*

# CPP03 — Inheritance and Class Hierarchies

## Description

CPP03 introduces inheritance through game-style characters that can attack, take damage, and repair themselves. Derived classes specialize the state and behavior of a common base.

Each exercise builds on the previous concepts. This guide explains **what the code does, why the concepts matter, and how to explore them**.

## Instructions

### Build and run

These exercises use **C++98**, with `-Wall -Wextra -Werror -std=c++98` in their Makefiles. They are independent executables compiled in their respective folders.

```bash
git clone https://github.com/hajarsen/CPP03.git
cd CPP03
cd ex00
make
./ClapTrap
cd ../ex01
make
./ScavTrap
```

Inside each exercise, use `make` to compile, `make clean` to remove objects, `make fclean` to remove the executable, or `make re` to rebuild. Check each Makefile for its executable name.

### Exercises

| Folder | Topic | Purpose |
|---|---|---|
| `ex00` | **ClapTrap** | Manage hit points, energy points, and attacks. |
| `ex01` | **ScavTrap** | Derive from ClapTrap and add gate-keeper behavior. |
| `ex02` | **FragTrap** | Add another specialized derived class. |

## Resources — Understand the Concepts

### 1. Base and derived classes

`ClapTrap` defines shared data and actions; `ScavTrap` and `FragTrap` extend that base type. Inheritance is useful when classes share a common interface and behavior but need different defaults or specialized methods.

### 2. Object construction order

When a `ScavTrap` is created, its `ClapTrap` base part is initialized first. When it is destroyed, the derived destructor runs before the base destructor. Reading printed constructor/destructor messages helps trace this sequence.

### 3. State transitions

The ex00 `ClapTrap` begins with 10 hit points, 10 energy points and 0 attack damage. Attacking or repairing uses an energy point and checks whether it is dead or out of energy. `takeDamage()` reduces hit points without allowing negative health. `ScavTrap` sets its own initial values in its constructors.

### How it works

```text
             ClapTrap
             /     \
       ScavTrap   FragTrap

Attack: alive? → energy left? → spend 1 energy
Damage: reduce HP, stop at 0
Repair: alive + energy? → increase HP
```

## Practice and Testing

Trace constructor order in ex01/ex02. Try an attack with no energy, repair after reaching zero health, and repeated damage. Compare default health/energy values and specialized methods across classes.

**What to watch for:** Health and energy counters are ordinary state variables; they are not an entire game engine. The example methods report actions through terminal output.

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
