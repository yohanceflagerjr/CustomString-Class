# Custom String Class — C++ Implementation

A college project reimplementing C++'s `std::string` class from scratch using dynamic memory allocation and raw character pointers. Built in C++.

> **Status:** Core functionality complete. Some known bugs exist — see [Known Issues](#known-issues) below.

---

## About

This project involved building a fully custom `String` class in C++ without using the standard library's `std::string`. The goal was to demonstrate a deep understanding of dynamic memory management, pointer arithmetic, copy semantics, and operator overloading.

---

## Features

### Constructors
| Constructor | Description |
|---|---|
| `String()` | Default — initializes to `nullptr` |
| `String(const char*)` | Constructs from a C-string |
| `String(const String&)` | Copy constructor |
| `String(char, int)` | Fills with `n` copies of a character |
| `String(String&, int, int)` | Constructs a substring from another String |

### Member Functions
| Function | Description |
|---|---|
| `append(int, char)` | Appends `n` copies of a character |
| `append(const String&)` | Appends another String |
| `append(const String&, int)` | Appends first `n` characters of another String |
| `append(const String&, int, int)` | Appends `n` characters starting at a position |
| `assign(...)` | Multiple overloads for assigning data |
| `at(int)` | Returns character at given position |
| `clear()` | Clears and frees memory |
| `compare(const String&)` | Compares two Strings, returns 0 if equal |
| `compare(int, int, const String&)` | Compares a substring |
| `empty()` | Returns `true` if String is empty |
| `front()` | Returns the first character |
| `find(char, int)` | Finds position of a character |
| `find(const char*, int)` | Finds position of a C-string |
| `find(String&, int)` | Finds position of another String |
| `insert(int, int, char)` | Inserts `n` copies of a character at position |
| `insert(int, const char*)` | Inserts a C-string at position |
| `palindrome()` | Checks if the full String is a palindrome |
| `palindrome(int, int)` | Checks if a substring is a palindrome |
| `projection(char)` | Removes all instances of a character |
| `projection(const String&)` | Removes all characters found in another String |
| `length()` | Returns the length |
| `reverse()` | Reverses the String, preserving original letter casing at each position |
| `size()` | Returns the size (same as `length`) |
| `substr(int, int)` | Returns a C-string copy of a substring |

### Overloaded Operators
| Operator | Description |
|---|---|
| `=` | Assignment |
| `+` | Concatenation |
| `-` | Removes all occurrences of right-hand String from left |
| `+=` | Append and assign |
| `<<` | Output to stream |
| `>>` | Input from stream |

---

## Example Usage

```cpp
String greeting("Hello");
String name(" World");

// Concatenation
String full = greeting + name;  // "Hello World"
cout << full;

// Append
greeting.append(3, '!');        // "Hello!!!"
cout << greeting;

// Reverse (preserves casing positions)
String word("Fla.ger");
cout << word.reverse();         // "Reg.Alf"

// Palindrome check
String pal("racecar");
cout << pal.palindrome();       // 1 (true)

// Projection (removal)
String str("AABBCCDD");
cout << str.projection('B');    // "AACCDD"

// Find
String sentence("Hello World");
cout << sentence.find("World", 0);  // 6
```

---

## Known Issues

This was a college project and has a few bugs that were identified after submission:

- `at()` uses an uninitialized `size` variable before the loop that sets it
- Some `for` loops redeclare their counter mid-function (e.g. `for(int count; ...)`) which resets the counter unexpectedly
- `operator+=` has an uninitialized loop counter in the second loop
- `insert(int, int, char)` declares `temp` as a null pointer and attempts to write to it, which would cause a crash

These are documented here for transparency and would be the first things addressed in a future revision.

---

## Building

This is a single-file project:

```bash
g++ -o string_class newString.cpp
./string_class
```

---

## License

Provided as-is for educational and portfolio purposes.