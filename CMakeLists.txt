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
# Add Git submodule
include(AddGitSubmodule)
# Doxygen module
include(Docs)

set(CUSTOM_LIBRARY_NAME custom_library)
set(EXECUTABLE_NAME application)

### Thrid party libraries versions
set(SPDLOG_TAG_VERSION                  v1.13.0)
set(CXXOPTS_TAG_VERSION                 v3.1.1)
set(JSON_LIB_TAG_VERSION                v3.11.3)
set(GOOGLE_TEST_TAG_VERSION             v1.14.0)

option(BUILD_APPLICATION "Build the application" ON)
option(BUILD_TESTS "Build the tests" OFF)

option(INCLUDE_GTEST "Include googletest in build" ON)
option(USE_GIT_SUBMODULES "Use git submodules during build" ON)

add_git_submodule(thridparty/sdplog ${SPDLOG_TAG_VERSION})
add_git_submodule(thridparty/cxxopts ${CXXOPTS_TAG_VERSION})
add_git_submodule(thridparty/json ${JSON_LIB_TAG_VERSION})

if(INCLUDE_GTEST)
    if(USE_GIT_SUBMODULES)
        message(STATUS "GIT SUBMODULES: updating git submodules...")
        add_git_submodule(thridparty/googletest ${GOOGLE_TEST_TAG_VERSION})
    else()
        message(STATUS "FETCH CONTENT: Clone Google Test Framework from Git repository...")
        include(FetchContent)
        FetchContent_Declare(
            googletest
            GIT_REPOSITORY https://github.com/google/googletest.git
            GIT_TAG ${GOOGLE_TEST_TAG_VERSION}
        )

        # For Windows: Prevent overriding the parent project's compiler/linker settings
        set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
        FetchContent_MakeAvailable(googletest)
    endif()
endif()

add_subdirectory(configuration)
add_subdirectory(thridparty)

add_subdirectory(src)

# It must to be declare before the test folder
enable_testing()

if(BUILD_TESTS)
    add_subdirectory(tests)
endif()


