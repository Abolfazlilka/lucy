<div align="center">

<img src="assets/logo.png" width="180" alt="Lucy">

# Lucy

### A lightweight, dynamic programming language built with C++17.

[![Version](https://img.shields.io/badge/version-0.9.1-8b5cf6?style=flat-square)](...)
[![License](https://img.shields.io/badge/license-GPL--3.0-blue?style=flat-square)](...)
[![Language](https://img.shields.io/badge/runtime-C%2B%2B17-orange?style=flat-square)](...)

**Simple syntax. Dynamic values. Classes. Modules. A small runtime.**

</div>

---

## ✦ About

**Lucy** is a lightweight, general-purpose, dynamically typed
programming language with a compact interpreter written in **C++17**.

Lucy is designed around a simple idea:

> **Keep the language expressive without making the runtime complicated.**

Source files use the `.lucy` extension and execute directly through
the Lucy interpreter.

---

## ⚡ Quick Example

```lucy
name = "Nima"

print "Hello $name"

class Counter
    def initialize(value)
        self.value = value
    end

    def increment()
        self.value += 1
        return self.value
    end
end

counter = Counter.new(10)

print counter.increment()
````

---

## ✨ Features

* Dynamic typing
* Variables, constants and globals
* Strings with interpolation
* Arrays and maps
* Functions and methods
* Command-style calls
* Classes and inheritance
* Constructors and instance fields
* Exceptions
* Modules and imports
* Range expressions
* `if`, `while`, `for`, `foreach` and `loop`
* Interactive REPL
* Filesystem and OS standard libraries
* Shell expressions
* Cross-platform runtime

---

## 🧠 Syntax

Lucy uses a compact, Ruby-inspired syntax while keeping its own
language semantics.

```lucy
items = [1, 2, 3]

items.push 4

foreach item in items
    print item
end
```

Functions can be written naturally:

```lucy
def add(a, b)
    return a + b
end

print add 2, 3
```

---

## 🏗 Architecture

Lucy 1.0 is built around a C++17 interpreter and a small runtime.

```text
.lucy source
     │
     ▼
  Parser
     │
     ▼
  Runtime
     │
     ├── Values
     ├── Functions
     ├── Classes
     ├── Modules
     └── Standard Library
```

The runtime intentionally remains implemented in C++ while the language
core is being stabilized.

---

## 📦 Standard Library

Lucy includes focused modules for common system operations:

```lucy
import file
import dir
import path
import os

file.write "hello.txt", "Lucy"

print dir.entries "."
print path.basename "/tmp/test.txt"
print os.platform()
```

---

## 💻 REPL

Run Lucy without a source file:

```text
$ lucy

>>> 2 + 2
4

>>> name = "Nima"
>>> print "Hello $name"
Hello Nima
```

---

## 🛠 Build

Lucy requires:

* C++17 compiler
* CMake 3.16+

```bash
cmake -S . -B build -DCMAKE_BUILD_TYPE=Release
cmake --build build -j2
ctest --test-dir build --output-on-failure
```

---

## 📚 Documentation

* [Language Reference](docs/LANGUAGE.md)
* [Tutorial](docs/TUTORIAL.md)
* [Standard Library](docs/STDLIB.md)
* [Architecture](docs/ARCHITECTURE.md)
* [Errors & Diagnostics](docs/ERRORS.md)
* [Roadmap](docs/ROADMAP.md)
* [Editor Support](editors/README.md)

---

## 🐾 The Name

Lucy is a small language with a small runtime — but it is meant to grow.

The cat represents the same idea:

**small, curious, and independent.**

---

## 👤 Author

Created and maintained by **Nima**
GitHub: [@nimacpp](https://github.com/nimacpp)

---

<div align="center">

### Lucy 1.0

**A small language, built from scratch.**

</div>
```
