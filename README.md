# SIC/XE Assembler

This project is an **assembler** for the **SIC/XE (Simplified Instructional Computer/Extended)** architecture, implemented in C++. It processes SIC/XE assembly language source code and generates the corresponding machine code.

## Features
- Reads SIC/XE assembly source files.
- Parses assembly instructions and translates them into object code.
- Generates output files with machine code.

## How It Works
1. **Input:** The program takes a SIC/XE assembly source file.
2. **Processing:** It performs lexical and syntax analysis, symbol table generation, and instruction translation.
3. **Output:** Produces an object file with the assembled machine code.

## Requirements
- C++ Compiler (e.g., g++)
- A SIC/XE assembly source file
  
### 🔄 Flowchart Representation

```plaintext
    +----------------+
    |  Input Source  |
    +----------------+
            |
            v
    +-----------------+
    |  Pass 1: Build  |
    |   Symbol Table  |
    +-----------------+
            |
            v
    +-----------------+
    |  Pass 2: Translate |
    |   to Object Code  |
    +-----------------+
            |
            v
    +-----------------+
    |   Output Object  |
    |      Code       |
    +-----------------+
