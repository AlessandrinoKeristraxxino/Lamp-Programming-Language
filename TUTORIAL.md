# Official Guide — Lamp v1.0.0

## *From the basics to advanced concepts — An introduction to the language*

![version](https://img.shields.io/badge/version-1.0.0-blue?style=flat-square) ![language](https://img.shields.io/badge/language-C%2B%2B-00599C?style=flat-square&logo=c%2B%2B&logoColor=white) ![license](https://img.shields.io/badge/license-MIT-green?style=flat-square) ![status](https://img.shields.io/badge/status-In%20Development-orange?style=flat-square) ![platform](https://img.shields.io/badge/platform-Linux%20%7C%20Windows%20%7C%20macOS-lightgrey?style=flat-square) ![build](https://img.shields.io/badge/build-passing-brightgreen?style=flat-square) ![contributors](https://img.shields.io/badge/contributors-1-blueviolet?style=flat-square) ![last commit](https://img.shields.io/badge/last%20commit-March%202026-informational?style=flat-square) ![open issues](https://img.shields.io/badge/open%20issues-0-success?style=flat-square)

---

## 1. Overview

**Lamp** is a modern imperative programming language designed for terminal environments and abstract computation. Written in **C++**, it draws structural inspiration from the C family: the `#include` directive system, the `::` member-access operator, typed variable declarations, and the `int main(void)` function convention are all present. What distinguishes Lamp is its **explicit runtime model** — programs are mandatory compositions of files with defined roles, and the language provides a dedicated library system to manage their interaction at launch time.

Lamp was created in **March 2026** by **Alessandro Napoli**, a student at ITIS (Istituto Tecnico Industriale e per l'Informatica) in Sondrio, Lombardy. The language is currently in active development.

> *Lamp: Light for the future*

---

## 2. Project Architecture

Every Lamp program is composed of at minimum two files. This split is **not optional** — it is enforced by the language's runtime model.

**`main.lamp`** is the runtime entry point. Its sole responsibility is to locate and launch the application file. It must not contain application logic. It imports the runtime libraries, attempts to invoke the application's entry function, and provides a fallback mechanism in case that function is not found.

**`App.lamp`** is the application file. It contains the program's functions and logic. Its entry function is invoked by `main.lamp` at startup.

This separation enforces a clean boundary between initialization and execution — a deliberate design decision that becomes especially relevant in larger projects where the application file may grow significantly in complexity.

---

## 3. Hello, World

### 3.1 `main.lamp`

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

### 3.2 `App.lamp`

```lamp
#include <std.io>

int main(void)
{
    std::dpo << "Hello, World!";
}
```

---

## 4. Language Reference

### 4.1 Preprocessor Directives — `#include`

```lamp
#include <libraryName>
```

Imports a library or external file into the current scope. Must appear before any executable code, at the top of the file. Lamp ships with three standard libraries used in the Hello World example:

- **`std.io`** — standard input/output operations. Required whenever the program reads from or writes to the terminal.
- **`runCode`** — exposes the `runcode` module, which provides the ability to launch external `.lamp` files as sub-programs.
- **`filesLibrary`** — exposes `filelib`, a utility for programmatically inspecting and searching the contents of external files without prior knowledge of their structure.

---

### 4.2 Error Handling — `try / catch`

```lamp
try:
    // statement or block to attempt
catch (ErrorType):
    // fallback block executed if ErrorType is raised
```

Lamp's error handling follows a typed `try / catch` model. The `try` block executes its statement; if execution raises an error matching the type specified in `catch`, control transfers to the fallback block. Errors in Lamp are namespaced by their originating module — `runcode.noFunction` indicates that the `runcode` module could not find the specified function in the target file.

---

### 4.3 Inter-file Execution — `runcode::run<>`

```lamp
runcode::run<FileName.lamp<functionName>>;
```

The `runcode` library is responsible for launching external `.lamp` files. Its `run<>` method accepts two nested angle-bracket arguments: the name of the target file and the name of the function to invoke within it. The `::` operator is Lamp's standard member-access syntax, used consistently across all library calls.

If the specified function does not exist in the target file, `run<>` raises `runcode.noFunction`, which can be caught with a `catch` block as shown in `main.lamp`.

---

### 4.4 File Inspection — `filelib::search()`

```lamp
filelib::search(
    source: "filename.lamp",
    search: filelib::search.firstFunction(
        name: <namePattern>,
        inBrackets: <bracketPattern>
    );
);
```

`filelib` provides utilities for inspecting external files at runtime. Its `search()` method takes two named parameters: `source`, which specifies the file to scan, and a nested `search`, which defines the pattern to match within it.

`search.firstFunction()` locates the first function in the target file that satisfies both criteria simultaneously. It is a method of `filelib`, and therefore must be called through it. The two parameters that define the match are:

**`name`** — the expected pattern for the function's identifier:

| Value | Description |
| ------- | ------------- |
| `string` | Alphabetic name only |
| `number` | Numeric name only |
| `string && number` | Alphanumeric name |
| `??` | Any name (wildcard) |
| `"main"` | Exact match — substitute with the target function name |

**`inBrackets`** — the expected content of the function's parameter list `()`:

| Value | Description |
| ------- | ------------- |
| `string` | A string-type parameter |
| `??` | Any content (wildcard) |
| `none` | Empty parameter list |
| `"void"` | Exact match — substitute with the expected content |

---

### 4.5 String Variables — `string`

```lamp
string variableName = value;
```

`string` declares a string variable. When used to capture the return value of `filelib::search`, the variable holds a reference to the matched construct, which the runtime can subsequently use as an execution target. Lamp resolves this reference at runtime, not at compile time.

---

### 4.6 Function Declaration — `int`

```lamp
int functionName(parameters)
{
    // body
}
```

In Lamp, `int` serves a dual purpose. In an expression context, it declares an integer variable. When followed by an identifier and a parenthesis pair, it declares a **function** — a convention inherited directly from C. The function body is enclosed in curly braces.

`void` inside the parentheses indicates that the function accepts no parameters, consistent with standard C semantics. A function declared with `int` is expected to return an integer value upon completion; `void` refers strictly to the parameter list, not the return type.

---

### 4.7 Standard Output — `std::dpo`

```lamp
std::dpo << "text to print";
```

`dpo` stands for *default print out* and is the primary output method provided by `std.io`. It is accessed through the standard library using the `::` member-access operator. The `<<` stream operator directs the string value to stdout. Output is sent to the terminal's standard output stream and is not buffered by default.

To print the value of a variable alongside a string, the `<<` operator can be chained:

```lamp
int x = 10;
std::dpo << "value: " << x << !"\n";
```

The `!"\n"` token forces a newline character at the end of the output. Unlike `std::lpo`, `dpo` does not append a newline automatically.

---

### 4.8 Line Output — `std::lpo`

```lamp
std::lpo << "text to print";
```

`lpo` stands for *line print out* and is the second output method provided by `std.io`. Its syntax and access pattern are identical to `std::dpo` — it is accessed via `std::` and uses the `<<` stream operator — with one behavioural distinction: `lpo` appends a newline character automatically at the end of every output, eliminating the need for an explicit `\n`.

To print a variable value alongside a string:

```lamp
int x = 10;
std::lpo << "value: " << x;
```

---

### 4.9 Formatted Output — `std::fpo`

```lamp
std::fpo << "format string with %specifiers" <<! var1, var2, var3;
```

`fpo` stands for *formatted print out* and is the third output method provided by `std.io`. It introduces a format-string mechanism: variables are not chained directly with `<<`, but are instead referenced within the string using **format specifiers** (e.g. `%d`, `%s`) and then supplied after the `<<!` operator as a comma-separated list. Variables must be listed in the same order they appear in the format string.

```lamp
int x = 10;
string y = "print";
char z = 'c';

std::fpo << "text to %s with variables: %d, %c" <<! y, x, z;
```

The `<<!` operator marks the boundary between the format string and the variable list. The supported format specifiers are:

| Specifier | Type |
| ----------- | ------ |
| `%d` / `%i` | Integer (`int`) |
| `%s` | String (`string`) |
| `%c` | Character (`char`) |
| `%f` | Floating-point (`float`) |
| `%lf` | Double-precision float (`double`) |
| `%l` | Long integer (`long`) |

---

## 5. Variable Declarations

Lamp is a statically typed language. Every variable must be declared with an explicit type before use. The following primitive types are available.

### 5.1 Integer — `int`

```lamp
int x = 10;
```

`int` (*integer*) stores whole numeric values within a 16-bit signed range (approximately −32,768 to 32,767). It is the most commonly used numeric type in Lamp for general-purpose integer arithmetic.

The `unsigned` modifier can be prepended to shift the range to 32-bit unsigned (0 to approximately 4,294,967,295), eliminating negative values in exchange for a larger positive range:

```lamp
unsigned int x = 70000;
```

---

### 5.2 Floating-point — `float`

```lamp
float x = 3.14;
```

`float` (*floating-point*) stores single-precision decimal numbers. It occupies 32 bits and provides approximately 7 significant decimal digits of precision. It is the appropriate choice when fractional values are required and memory efficiency is a priority over precision.

---

### 5.3 Double-precision — `double`

```lamp
double x = 3.141592653589;
```

`double` (*double-precision floating-point*) stores decimal numbers at 64-bit precision, providing approximately 15–16 significant decimal digits. It should be preferred over `float` whenever higher numerical accuracy is required, such as in scientific or financial computations.

---

### 5.4 Character — `char`

```lamp
char x = 'a';
```

`char` (*character*) stores a single character, enclosed in single quotes. Internally, it is represented as an 8-bit integer corresponding to the character's ASCII value. It is not interchangeable with `string`, which stores sequences of characters.

---

### 5.5 Long Integer — `long`

```lamp
long x = 9999999999;
```

`long` (*long integer*) stores whole numeric values at 64-bit signed precision, supporting a range of approximately −9.2 × 10¹⁸ to 9.2 × 10¹⁸. It is used when the value to be stored exceeds the capacity of `int`. As with `int`, the `unsigned` modifier is supported:

```lamp
unsigned long x = 18000000000;
```

---

### 5.6 String — `string`

```c
string x = "hello";
```

`string` stores a sequence of characters enclosed in double quotes. Unlike `char`, which holds a single character, `string` can hold text of arbitrary length. It is also used, as described in section 4.5, to capture references returned by `filelib::search` at runtime.

### 6.0 Void - `void`

```lamp
#include <std.io>

void hello(string name, string surname)
{
    if (surname)
    {
        std::fpo << "Hello, %s %s" <<! name, surname;
        break;
    } 
    std::fpo << "Hello, %s" <<! name;
}

int main()
{
    string name = "Alessandro";

    return 0;
}
```

`void` serve per dichiarare una funzione che non restituisce nulla, ma che esegue un blocco di codice

### 6.1 Static - `static`

```lamp
#include <std.io>

/* In Lamp, the 'static' keyword ensures that a variable 
   persists in memory throughout the entire program execution. 
*/

int plpl(int x, int y)
{
    x++;
    y++;
    return x, y;
}

int main()
{
    int x = 0;          // Automatic variable: reset/re-initialized
    static int y = 0;   // Static variable: persistent memory location

    plpl(x, y);
    // After first execution:
    // x = 0; (Automatic: local copy lost)
    // y = 1; (Static: value 1 is stored)

    plpl(x, y);
    // After second execution:
    // x = 0; (Automatic: starts from 0 again)
    // y = 2; (Static: starts from 1 and increments)
}
```

In the Lamp programming language, the `static` keyword modifies the storage duration of a variable without altering its scope.

#### Key Technical Concepts

- **Persistence:** Unlike a standard variable like `int x` (which is automatic and technically exists on the Stack), a `static int y` is stored in a dedicated Data Segment. It remains alive for the entire duration of the program's lifecycle.
- **Single Initialization:** The assignment `static int y = 0` is executed only once. During any subsequent passes or function calls, the system ignores the initialization line and retrieves the last value stored in that memory address.
- **Behavioral Logic:** In the provided code, while `x` is effectively "re-born" as $0$ every time the logic resets, `y` maintains its state. This allows `y` to "remember" it was $1$ after the first call, enabling it to increment to $2$ during the second call.

#### Summary Table

| Feature             | Automatic (`int x`)        | Static (`static int y`)       |
|---------------------|----------------------------|-------------------------------|
| Memory Location     | Stack                      | Data Segment                  |
| Lifetime            | Block Scope (Temporary)    | Program Duration (Permanent)  |
| Initialization      | Every time block is entered| Only once                     |
| Value Retention     | Lost after block exit      | Retained between calls        |

### Input dell'utente
