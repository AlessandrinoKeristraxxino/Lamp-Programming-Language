// tokenizer.h

#ifndef TOKENIZER_H
#define TOKENIZER_H
#include <iostream>

enum Tokens
{
    DPO,
    ENDL,
    INCLUDE,
    CHARP,
    SYS,
    IF,
    ELSE,
    ELIF,
    INT,
    FLOAT,
    STRING,
    CHAR,
    CONST,
    LPAREN,
    RPAREN,
    LBRACE,
    RBRACE,
    FOR,
    WHILE,
    RETURN,
    IDENTIFIER,
    INT_LITERAL,
    FLOAT_LITERAL,
    CHAR_LITERAL,
    STRING_LITERAL,
    EQUALS,
    PLUS,
    MINUS,
    MULT,
    DIV,
    EQEQ,
    PLPL,
    MIMI,
    SEMICOLON,
    COMMA,
    COLON,
    LESS_THAN,
    GREATER_THAN,
    OR,
    AND,
    EQ_GREATER_THAN,
    END_OF_FILE,
};

struct Token
{
    Tokens type;
    std::string value;
};

#endif