# Discrete Mathematics Toolkit

A modular, menu-driven C++ application that demonstrates and applies core concepts from Discrete Mathematics and Discrete Structures. The project brings together set theory, mathematical logic, relations, functions, graph-based course prerequisite management, combinatorics, proof explanations, and data-consistency validation in one console application.

> **Project title:** Discrete Mathematics Toolkit  
> **Project type:** Individual C++ project  
> **Interface:** Command-line / console  
> **Language:** C++

## Project Overview

The application presents a main menu containing nine modules. Each module focuses on a different discrete mathematics topic and provides operations through a separate menu.

The project is designed as an educational implementation of mathematical concepts and related algorithms rather than as a production university scheduling system.

## Features

### 1. Course Scheduling Module
- Add courses using a course code and name.
- Define prerequisite relationships between courses.
- Represent prerequisite dependencies using an adjacency list.
- Detect cycles in the prerequisite graph using Depth-First Search (DFS).
- Generate one valid course sequence using a topological-ordering approach.
- Report when a prerequisite cycle prevents scheduling.

### 2. Student Group Module
- Add students and display the student list.
- Generate all possible groups containing a specified number of students.
- Use recursion and backtracking to generate combinations.
- Display the total number of combinations and their members.

This module generates combinations of a chosen group size; it does not divide the class into a set of mutually exclusive teams.

### 3. Induction and Prerequisite Module
- Add courses and prerequisite relationships.
- Mark courses as completed for a student.
- Display available courses and completed courses.
- Check whether a student has completed the prerequisites required to take a course.
- Detect prerequisite cycles during recursive prerequisite checking.

The current implementation uses a single student record labelled `Student1`.

### 4. Logic and Inference Engine
- Store logical facts in predicate-subject-value form.
- Add IF-THEN inference rules.
- Display stored facts and rules.
- Apply forward-chaining inference to derive additional facts.
- Identify conflicting facts that assign different values to the same predicate and subject.
- Clear stored facts and rules.

The rule matcher supports `*` as a wildcard for matching any predicate, subject, or value.

### 5. Set Operations Module
- Create named sets.
- Add elements while preventing duplicate elements within a set.
- Display individual sets or all stored sets.
- Calculate union, intersection, and difference.
- Check whether one set is a subset of another.

### 6. Relations Module
- Create a base set of elements.
- Add ordered pairs to represent a relation.
- Display the base set and relation.
- Check reflexivity, symmetry, and transitivity.
- Determine whether a relation is an equivalence relation.
- Provide a partial-order classification check.

**Implementation note:** The current `isPartialOrder()` implementation checks reflexivity, non-symmetry, and transitivity. A mathematically correct partial-order test requires antisymmetry, so this check needs correction before it can be relied upon.

### 7. Functions Module
- Define a function name, domain, and codomain.
- Add mappings from domain elements to codomain elements.
- Display the domain, codomain, and mappings.
- Check injectivity (one-to-one).
- Check surjectivity (onto).
- Check bijectivity.
- Display an inverse when the function is bijective.
- Compose two functions where the required mappings exist.

### 8. Proof and Verification Module
Provides proof-oriented explanations based on conditions supplied by the user:
- Strong-induction prerequisite completion.
- Set-subset verification.
- Reflexive relation verification.
- Symmetric relation verification.
- Transitive relation verification.
- Injectivity counterexample explanation.
- Surjectivity verification.

This module prints proof explanations from supplied evidence; it does not automatically construct formal mathematical proofs from arbitrary inputs.

### 9. Consistency Checker Module
The separate `ConsistencyModule` class contains validation routines for:
- Missing courses in prerequisite relationships.
- Cycles in prerequisite graphs.
- Invalid function domain and codomain mappings.
- Multiple mappings for the same domain element.
- Relation pairs containing elements outside the base set.
- Empty sets and duplicate set elements.
- Conflicting logical facts.

**Integration note:** These validation routines are implemented in the module, but the current main-menu option only displays a placeholder message. The validation routines are not yet connected to an interactive consistency-checking workflow.

## Concepts and Algorithms Demonstrated

