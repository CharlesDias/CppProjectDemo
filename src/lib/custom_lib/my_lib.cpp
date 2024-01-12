#include <iostream>

#include "spdlog/spdlog.h"

#include "custom_lib/my_lib.h"
#include "configuration/config.h"

void print_configuration()
{
    spdlog::info("Project name:    {}", configuration::project_name);
    spdlog::info("Project version: {}", configuration::project_version);
}

int addition(int a, int b)
{
    return a + b;
}

int subtraction(int a, int b)
{
    return a - b;
}
