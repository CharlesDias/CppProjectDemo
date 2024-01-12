#include <iostream>

#include "nlohmann/json.hpp"

#include "custom_lib/my_lib.h"

int main()
{
    print_configuration();

    std::cout << "\nJSON library version: "
              << NLOHMANN_JSON_VERSION_MAJOR << "."
              << NLOHMANN_JSON_VERSION_MINOR << "."
              << NLOHMANN_JSON_VERSION_PATCH << "\n";

    return 0;
}
