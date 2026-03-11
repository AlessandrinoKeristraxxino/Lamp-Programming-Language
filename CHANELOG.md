## [0.1.0-alpha] - 2026-03-09

### Added

- `tokenizer.h`: `Tokens` enum with all language token types
- `tokenizer.h`: `Token` struct with `type` and `value` fields
- `lexer.h`: `Lexer` class declaration
- `lexer.cpp`: lexer implementation with support for:
  - Whitespace (spaces, tabs, newlines)
  - Simple characters (`(`, `)`, `{`, `}`, `<`, `>`, `*`, `/`, `,`, `;`)
  - Double operators (`==`, `=>`, `++`, `--`, `||`, `&&`, `::`)
  - Integer and float numbers
  - Double-quoted strings
  - Keywords (`int`, `float`, `string`, `char`, `const`, `if`, `else`, `for`, `while`, `return`, `sys`)
  - Identifiers
  - `//` comments
  - Error handling with red terminal output
- `README.md`: first version with description, features, syntax preview and project structure


## [0.2.0-alpha] - 2026-03-10

### Added
- `parser.h`: `NodeType` enum with types `INT_DECL`, `STRING_DECL`, `CONST_DECL`, `FLOAT_DECL`, `CHAR_DECL`, `BINARY_OPERATOR`, `IF_STMT`, `ELSE_IF_STMT`, `ELSE_STMT`, `DPO`, `PFO`, `ENDL`, `FUNCTION_DECL`, `RETURN`, `FOR`, `WHILE`
- `parser.h`: `Node` struct with fields `type`, `left`, `op`, `right`, `name`, `value`, `condition_left`, `condition_right`, `body`
- `parser.h`: `Parser` class with `pos`, `source`, `tokens` and `parse()` method
- `parser.cpp`: `parse()` implementation with support for:
  - Integer variable declaration (`int x = 10;`)
  - Integer function declaration (`int main() { ... }`)
  - Syntax error handling with automatic advancement