| Area | Concepts / techniques |
|---|---|
| Graph theory | Adjacency lists, DFS, cycle detection, topological ordering |
| Recursion | Recursive traversal and combination generation |
| Combinatorics | Generating student groups using combinations |
| Mathematical logic | Facts, IF-THEN rules, forward chaining, conflict detection |
| Set theory | Union, intersection, difference, subset |
| Relations | Reflexive, symmetric, transitive, equivalence |
| Function theory | Domain, codomain, mappings, injective, surjective, bijective |
| Proof concepts | Induction and property-based proof explanations |
| Validation | Prerequisite, mapping, relation, set, and fact consistency checks |

## Project Structure

```text
discrete-project-main/
│
├── main.cpp
│
├── module 1/
│   ├── CourseModule.h
│   └── CourseModule.cpp
│
├── module 2/
│   ├── StudentGroupModule.h
│   └── StudentGroupModule.cpp
│
├── module 3/
│   ├── InductionModule.h
│   └── InductionModule.cpp
│
├── module 4/
│   ├── LogicModule.h
│   └── LogicModule.cpp
│
├── module 5/
│   ├── SetModule.h
│   └── SetModule.cpp
│
├── module 6/
│   ├── RelationsModule.h
│   └── RelationsModule.cpp
│
├── module 7/
│   ├── FunctionsModule.h
│   └── FunctionsModule.cpp
│
├── module 8/
│   ├── ProofModule.h
│   └── ProofModule.cpp
│
└── module 9/
    ├── ConsistencyModule.h
    └── ConsistencyModule.cpp
```

Each module is separated into a header (`.h`) file and an implementation (`.cpp`) file. `main.cpp` creates the module objects and provides the main navigation menus.

## Requirements

- A C++ compiler such as GCC (g++) or MinGW.
- A C++11-compatible compiler or newer.
- A terminal or IDE capable of building a multi-file C++ project.

## Build Status and Compilation

**The uploaded source snapshot does not currently compile successfully.** A compilation attempt identified these blockers:

1. `Course` is defined in both `CourseModule.h` and `InductionModule.h`, causing a class redefinition.
2. `InductionModule.cpp` contains duplicate definitions of `markCompletedForStudent()` and `listCompletedCourses()`.
3. `canStudentTakeCourse()` refers to the misspelled identifier `persistantCompleted`.

The source also has logic/integration issues described in the module notes above. These should be fixed and tested before presenting the project as a successfully buildable application.

After those issues are corrected, a GCC build can be attempted from the project root with:

```bash
g++ -std=c++11 \
  -I"module 1" -I"module 2" -I"module 3" \
  -I"module 4" -I"module 5" -I"module 6" \
  -I"module 7" -I"module 8" -I"module 9" \
  main.cpp \
  "module 1/CourseModule.cpp" \
  "module 2/StudentGroupModule.cpp" \
  "module 3/InductionModule.cpp" \
  "module 4/LogicModule.cpp" \
  "module 5/SetModule.cpp" \
  "module 6/RelationsModule.cpp" \
  "module 7/FunctionsModule.cpp" \
  "module 8/ProofModule.cpp" \
  "module 9/ConsistencyModule.cpp" \
  -o discrete_toolkit
```

Run the executable after a successful build:

```bash
./discrete_toolkit
```

On Windows, run:

```powershell
.\discrete_toolkit.exe
```

## How to Use

1. Build the project after resolving the compilation issues.
2. Run the executable.
3. Select one of the nine modules from the main menu.
4. Follow the selected module's menu to add data and perform operations.
5. Enter `0` in a module menu to return to the main menu.
6. Enter `0` in the main menu to exit.

## Limitations

- The application is console-based; it does not include a graphical user interface.
- Data is stored in memory and is not saved to a database or persistent files.
- The prerequisite module currently models one student (`Student1`).
- Student grouping lists all combinations of the requested size, which can grow rapidly as the number of students increases.
- The proof module provides condition-based explanations rather than a general-purpose theorem prover.
- The consistency checker is not fully connected to the main menu.
- Some mathematical checks and the current source snapshot require correction before reliable use.

## Purpose

The project demonstrates how discrete mathematical structures and algorithms can be translated into modular C++ programs. It combines theoretical topics commonly taught in Discrete Mathematics with practical implementations involving graphs, recursion, logic, sets, relations, and functions.
