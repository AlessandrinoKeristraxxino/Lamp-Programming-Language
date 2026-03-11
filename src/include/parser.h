// parser.h

#ifndef PARSER_H
#define PARSER_H
#include <iostream>
#include <vector>
#include "lexer.h"

enum NodeType
{
    INT_DECL,
    STRING_DECL,
    CONST_DECL,
    FLOAT_DECL,
    CHAR_DECL,
    BINARY_OPERATOR,
    IF_STMT,
    ELSE_IF_STMT,
    ELSE_STMT,
    DPO,
    PFO,
    ENDL,
    FUNCTION_DECL,
    RETURN,
    FOR,
    WHILE
};

struct Node
{
    NodeType type;

    std::string left;
    std::string op;
    std::string right;
    std::string name;
    std::string value;
    std::string condition_left;
    std::string condition_right;
    std::vector<Node *> body;
};

class Parser
{
public:
    int pos;
    std::string source;
    std::vector<Token> tokens;
    std::vector<Node*> parse();
    Node* parseVarDecl(NodeType type, Tokens literalType);
};

#endif