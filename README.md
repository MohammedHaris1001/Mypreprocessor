# MyPreprocessor

A modular, custom C preprocessor built entirely from scratch in C. This project implements a multi-pass file processing pipeline to handle comment stripping, header file inclusion, and advanced macro substitution (supporting both simple and multi-argument function-like macros) without relying on external libraries like `<ctype.h>`.

---

##Features

- Comment Removal (comment_removal.c):  removes single-line (//) and multi-line (/* ... */) comments while preserving string literals.
- File Inclusion (file_inclusion.c): Resolves and expands #include directives to inline header file contents.
- Advanced Macro Substitution (macro_substitution.c): 
  - Handles simple object-like macros (e.g.,#define PI 3.14).
  - Handles complex, multi-argument function-like macros (e.g.,#define MAX(a, b) ((a) > (b) ? (a) : (b))).
  - Uses robust custom string parsing and 3D boundary arrays to substitute macro parameters safely.

---

## Project Structure


project1/
├── main.c                 # Coordinates the multi-pass preprocessor pipeline
├── header.h               # Shared header file containing declarations
├── comment_removal.c      # Module for removing comments
├── file_inclusion.c       # Module for processing #include directives
├── macro_substitution.c   # Module for handling object and function-like macros
└── Makefile               # Build automation script
