#include <iostream>
#include <vector>
#include <string>
#include "lexer.cpp"

// parser.cpp

enum NodeType
{
    VAR_DECL,
    BINARY_OP,
    PRINT,
    PRINTLN,
    IF_STMT
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
    std::vector<Node> body;
};

std::vector<Node> parse(std::vector<Token> tokens)
{
    std::vector<Node> nodes;
    int i = 0;
    while (i < tokens.size())
    {
        Token t = tokens[i];
        // var
        if (t.type == VAR)
        {
            Node n;
            n.type = VAR_DECL;
            n.name = tokens[i + 1].value;
            n.value = tokens[i + 3].value;
            i += 4;
            nodes.push_back(n);
            if (tokens[i].type != SEMICOLON)
            {
                std::cerr << "\033[31m" << "ERROR: missing ';'" << "\033[0m" << std::endl;
                return nodes;
            }
            else
            {
                i++;
            }
        }
        // print
        else if (t.type == IDENTIFIER && t.value == "print" && tokens[i + 1].type == LPAREN)
        {
            Node p;
            p.type = PRINT;
            p.name = tokens[i + 2].value;
            p.value = tokens[i + 3].value;
            nodes.push_back(p);
            i += 4;
            if (tokens[i].type != SEMICOLON)
            {
                std::cerr << "\033[31m" << "ERROR: missing ';'" << "\033[0m" << std::endl;
                return nodes;
            }
            else
            {
                i++;
            }
        }
        // println
        else if (t.type == IDENTIFIER && t.value == "println" && tokens[i + 1].type == LPAREN)
        {
            Node pl;
            pl.type = PRINTLN;
            pl.name = tokens[i + 2].value;
            pl.value = tokens[i + 3].value;
            nodes.push_back(pl);
            i += 4;
            if (tokens[i].type != SEMICOLON)
            {
                std::cerr << "\033[31m" << "ERROR: missing ';'" << "\033[0m" << std::endl;
                return nodes;
            }
            else
            {
                i++;
            }
        }
        else if (t.type == IF && t.value == "if" && tokens[i + 1].type == LPAREN)
        {
            Node n;
            n.type = IF_STMT;
            n.condition_left = tokens[i + 2].value;
            n.condition_right = tokens[i + 4].value;
            i += 7;
            while (tokens[i].type != RBRACE)
            {
                if (tokens[i].type == IDENTIFIER && tokens[i + 1].type == LPAREN)
                {
                    Node body_node;
                    body_node.type = tokens[i].value == "println" ? PRINTLN : PRINT;
                    body_node.name = tokens[i + 2].value;
                    n.body.push_back(body_node);
                    i += 4;
                    if (tokens[i].type == SEMICOLON)
                        i++;
                }
                else
                {
                    i++;
                }
            }
            i++;                             // salta }
            nodes.push_back(n);              // aggiunto
            if (tokens[i].type != SEMICOLON) // aggiunto
            {
                std::cerr << "\033[31m" << "ERROR: missing ';'" << "\033[0m" << std::endl;
                return nodes;
            }
            else
            {
                i++;
            }
        }
        else
        {
            i += 1;
        }
    }
    return nodes;
}