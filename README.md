# LAMP
**Light for the future**

LAMP is a modern, interpreted programming language built from scratch in C++. Designed to be expressive, readable, and powerful, LAMP brings a clean and intuitive syntax to systems-level thinking.

> LAMP is currently in early alpha. Expect things to change rapidly and often.

<p align="left">
  <a href="https://github.com/AlessandrinoKeristrtaxxino/lamp/actions/workflows/build.yml">
    <img src="https://github.com/AlessandrinoKeristrtaxxino/lamp/actions/workflows/build.yml/badge.svg" alt="Build">
  </a>
  <img src="https://img.shields.io/badge/license-MIT-blue.svg" alt="License">
  <img src="https://img.shields.io/badge/version-0.2.0--alpha-orange.svg" alt="Version">
  <img src="https://img.shields.io/badge/language-C%2B%2B17-blue.svg" alt="C++17">
</p>

---

## Features

| Feature | Status |
|--------|--------|
| Variables (`int`, `float`, `string`, `char`, `const`) | 🔨 In progress |
| Print output (`sys::dpo`) | 📅 Planned |
| Formatted print (`sys::pfo`) | 📅 Planned |
| Conditionals (`if`, `else if`, `else`) | 📅 Planned |
| Loops (`for`, `while`) | 📅 Planned |
| Functions (standard + arrow `=>`) | 📅 Planned |
| Error handling (`try`, `catch`) | 📅 Planned |
| Terminal User Interface (TUI) | 📅 Planned |

---

## Syntax Preview

```lamp
#using <sys>

int main()
{
    // Hello, World!
    sys::dpo() >> "Hello, World!" >> sys::endl();

    // Variables
    int x = 10;
    string name = "Alessandro";
    float pi = 3.14;
    char c = 'a';
    const string language = "LAMP";

    // Conditions
    if (x == 10)
    {
        sys::dpo() << "x is ten!" << sys::endl();
    }
    else
    {
        sys::dpo() << "x is something else." << sys::endl();
    }

    // Loop
    for (int i = 0; i < 10; i++)
    {
        sys::dpo() << i << sys::endl();
    }

    // Arrow function
    int double = (x) => return x * 2;

    return 0;
}
```

---

## Project Structure

```
LAMP/
├── src/
│   ├── include/
│   │   ├── lexer.h
│   │   ├── parser.h
│   │   └── tokenizer.h
│   ├── assets/
│   │   └── images/
│   │       └── logo.png
│   ├── test/
│   │   └── test.lamp
│   ├── lexer.cpp
│   └── parser.cpp
├── .github/
│   └── workflows/
│       └── build.yml
├── .gitignore
├── CHANGELOG.md
├── CODE_OF_CONDUCT.md
├── CONTRIBUTING.md
├── LICENSE
├── Makefile
├── SECURITY.md
└── README.md
```

---

## Building from Source

### Requirements

- `g++` with C++17 or later
- `make`

### Steps

```bash
# Clone the repository
git clone https://github.com/AlessandrinoKeristrtaxxino/lamp.git
cd lamp

# Build
make

# Run a .lamp file
./lamp myfile.lamp

# Clean build
make clean
```

---

## Contributing

Contributions are welcome! Please read [CONTRIBUTING.md](CONTRIBUTING.md) before opening a pull request.

---

## Code of Conduct

This project follows a [Code of Conduct](CODE_OF_CONDUCT.md). Please read it before participating.

---

## Security

To report a vulnerability, please read [SECURITY.md](SECURITY.md) and follow the responsible disclosure process.

---

## License

This project is licensed under the MIT License. See [LICENSE](LICENSE) for details.