# 🔷 C++ Modules

A progressive journey through C++ fundamentals and object-oriented programming, part of the 42 School curriculum. This repository contains my work on the C++ modules (CPP 00-09), exploring essential C++ concepts from basic syntax to advanced topics.

## 📖 About

Coming from a C programming background through previous 42 projects, these modules introduce the paradigm shift to object-oriented programming. Each module builds upon the previous one, exploring different aspects of C++ through practical exercises that reinforce both theoretical understanding and hands-on implementation.

The modules follow the **C++98 standard** as required by the 42 curriculum, providing a solid foundation in classical C++ before modern features.

## 📊 Progress

| Module | Status | Topic |
|--------|--------|-------|
| **CPP 00** | ✅ Complete | Introduction to C++: namespaces, classes, member functions |
| **CPP 01** | ✅ Complete | Memory allocation, references, pointers to members |
| **CPP 02** | ✅ Complete | Ad-hoc polymorphism, operator overloading, Orthodox Canonical Form |
| **CPP 03** | ⏳ In Progress | Inheritance |
| **CPP 04** | 📋 Upcoming | Subtype polymorphism, abstract classes, interfaces |
| **CPP 05** | 📋 Upcoming | Repetition and exceptions |
| **CPP 06** | 📋 Upcoming | C++ casts |
| **CPP 07** | 📋 Upcoming | C++ templates |
| **CPP 08** | 📋 Upcoming | Templated containers, iterators, algorithms |
| **CPP 09** | 📋 Upcoming | STL |

## 📁 Repository Structure
```
cpp/
├── cpp00/    # 🎯 Introduction to C++
├── cpp01/    # 💾 Memory and references
├── cpp02/    # ⚙️ Operator overloading
├── cpp03/    # 🔗 Inheritance (in progress)
├── cpp04/    # 🎭 Polymorphism
├── cpp05/    # ⚠️ Exceptions
├── cpp06/    # 🔄 Type casting
├── cpp07/    # 📐 Templates
├── cpp08/    # 📦 STL containers
└── cpp09/    # 🏆 Advanced STL
```

Each module contains multiple exercises with increasing complexity, typically named `ex00`, `ex01`, `ex02`, etc.

## 💡 Concepts Covered So Far

### 🎯 CPP 00 - Basics
- Namespaces and classes
- Member functions and attributes
- `this` keyword
- Initialization lists
- `const` correctness
- Static vs instance members
- Input/output streams

### 💾 CPP 01 - Memory and References
- Stack vs heap allocation
- References vs pointers
- Memory management with `new`/`delete`
- Pointers to member functions
- File streams

### ⚙️ CPP 02 - Operator Overloading
- Fixed-point number representation
- Operator overloading
- Orthodox Canonical Form (OCF)
- Copy constructor and assignment operator
- Increment/decrement operators
- Comparison operators

## 🚀 Installation & Usage

Each module is self-contained with its own Makefile.

### Building
```bash
git clone --recursive https://github.com/carowann/cpp.git
cd cpp/cpp0X/exXX  # Navigate to specific module and exercise
make
```

> **Note:** The `--recursive` flag ensures any submodules (like libft where used) are cloned properly.

### Running

Each exercise produces its own executable, typically named after the exercise or main class:
```bash
./executable_name
```

Some exercises include test programs or specific usage instructions in their respective directories.

## 📝 Coding Standards

All exercises follow the **42 C++ coding standards**, including:

- ✓ Orthodox Canonical Form for classes (constructor, copy constructor, assignment operator, destructor)
- ✓ No STL containers until CPP 08 (except where explicitly allowed)
- ✓ C++98 standard compliance
- ✓ No memory leaks
- ✓ Proper const correctness
- ✓ RAII principles

## 🎓 Learning Journey

These modules represent a significant learning curve, transitioning from procedural C programming to object-oriented C++. 

### Key learnings so far:

1. **Understanding classes and encapsulation** - Moving from structs and functions to cohesive objects
2. **Mastering memory management** - Learning RAII and when to use stack vs heap
3. **Operator overloading** - Making custom types behave like built-in types
4. **The Orthodox Canonical Form** - Understanding when and why deep copies are necessary
5. **Reference semantics** - Grasping the differences and use cases for references vs pointers

## 🔧 Challenges & Insights

The transition from C to C++ has required unlearning some habits while building new mental models. 

**Notable challenges so far:**

- Understanding the subtleties of the Orthodox Canonical Form and copy semantics
- Balancing between member functions and helper functions
- Learning when to use references vs pointers vs values
- Writing proper constructors and avoiding uninitialized members
- Debugging implicit conversions and operator precedence

> 💭 *The exercises are carefully designed to expose common pitfalls and force engagement with language mechanics rather than just syntax.*

## 🔄 Current Work

I'm currently progressing through **CPP 03**, exploring inheritance and class hierarchies. The modules continue to build complexity while reinforcing previously learned concepts.

## 🙏 Acknowledgments

Completed as part of the 42 School curriculum. These modules provide an intensive, practice-driven introduction to C++ that emphasizes understanding over memorization.

---

<div align="center">

*These modules mark my transition into object-oriented programming, building on the low-level systems knowledge from previous C projects.*

**[42 Intra Profile: cwannhed](https://profile.intra.42.fr/users/cwannhed)**

</div>
