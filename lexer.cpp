#include <iostream>
#include <vector>
#include <string>

enum Tokens
{
    NUMBER,
    EQUALS,
    PLUS,
    VAR,
    END,
    IDENTIFIER,
    LPAREN,
    RPAREN,
    STRING,
    SEMICOLON,
    IF,
    ELIF,
    ELSE,
    LBRACE,
    RBRACE,
    EQEQ
};

struct Token
{
    Tokens type;
    std::string value;
};

std::vector<Token> lex(std::string input)
{
    std::vector<Token> tokens;
    int i = 0;
    while (i < input.size())
    {
        char c = input[i];
        if (c == '=')
        {
            if (input[i + 1] == '=')
            {
                tokens.push_back({EQEQ, "=="});
                i += 2;
                continue;
            }
            else
            {
                tokens.push_back({EQUALS, "="});
            }
        }
        else if (c == '+')
        {
            tokens.push_back({PLUS, "+"});
        }
        else if (c == '(')
        {
            tokens.push_back({LPAREN, "("});
        }
        else if (c == ')')
        {
            tokens.push_back({RPAREN, ")"});
        }
        else if (c == '"')
        {
            std::string str;
            i++;
            while (input[i] != '"')
            {
                if (input[i] == '\\' && input[i + 1] == 'n')
                {
                    str += '\n';
                    i += 2;
                    continue;
                }
                str += input[i];
                i++;
            }
            i++;
            tokens.push_back({STRING, str});
            continue;
        }
        else if (isdigit(c))
        {
            std::string num;
            while (i < input.size() && isdigit(input[i]))
            {
                num += input[i];
                i++;
            }
            tokens.push_back({NUMBER, num});
            continue;
        }
        else if (isalpha(c))
        {
            std::string word;
            while (i < input.size() && isalpha(input[i]))
            {
                word += input[i];
                i++;
            }
            if (word == "var")
            {
                tokens.push_back({VAR, word});
            }
            else if (word == "if")
            {
                tokens.push_back({IF, word});
            }
            else if (word == "elif")
            {
                tokens.push_back({ELIF, word});
            }
            else if (word == "else")
            {
                tokens.push_back({ELSE, word});
            }
            else
            {
                tokens.push_back({IDENTIFIER, word});
            }
            continue;
        }
        else if (c == ' ')
        {
        }
        else if (c == ';')
        {
            tokens.push_back({SEMICOLON, ";"});
        }
        else if (c == '{')
        {
            tokens.push_back({LBRACE, "{"});
        }
        else if (c == '}')
        {
            tokens.push_back({RBRACE, "}"});
        }
        i++;
    }
    return tokens;
}