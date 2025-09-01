# 🧮 Algorithms & Problem Solving in C++

> A progressive journey through algorithmic thinking and problem solving, practicing clean code concepts such as divide and conquer and code reusability for future development (OOP), while improving logical reasoning to build a strong programming foundation.

[![Language](https://img.shields.io/badge/language-C++-blue.svg)](https://isocpp.org/)
[![Standard](https://img.shields.io/badge/C++-Modern-blue.svg)](https://en.wikipedia.org/wiki/C%2B%2B)
[![Purpose](https://img.shields.io/badge/purpose-Learning%20%26%20Practice-green.svg)]()
[![Difficulty](https://img.shields.io/badge/difficulty-Progressive-orange.svg)]()
[![Problems](https://img.shields.io/badge/problems-200%2B-red.svg)]()
[![Projects](https://img.shields.io/badge/projects-6%20small%20practices-purple.svg)]()

## 🔍 Quick Reference Guide
| Level | Topic | Problems | Key Concepts | Real Projects |
|-------|-------|----------|--------------|---------------|
| 📚 **Level 1** | Fundamentals | 50 | Variables, Enums, Functions/Procedures, Operators, If-Loops & Nested, Primitive Algorithms | - |
| 🧠 **Level 2** | Algorithms | 50 | Arrays, By Ref/By Val, Struct, Switch Case, Common Algorithms & Problems | 2 Games |
| 🔤 **Level 3** | Strings & Matrices | 51 | Pointers, Dynamic Memory Allocation, Dynamic Arrays, Vectors, Regular & 3x3 Matrices, String Work | Banking Apps |
| 📅 **Level 4** | Advanced Systems | 65 | Recursion, Huge Date Operations, Debugging Techniques, File I/O | ATM System |

**Total: 216 Problems + 6 Projects**

## 🎯 Project Vision

Master **algorithmic thinking** and **problem-solving patterns** through hands-on practice with progressively challenging C++ problems. Build strong fundamentals that transfer across programming languages while preparing for technical interviews and real-world software development.

## ❓ Why C++ First?
I started with C++ because it forces you to understand what’s happening under the hood — memory management, pointers, stack vs. heap, and data layouts. It builds strong discipline in types, performance, and debugging while giving systems-level insight. Since many modern languages borrow C-like syntax, mastering C++ makes learning others easier, and building things from scratch reveals exactly how programs work.

## 🏗️ Learning Architecture

### 📈 Progressive Difficulty System
Each level builds upon previous concepts, creating a structured learning path from fundamentals to advanced problem-solving.

```
Level 1 → Level 2 → Level 3 → Level 4      →→→      Advanced (Coming Soon in another repo)
   ↓         ↓         ↓         ↓                                   ↓
Syntax    Algorithms  Strings   Date/Time                     Data Structures
```

### 🎮 Interactive Learning Experience
- **C++**: Completed two progressive C++ courses — an introductory course (levels 1–2) covering fundamentals, and an advanced course (levels 3–4) focused on implementation details and the C++ memory model.
- **Theory + Practice**: Each problem includes explanation and implementation
- **Small Projects**: Real applications demonstrating concepts
- **Self-Contained**: Every file compiles and runs independently
- **Incremental Complexity**: Build confidence through gradual progression

## 📚 Comprehensive Curriculum

### 📖 **Level 1: Fundamentals** (50 Problems)
**Master the Foundation**
```cpp
// Example: Sum of odd numbers using different loop types and enums
#include <iostream>
using namespace std;

enum enOddEven {Odd = 1, Even = 2};

enOddEven CheckOddOrEven(int N) {
    if (N % 2 != 0)
        return enOddEven::Odd;
    else
        return enOddEven::Even;
}

int SumOddNumbersUsingForLoop(int N) {
    int sum = 0;
    for (int i = 0; i <= N; i++) {
        if (CheckOddOrEven(i) == 1) {
            sum += i;
        }
    }
    return sum;
}

int main() {
    int N;
    cout << "Please Enter a Number: ";
    cin >> N;
    
    cout << "Sum of Odd numbers: " << SumOddNumbersUsingForLoop(N) << endl;
    return 0;
}
```
**Core Concepts:**
- 🔤 Variables and data types (int, enum)
- 🔄 Control structures (for, while, do-while loops)
- 📊 Enumerations and type safety  
- ➕ Mathematical computations and modular arithmetic
- 🔧 Function creation and parameter passing
- 💡 Problem decomposition and code reusability

### 🧠 **Level 2: Intermediate Algorithms** (50 Problems + Projects)
**Build Algorithmic Thinking**
```cpp
// Example: Array manipulation and random number generation
#include <iostream>
using namespace std;

int RandomNumber(const int From, const int To) {
    return rand() % (To - From + 1) + From;
}

void FillArrayWithRandomNumbers(int Arr[100], int ArrLength) {
    for (int i = 0; i < ArrLength; i++) {
        Arr[i] = RandomNumber(1, 100);
    }
}

void AddArrayElement(int Arr[100], int& ArrLength, int Number) {
    ArrLength++;
    Arr[ArrLength - 1] = Number;
}

void CopyElementsFromArray(int ArrSource[100], int ArrDestination[100], 
                          int ArrSourceLength, int& ArrDestinationLength) {
    for (int i = 0; i < ArrSourceLength; i++) {
        AddArrayElement(ArrDestination, ArrDestinationLength, ArrSource[i]);
    }
}
```
**Advanced Concepts:**
- 🔍 Array manipulation and dynamic operations
- 📈 Random number generation and seeding
- 🎯 Pass-by-reference for dynamic array sizing
- 🧩 Function/Procedure composition and modular design
- 📊 Array copying and element addition algorithms
- 🎮 **Small Projects**: Rock-Paper-Scissors, Math Quiz Games

### 🔤 **Level 3: String Mastery** (51 Problems + Banking Projects)
**Text Processing & Real Applications**
```cpp
// Example: Advanced string splitting using vectors
#include <iostream>
#include <vector>
#include <string>
using namespace std;

vector<string> SplitString(string S1, string Delim) {
    vector<string> sWords;
    string Word;
    short pos = 0;

    while ((pos = S1.find(Delim)) != string::npos) {
        Word = S1.substr(0, pos);
        S1.erase(0, pos + Delim.length());
        
        if (Word != "") {
            sWords.push_back(Word);
        }
    }
    
    if (S1 != "") {
        sWords.push_back(S1);
    }
    
    return sWords;
}

string ReverseWordsInString(string S1, string Delim) {
    string S2 = "";
    vector<string> vWords = SplitString(S1, Delim);
    vector<string>::iterator iter = vWords.end();

    while (iter != vWords.begin()) {
        iter--;
        S2 += *(iter) + Delim;
    }
    
    return S2.substr(0, S2.length() - Delim.length());
}
```
**String Expertise:**
- 🎯 Working with regular and 3x3 Matrices
- 🧩 Pointers, Dynamic Memory Allocation, and Dynamic Arrays
- 🔠 Advanced string manipulation with vectors
- 📝 String splitting and tokenization algorithms
- 🔍 Iterator usage and vector operations
- 💾 Dynamic string building and concatenation
- 🔄 String reversal and reconstruction techniques
- 🎯 Applying Debugging tricks & techniques on every problem
- 🏦 **Real Projects**: Banking System, Bank Extension 1

### 📅 **Level 4: Date & Time Systems** (65 Problems + ATM Projects)
**Temporal Logic & Business Applications**
```cpp
// Example: Complex date increment operations
#include <iostream>
using namespace std;

struct stDate {
    short Year = 0;
    short Month = 0;
    short Days = 0;
};

bool IsLeapYear(short Year) {
    return (Year % 400 == 0) || ((Year % 4 == 0) && (Year % 100 != 0));
}

short NumberOfDaysInMonth(short Year, short Month) {
    if (Month < 1 || Month > 12) return 0;
    
    short ArrDays[] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    return (Month == 2) ? (IsLeapYear(Year) ? 29 : 28) : ArrDays[Month];
}

bool IsLastDay(stDate Date) {
    return (Date.Days == NumberOfDaysInMonth(Date.Year, Date.Month));
}

stDate IncreaseDayByOneDay(stDate Date) {
    if (IsLastDay(Date)) {
        if (Date.Month == 12) {
            Date.Days = 1;
            Date.Month = 1;
            Date.Year++;
        } else {
            Date.Days = 1;
            Date.Month++;
        }
    } else {
        Date.Days++;
    }
    return Date;
}
```
**Temporal Mastery:**
- 🔄 Using recursion Properly
- 📆 Custom date structures and data modeling
- ⏰ Leap year calculations and calendar logic
- 📊 Complex conditional logic for date validation
- 🔄 Date increment algorithms with edge case handling
- 📈 Month/year boundary management and transitions
- 🎯 More Debugging Experience on every problem
- 📚 Reading/Inserting/Writing on Files
- 🏧 **Advanced Projects**:  Bank Extension 2, ATM System

## 📁 File Organization

```
Algorithms-Problem-Solving-in-C++/
├── 📚 Level1/ (Fundamentals)
│   ├── Problem 1-10.cpp
│   ├── Problem 11-20.cpp
│   ├── Problem 21-30.cpp
│   ├── Problem 31-40.cpp 
│   └── Problem 41-50.cpp
│
├── 🧠 Level2/ (Intermediate)
│   ├── Problem 1-10.cpp   
│   ├── Problem 11-20.cpp  
│   ├── Problem 21-30.cpp  
│   ├── Problem 31-40.cpp   
│   ├── Problem 41-50.cpp   
│   └── 🎮 Small_Projects/
│       ├── rock_paper_scissors.cpp
│       └── simple_math_quiz_game.cpp
│
├── 🔤 Level3/ (Dealing with Matrices - String Processing - Common Algorithms)
│   ├── Problem 1-10.cpp 
│   ├── Problem 11-20.cpp  
│   ├── Problem 21-30.cpp   
│   ├── Problem 31-40.cpp  
│   ├── Problem 41-51.cpp   
│   └── 🏦 Small_Projects/
│       ├── Bank.cpp
│       └── Bank_Extension.cpp
│
├── 📅 Level4/ (Date & Time - Common Algorithms - Dealing with Files)
│   ├── Problem 1-10.cpp    
│   ├── Problem 11-20.cpp  
│   ├── Problem 21-30.cpp  
│   ├── Problem 31-40.cpp   
│   ├── Problem 41-50.cpp  
│   ├── Problem 51-65.cpp  
│   └── 🏧 Small_Projects/
│       ├── Bank_Extension_2.cpp
│       └── Simple_ATM_System.cpp
│
└── README.md
```

## 🚀 Quick Start Guide

### Prerequisites
```bash
✅ C++ compiler (g++, clang++, or MSVC)
✅ Basic command-line knowledge  
✅ Text editor or IDE
✅ Curiosity and persistence!
```

### Get Started in 30 Seconds
```bash
# 1. Clone the repository
git clone https://github.com/YaMazini/Algorithms-Problem-Solving-in-C.P.P.git
cd Algorithms-Problem-Solving-in-C.P.P

# 2. Pick your starting level and problem
cd Level1

# 3. Compile and run any problem
g++ "Problem 1-10.cpp" -o problem
./problem          # Windows: .\problem.exe

# 4. Start learning and solving!
```

### 📖 Learning Workflow
1. **Start with Level 1** - Essential for everyone to understand our coding methodology and structured approach
2. **Master the Foundation** - Learn the fundamental problem-solving patterns and code organization
3. **Read the problem header** for context and approach
4. **Compile and run** to see the solution in action
5. **Analyze the structure** - Notice how problems are broken into reusable functions
6. **Modify the code** - experiment and learn by doing
7. **Try alternative approaches** - implement your own variations
8. **Progress sequentially** - each level builds upon previous concepts
9. **Apply in projects** - use learned concepts in real applications

> 💡 **Important**: Even experienced programmers should start with Level 1 to understand our methodology, coding style, and systematic approach to problem-solving.

## 🎯 Key Learning Features

### 📚 **Educational Design**
- **Self-Contained Files**: Each problem compiles independently
- **Clear Problem Headers**: Every solution includes problem statement and approach
- **Progressive Complexity**: Build skills methodically from basics to advanced
- **Multiple Examples**: Different approaches to similar problems

### 🔧 **Code Quality Focus**
- **Modern C++ Practices**: Clean, readable, maintainable code
- **Readability First**: Clear variable names, proper indentation, and logical flow
- **Code Reusability**: Modular functions designed for reuse across different problems
- **Divide and Conquer**: Breaking complex problems into smaller, manageable functions
- **Clean Code Principles**: One responsibility per function, clear structure and organization
- **Consistent Conventions**: Uniform naming and structure throughout all levels
- **Input Validation**: Proper error handling and edge cases
- **Separation of Concerns**: Each function handles a single responsibility

### 🎮 **Interactive Projects**
- **Real Applications**: Banking systems, games, utilities
- **Console Interaction**: User-friendly interfaces
- **Practical Skills**: File I/O, data persistence, user experience
- **Business Logic**: Real-world problem solving

## 💡 Problem-Solving Methodology

### 🧩 **Pattern Recognition**
Learn to identify common algorithmic patterns:
- **Two Pointers**: For array and string problems
- **Sliding Window**: For substring and subarray problems  
- **Divide & Conquer**: For optimization and complex problem breakdown
- **Dynamic Programming**: For complex recursive problems

### 📊 **Complexity Analysis**
Understand performance characteristics:
- **Time Complexity**: How runtime scales with input size
- **Space Complexity**: Memory usage patterns
- **Optimization Techniques**: Making code faster and more efficient
- **Trade-offs**: Balancing time vs space vs readability

### 🔍 **Debugging Skills**
Develop systematic problem-solving:
- **Test Cases**: Edge cases and boundary conditions
- **Step-by-Step Execution**: Trace through algorithms
- **Error Patterns**: Common mistakes and how to avoid them
- **Verification**: Ensuring correctness before optimization

## 🏆 Skills You'll Master

### 🎓 **Core Programming**
- ✅ **C++ Mastery**: From basics to advanced features
- ✅ **Algorithm Design**: Creating efficient solutions
- ✅ **Data Structures**: Understanding when and how to use each type
- ✅ **Problem Decomposition**: Breaking complex problems into manageable parts

### 💼 **Professional Development**  
- ✅ **Code Quality**: Writing clean, maintainable code
- ✅ **Testing Mindset**: Thinking about edge cases and validation
- ✅ **Documentation**: Clear commenting and explanation
- ✅ **Version Control**: Git workflow and collaboration

### 🎯 **Career Preparation**
- ✅ **Technical Interviews**: Algorithm and coding challenges
- ✅ **Competitive Programming**: Contest-style problem solving
- ✅ **System Design**: Understanding how pieces fit together
- ✅ **Real-World Applications**: Practical software development skills

## 🔮 Roadmap & Future Enhancements

### 🎯 **Currently Available** (200+ Problems)
- ✅ **Level 1-4 Complete**: Comprehensive curriculum ready
- ✅ **Interactive Projects**: Real applications in each level
- ✅ **Progressive Learning**: Structured skill development
- ✅ **Self-Contained Solutions**: Independent problem files

### 🚀 **Coming Soon**
- 🔄 **Level 5: Advanced Data Structures** (Trees, Graphs, Heaps)
- 📈 **Level 6: Dynamic Programming** (Memoization, Optimization)
- 🌐 **Level 7: Graph Algorithms** (BFS, DFS, Shortest Paths)
- 🧪 **Unit Testing Framework** (Automated verification)
- 🏗️ **Build System** (CMake integration)
- 📝 **Solution Comparisons** (Multiple approaches explained)

### 🔧 **Quality Improvements**
- 🎨 **Code Formatting**: clang-format integration
- 🚀 **CI/CD Pipeline**: Automated builds and testing
- 📊 **Performance Benchmarks**: Solution timing and memory usage
- 📚 **Extended Documentation**: Theory explanations and tutorials

## 🤝 Contributing & Community

### 🌟 **How to Contribute**
```bash
# 1. Fork the repository
# 2. Create a feature branch
git checkout -b feature/new-problem-series

# 3. Add your solutions following conventions
# 4. Include problem headers and comments  
# 5. Submit a pull request with clear description
```

### 📝 **Contribution Guidelines**
- **Follow Naming Convention**: `Problem[level]_[number].cpp`
- **Include Problem Headers**: Clear description and approach
- **Self-Contained Solutions**: No external dependencies
- **Comment Your Code**: Explain complex logic
- **Test Your Solutions**: Verify correctness

### 🎯 **What We're Looking For**
- 🧩 **New Problem Categories**: Graph theory, machine learning
- 🎮 **Interactive Projects**: More real-world applications  
- 📚 **Educational Content**: Tutorials and explanations
- 🔧 **Tooling Improvements**: Build systems, testing frameworks
- 🌍 **Translations**: Multi-language support

## 👨‍💻 About the Maintainer

**YaMazini** - *Passionate Problem Solver & Educator*

🎯 **Mission**: Making algorithmic thinking accessible through hands-on practice and progressive learning.

📚 **Philosophy**: 
- Learn by building, not just reading
- Quality over quantity in problem selection  
- Real applications over academic exercises
- Community-driven improvement and feedback

🙏 **Acknowledgments**: Problems curated and adapted from [ProgrammingAdvices](https://programmingadvices.com/) - an excellent resource for systematic programming education.

🔗 **Connect**: 
- GitHub: [@YaMazini](https://github.com/YaMazini)
- Repository: [Algorithms-Problem-Solving-in-C++](https://github.com/YaMazini/Algorithms-Problem-Solving-in-C.P.P)

---

## 🎓 Start Your Journey Today

Whether you're preparing for **technical interviews**, improving **competitive programming** skills, or building **stronger algorithmic thinking**, this repository provides a structured path to mastery.

**Choose your starting point:**
- 🆕 **New to Programming?** → Start with Level 1
- 🧠 **Know the Basics?** → Still start with Level 1 to learn our methodology
- 🔤 **Strong in Logic?** → Begin with Level 1 for proper foundation
- 📅 **Experienced Developer?** → Level 1 teaches our systematic approach

> 💡 **Remember**: Every expert was once a beginner. Master the fundamentals, understand the methodology, then build complexity step by step.

---

⭐ **Ready to level up your problem-solving skills? Star this repo and start your coding journey!**

*Built for learners, by learners. Let's solve problems and build the future, one algorithm at a time.* 🚀
