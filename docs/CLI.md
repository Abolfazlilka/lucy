# Lucy Command-Line Interface

## Synopsis

```text
lucy <file.lucy> [arguments...]
lucy
lucy -i
lucy -h
lucy -v
```

## Run a file

```bash
lucy app.lucy
```

Arguments after the source file are passed to the Lucy program:

```bash
lucy app.lucy one two 42
```

Inside Lucy:

```lucy
print ARGV
print ARGV[0]
```

`ARGV` values are strings. The source filename itself is not included. `argv` is a lowercase alias.

## Interactive mode

```bash
lucy
```

or:

```bash
lucy -i
```

The REPL uses:

```text
>>> 
... 
```

for single-line and multiline input.

Commands:

| Command | Action |
|---|---|
| `:help` | show REPL commands |
| `:clear` | clear the current multiline buffer |
| `:version` | show interpreter version |
| `:exit` | leave the REPL |
| `:quit` | leave the REPL |

## Help

```bash
lucy -h
```

## Version

```bash
lucy -v
```

## Exit status

The interpreter returns `0` after successful execution and `1` when an uncaught error reaches the command-line entry point.

## Command-line arguments inside libraries

A library can access the same global argument array through `ARGV`, `argv`, or `sys.argv()`.

Application libraries should generally avoid depending on command-line arguments unless they are intentionally part of the application's interface.
