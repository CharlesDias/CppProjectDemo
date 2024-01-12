#include <iostream>

#include "custom_lib/my_lib.h"
#include "configuration/config.h"

void print_configuration()
{
    std::cout << "Project name: " << configuration::project_name << "\n";
    std::cout << "Project version: " << configuration::project_version << "\n";
}

int sum(int a, int b)
{
    return a + b;
}

int sub(int a, int b)
{
    return a - b;
}
