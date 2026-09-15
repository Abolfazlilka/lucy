
<div align="center">

<img src="assets/lucy-logo.png" width="180" alt="Lucy">

# Lucy

### A lightweight, dynamic programming language built with C++17.

[![Version](https://img.shields.io/badge/version-1.0.0-8b5cf6?style=flat-square)](...)
[![Language](https://img.shields.io/badge/runtime-C%2B%2B17-orange?style=flat-square)](...)

**Simple syntax. Dynamic values. Classes. Modules. A small runtime.**

</div>
Lucy is a general-purpose, dynamically typed programming language implemented in C++17. It combines a small readable syntax, Ruby-like method calls, a Python-style REPL, and a standard library whose high-level API is written in Lucy itself.

## What Lucy provides

- Direct `.lucy` source execution
- Interactive REPL
- Dynamic values: `nil`, `bool`, `int`, `double`, `string`, `array`, `map`, functions, classes, and instances
- Variables, constants, globals, interpolation, comments, and multiline comments
- Arithmetic, comparison, logical, bitwise, ternary, and range operators
- `if`, `else if`, `else`, `while`, `for`, `foreach`, `loop`, `break`, `continue`
- Functions with default, named, and variadic arguments
- Lexical block scoping and closures
- Classes, constructors, fields, methods, and inheritance
- Exceptions with `try`, `catch`, `finally`, and `throw`
- Modules and selective imports
- Backtick shell expressions
- Phase 2 standard library: regex, JSON, datetime, process, encoding, CSV, HTTP, and SQLite
- Script command-line arguments through `ARGV` / `argv`
- GPL-licensed source distribution

## Quick start

```text
lucy hello.lucy
lucy
lucy -i
```

Example:

```lucy
import json
import regex

user = json.parse("{\"name\":\"Nima\",\"age\":21}")

if regex.match("^[A-Z]", user.name)
    print "Hello $user.name"
end
```

## Command-line arguments

When a source file is executed, every argument after the `.lucy` file is exposed as a string in `ARGV`. The lowercase `argv` name is an alias for the same array.

```bash
lucy app.lucy one two 42
```

```lucy
print ARGV[0]
print ARGV[1]
print ARGV[2]
```

The standard `sys` module also exposes `sys.argv()`.

## Build

Requirements:

- C++17 compiler
- CMake 3.16+
- SQLite3 development package for the SQLite module (optional at build time)
- `curl` executable for the HTTP module

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j2
ctest --test-dir build --output-on-failure
```

## Install

Use `./install.sh` on Linux/macOS or `install.bat` on Windows. Both installers build, test, and install Lucy.

## Documentation

- `docs/REFERENCE.md` — complete language and API reference
- `docs/LANGUAGE.md` — language syntax and semantics
- `docs/TUTORIAL.md` — guided examples
- `docs/STDLIB.md` — standard library API
- `docs/ARCHITECTURE.md` — interpreter architecture
- `docs/ERRORS.md` — diagnostics and error categories
- `docs/CLI.md` — command-line interface
- `docs/HISTORY.md` — version-by-version additions
- `docs/ROADMAP.md` — planned work
- `editors/README.md` — editor integrations

## Architecture

Lucy deliberately keeps the native boundary small:

```text
Lucy application
      |
      v
stdlib/*.lucy
      |
      v
small native C++ primitives
      |
      +-- OS
      +-- filesystem
      +-- SQLite
      +-- regex
      +-- process
      +-- host curl
```

This means most standard-library behavior can be read and modified directly in Lucy without rebuilding the interpreter.

## Author

Lucy is created and maintained by **Nima**.
