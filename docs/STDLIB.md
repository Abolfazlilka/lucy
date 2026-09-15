# Lucy Standard Library Reference

**Version:** 1.0.0

Lucy 1.0.0 ships a small, cross-platform standard library. Public APIs are exposed as Lucy classes and module objects. Native C++ code is used only for low-level facilities such as filesystem access, regular expressions, process execution, HTTP transport, and SQLite.

## Importing

```lucy
import file
import json
import math

print math.square(5)
```

Aliases:

```lucy
import datetime as dt
print dt.now().year()
```

Selective imports:

```lucy
from math import square, cube
print square(5)
```

---

## `collections`

Object: `collections` (`Collections`)

| Method | Signature | Description |
|---|---|---|
| `first` | `first(items)` | First item or `nil`. |
| `last` | `last(items)` | Last item or `nil`. |
| `reverse` | `reverse(items)` | Returns a new reversed array. |
| `contains` | `contains(items, value)` | Tests membership. |
| `count` | `count(items, value)` | Counts equal values. |
| `index` | `index(items, value)` | Returns the first matching index or `nil`. |
| `compact` | `compact(items)` | Removes falsey values. |
| `unique` | `unique(items)` | Returns an array without duplicate values. |
| `flatten` | `flatten(items)` | Recursively flattens nested arrays. |
| `sum` | `sum(items)` | Adds numeric array elements. |
| `min` | `min(items)` | Smallest comparable value or `nil`. |
| `max` | `max(items)` | Largest comparable value or `nil`. |

---

## `csv`

Object: `csv` (`CSV`)

| Method | Signature | Description |
|---|---|---|
| `parse` | `parse(text, delimiter = ",")` | Parses CSV text into an array of rows. |
| `stringify` | `stringify(rows, delimiter = ",")` | Serializes rows as CSV text. |
| `load` | `load(path, delimiter = ",")` | Reads a file and parses it. |
| `dump` | `dump(path, rows, delimiter = ",")` | Serializes rows and writes the file. |

CSV supports quoted fields and escaped quotes through the native parser.

---

## `datetime`

Objects/classes: `datetime`, `DateTime`, `DateTimeModule`

Timestamps are Unix milliseconds.

### `datetime.now()`

Returns a `DateTime` for the current system time.

### `datetime.from_timestamp(milliseconds)`

Creates a `DateTime` from Unix milliseconds.

### `datetime.format(milliseconds, pattern)`

Formats a timestamp using the host C/C++ `strftime`-style pattern.

### `DateTime.initialize(timestamp)`

Stores the timestamp.

### `DateTime.timestamp()`

Returns the stored timestamp.

### `DateTime.format(pattern)`

Formats the stored timestamp.

### `DateTime.parts()`

Returns a map containing `year`, `month`, `day`, `hour`, `minute`, `second`, and `weekday`.

### Component methods

`year()`, `month()`, `day()`, `hour()`, `minute()`, `second()`, `weekday()` return individual components.

### `DateTime.iso()`

Returns a local-time ISO-like string in `YYYY-MM-DDTHH:MM:SS` format.

---

## `dir`

Object: `dir` (`Dir`)

| Method | Signature | Description |
|---|---|---|
| `pwd` | `pwd()` | Current working directory. |
| `chdir` | `chdir(path)` | Changes the working directory. |
| `exists` | `exists(path)` | Tests whether a directory exists. |
| `entries` | `entries(path)` | Lists directory entries. |
| `files` | `files(path)` | Lists files. |
| `dirs` | `dirs(path)` | Lists directories. |
| `glob` | `glob(pattern)` | Matches simple `*` and `?` patterns. |
| `walk` | `walk(path)` | Recursively lists entries. |
| `mkdir` | `mkdir(path, parents = true)` | Creates a directory. |
| `rmdir` | `rmdir(path)` | Removes a directory. |
| `empty` | `empty(path)` | Tests whether a directory is empty. |
| `copy` | `copy(source, destination)` | Copies a directory. |
| `file_count` | `file_count(path)` | Number of direct files. |
| `dir_count` | `dir_count(path)` | Number of direct directories. |
| `has` | `has(path, name)` | Tests whether a direct entry exists. |

---

## `encoding`

Object: `encoding` (`Encoding`)

| Method | Signature | Description |
|---|---|---|
| `base64_encode` | `base64_encode(text)` | Base64-encodes text. |
| `base64_decode` | `base64_decode(text)` | Decodes Base64 text. |
| `hex_encode` | `hex_encode(text)` | Converts bytes to hexadecimal. |
| `hex_decode` | `hex_decode(text)` | Converts hexadecimal to bytes/text. |
| `url_encode` | `url_encode(text)` | Percent-encodes a URL component. |
| `url_decode` | `url_decode(text)` | Decodes a URL component. |

---

## `file`

Object: `file` (`File`)

