// lexer.h

#ifndef LEXER_H
#define LEXER_H
#include <iostream>
#include <vector>
#include "tokenizer.h"

class Lexer
{
public:
    std::string source;
    int pos;
    std::vector<Token> tokenize();
};

#endif