// parser.cpp

#include <iostream>
#include "include/lexer.h"
#include "include/parser.h"

std::vector<Node *> Parser::parse()
{
    std::vector<Node *> nodes;
    while (pos < tokens.size())
    {
        Node* parseVarDecl(NodeType type, Tokens literalType)
        {
            if (tokens[pos].type == IDENTIFIER)
            {
                std::string name = tokens[pos].value;
                pos++;
                if (tokens[pos].type == EQUALS)
                {
                    pos++;
                    if (tokens[pos].type == literalType)
                    {
                        std::string value = tokens[pos].value;
                        pos++;
                        if (tokens[pos].type == SEMICOLON)
                        {
                            Node *node = new Node();
                            node->type = nodeType;
                            node->name = name;
                            node->value = value;
                            return node;
                            pos++;
                        }
                        else
                        {
                            pos++;
                        }
                    }
                    else
                    {
                        pos++;
                    }
                }
            }
        }
        if (tokens[pos].type == INT)
        {
            pos++;
            if (tokens[pos].type == IDENTIFIER)
            {
                std::string name = tokens[pos].value;
                pos++;
                if (tokens[pos].type == EQUALS)
                {
                    pos++;
                    if (tokens[pos].type == INT_LITERAL)
                    {
                        std::string value = tokens[pos].value;
                        pos++;
                        if (tokens[pos].type == SEMICOLON)
                        {
                            Node *node = new Node();
                            node->type = INT_DECL;
                            node->name = name;
                            node->value = value;
                            nodes.push_back(node);
                            pos++;
                        }
                        else
                        {
                            pos++;
                        }
                    }
                    else
                    {
                        pos++;
                    }
                }
                else if (tokens[pos].type == LPAREN)
                {
                    pos++;
                    if (tokens[pos].type == RPAREN)
                    {
                        pos++;
                        if (tokens[pos].type == LBRACE)
                        {
                            Node *node = new Node;
                            node->type = FUNCTION_DECL;
                            node->name = name;
                            nodes.push_back(node);
                            while (tokens[pos].type != RBRACE)
                            {
                                pos++;
                            }
                            pos++;
                        }
                    }
                }
                else
                {
                    pos++;
                }
            }
            else
            {
                pos++;
            }
        }
        else if (tokens[pos].type == FLOAT)
        {
            pos++;
            if (tokens[pos].type == IDENTIFIER)
            {
                std::string name = tokens[pos].value;
                pos++;
                if (tokens[pos].type == EQUALS)
                {
                    pos++;
                    if (tokens[pos].type == FLOAT_LITERAL)
                    {
                        std::string value = tokens[pos].value;
                        pos++;
                        if (tokens[pos].type == SEMICOLON)
                        {
                            Node *node = new Node();
                            node->type = FLOAT_DECL;
                            node->name = name;
                            node->value = value;
                            nodes.push_back(node);
                            pos++;
                        }
                        else
                        {
                            pos++;
                        }
                    }
                    else
                    {
                        pos++;
                    }
                }
                else
                {
                    pos++;
                }
            }
            else
            {
                pos++;
            }
        }
        else if (tokens[pos].type == CHAR)
        {
            pos++;
            if (tokens[pos].type == IDENTIFIER)
            {
                std::string name = tokens[pos].value;
                pos++;
                if (tokens[pos].type == EQUALS)
                {
                    pos++;
                    if (tokens[pos].type == CHAR_LITERAL)
                    {
                        std::string value = tokens[pos].value;
                        pos++;
                        if (tokens[pos].type == SEMICOLON)
                        {
                            Node *node = new Node();
                            node->type = CHAR_DECL;
                            node->name = name;
                            node->value = value;
                            nodes.push_back(node);
                            pos++;
                        }
                        else
                        {
                            pos++;
                        }
                    }
                    else
                    {
                        pos++;
                    }
                }
                else
                {
                    pos++;
                }
            }
            else
            {
                pos++;
            }
        }
        else if (tokens[pos].type == STRING)
        {
            pos++;
            if (tokens[pos].type == IDENTIFIER)
            {
                std::string name = tokens[pos].value;
                pos++;
                if (tokens[pos].type == EQUALS)
                {
                    pos++;
                    if (tokens[pos].type == STRING_LITERAL)
                    {
                        std::string value = tokens[pos].value;
                        pos++;
                        if (tokens[pos].type == SEMICOLON)
                        {
                            Node *node = new Node();
                            node->type = STRING_DECL;
                            node->name = name;
                            node->value = value;
                            nodes.push_back(node);
                            pos++;
                        }
                        else
                        {
                            pos++;
                        }
                    }
                    else
                    {
                        pos++;
                    }
                }
                else
                {
                    pos++;
                }
            }
            else
            {
                pos++;
            }
        }
        else
        {
            pos++;
        }
    }
    return nodes;
}