| Method | Signature | Description |
|---|---|---|
| `read` | `read(path)` | Reads an entire file. |
| `write` | `write(path, content)` | Replaces file contents. |
| `append` | `append(path, content)` | Appends text. |
| `read_lines` | `read_lines(path)` | Reads lines into an array. |
| `write_lines` | `write_lines(path, lines)` | Writes an array of lines. |
| `exists` | `exists(path)` | Tests whether a file exists. |
| `size` | `size(path)` | Returns file size. |
| `delete` | `delete(path)` | Deletes a file. |
| `copy` | `copy(source, destination)` | Copies a file. |
| `move` | `move(source, destination)` | Moves a file. |
| `touch` | `touch(path)` | Creates or updates a file. |
| `read_json` | `read_json(path)` | Reads and parses JSON. |
| `write_json` | `write_json(path, value)` | Serializes JSON and writes it. |
| `append_line` | `append_line(path, line)` | Appends a line and newline. |

---

## `http`

Object: `http` (`HTTP`)

| Method | Signature | Description |
|---|---|---|
| `get` | `get(url)` | Performs an HTTP GET request. |
| `post` | `post(url, body = "")` | Performs an HTTP POST request. |

The current implementation uses the host `curl` command/transport. HTTP APIs are intentionally small in 1.0.0; headers, cookies, streaming, and a server are not part of this release.

---

## `io`

Object: `io` (`IO`)

| Method | Signature | Description |
|---|---|---|
| `print` | `print(values)` | Prints a value followed by a newline. |
| `write` | `write(text)` | Writes text without adding a newline. |
| `read` | `read(prompt = "")` | Reads one line from standard input. |
| `ask` | `ask(prompt)` | Alias-style convenience wrapper for input. |

The global `print`, `puts`, and `input` builtins are also available.

---

## `json`

Object: `json` (`JSON`)

| Method | Signature | Description |
|---|---|---|
| `parse` | `parse(text)` | Parses JSON into Lucy values. |
| `stringify` | `stringify(value)` | Serializes a Lucy value as JSON. |
| `load` | `load(path)` | Reads and parses a JSON file. |
| `dump` | `dump(path, value)` | Serializes and writes a JSON file. |

JSON maps to Lucy `map`, arrays to `array`, strings to `string`, numbers to `int`/`double`, booleans to `bool`, and JSON `null` to `nil`.

---

## `math`

Object: `math` (`Math`)

| Method | Signature | Description |
|---|---|---|
| `square` | `square(x)` | `x * x`. |
| `cube` | `cube(x)` | `x * x * x`. |
| `clamp` | `clamp(x, low, high)` | Restricts a value to a range. |
| `even` | `even(x)` | Tests evenness. |
| `odd` | `odd(x)` | Tests oddness. |
| `abs` | `abs(x)` | Absolute value. |
| `sqrt` | `sqrt(x)` | Square root. |
| `pow` | `pow(x, y)` | Power operation. |
| `sin` | `sin(x)` | Sine. |
| `cos` | `cos(x)` | Cosine. |
| `tan` | `tan(x)` | Tangent. |
| `floor` | `floor(x)` | Floor. |
| `ceil` | `ceil(x)` | Ceiling. |
| `log` | `log(x)` | Natural logarithm. |
| `min` | `min(a, b)` | Smaller value. |
| `max` | `max(a, b)` | Larger value. |
| `factorial` | `factorial(n)` | Factorial of a non-negative integer. |
| `gcd` | `gcd(a, b)` | Greatest common divisor. |
| `lcm` | `lcm(a, b)` | Least common multiple. |
| `average` | `average(values)` | Numeric mean of an array. |

`PI` and `E` are global constants.

---

## `os`

Object: `os` (`OS`)

| Method | Signature | Description |
|---|---|---|
| `cwd` | `cwd()` | Current working directory. |
| `env` | `env(name)` | Reads an environment variable or returns `nil`. |
| `setenv` | `setenv(name, value)` | Sets an environment variable. |
| `unsetenv` | `unsetenv(name)` | Removes an environment variable. |
| `system` | `system(command)` | Runs a system command. |
| `pid` | `pid()` | Current process ID. |
| `cpu_count` | `cpu_count()` | Available CPU count. |
| `platform` | `platform()` | `windows`, `macos`, `linux`, or `unix`. |
| `version` | `version()` | Lucy version. |
| `home` | `home()` | User home directory. |
| `temp_dir` | `temp_dir()` | System temporary directory. |
| `command_exists` | `command_exists(command)` | Tests whether a command can be found. |
| `which` | `which(command)` | Alias-style wrapper around `command_exists`. |

---

## `path`

Object: `path` (`Path`)

| Method | Signature | Description |
|---|---|---|
| `join` | `join(parts)` | Joins path components using the host separator. |
| `absolute` | `absolute(path)` | Converts a path to an absolute path. |
| `expand` | `expand(path)` | Expands a leading `~`. |
| `basename` | `basename(path)` | Final path component. |
| `dirname` | `dirname(path)` | Parent directory. |
| `extname` | `extname(path)` | Extension including the dot. |
| `stem` | `stem(path)` | Filename without extension. |
| `join_all` | `join_all(first, second)` | Convenience two-part join. |
| `with_extension` | `with_extension(path, extension)` | Replaces a filename extension. |

