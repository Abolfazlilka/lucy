# Lucy REPL

The Lucy REPL is the interactive environment that starts when `lucy` is run without a source file or with `lucy -i`.

## Starting the REPL

```text
lucy
```

or:

```text
lucy -i
```

Lucy 1.0.0 provides a native line editor on Windows, Linux, and macOS. It does not require Python, GNU Readline, or an external runtime dependency.

## Editing

| Key | Action |
|---|---|
| Up | Previous history entry |
| Down | Next history entry |
| Left / Right | Move the cursor |
| Home / End | Move to the beginning/end |
| Backspace | Delete before the cursor |
| Delete | Delete at the cursor |
| Tab | Complete a name or member |
| Ctrl-D | Exit when the input line is empty |

The editor supports editing in the middle of a line, not only at the end.

## History

Lucy stores interactive commands persistently:

- Linux/macOS: `~/.lucy_history`
- Windows: `%USERPROFILE%\\.lucy_history`

Up and Down can be used across REPL sessions. Lucy keeps the most recent 1000 entries and removes immediate/older duplicates when a command is entered again.

Use:

```text
:history
```

to display stored entries from the current session.

## Completion

Press Tab after a partial name. Completion covers:

- language keywords
- built-in functions
- global constants and variables
- standard-library modules
- module members
- methods of arrays
- methods of strings
- methods of maps
- methods and fields of user objects
- methods of user classes

Examples:

```text
>>> pri<Tab>
>>> print
```

```text
>>> import math
>>> math.sq<Tab>
>>> math.square
```

When several names share a prefix, the first Tab completes the common prefix. A following Tab displays the matching candidates.

## Multiline input

Block constructs use the continuation prompt:

```text
>>> def greet(name)
... print "Hello " + name
... end
```

The REPL keeps collecting lines until the block is closed with `end`.

Supported block starters include `if`, `while`, `for`, `foreach`, `loop`, `function`, `def`, `class`, and `try`.

## REPL commands

| Command | Purpose |
|---|---|
| `:help` | Show REPL help |
| `:history` | Show history entries |
| `:clear` | Clear the terminal and current REPL state |
| `:version` | Show the Lucy version |
| `:quit` | Exit Lucy |
| `:exit` | Exit Lucy |
| `Ctrl-D` | Exit when the line is empty |

## Interactive variables

Values defined during the session remain available to later commands:

```text
>>> name = "Lucy"
>>> version = VERSION
>>> print name + " " + version
```

Imported modules and functions also remain available throughout the session.

## Script arguments

When Lucy runs a file, command-line arguments are available through `ARGV` and `argv`:

```text
lucy app.lucy one two three
```

```lucy
print ARGV
```

The source filename itself is not included in `ARGV`.

## Terminal compatibility

The line editor uses native console input on Windows and raw terminal input on Unix-like systems. When standard input is redirected rather than attached to a terminal, Lucy automatically falls back to normal line-based input so scripts and pipelines remain usable.
