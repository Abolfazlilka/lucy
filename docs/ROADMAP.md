# Lucy Roadmap

## Current — 1.0.x

- Stabilize the language core.
- Stabilize the Phase 2 standard library.
- Keep the public API documented and readable.
- Improve diagnostics and test coverage.

## Phase 3 — Developer Tooling

Planned priorities:

1. `lucy run` and a more structured CLI.
2. `lucy test` for project tests.
3. `lucy fmt` for source formatting.
4. `lucy lint` for static checks.
5. Better REPL commands and multiline behavior.
6. Debugger support.
7. LSP implementation.
8. A complete VS Code extension.

## Phase 4 — Package Ecosystem

Planned:

- `lucy.toml` project manifest;
- package manager;
- dependency resolution;
- version constraints;
- package registry;
- reproducible dependency installation.

## Phase 5 — Runtime

Planned:

- bytecode representation;
- bytecode VM;
- improved garbage collection strategy;
- runtime performance work;
- native FFI/extension API;
- concurrency and asynchronous I/O.

## Standard-library growth

The standard library will continue to grow around practical general-purpose programming:

- richer HTTP APIs;
- better JSON support;
- SQLite prepared statements and parameters;
- date/time utilities;
- process management;
- encoding and text utilities;
- networking;
- concurrency;
- testing utilities.

The guiding rule remains: high-level APIs should be written in Lucy whenever native code is not necessary.
