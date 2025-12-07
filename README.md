# C23 code snippets

## build
Provided code examples use C23 standard. It is not supported by some of the old versions of compilers.\
It is recommended to use GNU GCC version >= 15, or LLVM Clang version >= 20.\
Example of a command to build with GCC:
```console
gcc --std=c23 --pedantic -Wall main.c
```

## Folders
### bitint
Demonstrates bit-precise integers using _BitInt(n).

### embed

Example of binary data inclusion using #embed preprocessor directive.

### enums

Example of enum underlying type declaration.

### misc
Examples of multiple new features and keywords:
- #elifdef, #elifndef preprocessor directives
- typeof, auto, constexpr keywords
- 0b binary integer constants and `'` digit separators
- variable declaration after label

## Links
[My blogpost describing main C23 features](https://2pif.com/blog/03.html)\
[A more comprehensive overview of C23 changes](https://en.cppreference.com/w/c/23.html)
