#include <iostream>
#include <fstream>

#include "spdlog/spdlog.h"
#include "nlohmann/json.hpp"

#include "custom_lib/my_lib.h"

using json = nlohmann::json;

void spdlog_demo();
void json_demo();

int main()
{
    print_configuration();

    spdlog_demo();
    json_demo();

    return 0;
}

void spdlog_demo(void)
{
    std::cout << "\n============================= spdlog Demo =============================\n" << std::endl;

    spdlog::info("Welcome to spdlog!");
    spdlog::error("Some error message with arg: {}", 1);

    spdlog::warn("Easy padding in numbers like {:08d}", 12);
    spdlog::critical("Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}", 42);
    spdlog::info("Support for floats {:03.2f}", 1.23456);
    spdlog::info("Positional args are {1} {0}..", "too", "supported");
    spdlog::info("{:<30}", "left aligned");

    spdlog::set_level(spdlog::level::debug); // Set global log level to debug
    spdlog::debug("This message should be displayed..");

    // change log pattern
    spdlog::set_pattern("[%H:%M:%S %z] [%n] [%^---%L---%$] [thread %t] %v");

    spdlog::info("Welcome to spdlog!");
    spdlog::error("Some error message with arg: {}", 1);
    spdlog::debug("This message should be displayed..");
}

void json_demo(void)
{
    std::cout << "\n============================= JSON Demo =============================" << std::endl;

    std::cout << "\nJSON library version: "
            << NLOHMANN_JSON_VERSION_MAJOR << "."
            << NLOHMANN_JSON_VERSION_MINOR << "."
            << NLOHMANN_JSON_VERSION_PATCH << "\n\n";

    nlohmann::json j;
    j["pi"] = 3.141;
    j["happy"] = true;
    j["name"] = "Niels";
    j["nothing"] = nullptr;
    j["answer"]["everything"] = 42;
    j["list"] = { 1, 0, 2 };
    j["object"] = { {"currency", "USD"}, {"value", 42.99} };

    std::cout << j << std::endl << std::endl;

    // Load the JSON file
    std::ifstream file("sensor_data/sensor_data.json");
    json jsonData;
    file >> jsonData;

    // Process the JSON data
    std::string sensorId = jsonData["sensor_id"];
    std::cout << "Sensor ID: " << sensorId << std::endl;

    for (auto& reading : jsonData["readings"]) {
        std::string timestamp = reading["timestamp"];
        double temperature = reading["temperature_celsius"];
        double humidity = reading["humidity_percentage"];

        std::cout << "Timestamp: " << timestamp
                  << ", Temperature: " << temperature
                  << " Celsius, Humidity: " << humidity
                  << "%" << std::endl;
    }
}
