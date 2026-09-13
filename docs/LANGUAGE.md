# Lucy Language Guide

This file is the short language-oriented entry point. For the complete specification of the current interpreter, read [`REFERENCE.md`](REFERENCE.md).

## Quick syntax map

```lucy
# Variables
name = "Lucy"
count = 3

# Constants
const VERSION_NAME = "1.0.0"

# Conditions
if count > 0
    print "positive"
else
    print "zero or negative"
end

# Functions
def add(a, b = 0)
    return a + b
end

# Arrays
items = [1, 2, 3]
items.push 4

# Maps
user = {name: "Nima", age: 21}
print user.name

# Loops
for item in items
    print item
end

# Classes
class User
    def initialize(name)
        self.name = name
    end
end

user = User.new("Nima")

# Exceptions
try
    print user.name
catch Exception as error
    print error
finally
    print "done"
end

# Modules
import json
data = json.parse("{\"name\":\"Lucy\"}")
```

## Core types

```text
nil
bool
int
double
string
array
map
function
class
instance
```

## Core control flow

```text
if / else if / else / end
while / end
for / in / end
foreach / in / end
loop / end
break
continue
```

## Functions

```text
def name(parameters)
function name(parameters)
return value
name(arguments)
name positional, arguments
name(parameter: value)
def name(required, optional = value, *rest)
```

## Operators

```text
+ - * / % **
== != === !==
> >= < <=
and or not && || !
& | ^ ~ << >>
= += -= *= /= %= **= &= |= ^= <<= >>=
++ --
in
.. ...
? :
```

## Collections

Arrays are zero-based and mutable. Maps use string keys. Both support member methods documented in `REFERENCE.md`.

## Strings

Both `'single quotes'` and `"double quotes"` are supported. `$name` interpolation works in both.

## Modules

```lucy
import module
import module as alias
from module import name
from module import name, other
```

## Command-line arguments

```lucy
print ARGV
print argv
```

The source filename is not included in the array.

## Where to continue

- [`TUTORIAL.md`](TUTORIAL.md) — learn by building small programs.
- [`REFERENCE.md`](REFERENCE.md) — exact language semantics and every built-in.
- [`STDLIB.md`](STDLIB.md) — every standard-library module and public API.
- [`CLI.md`](CLI.md) — command-line and REPL behavior.
