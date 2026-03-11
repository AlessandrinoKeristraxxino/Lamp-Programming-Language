// lexer.cpp

#include <iostream>
#include <vector>
#include "tokenizer.h"
#include "lexer.h"

std::vector<Token> Lexer::tokenize()
{
    std::vector<Token> token;
    while (pos < source.length())
    {
        char c = source[pos];
        // simple tokens
        if (c == ' ' || c == '\n' || c == '\t')
        {
            pos++;
        }
        else if (c == '(')
        {
            token.push_back({LPAREN, "("});
            pos++;
        }
        else if (c == ')')
        {
            token.push_back({RPAREN, ")"});
            pos++;
        }
        else if (c == '{')
        {
            token.push_back({LBRACE, "{"});
            pos++;
        }
        else if (c == '}')
        {
            token.push_back({RBRACE, "}"});
            pos++;
        }
        else if (c == '<')
        {
            token.push_back({LESS_THAN, "<"});
            pos++;
        }
        // EQ_GREATER_THAN
        else if (c == '=' && source[pos + 1] == '>')
        {
            token.push_back({EQ_GREATER_THAN, "=>"});
            pos += 2;
        }
        else if (c == '>')
        {
            token.push_back({GREATER_THAN, ">"});
            pos++;
        }
        else if (c == '*')
        {
            token.push_back({MULT, "*"});
            pos++;
        }
        else if (c == '/')
        {
            token.push_back({DIV, "/"});
            pos++;
        }
        else if (c == ',')
        {
            token.push_back({COMMA, ","});
            pos++;
        }
        else if (c == ';')
        {
            token.push_back({SEMICOLON, ";"});
            pos++;
        }
        else if (c == ':' && source[pos + 1] == ':')
        {
            token.push_back({COLON, "::"});
            pos += 2;
        }
        // OR and AND
        else if (c == '|' && source[pos + 1] == '|')
        {
            token.push_back({OR, "||"});
            pos += 2;
        }
        else if (c == '&' && source[pos + 1] == '&')
        {
            token.push_back({AND, "&&"});
            pos += 2;
        }
        // EQEQ and EQUALS
        else if (c == '=' && source[pos + 1] == '=')
        {
            token.push_back({EQEQ, "=="});
            pos += 2;
        }
        else if (c == '=')
        {
            token.push_back({EQUALS, "="});
            pos++;
        }
        // PLUS and PLPL
        else if (c == '+' && source[pos + 1] == '+')
        {
            token.push_back({PLPL, "++"});
            pos += 2;
        }
        else if (c == '+')
        {
            token.push_back({PLUS, "+"});
            pos++;
        }
        // MINUS and MIMI
        else if (c == '-' && source[pos + 1] == '-')
        {
            token.push_back({MIMI, "--"});
            pos += 2;
        }
        else if (c == '-')
        {
            token.push_back({MINUS, "-"});
            pos++;
        }
        // controlla se cifra
        else if (isdigit(c))
        {
            std::string num;
            while (isdigit(c) || c == '.')
            {
                num.push_back(c);
                pos++;
                c = source[pos];
            }
            if (num.find('.') != std::string::npos)
            {
                token.push_back({FLOAT_LITERAL, num});
            }
            else
            {
                token.push_back({INT_LITERAL, num});
            }
        }
        else if (isalpha(c))
        {
            std::string str;
            while (isalpha(c))
            {
                str.push_back(c);
                pos++;
                c = source[pos];
            }
            if (str == "int")
            {
                token.push_back({INT, str});
            }
            else if (str == "string")
            {
                token.push_back({STRING, str});
            }
            else if (str == "float")
            {
                token.push_back({FLOAT, str});
            }
            else if (str == "else")
            {
                token.push_back({ELSE, str});
            }
            else if (str == "char")
            {
                token.push_back({CHAR, str});
            }
            else if (str == "return")
            {
                token.push_back({RETURN, str});
            }
            else if (str == "for")
            {
                token.push_back({FOR, str});
            }
            else if (str == "const")
            {
                token.push_back({CONST, str});
            }
            else if (str == "while")
            {
                token.push_back({WHILE, str});
            }
            else if (str == "if")
            {
                token.push_back({IF, str});
            }
            else if (str == "sys")
            {
                token.push_back({SYS, str});
            }
            else
            {
                token.push_back({IDENTIFIER, str});
            }
        }
        else if (c == '"')
        {
            std::string str;
            pos++;
            c = source[pos];
            while (c != '"')
            {
                str.push_back(c);
                pos++;
                c = source[pos];
            }
            token.push_back({STRING_LITERAL, str});
            pos++;
        }
        else if (c == '\'')
        {
            std::string chr;
            pos++;
            c = source[pos];
            while (c != '\'')
            {
                chr.push_back(c);
                pos++;
                c = source[pos];
            }
            token.push_back({CHAR_LITERAL, chr});
            pos++;
        }
        else if (c == '/' && source[pos + 1] == '/')
        {
            while (c != '\n')
            {
                pos++;
                c = source[pos];
            }
        }
        else
        {
            std::cout << "\033[31m" << "ERROR: carattere non riconosciuto: " << c << "\033[0m" << std::endl;
            pos++;
        }
    }
    return token;
}