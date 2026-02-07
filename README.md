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
├── cpp00/    # Introduction to C++
├── cpp01/    # Memory and references
├── cpp02/    # Operator overloading
├── cpp03/    # Inheritance (in progress)
├── cpp04/    # Polymorphism
├── cpp05/    # Exceptions
├── cpp06/    # Type casting
├── cpp07/    # Templates
├── cpp08/    # STL containers
└── cpp09/    # Advanced STL
```

Each module contains multiple exercises with increasing complexity, typically named `ex00`, `ex01`, `ex02`, etc.

## 🚀 Installation & Usage

Each module is self-contained with its own Makefile.

### Building
```bash
git clone https://github.com/carowann/cpp.git
cd cpp/cpp0X/exXX  # Navigate to specific module and exercise
make
```

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

## 🔧 Challenges & Insights

The transition from C to C++ has required unlearning some habits while building new mental models.

> 💭 *The exercises are carefully designed to expose common pitfalls and force engagement with language mechanics rather than just syntax.*


## 🙏 Acknowledgments

Completed as part of the 42 School curriculum. These modules provide an intensive, practice-driven introduction to C++ that emphasizes understanding over memorization.

---

<div align="center">

*These modules mark my transition into object-oriented programming, building on the low-level systems knowledge from previous C projects.*

**[42 Intra Profile: cwannhed](https://profile.intra.42.fr/users/cwannhed)**

</div>
