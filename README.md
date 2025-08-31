🧮 Algorithms & Problem Solving in C++ 🚀

Algorithms-Problem-Solving-in-C++ — a structured, progressive repository for learning algorithmic thinking, clean C++ code, and practical problem solving. Designed to build strong fundamentals that transfer across languages and support preparation for competitive programming, interviews, and real-world development.

📋 Table of Contents

Overview

Repository Structure

Key Features

Architecture & Conventions

Getting Started

Usage & Workflows

File Organization

Code Quality & Testing

Future Enhancements

Contributing

Maintainer & Contact

License

🎯 Overview

This repository contains a progressive set of algorithmic problems and small console projects organized into levels. Each level targets specific programming concepts and increases in complexity. Solutions are implemented in modern C++ with emphasis on clarity, maintainability, and educational value.

Goals

Teach algorithmic patterns and design.

Reinforce clean coding habits in C++.

Provide self-contained exercises and projects for hands-on practice.

📚 Repository Structure

Level 1 — Fundamentals (Problems 1–50)
Focus: syntax, variables, control flow, loops, arrays, simple math.

Level 2 — Intermediate (Problems 1–50 + Small_Projects/)
Focus: algorithms and common problem patterns.
Small_Projects/ contains console games and interactive examples.

Level 3 — Strings (Problems 1–50 + Small_Projects/)
Focus: string manipulation, parsing, pattern matching.
Small_Projects/ contains banking examples and file I/O demos.

Level 4 — Date & Time (Problems 1–65 + Small_Projects/)
Focus: date/time handling, scheduling, edge cases.
Small_Projects/ contains ATM and extended banking simulations.

File naming convention

Problems: Problem[level]_[number].cpp (example: Problem1_1.cpp)

Projects: stored in Small_Projects/ and use descriptive filenames (e.g., rock_paper_scissors.cpp).

✨ Key Features

Self-contained .cpp files that can be compiled and run independently.

Readable solutions with clear comments and brief problem headers.

Progressive difficulty so learners can build and reuse knowledge.

Interactive console projects placed in Small_Projects/ for each level.

Consistent naming and structure to simplify navigation and contributions.

🏗️ Architecture & Conventions

Single responsibility per file (one problem → one solution).

Use functions and modular code where applicable.

Basic input validation and simple error handling included.

Problem files include short headers describing the task and the approach.

Prefer modern, portable C++ idioms while keeping examples easy to follow.

🚀 Getting Started
Prerequisites

C++ compiler (g++, clang++, or MSVC)

Basic command-line / terminal knowledge

Clone
git clone https://github.com/YaMazini/Algorithms-Problem-Solving-in-C.P.P.git
cd Algorithms-Problem-Solving-in-C.P.P

Compile & run a single problem
g++ Problem1_1.cpp -o Problem1_1
./Problem1_1          # Windows: .\Problem1_1.exe


Note: Many files include main(). Compile single files, or use a build system (Makefile/CMake) if you combine files.

🧑‍💻 Usage & Workflows

Typical learning workflow

Choose a level and problem (e.g., Level2/Problem2_10.cpp).

Read the file header for the problem statement and approach.

Compile and run the solution.

Modify or implement an alternate solution in a new file to preserve originals.

Project workflow

Small_Projects/ folders contain interactive applications — run them and follow prompts.

Use project code as templates for larger applications.

📁 File Organization (example)
/
├── Level1/
│   ├── Problem 1-10.cpp
│   ├── Problem 11-20.cpp
│   ├── Problem 21-30.cpp
│   ├── Problem 31-40.cpp
│   └── Problem 41-50.cpp
│
├── Level2/
│   ├── Problem 1-10.cpp
│   ├── ...
│   ├── Problem 41-50.cpp
│   └── Small_Projects/
│       ├── rock_paper_scissors.cpp
│       └── simple_math_quiz_game.cpp
│
├── Level3/
│   ├── Problem 1-10.cpp
│   ├── ...
│   ├── Problem 41-50.cpp
│   └── Small_Projects/
│       ├── Bank.cpp
│       └── Bank_Extension.cpp
│
├── Level4/
│   ├── Problem 1-10.cpp
│   ├── ...
│   ├── Problem 56-65.cpp
│   └── Small_Projects/
│       ├── Bank_Extension_2.cpp
│       └── Simple_ATM_System.cpp
│
└── README.md


Each Problem X-Y.cpp above is illustrative for ranges; actual files are Problem[level]_[number].cpp (e.g., Problem2_1.cpp ... Problem2_50.cpp). Small_Projects/ contains the projects for that level.

✅ Code Quality & Testing

Files include headers describing the problem and algorithmic idea.

Encourage adding unit tests for key solutions (Catch2 or GoogleTest).

Prefer clear variable names, small helper functions, and brief complexity notes.

Consider CI (GitHub Actions) for automated builds/tests in future.

🔮 Future Enhancements

Planned improvements:

Add advanced problems (data structures, graphs, dynamic programming).

Provide unit tests and CI pipeline.

Add editorial notes comparing multiple solution strategies.

Introduce multi-file examples with CMake and sample Makefiles.

Add formatting rules (clang-format) and a contribution template.

🤝 Contributing

Contributions are warmly welcome.

How to contribute

Fork the repository.

Create a branch: git checkout -b feature/my-problem.

Add your .cpp file in the appropriate LevelX/ folder and include a header describing the problem and approach.

Submit a pull request with a clear description.

Guidelines

Follow naming and formatting conventions.

Keep solutions self-contained and dependency-light.

Add comments and complexity notes where useful.

Consider adding tests for new problems.

Consider adding CONTRIBUTING.md and CODE_OF_CONDUCT.md to simplify collaboration.

🏅 Maintainer & Contact

Maintainer: YaMazini

For issues or feature requests, please use the repository’s Issues tab.

Repository:
🔗 https://github.com/YaMazini/Algorithms-Problem-Solving-in-C.P.P
