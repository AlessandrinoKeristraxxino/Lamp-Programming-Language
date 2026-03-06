#include <iostream>
#include <vector>
#include <map>
#include "parser.cpp"

void evaluate(std::vector<Node> nodes)
{
    std::map<std::string, std::string> environment;
    int i = 0;
    while (i < nodes.size())
    {
        Node n = nodes[i];
        if (n.type == VAR_DECL)
        {
            environment[n.name] = n.value;
            i++;
        }
        else if (n.type == PRINTLN)
        {
            if (environment.count(n.name) > 0)
                std::cout << environment[n.name] << std::endl;
            else
                std::cout << n.name << std::endl;
            i++;
        }
        else if (n.type == PRINT)
        {
            if (environment.count(n.name) > 0)
                std::cout << environment[n.name];
            else
                std::cout << n.name;
            i++;
        }
        else if (n.type == IF_STMT)
        {
            if (environment[n.condition_left] == n.condition_right)
            {
                for (Node body_node : n.body)
                {
                    if (body_node.type == PRINT)
                    {
                        if (environment.count(body_node.name) > 0)
                            std::cout << environment[body_node.name];
                        else
                            std::cout << body_node.name;
                    }
                    else if (body_node.type == PRINTLN)
                    {
                        if (environment.count(body_node.name) > 0)
                            std::cout << environment[body_node.name] << std::endl;
                        else
                            std::cout << body_node.name << std::endl;
                    }
                }
            }
            i++;
        }
        else
        {
            i++;
        }
    }
}