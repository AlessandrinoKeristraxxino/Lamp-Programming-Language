#include <iostream>
#include <fstream>
#include "evaluator.cpp"

int main(int argc, char *argv[])
{
    std::ifstream file(argv[1]);
    std::string input((std::istreambuf_iterator<char>(file)), std::istreambuf_iterator<char>());
    auto tokens = lex(input);
    auto nodes = parse(tokens);
    evaluate(nodes);
}