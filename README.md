# Lamp v1.0.0

> *Lamp: Light for the future*

![version](https://img.shields.io/badge/version-1.0.0-blue?style=flat-square)
![language](https://img.shields.io/badge/language-C%2B%2B17-00599C?style=flat-square&logo=c%2B%2B)
![license](https://img.shields.io/badge/license-MIT-green?style=flat-square)
![status](https://img.shields.io/badge/status-In%20Development-orange?style=flat-square)
![platform](https://img.shields.io/badge/platform-Linux%20%7C%20Windows%20%7C%20macOS-lightgrey?style=flat-square)
![build](https://img.shields.io/badge/build-passing-brightgreen?style=flat-square)

Lamp is a modern imperative programming language designed for terminal environments. Written in C++17, it features an explicit two-file runtime model, a clean type system, and a built-in library for inter-file execution and inspection.

Created in **March 2026** by **Alessandro Napoli**, student at ITIS Sondrio.

---

## Quick Start

### Build from source

```bash
git clone https://github.com/your-username/lamp.git
cd lamp
make
```

### Run a program

```bash
./lamp examples/hello_world/App.lamp
```

### Install system-wide (Linux/macOS)

```bash
sudo make install
# lamp is now available as a command
lamp myprogram.lamp
```

---

## Hello, World

Every Lamp program consists of at least two files.

**`App.lamp`**

```lamp
#include <std.io>

int main(void)
{
    std::lpo << "Hello, World!";
}
```

**`main.lamp`** (runtime launcher)

```lamp
#include <std.io>
#include <runCode>
#include <filesLibrary>

try:
    runcode::run<App.lamp<main>>;
catch (runcode.noFunction):
    string main = filelib::search(
        source: "App.lamp",
        search: filelib::search.firstFunction(
            name: ??,
            inBrackets: "void"
        );
    );
```

---

## Language Features

| Feature | Syntax |
| --- | --- |
| Standard output (line) | `std::lpo << "text";` |
| Standard output (no newline) | `std::dpo << "text";` |
| Formatted output | `std::fpo << "Hello %s" <<! name;` |
| Variable declaration | `int x = 10;` |
| Function declaration | `int add(int a, int b) { return a + b; }` |
| Conditionals | `if (x > 0) { ... } else { ... }` |
| Loops | `while (x < 10) { ... }` |
| Error handling | `try: ... catch (ErrorType): ...` |
| Inter-file execution | `runcode::run<File.lamp<func>>;` |
| File inspection | `filelib::search(source: "F.lamp", search: ...);` |

### Primitive types

| Type | Description |
| --- | --- |
| `int` | 16-bit signed integer |
| `unsigned int` | 32-bit unsigned integer |
| `float` | 32-bit floating point |
| `double` | 64-bit floating point |
| `char` | Single character |
| `string` | Character sequence |
| `long` | 64-bit signed integer |
| `void` | No return value |
| `static` | Persistent variable modifier |

---

## Project Structure

```shell
lamp/
├── src/
│   ├── lexer/          # Tokenizer
│   ├── parser/         # AST builder
│   ├── interpreter/    # Tree-walk interpreter
│   └── main.cpp        # Entry point
├── include/            # Shared headers (token.h, ast.h)
├── examples/
│   └── hello_world/    # hello_world example
├── Makefile
└── TUTORIAL.md
```

---

## License

MIT — see [LICENSE](LICENSE)
