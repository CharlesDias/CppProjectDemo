#include <fstream>
#include <iostream>

#include "cxxopts.hpp"
#include "gtest_samples/sample1.h"
#include "nlohmann/json.hpp"
#include "spdlog/spdlog.h"

#include "custom_lib/my_lib.h"

using json = nlohmann::json;

/**
 * @brief Prints the version of the libraries used.
 */
void libraries_version();

/**
 * @brief Demonstrates the usage of the spdlog library.
 */
void spdlog_demo();

/**
 * @brief Demonstrates the usage of the JSON library.
 */
void json_demo();

/**
 * @brief Demonstrates the usage of the Google Test library.
 */
void gtest_samples();

/**
 * @brief Demonstrates the usage of the cxxopts library.
 */
void sanitizer_demo(void);

/**
 * @brief Demonstrates the usage of the cxxopts library.
 *
 * @param argc The number of command-line arguments.
 * @param argv The command-line arguments.
 */
void cxxopts_demo(int argc, char **argv);

/**
 * @brief The main function.
 *
 * @param argc The number of command-line arguments.
 * @param argv The command-line arguments.
 * @return int The exit code.
 */
int main(int argc, char **argv)
{
    print_configuration();

    libraries_version();
    spdlog_demo();
    json_demo();
    gtest_samples();
    sanitizer_demo();

    cxxopts_demo(argc, argv);

    return 0;
}

void libraries_version(void)
{
    std::cout << "\n============================= Libraries Version "
                 "=============================\n"
              << std::endl;
    std::cout << "CXXOPTS library version: " << CXXOPTS__VERSION_MAJOR << "."
              << CXXOPTS__VERSION_MINOR << "." << CXXOPTS__VERSION_PATCH
              << "\n";

    std::cout << "SPDLOG library version:  " << SPDLOG_VER_MAJOR << "."
              << SPDLOG_VER_MINOR << "." << SPDLOG_VER_PATCH << "\n";

    std::cout << "JSON library version:    " << NLOHMANN_JSON_VERSION_MAJOR
              << "." << NLOHMANN_JSON_VERSION_MINOR << "."
              << NLOHMANN_JSON_VERSION_PATCH << "\n";
}

void spdlog_demo(void)
{
    std::cout << "\n============================= spdlog Demo "
                 "=============================\n"
              << std::endl;

    spdlog::info("Welcome to spdlog!");
    spdlog::error("Some error message with arg: {}", 1);

    spdlog::warn("Easy padding in numbers like {:08d}", 12);
    spdlog::critical(
        "Support for int: {0:d};  hex: {0:x};  oct: {0:o}; bin: {0:b}",
        42);
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
    std::cout << "\n============================= JSON Demo "
                 "============================="
              << std::endl;

    nlohmann::json j;
    j["pi"] = 3.141;
    j["happy"] = true;
    j["name"] = "Niels";
    j["nothing"] = nullptr;
    j["answer"]["everything"] = 42;
    j["list"] = {1, 0, 2};
    j["object"] = {{"currency", "USD"}, {"value", 42.99}};

    std::cout << j << std::endl << std::endl;

    // Load the JSON file
    std::ifstream file("sensor_data/sensor_data.json");
    json jsonData;
    file >> jsonData;

    // Process the JSON data
    std::string sensorId = jsonData["sensor_id"];
    std::cout << "Sensor ID: " << sensorId << std::endl;

    for (auto &reading : jsonData["readings"])
    {
        std::string timestamp = reading["timestamp"];
        double temperature = reading["temperature_celsius"];
        double humidity = reading["humidity_percentage"];

        std::cout << "Timestamp: " << timestamp
                  << ", Temperature: " << temperature
                  << " Celsius, Humidity: " << humidity << "%" << std::endl;
    }
}

void gtest_samples(void)
{
    std::cout << "\n============================= Google Test Demo "
                 "=============================\n"
              << std::endl;
    int number = 5;
    std::cout << number << " is a primer number? " << std::boolalpha
              << IsPrime(number) << std::endl;
}

void sanitizer_demo(void)
{
    std::cout << "\n============================= Sanitizer Demo "
                 "=============================\n"
              << std::endl;

    int *p = new int[10];
    p[0] = 0;
    p = new int[10];
}

void cxxopts_demo(int argc, char **argv)
{
    std::cout << "\n============================= cxxopts Demo "
                 "=============================\n"
              << std::endl;

    cxxopts::Options options("MyProgram", "One line description of MyProgram");
    options.add_options()("d,debug", "Enable debugging") // a bool parameter
        ("i,integer", "Int param", cxxopts::value<int>())(
            "f,file",
            "File name",
            cxxopts::value<std::string>())(
            "v,verbose",
            "Verbose output",
            cxxopts::value<bool>()->default_value("false"))("h,help",
                                                            "Print usage");

    auto result = options.parse(argc, argv);

    if (result.count("help"))
    {
        std::cout << options.help() << std::endl;
        exit(0);
    }

    bool debug = result["debug"].as<bool>();
    int integer = result["integer"].as<int>();
    std::string file = result["file"].as<std::string>();
    bool verbose = result["verbose"].as<bool>();

    std::cout << "debug: " << debug << std::endl;
    std::cout << "integer: " << integer << std::endl;
    std::cout << "file: " << file << std::endl;
    std::cout << "verbose: " << verbose << std::endl;
}
