cmake_minimum_required(VERSION 3.22)

project(CppProjectDemo
        VERSION 1.0.0
        LANGUAGES C CXX)

set(CMAKE_CXX_STANDARD              20)
set(CMAKE_CXX_STANDARD_REQUIRED     ON)     # Define explicitly to use the standard declared in the previous line
set(CMAKE_CXX_EXTENSIONS            Off)    # Disable compiler extensions

# This is necessary for Sonarlint tools
# If enabled, generates a compile_commands.json file containing the exact compiler calls for all
# translation units of the project in machine-readable form.
# Note: This option currently does not work well in combination with the UNITY_BUILD target
# property or the CMAKE_UNITY_BUILD variable.
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

### CMAKE MODULES
set(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake/)
include(AddGitSubmodule)

add_git_submodule(thridparty/json)

set(LIBRARY_NAME custom_library)
set(EXECUTABLE_NAME application)

option(BUILD_APPLICATION "Build the application" ON)
option(BUILD_TESTS "Build the tests" OFF)

add_subdirectory(configuration)
add_subdirectory(thridparty)

add_subdirectory(src)

if(BUILD_TESTS)
    add_subdirectory(tests)
endif()


