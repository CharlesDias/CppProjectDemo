set(CMAKE_SYSTEM_NAME Linux)
set(CMAKE_SYSTEM_PROCESSOR arm)

# Check if the C compiler exists
find_program(C_COMPILER_FOUND arm-linux-gnueabihf-gcc)
if(NOT C_COMPILER_FOUND)
    message(FATAL_ERROR "C compiler not found: arm-linux-gnueabihf-gcc")
else()
    set(CMAKE_C_COMPILER arm-linux-gnueabihf-gcc)
    set(CMAKE_C_FLAGS -static)
endif()

# Check if the C++ compiler exists
find_program(CXX_COMPILER_FOUND arm-linux-gnueabihf-g++)
if(NOT CXX_COMPILER_FOUND)
    message(FATAL_ERROR "C++ compiler not found: arm-linux-gnueabihf-g++")
else()
    set(CMAKE_CXX_COMPILER arm-linux-gnueabihf-g++)
    set(CMAKE_CXX_FLAGS -static)
endif()

set(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
set(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)
set(CMAKE_FIND_ROOT_PATH_MODE_PACKAGE ONLY)