---

## `process`

Object: `process` (`Process`)

| Method | Signature | Description |
|---|---|---|
| `run` | `run(command)` | Returns a map with `stdout`, `status`, and `success`. |
| `capture` | `capture(command)` | Returns stdout or raises `ProcessError` on failure. |
| `success` | `success(command)` | Returns whether the command exits successfully. |
| `output` | `output(command)` | Returns command stdout. |

---

## `random`

Object: `random` (`Random`)

| Method | Signature | Description |
|---|---|---|
| `integer` | `integer(low, high)` | Random integer in the inclusive range. |
| `choice` | `choice(items)` | Random item or `nil` for an empty array. |

---

## `regex`

Object: `regex` (`Regex`)

| Method | Signature | Description |
|---|---|---|
| `match` | `match(pattern, text)` | Tests whether the complete text matches. |
| `search` | `search(pattern, text)` | Tests whether a match occurs anywhere. |
| `find_all` | `find_all(pattern, text)` | Returns all matched strings. |
| `replace` | `replace(pattern, replacement, text)` | Replaces regex matches. |
| `contains` | `contains(pattern, text)` | Convenience wrapper around `search`. |

Patterns use the host C++ standard regular-expression engine.

---

## `sqlite`

Objects/classes: `sqlite` (`SQLite`), `Database`

| Method | Signature | Description |
|---|---|---|
| `sqlite.open` | `open(path)` | Opens/creates a SQLite database handle. |
| `Database.initialize` | `initialize(path)` | Stores the database path. |
| `Database.execute` | `execute(sql)` | Executes SQL and returns affected changes. |
| `Database.query` | `query(sql)` | Executes a query and returns rows as Lucy maps. |
| `Database.rows` | `rows(sql)` | Alias-style wrapper around `query`. |
| `Database.create_table` | `create_table(name, columns)` | Convenience `CREATE TABLE` operation. |
| `Database.insert` | `insert(table, columns, values)` | Convenience `INSERT` operation. |

SQLite support depends on whether the interpreter was built with SQLite available to CMake.

---

## `string`

Object: `string` (`StringTools`)

| Method | Signature | Description |
|---|---|---|
| `capitalize` | `capitalize(text)` | Uppercases the first character. |
| `upper` | `upper(text)` | Uppercase copy. |
| `lower` | `lower(text)` | Lowercase copy. |
| `trim` | `trim(text)` | Removes surrounding whitespace. |
| `reverse` | `reverse(text)` | Reversed copy. |
| `repeat` | `repeat(text, count)` | Repeats text. |
| `split` | `split(text, separator)` | Splits into an array. |
| `replace` | `replace(text, old_value, new_value)` | Replaces occurrences. |
| `contains` | `contains(text, value)` | Tests substring membership. |
| `starts_with` | `starts_with(text, value)` | Tests prefix. |
| `ends_with` | `ends_with(text, value)` | Tests suffix. |
| `length` | `length(text)` | Character/byte count for the current string representation. |
| `to_int` | `to_int(text)` | Converts numeric text to an integer. |
| `to_float` | `to_float(text)` | Converts numeric text to a double. |
| `lines` | `lines(text)` | Splits on newline characters. |
| `words` | `words(text)` | Trims and splits on spaces. |

### Native string methods

Lucy strings also expose: `upper`, `upcase`, `lower`, `downcase`, `strip`, `trim`, `contains`, `starts_with`, `ends_with`, `length`, `size`, `reverse`, `repeat`, `to_int`, `to_float`, `slice`, `char_at`, `split`, and `replace`.

`slice(start, end)` uses a start-inclusive/end-exclusive range.

---

## `sys`

Object: `sys` (`System`)

| Method | Signature | Description |
|---|---|---|
| `version` | `version()` | Lucy version. |
| `platform` | `platform()` | Host platform name. |
| `cwd` | `cwd()` | Current working directory. |
| `env` | `env(name)` | Environment variable lookup. |
| `argv` | `argv()` | Returns `ARGV`. |

---

## `time`

Object: `time` (`Clock`)

| Method | Signature | Description |
|---|---|---|
| `milliseconds` | `milliseconds()` | Monotonic milliseconds since the interpreter clock started. |
| `elapsed` | `elapsed(start)` | Difference between the current clock and a previous value. |

---

# Core collection methods

Arrays support the following methods directly:

`push`, `pop`, `shift`, `unshift`, `insert`, `remove_at`, `clear`, `first`, `last`, `contains`, `count`, `index`, `join`, `reverse`, `length`, `size`, `each`, `map`, `filter`, `any`, `all`.

Maps support:

`get`, `set`, `has`, `delete`, `keys`, `values`, `clear`.

Numbers support:

`abs`, `floor`, `ceil`, `round`, `sqrt`, `sin`, `cos`, `tan`, `log`, `to_int`, `to_string`, `pow`.

These are part of the language runtime rather than separate standard-library modules.
