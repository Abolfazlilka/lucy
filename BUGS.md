# Lucy 1.0.0 Known Limitations

- Runtime AST nodes do not yet retain full source spans for caret diagnostics.
- The numeric model uses `long long` and `double`; arbitrary-precision integers are not implemented.
- The object graph uses shared ownership and does not yet have a tracing garbage collector.
- HTTP currently depends on the host `curl` executable.
- SQLite support depends on SQLite3 being available to CMake at build time.
- Shell backticks and `process` commands are host-dependent.
- The process API currently focuses on command execution rather than long-lived process handles.
- Callback syntax is intentionally conservative.
- The filesystem standard library does not yet expose advanced file descriptors, permissions, watchers, or async IO.
